#pragma once
#ifndef UTILS_H
#define UTILS_H
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>

class Utils {
public:
  static std::string readShaderSource(const char *filePath);
};

#endif // !UTILS_H
