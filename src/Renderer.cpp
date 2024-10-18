#include "Renderer.h"
#include "../external/glad/glad.h"
#include "Shader.h"
#include <GL/gl.h>
#include <cstdlib>
#include <memory>

Renderer::Renderer() {}

Renderer::~Renderer() {}

bool Renderer::Initialize() {
  triangleShader = std::make_unique<Shader>(
      "./src/shaders/vertex_shader.glsl", "./src/shaders/fragment_shader.glsl");

  // init triangle VBO and VAO
  float vertices[] = {
      -0.5f, -0.5f, 0.0f, // left
      0.5f,  -0.5f, 0.0f, // right
      0.0f,  0.5f,  0.0f  // top
  };
  glGenVertexArrays(1, &triangleVAO);
  glBindVertexArray(triangleVAO);
  glGenBuffers(1, &triangleVBO);
  glBindBuffer(GL_ARRAY_BUFFER, triangleVBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glBindVertexArray(0);
  return true;
}

void Renderer::Clear() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background color
  glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
}

void Renderer::RenderTriangle() {
  triangleShader->use();
  glBindVertexArray(triangleVAO);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glBindVertexArray(0);
}
