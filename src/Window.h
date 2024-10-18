#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>

class Window {
public:
  Window(int width, int height, const std::string &title);
  ~Window();

  bool Initialize();
  void Update();
  void Shutdown();
  bool IsOpen() const;

private:
  SDL_Window *sdlWindow;
  SDL_GLContext glContext;
  bool isOpen;
};

#endif
