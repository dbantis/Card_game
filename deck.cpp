// =============================================================================
// Deck.cpp
// -----------------------------------------------------------------------------
// Implements the Deck class: construction, card dealing, shuffling, and
// rebuilding the deck from the discard pile.
// =============================================================================

#include "Deck.h"

CardSuit operator++(CardSuit& s, int) 
{
    CardSuit value=s; 
    if (s==SPADE) 
        s=HEART; 
    else 
        s=(CardSuit)((int)s+1);
    
    return value;
}

Deck::Deck()
{
    currentSize=0;
    capacity=52; 
    CardSuit s=HEART;
    for(int i=0 ; i<4 ; i++)
    {
        for(int j=1 ; j<=13 ; j++)
        {
            if(j==1)
                cards[currentSize]=new Ace(s,j,11);
            else if(j==11 || j==12 || j==13)
                cards[currentSize]=new Simple(s,j,10);
            else if(j==7)
                cards[currentSize]=new Seven(s, j, j);
            else if(j==8)
                cards[currentSize]=new Eight(s, j, j);
            else if(j==9)
                cards[currentSize]=new Nine(s, j, j);
            else
                cards[currentSize]=new Simple(s, j, j);

            currentSize++;
        }
        s++;
    }
}

Deck::~Deck()
{
    for(int i=0 ; i<currentSize ; i++)
        delete cards[i];
    delete []cards;
}

void Deck::reset()
{
    for(int i=0 ; i<currentSize ; i++)
        delete cards[i];
    currentSize=0;
    CardSuit s=HEART;
    for(int i=0 ; i<4 ; i++)
    {
        for(int j=1 ; j<=13 ; j++)
        {
            if(j==1)
                cards[currentSize]=new Ace(s,j,11);
            else if(j==11 || j==12 || j==13)
                cards[currentSize]=new Simple(s,j,10);
            else if(j==7)
                cards[currentSize]=new Seven(s, j, j);
            else if(j==8)
                cards[currentSize]=new Eight(s, j, j);
            else if(j==9)
                cards[currentSize]=new Nine(s, j, j);
            else
                cards[currentSize]=new Simple(s, j, j);

            currentSize++;
        }
        s++;
    }
}

Card* Deck::deal()
{
    if(currentSize==0)
        return nullptr;
    currentSize--;
    return cards[currentSize-1];
}

void Deck::rebuildFromDiscard(Card** discardPile, int discardSize)
{
    currentSize=0;
    for(int i=0 ; i<discardSize-1 ; i++)
    {
        cards[currentSize]=discardPile[i];
        currentSize++;
    }
    shuffle();
}

void Deck::shuffle() {
    for (int i = currentSize - 1; i > 0; i--) {
        // Pick a random index between 0 and i (inclusive)
        int j = rand() % (i + 1);

        // Swap the cards at positions i and j
        Card* temp = cards[i];
        cards[i]   = cards[j];
        cards[j]   = temp;
    }
}
// ---------------------------------------------------------------------------
// shuffle
// ---------------------------------------------------------------------------
// Randomly reorders the cards in the deck using the Fisher-Yates algorithm.
//
// How Fisher-Yates works:
//   For each position i from the end down to 1:
//     Pick a random position j between 0 and i (inclusive)
//     Swap cards[i] and cards[j]
// This guarantees every possible ordering is equally likely.
// ---------------------------------------------------------------------------
// isEmpty
// ---------------------------------------------------------------------------
bool Deck::isEmpty() const {
    return currentSize == 0;
}


// ---------------------------------------------------------------------------
// getCurrentSize
// ---------------------------------------------------------------------------
int Deck::getCurrentSize() const {
    return currentSize;
}
