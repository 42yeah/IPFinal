#version 330 core


in vec2 uv;

out vec4 color;

uniform sampler2D hdrTexture;
// uniform vec2 resolution;

vec3 toneMapping(vec3 hdr) {
    const float gamma = 2.2;
    vec3 mapped = hdr / (hdr + vec3(1.0));
    mapped = pow(mapped, vec3(1.0 / gamma));
    return mapped;
}

vec3 exposureMapping(vec3 hdr) {
    const float exposure = 5.0;
    const float gamma = 2.2;
    vec3 mapped = vec3(1.0) - exp(-hdr * exposure);
    mapped = pow(mapped, vec3(1.0 / gamma));
    return mapped;
}

void main() {
    vec3 hdrColor = texture(hdrTexture, uv).rgb;
    vec3 toneMapped = toneMapping(hdrColor);
    vec3 exposureMapped = exposureMapping(hdrColor);
    if (gl_FragCoord.x > 1300) {
        color = vec4(hdrColor, 1.0);
    } /* else if (gl_FragCoord.x > 1200) {
        color = vec4(exposureMapped, 1.0);
    } */ else {
        color = vec4(exposureMapped, 1.0);
    }
    
}
