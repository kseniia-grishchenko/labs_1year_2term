#ifndef LAB4_VECTOR2D_H
#define LAB4_VECTOR2D_H


class Vector3d;

class Vector2d {
private:
    double x;
    double y;
public:

    Vector2d();
    Vector2d(double x, double y);
    explicit Vector2d(Vector3d a);

    double getX();
    double getY();

    bool check();
    double length();
    void print();
    bool normalize();
    void turn(int angle);

    static Vector2d right();
    static Vector2d left();
    static Vector2d up();
    static Vector2d down();

    static Vector2d plus(Vector2d a, Vector2d b);
    static Vector2d subtract(Vector2d a, Vector2d b);
    static int multiply(Vector2d a, Vector2d b);
    static int compare(Vector2d a, Vector2d b);
    static bool equal(Vector2d a, Vector2d b);

};




#endif //LAB4_VECTOR2D_H
