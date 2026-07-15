#pragma once

// Workaround: prevent SDL headers from redefining clang's builtin _m_prefetch
#ifdef __clang__
#define __PRFCHWINTRIN_H 1
#endif

#include <SDL.h>
#include <SDL_image.h>

class PlayerChick {
public:
  PlayerChick(SDL_Renderer *renderer, const char *texturePath, int x, int y);
  ~PlayerChick();
  void draw(SDL_Renderer *rend);
  void update();

private:
};
