#include "Window.h"
#include "../external/glad/glad.h"
#include <SDL2/SDL_video.h>
#include <iostream>

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

  if (sdlWindow == NULL) {
    return false;
  }

  glContext = SDL_GL_CreateContext(sdlWindow);
  if (glContext == NULL) {
    return false;
  }

  SDL_GL_MakeCurrent(sdlWindow, glContext);

  if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    return false;
  }

  glViewport(0, 0, 800, 600);

  // init OPENGL here
  return true;
}

void Window::Update() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      isOpen = false;
    } else if (event.type == SDL_WINDOWEVENT) {
      if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
        int width = event.window.data1;
        int height = event.window.data2;
        glViewport(0, 0, width, height);
      }
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
