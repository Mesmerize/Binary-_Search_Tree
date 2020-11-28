#include <iostream>
#include "LL.h"
#include "binarytree.h"
using namespace std;

int main() {
    binarytree myTree;
    for (int i = 0; i < 20; i++) {
        myTree.insert(rand() % 50);
    }

    cout << "The binary tree: ";
    myTree.print();
    cout << endl;

    LL<int> myList;
    myList = myTree.toLL();

    cout << "The linked list: ";

    // if you haven't studied iterators yet, the following may not make sense  Don't worry.
    // You just have to know that this for loop prints the contents of myList.

    for (LL<int>::iterator i = myList.begin(); i != myList.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    cout << "The original binary tree still intact: ";
    myTree.print();

    cout << endl;
}