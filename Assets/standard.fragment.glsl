#version 330 core


in vec2 uv;

out vec4 color;

uniform samplerBuffer cameraTexture;
uniform vec2 resolution;

void main() {
    vec2 sp = uv * resolution;
    ivec2 samplePos = ivec2(floor(sp.x), floor(sp.y));
    int offset = samplePos.x + int(samplePos.y * resolution.x);
    color = vec4(texelFetch(cameraTexture, offset).rrr, 1.0);
}
