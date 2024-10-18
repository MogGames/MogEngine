#include "Renderer.h"
#include "Window.h"

int main(int argc, char *argv[]) {
  Window window(800, 600, "MogEngine");
  Renderer renderer;

  if (!window.Initialize() || !renderer.Initialize()) {
    return -1;
  }

  while (window.IsOpen()) {
    renderer.Clear();
    window.Update();
  }

  window.Shutdown();
  return 0;
}
