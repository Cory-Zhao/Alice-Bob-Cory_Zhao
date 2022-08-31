#include "utility.h"
#include <iostream>

using namespace std;

Card::Card() {
    suit = 'c';
    number = 1;
}

Card::Card(char symbol, int value) {
    suit = symbol;
    number = value;
}


Card::~Card() {

}

void Card::setSuit(const char& symbol) {
    suit = symbol;
}

void Card::setNumber(const int& value) {
    number = value;
}

char Card::getSuit() const {
    return suit;
}

int Card::getNumber() const {
    return number;
}

bool operator==(const Card& c1, const Card& c2) {
    if (c1.suit == c2.suit && c1.number == c2.number) {
        return true;
    }
    else return false;
}

bool operator<(const Card& c1, const Card& c2) {
    int c1Total = 0;
    int c2Total = 0;

    if (c1.suit == 'h') {
        c1Total = 10000;
    }
    else c1Total = (c1.suit - '0') * 30;

    if (c2.suit == 'h') {
        c2Total = 10000;
    }
    else c2Total = (c2.suit - '0') * 30;
    
    c1Total += c1.number;
    c2Total += c2.number;
    
    return c1Total < c2Total; 
}

bool operator>(const Card& c1, const Card& c2) {
    int c1Total = 0;
    int c2Total = 0;

    if (c1.suit == 'h') {
        c1Total = 10000;
    }
    else c1Total = (c1.suit - '0') * 30;

    if (c2.suit == 'h') {
        c2Total = 10000;
    }
    else c2Total = (c2.suit - '0') * 30;

    c1Total += c1.number;
    c2Total += c2.number;

    return c1Total > c2Total;
}

void Card::print() {
    if (number == 1) {
        cout << suit << " a" << endl;
    }
    else if (number == 11) {
        cout << suit << " j" << endl;
    }
    else if (number == 12) {
        cout << suit << " q" << endl;
    }
    else if (number == 13) {
        cout << suit << " k" << endl;
    }
    else cout << suit << " " << number << endl;
}
