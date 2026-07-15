#include<iostream>
#include<SDL.h>

using namespace std;


static SDL_Rect drawRect(SDL_Renderer* renderer, int x, int y, int width, int height) {
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


int main(int argc, char* argv[]) {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		return 1;
	}
	// Create a window
	SDL_Window* window = SDL_CreateWindow("Flappy Chicken", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Rect chickensprite = drawRect(renderer, 100, 100, 50, 50); // Example rectangle
	// Main loop
	bool running = true;
	while (running) {
		SDL_Event event;



		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}

			if(event.type == SDL_MOUSEBUTTONDOWN) {
				cout << "LeftButton is Pressed " << SDL_GetError() << endl;

				if(event.button.button == SDL_BUTTON_LEFT) {
					chickensprite = drawRect(renderer, event.button.x, event.button.y, 50, 50); // Draw rectangle at mouse click position
					cout << "LeftButton is Pressed " << SDL_GetError() << endl;

				}
			}				
		}
		
		SDL_RenderPresent(renderer); // Update the screen
		// Game logic and rendering would go here
		// Delay to control frame rate
		SDL_Delay(16); // Roughly 60 FPS
	}
	// Clean up and close the window
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}

