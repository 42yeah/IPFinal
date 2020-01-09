#version 330 core


in vec2 uv;

out vec4 color;

uniform sampler2D hdrTexture;
// uniform vec2 resolution;


void main() {
    color = vec4(texture(hdrTexture, uv).rgb, 1.0);
}
