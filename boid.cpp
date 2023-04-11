#include "boid.h"

Boid::Boid(int w, int h, Vector2D pos, Vector2D vel, int id) : 
    screen_width(w),
    screen_height(h),
    position(pos), 
    velocity(vel), 
    id(id) 
{};

Vector2D Boid::Pos() const {
    return position;
}

Vector2D Boid::Vel() const {
    return velocity;
}

void Boid::MoveOne() {
    position = position + velocity;
    Vector2D next = position + velocity;

    if (next.X() >= screen_width || next.X() < 0) {
        velocity = Vector2D{ -velocity.X(), velocity.Y() };
    }

    if (next.Y() >= screen_height || next.Y() < 0) {
        velocity = Vector2D{ velocity.X(), -velocity.Y() };
    }
}

void Boid::Run() {
    while (true) {
        MoveOne();
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

void Boid::Start() {
    t = std::thread{ [this] {this->Run(); } };
};
