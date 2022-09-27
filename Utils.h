#pragma once
#ifndef UTILS_H
#define UTILS_H
#define GLFW_INCLUDE_NONE
#include <iostream>
#include <GLFW/glfw3.h> // GLuint

class Utils {
private:
	// https://www.tutorialspoint.com/cplusplus/cpp_static_members.htm
	// OpenGL error checking voids
	static void printShaderLog(GLuint shader);
	static void printProgramLog(int prog);
	
	// static GLuint createShaderProgram(); // Not required as all the variants are mentioned in public
	// Reading GLSL Source from files
	//static std::string readShaderSource(const char* filepath);
	// Prepare shaders
	static GLuint prepareShader(int shaderTYPE, const char* shaderPath);
	static int finalizeShaderProgram(GLuint sprogram);
public:
	static bool checkOpenGLError();
	// delete later
	static std::string readShaderSource(const char* filepath);
	static GLuint createShaderProgram(const char* vp, const char* fp);
	static GLuint createShaderProgram(const char* vp, const char* gp, const char* fp);
	static GLuint createShaderProgram(const char* vp, const char* tCS, const char* tES, const char* fp);
	static GLuint createShaderProgram(const char* vp, const char* tCS, const char* tES, const char* gp, const char* fp);
};
#endif // !UTILS_H

