#include "PlayerChicken.h"
#include "SDL_rect.h"


static SDL_Rect drawRect(SDL_Renderer *renderer, int x, int y, int width,
                         int height) {
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = width;
  rect.h = height;

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set color to red

  SDL_RenderDrawRect(renderer, &rect);
  SDL_RenderFillRect(renderer, &rect);

  return rect;
}

void PlayerChick::draw(SDL_Renderer *rend) {
  chickenSprite = drawRect(rend, 100, 100, 50, 50);
  PlayerChick::setmass(1.0);
}

void PlayerChick::update() {}