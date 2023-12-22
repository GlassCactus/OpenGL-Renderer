# OpenGL-Renderer
This is my renderer in OpenGL. It is a work in progress and the plan is to turn this into a physics/game engine. 

I started this project to teach myself the graphics pipeline and to learn about graphics API, shader language, rendering methods, simulations, and lighting methods. I'll also be logging things I find interesting to help both me and anyone who comes across this project. 

# Planned Features
- [x] BRDF (Blinn-Phong & Phong Lighting)
- [x] Texture Mapping
- [x] MipMaps
- [x] Light Mapping & Light Casters (Point Lights, Direct Lights, Spotlights)
- [x] Specular Normalization
- [x] Gamma Correction
- [x] Face culling
- [x] Interactive GUI
- [ ] Shadow Mapping/Point Shadows
- [ ] Normal Mapping
- [ ] Parallax Mapping
- [ ] Cubemaps

# Third Party Libraries
- [GLFW](https://github.com/glfw/glfw): A multi-platform library for window and input.
- [GLM](https://github.com/g-truc/glm): A header only mathematics software for graphics software 
- [ImGUI](https://github.com/ocornut/imgui): It's the GUI
- [stb_image](https://github.com/ocornut/imgui): Used for loading images

# Displays
![Wood Texture 4](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/a9d1899a-a1d1-4f13-9e2f-dee27b0ed06b)
![Wood Texture 5](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/64c66dc5-53d3-4b86-84be-1d5762257e7f)
![Wood Texture 6](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/c73caf61-52eb-40f8-81b9-71a08bdc8d0d)
![Amogus White](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/6b011947-4c98-47fb-8990-e106ce02292f)
<br /><br />

# Blinn-Phong BRDF vs Phong BRDF
Light tends to elongate alongside a surface when viewed at grazing angles. The Blinn-Phong BRDF depicts a more realistic lighting by emulating this elongation through a modified specular component.<br /><br />
![Blinn vs Phong Wood](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/e2bb18f8-a3a0-4245-853e-7efe41bc77c0)<br />
You can see the difference between both methods more clearly at increased alpha values. The regular Phong model cuts off the streak of light abruptly and casts a more circular reflection while the Blinn-Phong model makes the light casts streak downward from the user's POV.<br /><br />
**Note:** In every depiction in this README, the light sources are coming from a singular point in the center of each light box. The boxes themselves are not the ones emitting light. They're just cute.
<br /><br />

# Specular Normalization
I'll add more to this later, but for now screenshots and references for where I learned about this stuff are listed at the bottom of the README.<br /><br />
**Tl:dr version:** By including a normalization constant in the specular component of the BRDF, we can modify how the intensity of the specular reflection scales with the angle. This lets the total output of light stay constant, but it would be inaccurate to say that energy is being conserved. This isn't a PBR method, but it's pretty damn good and cheap.<br /><br />
![Spec P norm 1 -](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/fff83fd8-b8c0-48b5-bdc9-250fc4a10a9c)
![Spec P norm 2 - Copy](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/a8132ca1-cfaa-417b-8d4e-190d6ceeaceb)
![Spec P norm 3 - Copy](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/8ede7975-1161-4461-8a42-c615c9d51123)
<br />
Using the standard Phong Normalization method, the speculars are harsh and have strong cut offs at the "edge" of the reflections. The modified Blinn-Phong Normalization depicts a better representation of how much specular light is being distributed and reflected towards the viewer's POV.
<br /><br />

# Z-Buffering
I ran into a bug where these black artifacts kept appearing at the edges of my boxes. After some reading I realized that it was a z-buffering issue since the artifacts were specifically appearing in spots where z-fighting was possible. It also helped learning that the depth buffering function in OpenGL was not linear.<br /><br />
![Z Buffer Bug 2](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/2a953a96-b8f8-47c7-946b-8c43a8832a5a)<br />
The Z-buffering provided by OpenGL uses a Non-linear Z-Buffering function which is proportional to $1/nearPlane$. This meant that the accuracy of depth testing diminished DRASTICALLY as the nearPlane approached zero. 
$$Non Linear Depth Buffer = \frac{1/z-1/nearPlane}{1/farPlane-1/nearPlane}$$
All I had to do was increase the nearPlane from 0.001 to 0.1 and the artifacts disappeared. I was able to recreate a more extreme version of this bug by further reducing the nearPlane value to nearPlane = 0.0001 which is displayed below. Even though this was a very easy fix, I was pretty amped that I was able to figure it out.<br /><br />
![Z Buffer Bug 4](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/c0f64ea9-4697-410c-8e69-a194aa365c4a)<br />
Recreating a more extreme version shows that the artifacts weren't actually black, but instead the interior of the wood texture. It confirmed that the artifacts were a product of z-fighting.

# Bigger Goals 
- [x] Interactive UI with ImGUI
- [ ] Model Loading with Assimp
- [ ] Cook-Torrance Lighting
- [ ] PBR
- [ ] Particle Simulation
- [ ] Game Perhaps??
<br /><br />

# References & Resources
https://learnopengl.com/<br />
http://www.thetenthplanet.de/archives/255<br />
http://www.farbrausch.de/~fg/stuff/phong.pdf
