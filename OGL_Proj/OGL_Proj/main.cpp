// Right angle triangle example using OpenGL 4.3
#define GLFW_INCLUDE_NONE // This helps to include glew and glfw in any order
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define numVAOs 1

GLuint renderingProgram;
GLuint vao[numVAOs];

GLuint createShaderProgram() {

  const char *vshaderSource{
      "#version 430 \n"
      "void main(void) \n"
      "{if (gl_VertexID == 0) gl_Position = vec4(0.25, -0.25, 0.0, 1.0); else "
      "if (gl_VertexID == 1) gl_Position = vec4(-0.25, -0.25, 0.0, 1.0); else "
      "gl_Position = vec4( 0.25, 0.25, 0.0, 1.0);}"};

  const char *fshaderSource{"#version 430 \n"
                            "out vec4 color; \n"
                            "void main(void) \n"
                            "{color = vec4(1.0, 0.6, 0.0, 1.0);}"};

  GLuint vShader{glCreateShader(GL_VERTEX_SHADER)};
  GLuint fShader{glCreateShader(GL_FRAGMENT_SHADER)};

  glShaderSource(vShader, 1, &vshaderSource, NULL);
  glShaderSource(fShader, 1, &fshaderSource, NULL);
  glCompileShader(vShader);
  glCompileShader(fShader);

  GLuint vfProgram{glCreateProgram()};
  glAttachShader(vfProgram, vShader);
  glAttachShader(vfProgram, fShader);
  glLinkProgram(vfProgram);

  return vfProgram;
}

void init(GLFWwindow *window) {
  renderingProgram = createShaderProgram();
  glGenVertexArrays(numVAOs, vao);
  glBindVertexArray(vao[0]);
}

void display(GLFWwindow *window, double currentTime) {
  glUseProgram(renderingProgram);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glPointSize(30.0f);
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
