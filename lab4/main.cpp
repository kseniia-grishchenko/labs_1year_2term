#include <iostream>
#include "vector3d.h"
#include "vector2d.h"

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

#include <sstream>

TEST_CASE("Working with vector"){
    Vector *vector = nullptr;
    std::stringstream out;

    SECTION("Working with Vector 2d") {
        vector = new Vector2d{};
        vector->print(out);
        REQUIRE(out.str() == "This is Vector 2d :\nX - 0 Y - 0\n" );
    }

    SECTION("Working with Vector 2d"){
        vector = new Vector3d{};
        vector->print(out);
        REQUIRE(out.str() == "This is Vector 3d :\nX - 0 Y - 0 Z - 0\n" );
    }



}