#include "Graphics.h"
#include <stdio.h>
#include <string>

//Hack to get window to stay up
//SDL_Event e;
//bool quit = false;
//while (quit == false) {
//	while (SDL_PollEvent(&e)) {
//		if (e.type == SDL_QUIT)
//			quit = true;
//	}
//}

Graphics::Graphics(int width, int height) : w(width), h(height) 
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		throw GraphicsException("Failed to initialize SDL");
	}

	//Create window
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		throw GraphicsException("Window could not be created!");
	}

	////Get window surface
	//screenSurface = SDL_GetWindowSurface(window);

	////Fill the surface white
	//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

	////Update the surface
	//SDL_UpdateWindowSurface(window);

	renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		printf("Failed to create Renderer! SDL_Error: %s\n", SDL_GetError());
		throw GraphicsException("Failed to create renderer");
	}
};

Graphics::~Graphics() {
	SDL_DestroyRenderer(renderer);

	// Destroy window
	SDL_DestroyWindow(window);

	// Quit SDL subsystems
	SDL_Quit();
}

void Graphics::DrawPoint(int x, int y, Color color) {
	// Set our color for the draw functions
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	// Now we can draw our point
	SDL_RenderDrawPoint(renderer, x, y);
}

void Graphics::Clear(Color color) {
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	// We clear what we draw before
	SDL_RenderClear(renderer);
}
void Graphics::Present() {
	SDL_RenderPresent(renderer);
}