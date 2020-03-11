#include <iostream>
#include "vector3d.h"
#include "vector2d.h"

using namespace std;

int main() {
    Vector3d vec{1, 2, 4};
    Vector2d vector{4,3};
    vector.print();
    Vector2d::plus(vector, vector).print();
    cout << Vector2d::compare(vector, vector) << endl;
//    Vector2d::normalize(vector).print();
    Vector3d(vector).print();

    //    Vector2d::right().print();

    return 0;
}