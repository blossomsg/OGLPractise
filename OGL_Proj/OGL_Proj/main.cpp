#define GLFW_INCLUDE_NONE // This helps to include glew and glfw in any order
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void init(GLFWwindow *window) {}

void display(GLFWwindow *window, double currentTime) {
  glClearColor(1.0, 0.42, 0.31, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

int main(void) {
  // Initialize GLFW to run all the functions.
  if (!glfwInit()) {
    exit(EXIT_FAILURE);
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  GLFWwindow *window = glfwCreateWindow(600, 600, "OGL_Proj", NULL, NULL);
  glfwMakeContextCurrent(window);

  // Initialize GLEW to run all the functions.
  if (glewInit() != GLEW_OK) {
    exit(EXIT_FAILURE);
  }
  glfwSwapInterval(1);

  init(window);

  while (!glfwWindowShouldClose(window)) {
    display(window, glfwGetTime());
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
}
