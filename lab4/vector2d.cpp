#include <iostream>
#include <cmath>
#include "vector2d.h"
#include "vector3d.h"

using namespace std;

Vector2d::Vector2d() {
    x = 0;
    y = 0;
}

Vector2d::Vector2d(double x, double y) {
    this->x = x;
    this->y = y;
}

Vector2d::Vector2d(Vector3d a) {
    this->x = a.getX();
    this->y = a.getY();
}


double Vector2d::getX() {
    return x;
}

double Vector2d::getY() {
    return y;
}


double Vector2d::length() {
    return sqrt(x*x + y*y);
}


void Vector2d::print(std::stringstream& out) {
    out << "This is Vector 2d :" << std::endl;
    out << "X - " << x << " Y - " << y << std::endl;
}

bool Vector2d::check() {
    if(x == 0 && y == 0)
        return true;
    return false;
}

bool Vector2d::normalize() {
    if(!equal(Vector2d{}, *this))
        return false;
    x = x/length();
    y = y/length();
    return true;
}

void Vector2d::turn(int angle) {
    x = x*cos(angle) - y*sin(angle);
    y = y*cos(angle) + x*sin(angle);
}


Vector2d Vector2d::right() {
    return Vector2d{1,0};
}

Vector2d Vector2d::left() {
    return Vector2d{-1,0};
}

Vector2d Vector2d::up() {
    return Vector2d{0,1};
}
Vector2d Vector2d::down() {
    return Vector2d{0,-1};
}


Vector2d Vector2d::plus(Vector2d a, Vector2d b) {
    return Vector2d{a.getX() + b.getX(), a.getY() + b.getY()};
}

Vector2d Vector2d::subtract(Vector2d a, Vector2d b) {
    return Vector2d{a.getX() - b.getX(), a.getY() - b.getY()};
}

int Vector2d::multiply(Vector2d a, Vector2d b) {
    return a.getX()*b.getX()+a.getY()*b.getY();
}

int Vector2d::compare(Vector2d a, Vector2d b) {
    if(a.length() > b.length())
        return 1;
    if(a.length() == b.length())
        return 0;
    return -1;
}

bool Vector2d::equal(Vector2d a, Vector2d b) {
    if(a.getX() == b.getX() && a.getY() == b.getY())
        return true;
    return false;
}
























