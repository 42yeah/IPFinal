#version 330 core


in vec2 uv;

out vec4 color;

uniform samplerBuffer cameraTexture;
uniform vec2 resolution;


vec4 textureCam(vec2 _uv) {
    vec2 invUV = vec2(1.0 - _uv.x, 1.0 - _uv.y);
    vec2 sp = invUV * resolution;
    ivec2 samplePos = ivec2(floor(sp.x), floor(sp.y));
    int offset = (samplePos.x + int(samplePos.y * resolution.x)) * 3;
    vec3 sampled = vec3(texelFetch(cameraTexture, offset + 2).r, texelFetch(cameraTexture, offset + 1).r, texelFetch(cameraTexture, offset).r); // BGR
    return vec4(sampled, 1.0);
}

void main() {
    color = vec4(textureCam(uv).rgb, 1.0);
}
