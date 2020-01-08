#version 330 core


in vec2 uv;

out vec4 color;

uniform samplerBuffer cameraTexture;
uniform vec2 resolution;

void main() {
    vec2 invUV = vec2(uv.x, 1.0 - uv.y);
    vec2 sp = invUV * resolution;
    ivec2 samplePos = ivec2(floor(sp.x), floor(sp.y));
    int offset = (samplePos.x + int(samplePos.y * resolution.x)) * 3;
    vec3 sampled = vec3(texelFetch(cameraTexture, offset + 2).r,
        texelFetch(cameraTexture, offset + 1).r,
        texelFetch(cameraTexture, offset).r);
    color = vec4(sampled.r, sampled.g, sampled.b, 1.0);
}
