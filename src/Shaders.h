#pragma once

#include "ogles_sys.h"
#include <glm.hpp>
#include <stdio.h>

using namespace glm;

class Shaders
{
public:
	GLuint program, vertexShader, fragmentShader;
	char fileVS[260];
	char fileFS[260];
	GLint positionAttribute;

	Shaders();
	~Shaders();

	GLint Init(char* vertexShaderFilePath, char* fragmentShaderFilePath);

private:
	GLuint LoadShader(GLuint type, char* filePath);
	GLuint LoadProgram(GLuint vertexShader, GLuint fragmentShader);
};

