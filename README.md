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


![3 Lights with Proper GAMMA](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/6ee4077d-c61d-429e-80b3-538b16e6c566)


![Amogus Texture](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/f867db27-f648-421e-ad54-b40bc7eb3c38)


![Amogus White](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/017ede18-7db0-42c8-ba32-ea00c7176a8f)
*Fixed a bug where the colored lights weren't combining properly. Here you can see the red, green and blue properly display the white color of the texture map*


![Blinn vs Phong RGB   BLACK](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/4f394f5b-fdf7-46d1-9742-2b9d665869aa)
*Note how Blinn-Phong lighting make the lights elongate like in real life compared to the more circular light casts of the regular Phong Lighting. The scene on the is the same scene but with white lights and 0 diffuse*


# Goals
- Cubemaps
- Model Loading with Assimp
- Framebuffers
- Shadow Mapping
- Normal Mapping
- Parallax Mapping
- Cook-Torrance Lighting
- PBR
