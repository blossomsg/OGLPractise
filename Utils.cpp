#define GLFW_INCLUDE_NONE
#include <iostream>
#include <string>
#include <fstream>
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include "Utils.h"

void Utils::printShaderLog(GLuint shader) {
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
	if (len > 0) {
		log = (char*)malloc(len);
		glGetShaderInfoLog(shader, len, & chWrittn, log);
		std::cout << "Shader Info Log: " << log << std::endl;
		free(log);
	}
}

void Utils::printProgramLog(int prog) {
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
	if (len > 0) {
		log = (char*)malloc(len);
		glGetProgramInfoLog(prog, len, &chWrittn, log);
		std::cout << "Program Info Log: " << log << std::endl;
		free(log);
	}
}

bool Utils::checkOpenGLError() {
	bool foundError = false;
	int glErr = glGetError();
	while (glErr != GL_NO_ERROR) {
		std::cout << "glError: " << std::endl;
		foundError = true;
		glErr = glGetError();
	}
	return foundError;
}

std::string Utils::readShaderSource(const char* filePath) {
	std::string content;
	std::ifstream fileStream(filePath, std::ios::in);
	std::string line = "";
	while (!fileStream.eof()) {
		std::getline(fileStream, line);
		content.append(line + "\n");
	}
	fileStream.close();
	return content;
}

// This is not mentioned in the book, probably those who have purchased the book might find below code in a CD
GLuint Utils::prepareShader(int shaderTYPE, const char* shaderPath) {
	GLint shaderCompiled;
	std::string shaderStr = readShaderSource(shaderPath);
	const char* shaderSrc = shaderStr.c_str();
	GLuint shaderRef = glCreateShader(shaderTYPE);
	glShaderSource(shaderRef, 1, &shaderSrc, NULL);
	glCompileShader(shaderRef);
	checkOpenGLError();
	glGetShaderiv(shaderRef, GL_COMPILE_STATUS, &shaderCompiled);
	if (shaderCompiled != 1) {
		if (shaderTYPE == 35633) std::cout << "Vertex ";
		if (shaderTYPE == 36488) std::cout << "Tess Control ";
		if (shaderTYPE == 36487) std::cout << "Tess Eval ";
		if (shaderTYPE == 36313) std::cout << "Geometry ";
		if (shaderTYPE == 35632) std::cout << "Fragment ";
		std::cout << "shader compilation error." << std::endl;
		printShaderLog(shaderRef);
	}
	return shaderRef;
}

// Book Page no. - 25
int Utils::finalizeShaderProgram(GLuint sprogram) {
	GLint linked;
	glLinkProgram(sprogram);
	checkOpenGLError();
	glGetProgramiv(sprogram, GL_LINK_STATUS, &linked);
	if (linked != 1) {
		std::cout << "linking failed" << std::endl;
		printProgramLog(sprogram);
	}
	return sprogram;
}

GLuint Utils::createShaderProgram(const char* vp, const char* fp) {
	GLuint vShader = prepareShader(GL_VERTEX_SHADER, vp);
	GLuint fShader = prepareShader(GL_FRAGMENT_SHADER, fp);
	GLuint vfProgram = glCreateProgram();
	glAttachShader(vfProgram, vShader);
	glAttachShader(vfProgram, fShader);
	finalizeShaderProgram(vfProgram);
	return vfProgram;
}

GLuint Utils::createShaderProgram(const char* vp, const char* gp, const char* fp) {
	GLuint vShader = prepareShader(GL_VERTEX_SHADER, vp);
	GLuint gShader = prepareShader(GL_GEOMETRY_SHADER, gp);
	GLuint fShader = prepareShader(GL_FRAGMENT_SHADER, fp);
	GLuint vgfProgram = glCreateProgram();
	glAttachShader(vgfProgram, vShader);
	glAttachShader(vgfProgram, gShader);
	glAttachShader(vgfProgram, fShader);
	finalizeShaderProgram(vgfProgram);
	return vgfProgram;
}

GLuint Utils::createShaderProgram(const char* vp, const char* tCS, const char* tES, const char* fp) {
	GLuint vShader = prepareShader(GL_VERTEX_SHADER, vp);
	GLuint tcShader = prepareShader(GL_TESS_CONTROL_SHADER, tCS);
	GLuint teShader = prepareShader(GL_TESS_EVALUATION_SHADER, tES);
	GLuint fShader = prepareShader(GL_FRAGMENT_SHADER, fp);
	GLuint vtfProgram = glCreateProgram();
	glAttachShader(vtfProgram, vShader);
	glAttachShader(vtfProgram, tcShader);
	glAttachShader(vtfProgram, teShader);
	glAttachShader(vtfProgram, fShader);
	return vtfProgram;
}

GLuint Utils::createShaderProgram(const char* vp, const char* tCS, const char* tES, const char* gp, const char* fp) {
	GLuint vShader = prepareShader(GL_VERTEX_SHADER, vp);
	GLuint tcShader = prepareShader(GL_TESS_CONTROL_SHADER, tCS);
	GLuint teShader = prepareShader(GL_TESS_EVALUATION_SHADER, tES);
	GLuint gShader = prepareShader(GL_GEOMETRY_SHADER, gp);
	GLuint fShader = prepareShader(GL_FRAGMENT_SHADER, fp);
	GLuint vtgfProgram = glCreateProgram();
	glAttachShader(vtgfProgram, vShader);
	glAttachShader(vtgfProgram, tcShader);
	glAttachShader(vtgfProgram, teShader);
	glAttachShader(vtgfProgram, gShader);
	glAttachShader(vtgfProgram, fShader);
	return vtgfProgram;
}