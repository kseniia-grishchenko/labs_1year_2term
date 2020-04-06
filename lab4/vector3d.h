#ifndef LAB4_VECTOR3D_H
#define LAB4_VECTOR3D_H

#include "vector.h"

class Plate;
class Vector2d;

class Vector3d: public Vector {
private:
    double x;
    double y;
    double z;
public:
    Vector3d();
    Vector3d(double x, double y,double z);
    explicit Vector3d(Vector2d a);

    double getX();
    double getY();
    double getZ();

    double length() override ;
    void print(std::stringstream& out) override ;
    bool normalize() override ;
    bool plateCrossing(Plate plate);
    bool plateParallel(Plate plate);

    static Vector3d right();
    static Vector3d left();
    static Vector3d up();
    static Vector3d down();

    static Vector3d plus(Vector3d a, Vector3d b);
    static Vector3d subtract(Vector3d a, Vector3d b);
    static int multiply(Vector3d a, Vector3d b);
    static int compare(Vector3d a, Vector3d b);
    static bool equal(Vector3d a, Vector3d b);


};

#endif //LAB4_VECTOR3D_H
