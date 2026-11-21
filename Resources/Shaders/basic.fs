#version 460 core

//in vec3 ourColor;
in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D texture1;

void main()
{
   FragColor = texture(texture1, TexCoord);
   //FragColor = vec4(0.9352f, 0.8490f, 0.0017, 1.0f); //vec4(1.0f, 0.5f, 0.2f, 1.0f);
}