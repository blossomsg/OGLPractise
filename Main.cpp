#define GLFW_INCLUDE_NONE
#include<GLFW/glfw3.h>
#include<GL/glew.h>
#include<iostream>
using namespace std;

void init(GLFWwindow* window) {

}

// Color values
void display(GLFWwindow* window, double currentTime) {
	glClearColor(1.0, 0.0, 0.0, 1.0); // clamped to the range [0,1]
	glClear(GL_COLOR_BUFFER_BIT); // clear color buffer(colors)
}

int main(void) {
	if (!glfwInit()) {
		//Initializing GLFW
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	GLFWwindow* window = glfwCreateWindow(640, 480, "color window", NULL, NULL);
	if (!window) {
		exit(EXIT_FAILURE);
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	
	if (glewInit() != GLEW_OK) {
		// Initializing GL
		exit(EXIT_FAILURE);
	}
	glfwSwapInterval(1);
	
	while (!glfwWindowShouldClose(window)) {
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Destroying the window
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}