#include "./Graphics/Renderer.h"
#include "./Window/Window.h"
#include <cstdlib>

typedef struct {
  float r;
  float g;
  float b;
} RGBColor;

RGBColor generate_random_rgb() {
  RGBColor color;
  color.r = rand() % 256 / 255.0f;
  color.g = rand() % 256 / 255.0f;
  color.b = rand() % 256 / 255.0f;
  return color;
}

int main(int argc, char *argv[]) {
  Window window(800, 600, "MogEngine");
  Renderer renderer;

  if (!window.Initialize() || !renderer.Initialize()) {
    return -1;
  }

  while (window.IsOpen()) {
    renderer.Clear();
    RGBColor color = generate_random_rgb();
    renderer.RenderTriangle(color.r, color.g, color.b);
    window.Update();
  }

  window.Shutdown();
  return 0;
}
