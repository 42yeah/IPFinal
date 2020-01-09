#version 330 core


in vec2 uv;

out vec4 color;

uniform sampler2D hdrTexture;
// uniform vec2 resolution;


void main() {
    const float gamma = 2.2;
    vec3 hdrColor = texture(hdrTexture, uv).rgb;
    vec3 mapped = hdrColor / (hdrColor + vec3(1.0));
    mapped = pow(mapped, vec3(1.0 / gamma));
    color = vec4(mapped, 1.0);
}
