#pragma once

#include <SDL.h>
#include <SDL_image.h>

class PlayerChick {
public:
  PlayerChick(SDL_Renderer *renderer, const char *texturePath, int x, int y);
  ~PlayerChick();
  
  ////////////////////////// Class basic Functions ////////////////////////////
  void draw(SDL_Renderer *rend);
  void update();


  ///////////////////////// getters and setters //////////////////////////////
    
  //Mass Setup
  double getMass() const { return mass; }
  void setmass(double m){mass = m;}


  //Texture Setup
  SDL_Texture* getChickenTexture() const { return chickenTexture; }
  void setTexture(const char* texturePath){
    chickenTexture = IMG_LoadTexture(renderer, texturePath);
    if(chickenTexture == nullptr) {
        cout << "Texture could not be loaded! SDL_Error: " << SDL_GetError() << endl;
    }
  }

  SDL_Rect getChickenSprite() const { return chickenSprite; }

private:
  double mass;
  SDL_Texture *chickenTexture;
  SDL_Rect chickenSprite;

};
