Player::Player(int idx, string n)
{
    index=idx;
    name=n;
    
    status=HASNTPLAYED;          
    points=0;                     
    hasDrawnCard=false;
}

int Player::getIndex() const
{
    return index;
}

string Player::getName() const
{
    return name;
}

PlayerStatus Player::getStatus() const
{
    return status;
}

void Player::setStatus(PlayerStatus s)
{
    status=s;
}

int Player::getPoints() const
{
    return points;
}

void Player::setPoints(int p)
{
    points=p;
}

void Player::addPoints(int p)
{
    points+=p;
}

bool Player::getHasDrawnCard() const
{
    return hasDrawnCard;
}

void Player::setHasDrawnCard(bool b)
{
    hasDrawnCard=b;
}

Hand& Player::getHand()
{
    return hand;
}

const Hand& Player::getHand() const 
{
    return hand;
}

bool Player::playCard(Card* card)
{
    bool card_played=hand.removeCard(card);
    if (card_played) 
    {
        status=PLAYED;
        hasDrawnCard=false;
    }   
    return card_played;
}

void Player::drawCard(Card* card)
{
    hand.addCard(card);
    hasDrawnCard=true;    
}

void Player::pass()
{
    if(hasDrawnCard)
    {
        status=PASSED;
        hasDrawnCard=false;
    }
}

bool Player::hasCards() const
{
    if(hand.numberOfCards())
        return true;
    return false;  
}

void Player::clearHand()
{
    hand.clear();
}

string statusToString(PlayerStatus status)
{
     switch(status)
    {
        case HASNTPLAYED:
            return "Hasn't Played";

        case PASSED:
            return "Passed";

        case PLAYED:
            return "Played";

        case HASNOCARDSLEFT:
            return "Has No Cards Left";

        case WONTHETRICK:
            return "Won the Trick";

        case MISSEDTURN:
            return "Missed Turn";

        default:
            return "Unknown";
    }
}

bool hasPlayerReachedPointsLimit(const Game& game, int pointsLimit) 
{
    int num_of_players=game.getCurrentPlayersCount();
    for(int i=0; i<num_of_players; i++)
    {
        if(game.getPlayers()[i]->getPoints()>=pointsLimit)
            return true;
    }
    return false;
}

bool hasTieForBestScore(const Game& game) 
{
    int count=0;
    int num_of_players=game.getCurrentPlayersCount();
    
    int minimum_points=game.getPlayers()[0]->getPoints();
    
    for(int i=0; i<num_of_players-1; i++)
    {
        if(game.getPlayers()[i+1]->getPoints()<minimum_points)
        {
            minimum_points=game.getPlayers()[i+1]->getPoints();
        }
    }
    
    for(int i=0; i<num_of_players; i++)
    {
        if(game.getPlayers()[i]->getPoints()==minimum_points)
            count++;
    }
    
    if(count>1)
        return true;
    return false;
}
