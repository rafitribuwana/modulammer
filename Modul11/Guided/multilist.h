#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
using namespace std;

struct Anak {
    int info;
    Anak* next;
};

struct Induk {
    int info;
    Anak* firstAnak;
    Induk* next;
};

void createInduk(Induk*& p, int x);
void insertAnak(Induk* induk, int x);
void printAll(Induk* L);


#endif