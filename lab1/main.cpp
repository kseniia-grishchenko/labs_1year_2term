#include <iostream>
#include "array.h"
#include <limits>

using namespace std;

const int MAX_N = 10000;

void hello_and_author() {
    cout << "Kseniia Grishchenko K-14" << endl;
}

void print_menu(int N) {
    cout << endl;
    cout << "N = " << N << endl;
    cout << "Press 1 to fill array from keyboard" << endl;
    cout << "Press 2 to fill array with random numbers" << endl;
    cout << "Press 3 to change N" << endl;
    cout << "Press 4 to print array" << endl;
    cout << "Press any another button to exit" << endl;
    cout << endl;
}

void print_full_menu() {
    cout << endl;
    cout << "Press 1 to add element as in variant" << endl;
    cout << "Press 2 to sort array" << endl;
    cout << "Press R to return to prev menu" << endl;
    cout << "Press Q to exit the program" << endl;
    cout << endl;
}

void print_sort_menu() {
    cout << endl;
    cout << "Press 1 - Bubble Sort" << endl;
    cout << "Press 2 - Insertion Sort" << endl;
    cout << "Press R - return to prev menu" << endl;
    cout << "Press Q - exit the program" << endl;
    cout << endl;
}

int read_input(string s) {
    int input = -1;
    bool valid= false;
    do
    {
        cout << s << endl;
        cin >> input;
        if (cin.good()) {
            valid = true;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input; please re-enter." << endl;
        }
    } while (!valid);

    return (input);
}

bool show_menu_two(vector<int> vec, int& N){
    while(true) {
        string operation;
        print_full_menu();
        cin >> operation;

        if(operation == "1") {
            int data;
            data = read_input("Enter data:");
            vec = insertElement(vec, data, N);
        }
        else if(operation == "2") {
            while(true) {
                string operation;
                print_sort_menu();
                cin >> operation;

                if(operation == "1") {
                    vec = bubbleSort(vec);
                    cout << "Bubble Sort was successful!" << endl;
                    print(vec);
                }
                else if(operation == "2") {
                    vec = insertionSort(vec);
                    cout << "Insertion Sort was successful!" << endl;
                    print(vec);
                }
                else if(operation == "R") {
                    break;
                }
                else if(operation == "Q") {
                    return false;
                }
            }
        }
        else if(operation == "R") {
            break;
        }
        else if(operation == "Q") {
            return false;
        }
    }
    return true;
}

int main() {
    hello_and_author();
    int N = 12;
    int operation;
    string error;
    vector<int> vec;
    int length;
    while(true) {
        print_menu(N);
        cin >> operation;
        switch(operation) {
            case 1:
                if(vec.size() < N) {
                    length = vec.size();
                    for (int i = 0; i < N - length; i++) {
                        int data;
                        data = read_input("Enter data:");
                        vec.push_back(data);
                    }
                    cout << "MEMORY ALLOC" << endl;
                    cout << "SUCCESS" << endl;
                    print(vec);
                    cout << "ARRAY IS FULL" << endl;
                    show_menu_two(vec,N);
                } else if(vec.size() == N) {
                    cout << "ARRAY IS FULL" << endl;
                    while(true) {
                        string operation;
                        print_full_menu();
                        cin >> operation;

                        if(operation == "1") {
                            int data;
                            data = read_input("Enter data:");
                            vec = insertElement(vec, data, N);
                        }
                        else if(operation == "2") {
                            cout << "ARRAY IS FULL" << endl;
                            show_menu_two(vec,N);
                        }
                        else if(operation == "R") {
                            break;
                        }
                        else if(operation == "Q") {
                            return 0;
                        }
                    }
                } else { // if N < array size
                    cout << "MEMORY FREED" << endl;
                    vec.resize(N);
                }

                break;

            case 2:
                vec = fillRandom(N);
                cout << "SUCCESS" << endl;
                print(vec);

                if(!show_menu_two(vec,N)){
                    return 0;
                };

                break;

            case 3:
                int data;

                try {
                    data = read_input("Enter new N:");
                    if(data > MAX_N) {
                        error = "N must be less or equal to " + to_string(MAX_N);
                        throw (error);
                    } else if(data <= 0) {
                        error = "N must be positive";
                        throw (error);
                    } else {
                        N = data;
                    }
                }
                catch(const string error) {
                    cout << error << endl;
                    break;
                }

                cout << "SUCCESS" << endl;
                print(vec);

                break;

            case 4:
                print(vec);

                break;

            default:
                return 0;
        }
    }
}

