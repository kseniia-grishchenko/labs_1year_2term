#include "stringFunc.h"
#include <iostream>

const int MAX_SIZE = 1000;

int length(char s1[]) {
    int i = 0;
    while (s1[i] != '\0') {
        i++;
    }
    return i;
}

void swap(char s1[], char s2[]) {

    char stemp[max(length(s1), length(s2)) + 1];

    int i = -1;
    do {
        i++;
        stemp[i] = s1[i];
    } while (s1[i] != '\0');

    i = -1;
    do {
        i++;
        s1[i] = s2[i];
    } while (s2[i] != '\0');

    i = -1;
    do {
        i++;
        s2[i] = stemp[i];
    } while (stemp[i] != '\0');
}

void push_back(char s[], char to_add) {
    s[length(s)] = to_add;
    s[length(s)] = '\0';
}

void pop_back(char s[]) {
    if (length(s) == 0)
        return;
    s[length(s) - 1] = '\0';
}

char *copy(char s[], int len, int pos) {
    char *ret = static_cast<char *>(malloc(MAX_SIZE));
    int slength = length(s);
    int counter = 0;
    while (pos < slength && counter < len) {
        ret[counter] = s[pos];
        pos++;
        counter++;
    }
    ret[counter] = '\0';
    return ret;
}

char *strncpy(char dest[], char src[], int count) {
    int len = length(src);
    if (count <= length(src)) {
        for (int i = 0; i < count; i++) {
            dest[i] = src[i];
        }
    } else
        for (int i = 0; i < len; i++) {
            dest[i] = src[i];
        }
    dest[len] = '\0';
    return dest;
}

void resize(char s[], int size) {
    if (size < length(s)) {
        s[size] = '\0';
        return;
    } else {
        while (length(s) < size) {
            push_back(s, 'g');
        }
    }
}

int strcmp(char s1[], char s2[]) {
    if (length(s1) > length(s2))
        return 1;
    if (length(s1) < length(s2))
        return -1;

    int len = length(s1);
    for (int i = 0; i < len; i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
    }
    return 0;
}

int strncmp(char s1[], char s2[], int count) {
    for (int i = 0; i < count; i++) {
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;
        else
            return 0;
    }
}

void strcat(char destination[], char source[]) {
    int len1 = length(destination);
    int len2 = length(source);
    for (int i = 0; i < len2; i++) {
        destination[len1 + i] = source[i];
    }
    destination[len1 + len2] = '\0';
}

void strncat(char *destination, char *source, int count) {
    int len1 = length(destination);
    int len2 = length(source);
    if (count > len2) {
        for (int i = 0; i < len2; i++) {
            destination[len1 + i] = source[i];
        }
        destination[len1 + len2] = '\0';
    } else {
        for (int i = 0; i < count; i++) {
            destination[len1 + i] = source[i];
        }
        destination[len1 + count] = '\0';
    }
}

int strstr(char text[], char pivot[]) {
    int len1 = length(text);
    int len2 = length(pivot);
    if (len2 > len1)
        return -1;
    for (int i = 0; i < len1 - len2 + 1; i++) {
        if (text[i] == pivot[0]) {
            int j;
            for (j = 0; j < len2; j++) {
                if (text[i + j] != pivot[j]) {
                    break;
                }
            }
            if (j == len2)
                return i;
        }
    }
    return -1;
}

int strchr(char s[], char character) {
    int len = length(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == character) {
            return i;
        }
    }
    return 0;
}

char strpbrk(char s1[], char s2[]) {
    int len1 = length(s1);
    int len2 = length(s2);
    for (int i = 0; i < len2; i++) {
        for (int j = 0; j < len1; j++) {
            if (s2[i] == s1[j]) {
                return s2[i];
            }
        }
    }
    return 0;
}

int strspn(char s1[], char s2[]) {
    int len1 = length(s1);
    int len2 = length(s2);
    int counter = 0;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (s1[i] == s2[j]) {
                counter++;
            }
        }
    }
    return counter;
}

int strcspn(char destination[], char source[]) {
    int len1 = length(destination);
    int len2 = length(source);
    for (int i = 0; i < len2; i++) {
        for (int j = 0; j < len1; j++) {
            if (source[i] == destination[j]) {
                return j;
            }
        }
    }
    return len1;
}

int find_first_of(char s1[], char s2[], int pos){
    int len1 = length(s1);
    int len2 = length(s2);
    if(pos > len1)
        return -1;
    for (int i = pos; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;
}

int find_last_of(char s1[], char s2[], int pos) {
    int len1 = length(s1);
    int len2 = length(s2);
    if (pos > len1) {
        for (int i = len1; i > 0; i--) {
            for (int j = 0; j < len2; j++) {
                if (s1[i] == s2[j]) {
                    return i;
                }
            }
        }
    } else {
        for (int i = pos; i > 0; i--) {
            for (int j = 0; j < len2; j++) {
                if (s1[i] == s2[j]) {
                    return i;
                }
            }
        }
        return -1;
    }
}

int find_first_not_of(char s1[], char s2[], int pos){
    int len1 = length(s1);
    int len2 = length(s2);
    if(pos > len1)
        return -2;
    for (int i = 0; i < len2; i++) {
        for (int j = pos; j < len1; j++) {
            if (s2[i] != s1[j]) {
                return j;
            }
        }
    }
    return -1;
}





