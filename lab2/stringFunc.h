#ifndef LAB2_STRINGFUNC_H
#define LAB2_STRINGFUNC_H

using namespace std;


int length(char s1[]);

void swap(char s1[], char s2[]);

void push_back(char s[], char to_add);

void  pop_back(char s[]);

char* copy(char s[], int len, int pos);

void resize(char s[], int size);

int strcmp( char s1[], char s2[]);

void strcat(char destination[], char source[]);

int strstr(char text[], char pivot[]);

int strchr(char s[], char character);

char* strncpy( char dest[],  char src[], int count );

int strncmp( char s1[], char s2[], int count);

void strncat(char destination[], char *source, int count);

char strpbrk(char s1[], char s2[]);

int strspn( char s1[], char s2[]);

int strcspn(char destination[], char source[]);

int find_first_of(char s1[], char s2[], int pos = 0);

int find_last_of(char s1[], char s2[], int pos);

int find_first_not_of(char s1[], char s2[], int pos = 0);


#endif //LAB2_STRINGFUNC_H
