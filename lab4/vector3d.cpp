#include <iostream>
#include <cmath>
#include "vector3d.h"
#include "vector2d.h"
#include "plate.h"

Vector3d::Vector3d() {
    x = 0;
    y = 0;
    z = 0;
}

Vector3d::Vector3d(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3d::Vector3d(Vector2d a) {
    this->x = a.getX();
    this->y = a.getY();
    this->z = 0;
}

double Vector3d::getX() {
    return x;
}

double Vector3d::getY() {
    return y;
}

double Vector3d::getZ() {
    return z;
}

double Vector3d::length() {
    return sqrt(x*x + y*y + z*z);
}

void Vector3d::print(std::stringstream& out) {
    out << "This is Vector 3d :" << std::endl;
    out << "X - " << x << " Y - " << y <<" Z - "<< z << std::endl;
}

bool Vector3d::normalize() {
    if(!equal(Vector3d{}, *this))
        return false;
    x = x/length();
    y = y/length();
    z = z/length();
    return true;
}

bool Vector3d::plateCrossing(Plate plate) {
    if(multiply(*this, plate.getNormale()) !=0)
        return true;
    return false;
}

bool Vector3d::plateParallel(Plate plate) {
    if (multiply(*this, plate.getNormale()) == 0) {
        if (!plate.checkPointOnPlate(Point(this->x, this->y, this->z)))
            return true;
    };
    return false;
}

Vector3d Vector3d::right() {
    return Vector3d{1, 0, 0};
}

Vector3d Vector3d::left() {
    return Vector3d{-1,0, 0};
}

Vector3d Vector3d::up() {
    return Vector3d{0, 1, 0};
}

Vector3d Vector3d::down() {
    return Vector3d{0, -1, 0};
}

Vector3d Vector3d::plus(Vector3d a, Vector3d b) {
    return Vector3d{a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ()};
}

Vector3d Vector3d::subtract(Vector3d a, Vector3d b) {
    return Vector3d{a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ()};
}

int Vector3d::multiply(Vector3d a, Vector3d b) {
    return a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ();
}

int Vector3d::compare(Vector3d a, Vector3d b) {
    if(a.length() > b.length())
        return 1;
    if(a.length() == b.length())
        return 0;
    return -1;
}

bool Vector3d::equal(Vector3d a, Vector3d b) {
    if(a.getX() == b.getX() && a.getY() == b.getY() && a.getZ() == a.getZ())
        return true;
    return false;
}




