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

# Displays
![Wood Texture 4](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/a9d1899a-a1d1-4f13-9e2f-dee27b0ed06b)
![Wood Texture 5](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/64c66dc5-53d3-4b86-84be-1d5762257e7f)
![Wood Texture 6](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/c73caf61-52eb-40f8-81b9-71a08bdc8d0d)
![Amogus White](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/6b011947-4c98-47fb-8990-e106ce02292f)
<br /><br />

# Blinn-Phong BRDF vs Phong BRDF
Light tends to elongate alongside a surface when viewed at grazing angles. The Blinn-Phong BRDF depicts a more realistic lighting by emulating this elongation through a modified specular component.
![Blinn vs Phong Wood](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/e2bb18f8-a3a0-4245-853e-7efe41bc77c0)<br />
You can see the difference between both methods more clearly at increased alpha values. The regular Phong model cuts off the streak of light abruptly and casts a more circular reflection while the Blinn-Phong model makes the light casts streak downward from the user's POV. <br /><br />
**Note:** In every depiction in this README, the light sources are coming from a singular point in the center of each light box. The boxes themselves are not the ones emitting light. They're just cute.
<br /><br />

# Specular Normalization
I'll add more to this later, but for now screenshots and references for where I learned about this stuff are listed at the bottom of the README.<br /><br />
**Tl:dr version:** By including a normalization constant in the specular component of the BRDF, we can modify how the intensity of the specular reflection scales with the angle. This lets the total output of light stay constant, but it would be inaccurate to say that energy is being conserved. This isn't a PBR method, but it's pretty damn good and cheap.
![Spec P norm 1 -](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/fff83fd8-b8c0-48b5-bdc9-250fc4a10a9c)
![Spec P norm 2 - Copy](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/a8132ca1-cfaa-417b-8d4e-190d6ceeaceb)
![Spec P norm 3 - Copy](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/8ede7975-1161-4461-8a42-c615c9d51123)
<br />
Using the standard Phong Normalization method, the speculars are harsh and have strong cut offs at the "edge" of the reflections. The modified Blinn-Phong Normalization depicts a better representation of how much specular light is being distributed and reflected towards the viewer's POV.
<br /><br />

# Z-Buffering
![Z Buffer Bug 2](https://github.com/GlassCactus/OpenGL-Renderer/assets/86325057/3e8ac73b-2ea6-4efa-a2a5-65db9c59a920)<br />
Artifacts appeared around the outer edges of the cubes due to a depth testing issue. The Z-buffering provided by OpenGL uses a Non-linear Z-Buffering function so the accuracy of depth testing diminished (honestly the values calculated became extremely off) as the nearPlane approached zero. I was able to emulate a more extreme version of this bug by further reducing the nearPlane value. $$Non Linear Depth Buffer = \frac{1/z-1/nearPlane}{1/farPlane-1/nearPlane}$$

# Bigger Goals 
- [x] Interactive UI with ImGUI
- [ ] Model Loading with Assimp
- [ ] Cook-Torrance Lighting
- [ ] PBR
- [ ] Particle Simulation
- [ ] Game Perhaps??
<br /><br />

# References & Links
http://www.thetenthplanet.de/archives/255<br />
http://www.farbrausch.de/~fg/stuff/phong.pdf
