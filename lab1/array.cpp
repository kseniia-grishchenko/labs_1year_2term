#include "array.h"

#include <iostream>
#include <random>
#include <ctime>

const int MAX_RAND = 100;

int rand_num(int max) {
    static std::random_device rd;
    static std::seed_seq seed { rd(), static_cast<unsigned int>(time(nullptr))};
    static std::mt19937_64 gen(seed);
    std::uniform_real_distribution<double> dist(0, max);

    return int(dist(gen));
}
int* array= new int[N]
delete []array;
vector<int> fillRandom(int N) {
    vector<int> vec;
    for(int i = 0; i < N; i++) {
        vec.push_back(rand_num(MAX_RAND));
    }
    cout << "MEMORY ALLOC" << endl;
    return vec;
}

void print(vector<int> vec) {
    cout << "This is array:";
    int length = vec.size();
    for(int i = 0; i < length; i++) {
        if(i % 5 == 0)
            cout << endl;
        cout << vec[i] << " ";
    }
    cout << endl;
}

vector<int> bubbleSort(vector<int> vec) {
    int length = vec.size();
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length - 1; j++) {
            if(vec[j] > vec[j+1]) {
                swap(vec[j], vec[j+1]);
            }
        }
    }
    return vec;
}

vector<int> insertionSort(vector<int> vec) {
    int length = vec.size();
    for(int i = 1; i < length; i++) {
        int key = vec[i];
        int wall = i - 1;
        while(wall >= 0 && key < vec[wall]) {
            vec[wall + 1] = vec[wall];
            wall--;
        }
        vec[wall + 1] = key;

    }
    return vec;
}

bool isPrime(int N) {
    if(N == 0) {
        return false;
    }

    if(N == 1) {
        return false;
    }
    for(int i = 2; i <= sqrt(N); i++) {
        if(N % i == 0)
            return false;
    }
    return true;
}

vector<int> insertElement(vector<int> vec, int data, int& N) {
    N++;
    cout << "MEMORY ALLOC" << endl;
    int length = vec.size();
    for(int i = length - 1; i >= 0; i--) {
        if(isPrime(vec[i])) {
            //TODO insert into current position in function
            vec.insert(vec.begin() + i, data);
            print(vec);
            return vec;
        }
    }
    vec.push_back(data);
    print(vec);
    return vec;
}
