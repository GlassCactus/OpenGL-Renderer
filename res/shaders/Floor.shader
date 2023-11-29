#shader vertex
#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTex;

out vec3 FragPos;
out vec3 Normal;
out vec2 Tex;

uniform mat4 normalMat;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	FragPos = vec3(model * vec4(aPos, 1.0f));
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
const float GAMMA = 2.2f;

struct TexMaterial
{
	sampler2D diffuse;
	sampler2D specular;
	float alpha;
};

uniform TexMaterial material;

uniform vec3 lightCol;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
	float distance = length(lightPos - FragPos);
	float attenuation = 1.0f / (attConst + (attLinear * distance) + (attQuad * distance * distance));

	//ambient
	vec3 ambience = vec3(texture(material.diffuse, Tex).rgb) * 0.7;

	//diffuse
	vec3 lightDir = normalize(lightPos - FragPos);
	float diff = max(dot(Normal, lightDir), 0.0f);
	vec3 diffuse = diff * vec3(texture(material.diffuse, Tex).rgb);

	//specular with normalization constant
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = normalize(reflect(-lightDir, Normal));
	vec3 halfwayDir = normalize(viewDir + reflectDir); //Blinn-Phong's halfwayDir vector
	float spec = pow(max(dot(viewDir, halfwayDir), 0.0f), material.alpha) *((material.alpha + 2.0) / (4.0 * 3.141596 * (2.0 - exp(-material.alpha / 2.0))));
	vec3 specular = spec * lightCol * texture(material.specular, Tex).rgb;

	//Blinn-Phong
	vec3 phong = (ambience + diffuse + specular) * attenuation;
	FragColor.rgb = pow(phong.rgb, vec3(1.0 / GAMMA));
}