#include <iostream>
#include <set> // STL BinTree
#include "BinTree.h"
#include "Train.h"
using namespace std;

int main()
{
    /*BinTree<int> tree;
    tree.insert(7);
    tree.insert(5);
    tree.insert(9);
    tree.insert(6);
    tree.insert(11);
    tree.insert(8);
    tree.insert(1);
    tree.insert(-1);

    cout << endl;
    tree.search(8);
    cout << "===============\n";
    tree.showTree();
    tree.~BinTree();*/

    set<Train> table;
    table.insert(Train("10100", "12:55", "Kyiv"));
    table.insert(Train("10010", "07:55", "Kharkiv"));
    table.insert(Train("20911", "08:05", "Lviv"));
    table.insert(Train("67100", "23:15", "Zaporizhya"));
    table.insert(Train("56110", "19:00", "Cherson"));
    set<Train>::iterator p;
    for (p = table.begin(); p != table.end(); p++) {
        p->showInfo();
    }

    string number;
    cout << "Enter num: ";
    cin >> number;
    bool isFound = false;
    for (p = table.begin(); p != table.end(); p++) {
        if (p->getNum() == number) {
            p->showInfo();
            isFound = true;
        }
    }
    if (!isFound) { cout << "Not found"; }

}