#include "utility.h"
#include "cards.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argv, char** argc){


  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;
  
  Card c1;
  string num;
  int value;
  char suit;
  
  CardsBST bst1;
  CardsBST bst2;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }
  



  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    suit = line[0];
    c1.setSuit(suit);

    if (line.length() > 3) {
        num = line.substr(2, 2);
        value = stoi(num);
        c1.setNumber(value);
    }
    else {
        num = line.substr(2, 1);
        
        if (num[0] == 'a') {
            value = 1;
        }
        else if (num[0] == 'k') {
            value = 13;
        }
        else if (num[0] == 'q') {
            value = 12;
        }
        else if (num[0] == 'j') {
            value = 11;
        }
        else value = stoi(num);
        
        c1.setNumber(value);
    }
    bst1.insert(c1);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    suit = line[0];
    c1.setSuit(suit);

    if (line.length() > 3) {
        num = line.substr(2, 2);
        value = stoi(num);
        c1.setNumber(value);
    }
    else {
        num = line.substr(2, 1);
        
        if (num[0] == 'a') {
            value = 1;
        }
        else if (num[0] == 'k') {
            value = 13;
        }
        else if (num[0] == 'q') {
            value = 12;
        }
        else if (num[0] == 'j') {
            value = 11;
        }
        else value = stoi(num);
        
        c1.setNumber(value);
    }
    bst2.insert(c1);

  }
  cardFile2.close();
  
  CardsBST::Node* tempNode;
  Card tempCard;

  Card aliceNextCard = bst1.getMinNode(bst1.root)->info;
  Card bobNextCard = bst2.getMaxNode(bst2.root)->info;
  bool finished = false;

  while (1) {
      if (bst2.getNodeFor(aliceNextCard, bst2.root) != nullptr) {
         cout << "Alice picked matching card ";
         aliceNextCard.print();
         
         tempCard = aliceNextCard;
         tempNode = bst1.getSuccessorNode(aliceNextCard);
         
         if (tempNode == nullptr) {
             break;
         }

         aliceNextCard = tempNode->info;

         if (tempCard == bobNextCard) {
             tempNode = bst2.getPredecessorNode(bobNextCard);
             bobNextCard = tempNode->info;
         }

         bst1.remove(tempCard);
         bst2.remove(tempCard);
            

         while (1) {
            if (bst1.getNodeFor(bobNextCard, bst1.root) != nullptr) {
                cout << "Bob picked matching card ";
                bobNextCard.print();

                tempCard = bobNextCard;
                tempNode = bst2.getPredecessorNode(bobNextCard);

                if (tempNode == nullptr) {
                    break;
                }

                bobNextCard = tempNode->info;

                if (tempCard == aliceNextCard) {
                    tempNode = bst1.getSuccessorNode(aliceNextCard);
                    aliceNextCard = tempNode->info;
                }

                bst1.remove(tempCard);
                bst2.remove(tempCard);

                break;
            }
            else {
                tempNode = bst2.getPredecessorNode(bobNextCard);
                if (tempNode == nullptr) {
                    finished = true;
                    break;
                }
                bobNextCard = tempNode->info;
            }
         }
         if (finished) {
             break;
         }
     }
     else {
         tempNode = bst1.getSuccessorNode(aliceNextCard);
         if (tempNode == nullptr) {
             finished = true;
             break;
         }
         aliceNextCard = tempNode->info;
     }
  }

  cout << endl;

  cout << "Alice's cards:" << endl;
  bst1.printInOrder();

  cout << endl;

  cout << "Bob's cards:" << endl;
  bst2.printInOrder();
  

  return 0;
}
