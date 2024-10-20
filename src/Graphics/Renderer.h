#ifndef RENDERER_H
#define RENDERER_H

#include "Shader.h"
#include <memory>

class Renderer {
public:
  Renderer();
  ~Renderer();

  bool Initialize();
  void Clear();
  void RenderTriangle(float r, float g, float b);
  void RenderRectangle(float r, float g, float b);

private:
  unsigned int triangleVBO;
  unsigned int triangleVAO;
  std::unique_ptr<Shader> triangleShader;
  unsigned int rectangleEBO;
  unsigned int rectangleVBO;
  unsigned int rectangleVAO;
};

#endif
