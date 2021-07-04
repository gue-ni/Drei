#include <iostream>
#include "core/Mesh.h"
#include "core/Renderer.h"
#include "camera/Camera.h"
#include "geometry/BoxGeometry.h"
#include "material/BasicMaterial.h"
#include "material/PhongMaterial.h"
#include "geometry/PlaneGeometry.h"

int main(void)
{
	int width = 640, height = 480;

	Renderer renderer = Renderer(width, height);

	Scene scene = Scene();

	Camera camera = Camera(width, height, 45.0f, 0.1, 100.0f);
	camera.position.z = -5;
	scene.add(&camera);

	BasicMaterial material = BasicMaterial();
	BasicMaterial material2 = BasicMaterial();
	material2.wireframe = true;

	BoxGeometry geometry = BoxGeometry(0.5, 0.5, 0.5);
	Mesh box1 = Mesh(&geometry, &material2);
	scene.add(&box1);

	BoxGeometry geometry2 = BoxGeometry(0.3, 0.3, 0.3);
	Mesh box2 = Mesh(&geometry2, &material);
	box2.position.y = 1;
	box1.add(&box2);

	BoxGeometry geometry3 = BoxGeometry(0.1, 0.1, 0.1);
	Mesh box3 = Mesh(&geometry3, &material);
	box3.position.y = 1;
	box2.add(&box3);

	float now, dt;
	float then = renderer.time();

	while (!renderer.close) {
		now = renderer.time();
		dt = now - then;
		then = now;

		box1.rotation.z += 0.3 * dt;
		box1.rotation.x += 0.3 * dt;

		box2.rotation.z += 0.5 * dt;
		box3.rotation.z += 0.7 * dt;

		renderer.render(&scene, &camera);
	}

	return 0;
}


