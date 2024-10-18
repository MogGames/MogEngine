#include "Window.h"
#include <SDL2/SDL_video.h>

Window::Window(int width, int height, const std::string &tile)
    : sdlWindow(nullptr), glContext(nullptr), isOpen(true) {}

Window::~Window() {}

bool Window::Initialize() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    return false;
  }

  sdlWindow = SDL_CreateWindow("MogEngine", SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED, 800, 600,
                               SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

  if (sdlWindow) {
    return false;
  }

  // init OPENGL here
  return true;
}

void Window::Update() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      isOpen = false;
    }
  }

  SDL_GL_SwapWindow(sdlWindow);
}

void Window::Shutdown() {
  SDL_GL_DeleteContext(glContext);
  SDL_DestroyWindow(sdlWindow);
  SDL_Quit();
}

bool Window::IsOpen() const { return isOpen; }
