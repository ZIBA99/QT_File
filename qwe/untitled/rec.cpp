/*
#include "rec.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(){

}

void Rectangle::SetWidth(const double width){

}

void Rectangle::GetHeight(const double Height){

}

void Rectangle::CalArea(){

}

double Rectangle::GetWidth(){

}

double Rectangle::GetHeight(){

}

double Rectangle::CalArea(){

}


int main()
{
    Rectangle rect1;
    rect1.SetWidth(3.2);
    rect1.SetHeight(4.3);
    rect1.CalArea();
    Rect1.SetColor("blue");
    cout << " " << endl;
    cout << "*Width: " << rect1.GetWidth() << endl;
    cout << "*Height:  " << rect1.SetHeight() << endl;
    cout << "*Area: " << rect1.GetArea() << endl;

    if(rect1.IsPaint())
        cout << "*color: " << rect1.GetColor() << endl;

    return 0;
}*/


#include "rec.h"

// 기본 생성자
Rectangle::Rectangle() : width(0), height(0), area(0) {}

// 너비 설정
void Rectangle::SetWidth(const double width) {
    this->width = width;
}

// 높이 설정
void Rectangle::SetHeight(const double height) {
    this->height = height;
}

// 넓이 계산
void Rectangle::CalArea() {
    area = width * height;
}

// 너비 반환
double Rectangle::GetWidth() const {
    return width;
}

// 높이 반환
double Rectangle::GetHeight() const {
    return height;
}

// 넓이 반환
double Rectangle::GetArea() const {
    return area;
}


