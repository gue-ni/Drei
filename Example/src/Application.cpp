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

		box.rotation.x += 0.5 * dt;
		box.rotation.y += 0.5 * dt;
		box.rotation.z += 0.5 * dt;

		renderer.render(&scene, &camera);
	}

	return 0;
}


