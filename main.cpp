#include "bstree.h"
#include "bstree.cpp"

int main() {
    cout << "Hello World" << endl;

    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);

    printInorder(root);
    cout << "\n";

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;

    cout << "PreOrder : ";
    printPreorder(root);
    cout << endl;

    cout << "PostOrder: ";
    printPostorder(root);
    cout << endl;


    return 0;
}


