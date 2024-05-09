#version 420 core

uniform vec3 objectColor;
uniform vec3 lightColor;

out vec4 FragColor;
void main()
{
    float ambientStrength = 0.2;
    vec3 ambientLight = ambientStrength * lightColor;
    vec3 result = ambientLight * objectColor;    

    FragColor = vec4(result, 1.0f);
}