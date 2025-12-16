#include "multilist.h"
#include "multilist.cpp"

int main() {
    Induk* Listpeg = NULL;

    createInduk(Listpeg, 1);
    createInduk(Listpeg, 2);

    insertAnak(Listpeg, 11);
    insertAnak(Listpeg, 12);

    insertAnak(Listpeg->next, 21);
    insertAnak(Listpeg->next, 22);
    
    printAll(Listpeg);

    return 0;
}