#ifndef UTILITY_H
#define UTILITY_H


using namespace std;

class Card {
    public:
        Card();
        Card(char symbol, int value);
        ~Card();

        friend bool operator==(const Card& c1, const Card& c2);
        friend bool operator<(const Card& c1, const Card& c2);
        friend bool operator>(const Card& c1, const Card& c2);
            
        void setSuit(const char& symbol);
        void setNumber(const int& value);

        char getSuit() const;
        int getNumber() const;
   
        void print();

    private:
        char suit;
        int number;
};
#endif
