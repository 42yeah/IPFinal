#version 330 core


in vec2 uv;

out vec4 color;

uniform samplerBuffer cameraTexture;
uniform vec2 resolution;

void main() {
    vec2 invUV = vec2(uv.x, 1.0 - uv.y);
    vec2 sp = invUV * resolution;
    ivec2 samplePos = ivec2(floor(sp.x), floor(sp.y));
    int offset = samplePos.x + int(samplePos.y * resolution.x);
    vec3 sampled = texelFetch(cameraTexture, offset).bgr;
    float redness = sampled.r / 256.0;
    color = vec4(redness, redness, redness, 1.0);
}
