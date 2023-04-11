#pragma once

enum class Color {
    Red,
    Green,
    Blue
};

class IGraphics {
public:
    virtual void DrawPoint(int x, int y, Color color) = 0;
    virtual void Clear(Color color) = 0;
    virtual void Present() = 0;

    virtual ~IGraphics() {};
};
