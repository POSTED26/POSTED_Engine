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
uniform vec3 viewPos;


void main()
{
   float ambientStrength = 0.1;
   vec3 ambient = ambientStrength * lightColor;

   // diffuse
   vec3 norm = normalize(normal);
   vec3 lightDir = normalize(lightPos - fragPos);
   float diff = max(dot(norm, lightDir), 0.0f);
   vec3 diffuse = diff * lightColor;

   float specStrength = 0.5f;
   vec3 viewDir = normalize(viewPos - fragPos);
   vec3 relectDir = reflect(-lightDir, norm);
   float spec = pow(max(dot(viewDir, relectDir), 0.0), 256);
   vec3 specular = specStrength * spec * lightColor;

   vec3 result = (ambient + diffuse + specular) * objectColor;
   //FragColor = texture(texture1, TexCoord);
   FragColor = vec4(result, 1.0f); //vec4(1.0f, 0.5f, 0.2f, 1.0f);
}