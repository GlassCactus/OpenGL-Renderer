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
const float attLinear = 0.035f;
const float attQuad = 0.0005f;
const float PI = 3.141596;

const int NR_POINT_LIGHTS = 3;


struct TexMaterial
{
	sampler2D diffuse;
	sampler2D specular;
	float shine;
};

struct Materials
{
	vec3 ambientCol;
	vec3 diffCol;
	vec3 specCol;
	float alpha;
};

struct DirLight
{
	vec3 lightDir;

	vec3 ambient;
	vec3 diff;
	vec3 spec;
};

struct PointLight
{
	vec3 position;

	vec3 ambient;
	vec3 diff;
	vec3 spec;
};

uniform TexMaterial material;
uniform Materials box;
uniform sampler2D normalMap;
uniform float GAMMA;

uniform DirLight dirlight;
uniform PointLight pointlight[NR_POINT_LIGHTS];
uniform vec3 lightPos;
uniform vec3 viewPos;

uniform bool Blinn;
uniform bool ModifiedSpecNorm;
uniform bool SpecNorm;


vec3 DirectLight(DirLight light, vec3 viewPos)
{
	vec3 ambience = light.ambient * box.ambientCol;

	vec3 lightDir = normalize(light.lightDir);
	float diff = max(dot(Normal, lightDir), 0.0f);
	vec3 diffuse = diff * light.diff * box.diffCol;// texture(material.diffuse, Tex).rgb;

	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, Normal);
	vec3 halfwayDir = normalize(viewDir + lightDir); //Blinn-Phong's halfwayDir vector
	float spec = max(dot(Normal, halfwayDir), 0.0f);
	spec = pow(spec, box.alpha) * ((box.alpha + 2.0) / (4.0 * PI * (2.0 - exp(-box.alpha / 2.0))));
	vec3 specular = spec * light.spec * box.specCol;//texture(material.specular, Tex).rgb;

	return (ambience + diffuse + specular);
}


vec3 PointLights(PointLight light, vec3 FragPos)
{
	vec3 apple = lightPos;
	float distance = length(light.position - FragPos); //Try to calculate this using SDF later lol.
	float attenuation = 1.0f / (attConst + (attLinear * distance) + (attQuad * (distance * distance)));

	//ambient
	vec3 ambience = light.ambient * box.ambientCol;// texture(material.diffuse, Tex).rgb;

	//diffuse
	vec3 lightDir = normalize(light.position - FragPos);
	float diff = max(dot(Normal, lightDir), 0.0f);
	vec3 diffuse = light.diff * diff * box.diffCol;// texture(material.diffuse, Tex).rgb;

	//specular with normalization constant
	vec3 viewDir = normalize(viewPos - FragPos);
	float spec;

	if (Blinn)
	{
		vec3 halfwayDir = normalize(viewDir + lightDir); //Blinn-Phong's halfwayDir vector
		spec = max(dot(Normal, halfwayDir), 0.0f);
	}

	else
	{
		vec3 reflectDir = reflect(-lightDir, Normal);
		spec = max(dot(viewDir, reflectDir), 0.0f);
	}

	float specNormalization = 1.0f;

	if (ModifiedSpecNorm)
		specNormalization = (box.alpha + 2.0) / (4.0 * PI * (2.0 - exp(-box.alpha / 2.0)));

	if (SpecNorm)
		specNormalization = (box.alpha + 1.0) / (2.0 * PI);


	spec = pow(spec, box.alpha) * specNormalization;
	vec3 specular = spec * (light.spec*0.25) * box.specCol;//texture(material.specular, Tex).rgb;

	//Blinn-Phong!!!
	return (ambience + diffuse + specular) * attenuation;
}

void main()
{
	box;
	material;
	vec3 phong = vec3(0.0, 0.0, 0.0);
	
	for (int i = 0; i < NR_POINT_LIGHTS; i++)
	{
		phong += (PointLights(pointlight[i], FragPos));
	}
	//phong = pow(DirectLight(dirlight, FragPos).rgb, vec3(1.0/GAMMA));

	
	FragColor.rgb = pow(phong.rgb, vec3(1.0 / GAMMA));
}