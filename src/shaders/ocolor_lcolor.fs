#version 420 core

in vec3 fragPos;
in vec3 Normal;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;

out vec4 FragColor;
void main()
{
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - fragPos);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    float ambientStrength = 0.2;
    vec3 ambientLight = ambientStrength * lightColor;
    vec3 result = (ambientLight + diffuse) * objectColor;    

    FragColor = vec4(result, 1.0f);
}