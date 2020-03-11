#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkConsonants(char c) {
    if ((int) c < 65)
        return false;
    if ((int) c > 90 && (int) c < 97)
        return false;
    if ((int) c > 122)
        return false;
    if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'U' || c == 'u' || c == 'I' ||
        c == 'i' || c == 'O' || c == 'o')
        return false;
    return true;
}

int countConsonants(string s) {
    int counter = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (checkConsonants(s[i]))
            counter++;
    }
    return counter;
}

int main() {
    ifstream f;
    ofstream g;
    vector <string> consonants;

    f.open("input.txt");
    g.open("output.txt");

    string s;
    while (f >> s)
        if (!checkConsonants(s[0])) {
            g << s << ' ';
        }
        else {
            consonants.push_back(s);
        }

    auto sortStringByCount = [] (string s1, string s2) -> bool
    {
        return countConsonants(s1) < countConsonants(s2);
    };

    sort(consonants.begin(), consonants.end(), sortStringByCount);
    g << endl << "This is a count of words: " << consonants.size() << endl;
    for(auto data:consonants)
        g << data << endl;

    g.close();
    f.close();
    return 0;
}