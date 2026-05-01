#ifndef HAND_H
#define HAND_H

#include "Card.h"

class Hand {
private:
    Card** cards;
    int currentSize;
    int capacity;

public:
    Hand();
    ~Hand();

    Card** getCards() const;
    int numberOfCards() const;
    
    // Returns a dynamically allocated array of valid cards.
    // outCount is updated with the number of valid cards found.
    Card** validRoundCards(Card* topCard, bool hasDeclaredSuit, CardSuit declaredSuit, int& outCount) const;
    int calculatePoints() const;

    void addCard(Card* card);
    bool removeCard(Card* card);
    void clear();
};

#endif // HAND_H