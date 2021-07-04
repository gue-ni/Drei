#include "drei/core/Mesh.h"
#include "drei/core/Renderer.h"
#include "drei/camera/Camera.h"
#include "drei/geometry/BoxGeometry.h"
#include "drei/material/BasicMaterial.h"

int main(void)
{
	int width = 640, height = 480;

	DREI::Renderer renderer = DREI::Renderer(width, height);
	DREI::Scene scene = DREI::Scene();

	DREI::Camera camera = DREI::Camera(width, height, 45.0f, 0.1, 100.0f);
	camera.position.z = -5;
	scene.add(&camera);

	DREI::BasicMaterial material = DREI::BasicMaterial();
	DREI::BoxGeometry geometry = DREI::BoxGeometry(1,1,1);
	DREI::Mesh cube = DREI::Mesh(&geometry, &material);
	scene.add(&cube);

	float now, dt;
	float then = renderer.time();

	while (!renderer.close) {
		now = renderer.time();
		dt = now - then;
		then = now;

		cube.rotation.x += 0.5 * dt;
		cube.rotation.y += 0.5 * dt;

		renderer.render(&scene, &camera);
	}

	return 0;
}


