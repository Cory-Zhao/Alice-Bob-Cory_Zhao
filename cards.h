//cards.h
//Authors: Cory Zhao
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include "utility.h"

using namespace std;

class CardsBST {
    public:

        struct Node {
            Card info;
            
            Node* left;
            Node* right;
            Node* parent;

            Node(Card c): info(c), left(0), right(0), parent(0) {}
        };

        CardsBST();
        ~CardsBST();
        
        void insert(Card c);        
        void remove(Card c);

        void printPreOrder() const;
        void printInOrder() const;
        void printPostOrder() const;

        bool contains(const Card& c) const;

        Node* getPredecessorNode(const Card& c) const;
        Node* getSuccessorNode(const Card& c) const;
        
        Node* getMaxNode(Node* n) const;
        Node* getMinNode(Node* n) const;

        Node* getRoot() const;
   // private:
        
        void printPreOrder(Node* n) const;
        void printInOrder(Node* n) const;
        void printPostOrder(Node* n) const;
        
        void clear(Node* n);
        
        Node* getNodeFor(const Card c, Node* n) const;

        void insert(Card c, Node* n);

        Node* root;

};
#endif
