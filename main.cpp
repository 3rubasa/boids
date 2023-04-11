/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <chrono>
#include <random>
#include <array>
#include "vector2d.h"
#include "math.h"
#include "boid.h"
#include <thread>
#include "interfaces.h"
#include "Graphics.h"

//Screen dimension constants
constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 360;
constexpr int BoidCount = 500;

using Boids = std::vector<Boid>;

Boids CreateBoids() {
	Boids boids;

	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine random_generator(static_cast<unsigned>(seed));
	std::uniform_real_distribution<double> distribution(0.0, 1.0);

	for (int i = 0; i < BoidCount; i++) {
		boids.push_back(Boid{
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			Vector2D{distribution(random_generator) * SCREEN_WIDTH,distribution(random_generator) * SCREEN_HEIGHT},
			Vector2D{distribution(random_generator) * 2 - 1.0, distribution(random_generator) * 2 - 1.0},
			i
		});
	}

	return boids;
}

int main(int argc, char* args[])
{
	Boids boids{ CreateBoids() };
	std::unique_ptr<IGraphics> g{ new Graphics{SCREEN_WIDTH, SCREEN_HEIGHT} };
	

	for (auto& b : boids) {
		b.Start();
	}

	while (true) {
		g->Clear(Color::Red);
		for (const auto& b : boids) {
			g->DrawPoint(static_cast<int>(b.Pos().X() + 1), static_cast<int>(b.Pos().Y()), Color::Green);
			g->DrawPoint(static_cast<int>(b.Pos().X() - 1), static_cast<int>(b.Pos().Y()), Color::Green);
			g->DrawPoint(static_cast<int>(b.Pos().X()), static_cast<int>(b.Pos().Y() + 1), Color::Green);
			g->DrawPoint(static_cast<int>(b.Pos().X()), static_cast<int>(b.Pos().Y() - 1), Color::Green);
		}
		g->Present();

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
	
	return 0;
}
