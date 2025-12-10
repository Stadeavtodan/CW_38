#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T info;
    Node* left;
    Node* right;

    Node(T value) { info = value; left = right = nullptr; }
    void showNode() {
        cout << "INFO: " << info << endl;
        cout << "\t Left: " << left << " Right: " << right << endl;
    }
};

template <typename U>
class BinTree {
    Node<U>* root; //¬каз≥вник на перший вузол у дерев≥

    void showSubTree(Node<U>* p) {
        if (p != nullptr) {
            showSubTree(p->left);
            cout << p->info << " ";
            showSubTree(p->right);
        }
    }

    void delSubTree(Node<U>* p) {
        if (p != nullptr) {
            delSubTree(p->left);
            delSubTree(p->right);
            cout << "DELETE: " << p->info << endl;
            delete p;
        }
    }
public:
    BinTree() { root = nullptr; }
    ~BinTree() {
        delSubTree(root);
    }

    void insert(U value) {
        //1- створюЇмо вузол
        Node<U>* el = new Node<U>(value);

        //2.1 - якщо це перший вузол
        if (root == nullptr) { root = el; }
        else {
            //2.2 - ¬же Ї вузли = «находимо м≥сце дл€ вставки нового вузла
            Node<U>* p = root;
            Node<U>* pPrev = root;

            while (p != nullptr) {
                pPrev = p;
                /*if (value < p->info) 
                    p = p->left;
                else
                    p = p->right;*/
                p = value < p->info ? p->left : p->right;
            }
            //2.3 - ѕрив'€зуЇмо новий вузол до знайденого м≥сц€
            if (value < pPrev->info)
                pPrev->left = el;
            else
                pPrev->right = el;
        }
    }

    Node<U>* search(U value) {
        Node<U>* p = root;
        while (p != nullptr) {
            if (value == p->info) {
                cout << "The num with root " << p << " was found";
                return p;
            }
            p = value < p->info ? p->left : p->right;
        }
        return nullptr;

    }

    //ѕовний обх≥д дерева
    void showTree() {
        if (root == nullptr)
            cout << "Tree is empty!" << endl;
        else {
            showSubTree(root->left);
            cout << root->info << " ";
            showSubTree(root->right);
            cout << endl;
        }
    }

};