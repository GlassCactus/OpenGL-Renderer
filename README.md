# OpenGL-Renderer
This is my renderer in OpenGL. It is a work in progress and will eventually turn into a working game/physics engine.

I started this project to teach myself the graphics pipeline and to learn about graphics APIs, shader language, rendering methods, simulations, and lighting methods. This is separate from the shadertoy 

# Features
- BRDF (Blinn-Phong & Phong Lighting)
- Texture Mapping
- Specular Normalization
- Light Maps
- Light Casters (Point Lights, Direct Lights, Spotlights)
- Gamma Correction
- Face culling
- MipMaps
- Interactive GUI

# Displays
![Wood Texture 4](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/6455dbfd-79ac-439e-bddf-cbd752b91f1a)
![Wood Texture 5](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/b0550f4c-e952-4456-a900-68babc7dcf37)
![Wood Texture 6](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/4d3619b2-34ab-426b-8787-0cebe23f3cef)


![Amogus White](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/017ede18-7db0-42c8-ba32-ea00c7176a8f)
The red, green, and blue lighting properly shows the white of the texture map.


![Blinn vs Phong RGB   BLACK](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/4f394f5b-fdf7-46d1-9742-2b9d665869aa)
The Blinn-Phong BRDF portrays a more accurate depiction of light at a grazing surface compared to the regular Phong BRDF. Note how the lights become more elongated as they do in reality compared to how the regular Phong BRDF fans the light casts. 


![Pearl and Jade](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/c5077b64-a24c-47fd-9c98-328667301c71)
A scene with no texture mapping.


# Goals
- Cubemaps
- Model Loading with Assimp
- Framebuffers
- Shadow Mapping
- Normal Mapping
- Parallax Mapping
- Cook-Torrance Lighting
- PBR
