#include "header/vector2.h"
#include <iostream>


Vector2::Vector2(int x = 0, int y = 0){
    std::cout << "Hello Vector" << std::endl;
    this -> x = x;
    this -> y = y;
}

Vector2::Vector2(const Vector2 &v){
    Vector2(v.x, v.y);
}
Vector2::Vector2(){
    Vector2(0, 0);
}

int Vector2::getVector2X() const { return x; }
int Vector2::getVector2Y() const { return y; }

void Vector2::getVector2ByR(int &_x, int &_y){
    _x = x;
    _y = y;
}

void Vector2::setVector2(const int &_x, const int &_y){
    x = _x;
    y = _y;
}
void Vector2::setVector2X(const int &_x){ x = _x; }
void Vector2::setVector2Y(const int &_y){ y = _y; }

Vector2 & Vector2::operator=(const Vector2 &other){
    this -> x = other.x;
    this -> y = other.y;
    return *this;
}

Vector2::~Vector2(){
    std::cout << "bye Vector" << std::endl;

}

bool std::isOverSize(const int &pos_x, const int &pos_y, const int &limit_x, const int &limit_y){
    if(pos_x >= limit_x || pos_y >= limit_y)
        return false;
    else if(pos_x < 0 || pos_y < 0)
        return false;
    else
        return true;

}

bool std::isOverSize(const Vector2 &pos, const Vector2 &limit){
    std::isOverSize(pos.getVector2X(), pos.getVector2Y(), limit.getVector2X(), limit.getVector2Y());
}

bool std::isOverSize(const Vector2 &pos, const int &limit_x, const int &limit_y){
    std::isOverSize(pos.getVector2X(), pos.getVector2Y(), limit_x, limit_y);
}

bool std::isOverSize(const int &pos_x, const int &pos_y, const Vector2 &limit){
    std::isOverSize(pos_x, pos_y, limit.getVector2X(), limit.getVector2Y());

} // namespace std

