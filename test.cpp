#include "utility.h"
#include "cards.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    Card c1('c', 3);
    Card c2('h', 2);
    Card c3('s', 2);
    Card c4('c', 7);
    Card c5('d', 6);
    Card c6('c', 1);
    Card c7('c', 2);

    CardsBST bst1;
    bst1.insert(c1);
    bst1.insert(c2);
    bst1.insert(c3);
    bst1.insert(c4);
    bst1.insert(c5);
    bst1.insert(c6);
    bst1.insert(c7);
    bst1.printPreOrder();

/*    Card c1;
    Card c2('h', 11);
    Card c3('s', 11);
    Card c4('c', 5);
    Card c5('d', 12);
    Card c6('h', 2);
    Card c7('c', 4);
    Card c8('c', 12);
    Card c9('s', 10);
    Card c10('d', 4);
    Card c11('d', 8);
    Card c12('h', 3);
    Card c13('d', 13);

    Card c14('c', 5);
    Card c15('h', 4);

    CardsBST bst1, bst2;


    bst1.insert(c13);
    bst1.insert(c12);
    bst1.insert(c11);
    bst1.insert(c10);
    bst1.insert(c9);
    bst1.insert(c8);
    bst1.insert(c7);
    bst1.insert(c6);
    bst1.insert(c5);
    bst1.insert(c4);
    bst1.insert(c3);
    bst1.insert(c2);
    bst1.insert(c1);


    cout << "Testing Card Class" << endl;
    
    if (c1 == c2) {
        cout << "c1 is c2" << endl;
    }
    else cout << "c1 isn't c2" << endl;

    c1.print();
    c2.print();

    if (c1 < c2) {
        cout << "c1 is less than c2" << endl;
    }
    else cout << "c1 is greater than c2" << endl;

    c1.setSuit('h');
    c1.setNumber(11);

    if (c1 == c2) {
        cout << "They are equal" << endl;
    }

    cout << endl;
    cout << endl;
 */  return 0;
}
