#include "circularlist.h"
#include <iostream>

void CreateList(List &L) {
    L.First = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        P->next = P;
    } else {
        address last = L.First;
        while (last->next != L.First) {
            last = last->next;
        }
        P->next = L.First;
        last->next = P;
        L.First = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        P->next = P;
    } else {
        address last = L.First;
        while (last->next != L.First) {
            last = last->next;
        }
        last->next = P;
        P->next = L.First;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.First != NULL) {
        if (L.First->next == L.First) {
            P = L.First;
            L.First = NULL;
        } else {
            address last = L.First;
            while (last->next != L.First) {
                last = last->next;
            }
            P = L.First;
            L.First = L.First->next;
            last->next = L.First;
        }
        P->next = NULL;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && Prec->next != L.First) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First != NULL) {
        if (L.First->next == L.First) {
            P = L.First;
            L.First = NULL;
        } else {
            address prev = L.First;
            address last = L.First->next;
            while (last->next != L.First) {
                prev = last;
                last = last->next;
            }
            P = last;
            prev->next = L.First;
        }
        P->next = NULL;
    }
}

address findElm(List L, infotype x) {
    if (L.First == NULL) return NULL;

    address P = L.First;
    do {
        if (P->info.nim == x.nim) {
            return P;
        }
        P = P->next;
    } while (P != L.First);

    return NULL;
}

void printInfo(List L) {
    if (L.First != NULL) {
        address P = L.First;
        do {
            cout << "Nama          : " << P->info.nama << endl;
            cout << "NIM           : " << P->info.nim << endl;
            cout << "Jenis Kelamin : " << P->info.jenis_kelamin << endl;
            cout << "IPK           : " << P->info.ipk << endl;
            cout << "-----------------------------" << endl;
            P = P->next;
        } while (P != L.First);
    } else {
        cout << "List kosong" << endl;
    }
}
