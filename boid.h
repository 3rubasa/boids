#pragma once

#include "vector2d.h"
#include <thread>

class Boid {
public:
    Boid(int w, int h, Vector2D pos, Vector2D vel, int id);
    Vector2D Pos() const;
    Vector2D Vel() const;
    void Start();
    void Stop();
private:
    void Run();
    void MoveOne();

    int screen_width, screen_height;
    Vector2D position;
    Vector2D velocity;
    int id;
    std::thread t;
};