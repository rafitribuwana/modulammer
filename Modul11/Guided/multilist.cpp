#include "multilist.h"

void createInduk(Induk*& L, int x) {
    Induk* p = new Induk;
    p->info = x;
    p->firstAnak = NULL;
    p->next = L;
    L = p;
}

void insertAnak(Induk* induk, int x) {
    Anak* p = new Anak;
    p->info = x;
    p->next = NULL;
    if (induk->firstAnak == NULL) {
        induk->firstAnak = p;
    } else {
        Anak* q = induk->firstAnak;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void printAll(Induk* L) {
    while (L != NULL) {
        cout << "Pegawai: " << L->info << endl;
        cout << "Induk: " << L->info << endl;
        Anak* A = L->firstAnak;
        while (A != NULL) {
            cout << A->info << endl;
            A = A->next;
        }
        cout << endl;
        L = L->next;
    }
}