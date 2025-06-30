#ifndef REC_H
#define REC_H

#include "geo.h"

class Rectangle : public GeometricFigure {
public:
    Rectangle();                        // 생성자

    void SetWidth(const double width);  // 너비 설정
    void SetHeight(const double height); // 높이 설정
    void CalArea();                     // 넓이 계산

    double GetWidth() const;           // 너비 반환
    double GetHeight() const;          // 높이 반환
    double GetArea() const;            // 넓이 반환

private:
    double width;
    double height;
    double area;
};

#endif // REC_H
