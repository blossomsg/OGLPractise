#define GLFW_INCLUDE_NONE
#include<GLFW/glfw3.h>
#include<GL/glew.h>
#include<iostream>
#include<string>
using namespace std;

void init(GLFWwindow* window) {

}

void display(GLFWwindow* window, double currentTime) {
    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(void) {
    //Initialize GLFW
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    //OpenGL version
    glfwWindowHint(GLFW_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_VERSION_MAJOR, 6);
    //Window creation
    GLFWwindow* window = glfwCreateWindow(640, 480, "Practise", NULL, NULL);
    //Window does not match
    if (!window) {
        exit(EXIT_FAILURE);
        glfwTerminate();
    }
    //Select current context
    glfwMakeContextCurrent(window);

    //Initialize GLEW
    if (glewInit() != GLEW_OK) {
        exit(EXIT_FAILURE);
    }
    //avoid screen tear useful for High-motion-conten-graphics(vsync)
    glfwSwapInterval(1);

    init(window);
    while (!glfwWindowShouldClose(window)) {
        display(window, glfwGetTime());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //Destory GLFW window
    glfwDestroyWindow(window);
    //Terminate GLFW
    glfwTerminate();
    exit(EXIT_SUCCESS);
}