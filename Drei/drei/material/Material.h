#pragma once
#include "../camera/Camera.h"
#include "../core/Object3D.h"
#include "MaterialOptions.h"

#include <string>

namespace DREI {
	class Material
	{
	public:
		int shader = -1;
		bool wireframe = false;
		glm::vec3 color = glm::vec3(0.0f, 1.0f, 0.0f);
		DREI::MaterialOptions* options;

		Material(DREI::MaterialOptions* options);

		virtual void draw(DREI::Camera* camera, DREI::Object3D* object) = 0;

	protected:
		void loadFile(std::string filename, std::string& code);
		int loadShader(std::string vertexShaderPath, std::string fragementShaderPath);
		int createShader(std::string& vertexShaderCode, std::string& fragementShaderCode);
	};
}
