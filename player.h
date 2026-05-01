#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;
#include "Hand.h"
#include "Card.h"

enum PlayerStatus { HASNTPLAYED, PASSED, PLAYED, HASNOCARDSLEFT, WONTHETRICK, MISSEDTURN };

string statusToString(PlayerStatus status);

class Player {
private:
    int index;
    string name;
    PlayerStatus status;
    int points;
    bool hasDrawnCard;
    Hand hand;

public:
    Player(int idx, string n);

    int getIndex() const;
    string getName() const;

    PlayerStatus getStatus() const;
    void setStatus(PlayerStatus s);

    int getPoints() const;
    void setPoints(int p);
    void addPoints(int p);

    bool getHasDrawnCard() const;
    void setHasDrawnCard(bool b);

    Hand& getHand();
    const Hand& getHand() const;

    bool playCard(Card* card);
    void drawCard(Card* card);
    void pass();
    CardSuit chooseSuit();

    bool hasCards() const;
    void clearHand();
};

#endif // PLAYER_H