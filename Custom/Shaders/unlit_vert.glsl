#version 330 core

layout (location = 0) in vec3 vert_pos;
layout (location = 2) in vec2 vert_uv;

uniform mat4 model_transform;
uniform mat4 camera_transform;
uniform mat4 camera_normalization;

out vec2 frag_uv;

void main() {
    frag_uv = vert_uv;
    gl_Position = camera_normalization * inverse(camera_transform) * model_transform * vec4(vert_pos, 1.0);
}