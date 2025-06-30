#ifndef GEO_H
#define GEO_H

#include <string>

class GeometricFigure {
protected:
    std::string color;
    bool painted = false;

public:
    void SetColor(const std::string& c) {
        color = c;
        painted = true;
    }

    std::string GetColor() const {
        return color;
    }

    bool IsPaint() const {
        return painted;
    }
};

#endif // GEO_H
