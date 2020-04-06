#ifndef LAB4_VECTOR_H
#define LAB4_VECTOR_H

#include <sstream>

class Vector{
public:
    virtual double length()=0;
    virtual void print(std::stringstream& out)=0;
    virtual bool normalize()=0;
};
#endif //LAB4_VECTOR_H
