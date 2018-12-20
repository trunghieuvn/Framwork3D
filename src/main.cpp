#include "ogles_sys.h"
#include <glm.hpp>
#include <stdio.h>
#include "Shaders.h"

using namespace glm;

SysContext oglSysCtx;
vec3 vertex[3];
Shaders myShader;

int Init()
{
	vertex[0].x = 0.0f;		vertex[0].y = 0.5f;		vertex[0].z = 0.0f;
	vertex[1].x = -0.5f;	vertex[1].y = -0.5f;	vertex[1].z = 0.0f;
	vertex[2].x = 0.5f;		vertex[2].y = -0.5f;	vertex[2].z = 0.0f;
	
	return myShader.Init("../data/Shaders/TriangleShaderVS.vs", "../data/Shaders/TriangleShaderFS.fs");
}

void Update(float deltaTime)
{

}

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(myShader.program);

	if (myShader.positionAttribute != -1)
	{
		glEnableVertexAttribArray(myShader.positionAttribute);
		glVertexAttribPointer(myShader.positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(vec3), &vertex[0].x);
	}

	glDrawArrays(GL_TRIANGLES, 0, 3);

	eglSwapBuffers(oglSysCtx.eglDisplay, oglSysCtx.eglSurface);
}

void Key(unsigned char key, bool bIsPressed)
{

}

void main()
{
	ZeroMemory(&oglSysCtx, sizeof(SysContext));

	sysInit(&oglSysCtx, 800, 600);

	if (Init() != 0)	//duongnt
	{	
		Debug("\nInit shader failed");
	}

	sysRegisterKeyFunc(&oglSysCtx, Key);
	sysRegisterRenderFunc(&oglSysCtx, Render);
	sysRegisterUpdateFunc(&oglSysCtx, Update);

	sysMainLoop(&oglSysCtx);
}