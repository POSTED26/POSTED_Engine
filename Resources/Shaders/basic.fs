#version 460 core

in vec3 ourColor;
in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D texture1;

void main()
{
   FragColor = texture(texture1, TexCoord) * vec4(ourColor, 1.0);
   //FragColor = vec4(ourColor, 1.0f); //vec4(1.0f, 0.5f, 0.2f, 1.0f);
}