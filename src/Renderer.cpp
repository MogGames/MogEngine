#include "Renderer.h"
#include <GL/gl.h>

Renderer::Renderer() {}

Renderer::~Renderer() {}

bool Renderer::Initialize() {
  // Initialize OpenGL-related functions
  return true;
}

void Renderer::Clear() {
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Background color
  glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
}
