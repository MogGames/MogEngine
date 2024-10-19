#include "Renderer.h"
#include "../external/glad/glad.h"
#include "Shader.h"
#include <GL/gl.h>
#include <cstdlib>
#include <memory>

Renderer::Renderer() {}

Renderer::~Renderer() {}

bool Renderer::Initialize() {
  // build triangle shape utils
  triangleShader = std::make_unique<Shader>(
      "./src/shaders/vertex_shader.glsl", "./src/shaders/fragment_shader.glsl");

  float triangleVertices[] = {
      -0.5f, -0.5f, 0.0f, // left
      0.5f,  -0.5f, 0.0f, // right
      0.0f,  0.5f,  0.0f  // top
  };
  glGenVertexArrays(1, &triangleVAO);
  glBindVertexArray(triangleVAO);
  glGenBuffers(1, &triangleVBO);
  glBindBuffer(GL_ARRAY_BUFFER, triangleVBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices,
               GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glBindVertexArray(0);

  // build rectangle shape utils
  float rectangleVertices[] = {
      0.5f,  0.5f,  0.0f, // top right
      0.5f,  -0.5f, 0.0f, // bottom right
      -0.5f, -0.5f, 0.0f, // bottom left
      -0.5f, 0.5f,  0.0f  // top left
  };
  unsigned int uniqueIndices[] = {
      0, 1, 3, // first triangle
      1, 2, 3  // second triangle
  };

  glBindVertexArray(rectangleVAO);
  glBindBuffer(GL_ARRAY_BUFFER, rectangleVBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(rectangleVertices), rectangleVertices,
               GL_STATIC_DRAW);

  glGenBuffers(1, &rectangleEBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rectangleEBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uniqueIndices), uniqueIndices,
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
  glBindVertexArray(0);

  return true;
}

void Renderer::Clear() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background color
  glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
}

void Renderer::RenderTriangle(float r, float g, float b) {
  triangleShader->use();
  triangleShader->setVector4("color", r, g, b, 1.0f);
  glBindVertexArray(triangleVAO);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glBindVertexArray(0);
}

void Renderer::RenderRectangle(float r, float g, float b) {
  triangleShader->use();
  triangleShader->setVector4("color", r, g, b, 1.0f);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rectangleEBO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
}
