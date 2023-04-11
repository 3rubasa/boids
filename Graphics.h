#pragma once
#include <SDL.h>
#include <exception>
#include "interfaces.h"

class GraphicsException : public std::exception {
public: 
    GraphicsException(const char* message) :std::exception(message) {}
};

class Graphics : public IGraphics {
public:
    Graphics(int width, int height);
    virtual ~Graphics();

    virtual void DrawPoint(int x, int y, Color color);
    virtual void Clear(Color color);
    virtual void Present();
private:
    int w;
    int h;
    SDL_Window* window{ nullptr};
    SDL_Surface* screenSurface{ nullptr };
    SDL_Renderer* renderer{ nullptr };

};