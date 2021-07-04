# Drei

A high level 3D library using C++ and OpenGL inspired by [three.js](https://github.com/mrdoob/three.js/). Just trying to make 3D graphics in C++ easier.

## Usage

```c++

#include "core/Mesh.h"
#include "core/Renderer.h"
#include "camera/Camera.h"
#include "geometry/BoxGeometry.h"
#include "material/BasicMaterial.h"

int main(void)
{
	int width = 640, height = 480;

	Renderer renderer = Renderer(width, height);
	Scene scene = Scene();

	Camera camera = Camera(width, height, 45.0f, 0.1, 100.0f);
	camera.position.z = -5;
	scene.add(&camera);

	BasicMaterial material = BasicMaterial();

	BoxGeometry geometry = BoxGeometry(0.5, 0.5, 0.5);
	Mesh box = Mesh(&geometry, &material);
	scene.add(&box);

	float now, dt;
	float then = renderer.time();

	while (!renderer.close) {
		now = renderer.time();
		dt = now - then;
		then = now;

		box.rotation.z += 0.5 * dt;
		box.rotation.z += 0.5 * dt;

		renderer.render(&scene, &camera);
	}

	return 0;
}
```
