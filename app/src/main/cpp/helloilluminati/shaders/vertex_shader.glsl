#version 300 es

layout (location = 0) in vec2 inPosition;
layout (location = 1) in vec2 inTextureCoordinates;

uniform mat4 uModel;

out vec2 textureCoordinates;

void main()
{
    gl_Position = uModel * vec4(inPosition, 0.0f, 1.0f);
    textureCoordinates = inTextureCoordinates;
}