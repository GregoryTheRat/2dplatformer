#version 420 core

uniform sampler2D texture1;

in vec3 ourColor;
in vec2 TexCoord;

out vec4 FragColor;

void main()
{
    FragColor = texture(texture1, TexCoord);
}
