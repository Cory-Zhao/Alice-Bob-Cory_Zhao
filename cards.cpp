//cards.cpp
//Authors: Cory Zhao
//Implementation of the classes defined in cards.h

#include "cards.h"

#include <iostream>
using namespace std;

CardsBST::CardsBST() : root(0) { }

CardsBST::~CardsBST() {
    clear(root);
}

void CardsBST::clear(Node* n) {
    if (n) {
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

void CardsBST::insert(Card c) {
    if (!root) {
        root = new Node(c);
    }
    insert(c, root);
}

void CardsBST::insert(Card c, Node* n) {
    if (c == n->info) {
        return;
    }
    if (c < n->info) {
        if (n->left) {
            insert(c, n->left);
        }
        else {
            n->left = new Node(c);
            n->left->parent = n;
            return;
        }
    }
    else {
        if (n->right) {
            insert(c, n->right);
        }
        else {
            n->right = new Node(c);
            n->right->parent = n;
            return;
        }
    }
}

void CardsBST::remove(Card c) {
    Node* n = getNodeFor(c, root);
    Node* suc;
    Card c1;
    
    if (n == nullptr) {
        return;
    }

    if (n->parent == nullptr && !n->right && !n->left) {
        delete n;
        root = nullptr;
    }

    else if (n && !n->right && !n->left) {
        
        if (n == n->parent->left) {
            n->parent->left = nullptr;
        }
        else {
            n->parent->right = nullptr;
        }
        delete n;
        n = nullptr;
    }

    else if (n->left && !n->right) {
        if (n->parent == nullptr) {
            n->left->parent = nullptr;
            root = n->left;
        }
        else if (n == n->parent->left) {
            n->left->parent = n->parent;
            n->parent->left = n->left;
        }
        else {
            n->left->parent = n->parent;
            n->parent->right = n->left;
        }
        delete n;
        n = nullptr;
    }
    
    else if (!n->left && n->right) {
        if (n->parent == nullptr) {
            n->right->parent = nullptr;
            root = n->right;
        }
        else if (n == n->parent->left) {
            n->right->parent = n->parent;
            n->parent->left = n->right;
        }
        else {
            n->right->parent = n->parent;
            n->parent->right = n->right;
        }
        delete n;
        n = nullptr;
    }

    else if (n->left && n->right) {
        suc = getSuccessorNode(c);
        c1 = suc->info;
        n->info = c1;
        
        if (!suc->right) {
            if (suc->parent->right == suc) {
                suc->parent->right = nullptr;
            }
            else if (suc->parent->left == suc) {
                suc->parent->left = nullptr;
            }
        }
        else {
            if (suc->parent->right == suc) {
                suc->right->parent = suc->parent;
                suc->parent->right = suc->right;
            }
            else if (suc->parent->left == suc) {
                suc->right->parent = suc->parent;
                suc->parent->left = suc->right;
            }
        }
        delete suc;
        suc = nullptr;
    }
}

void CardsBST::printPreOrder() const {
    printPreOrder(root);
}

void CardsBST::printPreOrder(Node* n) const {
    if (n) {
        n->info.print();
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}

void CardsBST::printInOrder() const {
    printInOrder(root);
}

void CardsBST::printInOrder(Node* n) const {
    if (n) {
        printInOrder(n->left);
        n->info.print();
        printInOrder(n->right);
    }
}

void CardsBST::printPostOrder() const {
    printPostOrder(root);
}

void CardsBST::printPostOrder(Node* n) const {
    if (n) {
        printPostOrder(n->left);
        printPostOrder(n->right);
        n->info.print();
    }
}

bool CardsBST::contains(const Card& c) const {
    if (!root) {
        return false;
    }
    if (getNodeFor(c, root) != nullptr) {
        return true;
    }
    return false;
}

CardsBST::Node* CardsBST::getPredecessorNode(const Card& c) const {
    Node* n = getNodeFor(c, root);
    Node* p;

    if (n == nullptr) {
        return nullptr;
    }

    if (n == getMinNode(root)) {
        return nullptr;
    }

    if (n->left) {
        return getMaxNode(n->left);
    }

    p = n->parent;

    while (p && n == p->left) {
        n = p;
        p = p->parent;
    }

    return p;
}

CardsBST::Node* CardsBST::getSuccessorNode(const Card& c) const {
    Node* n = getNodeFor(c, root);
    Node* p;

    if (n == nullptr) {
        return nullptr;
    }

    if (n == getMaxNode(root)) {
        return nullptr;
    }

    if (n->right) {
        return getMinNode(n->right);
    }

    p = n->parent;

    while (p && n == p->right) {
        n = p;
        p = p->parent;
    }
    return p;
}

CardsBST::Node* CardsBST::getNodeFor(const Card c, Node* n) const {
    Node* p;
    

    if (n->info == c) {
        return n;
    }

    else {
        if (c < n->info && n->left) {
            p = getNodeFor(c, n->left);
        }
        if (c > n->info && n->right) {
            p = getNodeFor(c, n->right);
        }
        if (c < n->info && !n->left) {
            p = nullptr;
        }
        if (c > n->info && !n->right) {
            p = nullptr;
        }
    }

    return p;
}

CardsBST::Node* CardsBST::getMaxNode(Node* n) const {
    while (n->right) {
        n = n->right;
    }
    return n;
}

CardsBST::Node* CardsBST::getMinNode(Node* n) const {
    while (n->left) {
        n = n->left;
    }
    return n;
}

CardsBST::Node* CardsBST::getRoot() const {
    return root;
}
