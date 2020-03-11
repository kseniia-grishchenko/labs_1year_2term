#ifndef LAB1_ARRAY_H
#define LAB1_ARRAY_H

using namespace std;

#include <vector>

vector<int> fillRandom(int N);

void print(vector<int> vec);

vector<int> bubbleSort(vector<int> vec);

vector<int> insertionSort(vector<int> vec);

bool isPrime(int N);

vector<int> insertElement(vector<int> vec, int data, int& N);

#endif //LAB1_ARRAY_H
