#include <iostream>
#include "stringFunc.h"

const int MAX_SIZE = 1000;

using namespace std;


int main() {
    char cs1[MAX_SIZE] = "Lorem";
    char cs2[MAX_SIZE] = "Ipsum text";
//    std::cout << "first: " << cs1 << " -- second: "<< cs2 << std::endl;
//    cout << length(cs1) << endl;
//    cout << "swap elements" << endl;
//    swap(cs1,cs2);
//    std::cout << "first:" << cs1 << "-- second: " << cs2 << std::endl;
//
//    cout << "push back element:" << endl;
//    push_back(cs1, 'a');
//    cout << cs1 << endl;
//
//    cout << "pop back element:" << endl;
//    pop_back(cs1);
//    cout << cs1 << endl;
//
//
//    cout << "copy part of first word:" << endl;
//    cout << copy(cs1, 4, 3) << endl;
//
//    cout << "resize first word:" << endl;
//    resize(cs1,20);
//    cout << cs1 << endl;

    char a[] = "sunny hot day";
    char b[] = "banana";
    char c[MAX_SIZE];

//    cout << strcmp(a, b) << endl;
//
    strcat(a, b);
    cout << a << endl;
//
//    cout << strstr(a, b) << endl;
//
//    if(strchr(a, 'f')  != 0){
//        cout << "This character is on " << strchr(a, 'f') << " position";
//    } else
//        cout << "This character is not in the string" << endl;
//
    char m[] = "apple";
//
//    cout << strncpy(c, m,30) << endl;
//
//    if(strncmp(m, b, 1) == 1)
//        cout << "First string is greater than second" << endl;
//    else if(strncmp(m, b, 1) == -1)
//        cout << "Second string is greater than first" << endl;
//    else cout << "Strings are equal" << endl;

    strncat(a, m, 3);
    cout << a << endl;

    char t;
    t = strpbrk(m, b);
    if(t != 0) cout << t << endl;
    else cout << "There are not  common letters" << endl;
//
    cout << strspn(m, b) << endl;
//
   cout << strcspn(b, m) << endl;

//    int f;
//    f = find_first_of(b, m);
//    if(f != -1) cout << f << endl;
//    else cout << "There are not  common letters in this segment" << endl;
//
//    int z;
//    z = find_last_of(b,m, 8);
//    if(z != -1) cout << z << endl;
//    else cout << "There are not common letters in this segment" << endl;
//
//    int h;
//    h = find_first_not_of(b, m, 0);
//    if(h == -2) cout << "Position must be less than string`s length" << endl;
//    else if(h != 0) cout << h << endl;



    return 0;
}