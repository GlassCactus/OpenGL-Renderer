#shader vertex
#version 330 core

layout(location = 0) in vec3 aPos; //This refers to their index in the AttribPointer
layout(location = 1) in vec3 aNormal; //The normal vectors 
layout(location = 2) in vec2 aTex; //Texture coordinates

out vec3 FragPos;
out vec3 Normal;
out vec2 Tex;

uniform mat4 normalMat;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	FragPos = vec3(model * vec4(aPos, 1.0f)); //position of the target box (orange boi)
	Tex = aTex;
	gl_Position = projection * view * vec4(FragPos, 1.0f);
	
	Normal = normalize(mat3(normalMat) * aNormal);
}

//==============================================================================================================//
//==============================================================================================================//

#shader fragment
#version 330 core

out vec4 FragColor;
in vec3 FragPos;
in vec3 Normal;
in vec2 Tex;

const float attConst = 1.0f;
const float attLinear = 0.0035f;
const float attQuad = 0.0005f;

struct Material
{
	sampler2D diffuse;
	sampler2D specular;
	vec3 ambient;
	float shine;
};

struct Materials
{
	vec3 ambientCol;
	vec3 diffCol;
	vec3 specCol;
	float alpha;
};


uniform Material material;
uniform Materials choc;

uniform vec3 lightCol;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
	material;
	float distance = length(lightPos - FragPos); //Try to calculate this using SDF later lol.
	float attenuation = 1.0f / (attConst + (attLinear * distance) + (attQuad * distance * distance));

	//ambient
	vec3 ambience = choc.ambientCol;// texture(material.diffuse, Tex).rgb;

	//diffuse
	vec3 lightDir = normalize(lightPos - FragPos);
	float diff = max(dot(Normal, lightDir), 0.0f); 
	vec3 diffuse = diff * choc.diffCol;// texture(material.diffuse, Tex).rgb;

	//specular
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, Normal);
	vec3 halfwayDir = normalize(viewDir + reflectDir); //Blinn-Phong's halfwayDir vector
	float spec = pow(max(dot(viewDir, halfwayDir), 0.0f), choc.alpha) * ((choc.alpha + 2.0) / (4.0 * 3.141596 * (2.0 - exp(-choc.alpha / 2.0))));
	vec3 specular = spec * choc.specCol;//texture(material.specular, Tex).rgb;

	//phong!!!
	vec3 phong = (ambience + diffuse + specular) * attenuation * lightCol;
	FragColor = vec4(phong, 1.0f); //You can add "CalculateDirLight" directly to "Phong" to include "Sunlight" alongside the regular lighting
}