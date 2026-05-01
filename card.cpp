Card::Card(CardSuit s, int v, int p)
{
    suit=s;
    value=v;
    points=p;
}

Card::~Card() { }

CardSuit Card::getSuit() const
{
    return suit;
}

int Card::getValue() const
{
    return value;
}

int Card::getPoints() const
{
    return points;
}

string suitToString(CardSuit suit)
{
    switch (suit)
    {
        case HEART:
        return "Heart";
       
        case DIAMOND:
        return "Diamond";
      
        case CLUB:
        return "Club";
        
        case SPADE:
        return "Spade";
       
        default:
        return "Unknown";
    }
}

Simple::Simple(CardSuit s, int v, int p):Card(s, v, p) {}

CardEffect Simple::getEffect() const
{
    return NONE;
}

bool Simple::isSpecial() const
{
    return false;
}

Seven::Seven(CardSuit s, int v, int p):Card(s, v , p) {}

CardEffect Seven::getEffect()const
{
    return DRAW_TWO;
}

bool Seven::isSpecial()const
{
    return true;
}

Eight::Eight(CardSuit s, int v, int p):Card(s, v, p){}

CardEffect Eight::getEffect() const
{
    return PLAY_AGAIN;
}

bool Eight::isSpecial()const
{
    return true;
}

Nine::Nine(CardSuit s, int v, int p):Card(s, v, p) {}

CardEffect Nine::getEffect()const
{
    return SKIP_NEXT;
}

bool Nine::isSpecial()const
{
    return true;
}

Ace::Ace(CardSuit s, int v, int p):Card(s, v, p){}

CardEffect Ace::getEffect()const
{
    return CHANGE_SUIT;
}

bool Ace::isSpecial()const
{
    return true;
}


