#version 460 core

//in vec3 ourColor;
//in vec2 TexCoord;
in vec3 normal;
//in vec3 lightPos;
in vec3 fragPos;

out vec4 FragColor;

uniform sampler2D texture1;
uniform vec3 lightColor;
uniform vec3 objectColor;
uniform vec3 lightPos;


void main()
{
   float ambientStrength = 0.1;
   vec3 ambient = ambientStrength * lightColor;

   // diffuse
   vec3 norm = normalize(normal);
   vec3 lightDir = normalize(lightPos - fragPos);
   float diff = max(dot(norm, lightDir), 0.0f);
   vec3 diffuse = diff * lightColor;

   vec3 result = (ambient + diffuse)* objectColor;
   //FragColor = texture(texture1, TexCoord);
   FragColor = vec4(result, 1.0f); //vec4(1.0f, 0.5f, 0.2f, 1.0f);
}