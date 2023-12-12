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

![Pearl and Jade](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/c5077b64-a24c-47fd-9c98-328667301c71)

![Wood Texture 4](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/6455dbfd-79ac-439e-bddf-cbd752b91f1a)
![Wood Texture 5](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/b0550f4c-e952-4456-a900-68babc7dcf37)
![Wood Texture 6](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/4d3619b2-34ab-426b-8787-0cebe23f3cef)



![Amogus White](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/017ede18-7db0-42c8-ba32-ea00c7176a8f)
Fixed a bug where the colored lights weren't combining properly. Here you can see the red, green and blue properly display the white color of the texture map


![Blinn vs Phong RGB   BLACK](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/4f394f5b-fdf7-46d1-9742-2b9d665869aa)
Note how Blinn-Phong lighting make the lights elongate like in real life compared to the more circular light casts of the regular Phong Lighting. The scene on the is the same scene but with white lights and 0 diffuse


# Goals
- Cubemaps
- Model Loading with Assimp
- Framebuffers
- Shadow Mapping
- Normal Mapping
- Parallax Mapping
- Cook-Torrance Lighting
- PBR
