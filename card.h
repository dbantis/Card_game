#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

enum CardSuit { HEART, DIAMOND, CLUB, SPADE };
enum CardEffect { NONE, DRAW_TWO, PLAY_AGAIN, SKIP_NEXT, CHANGE_SUIT };

string suitToString(CardSuit suit);

class Card {
private:
    CardSuit suit;
    int value;  // 1-13
    int points;

public:
    Card(CardSuit s, int v, int p);
    virtual ~Card();

    CardSuit getSuit() const;
    int getValue() const;
    int getPoints() const;

    virtual CardEffect getEffect() const = 0;
    virtual bool isSpecial() const = 0;
};

class Simple : public Card {
public:
    Simple(CardSuit s, int v, int p);
    CardEffect getEffect() const override;
    bool isSpecial() const override;
};

class Seven : public Card {
public:
    Seven(CardSuit s, int v, int p);
    CardEffect getEffect() const override;
    bool isSpecial() const override;
};

class Eight : public Card {
public:
    Eight(CardSuit s, int v, int p);
    CardEffect getEffect() const override;
    bool isSpecial() const override;
};

class Nine : public Card {
public:
    Nine(CardSuit s, int v, int p);
    CardEffect getEffect() const override;
    bool isSpecial() const override;
};

class Ace : public Card {
public:
    Ace(CardSuit s, int v, int p);
    CardEffect getEffect() const override;
    bool isSpecial() const override;
};

#endif // CARD_H