#shader vertex
#version 330 core

layout(location = 0) in vec4 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * aPos;
}


#shader fragment
#version 330 core


out vec4 FragColor;

uniform vec4 luminosity;


void main()
{
	FragColor = luminosity;
}