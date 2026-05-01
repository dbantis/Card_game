Hand::Hand()
{
    currentSize=0;
    capacity=52;

    cards=new Card*[capacity];
    if (cards==NULL) cout<<"Error allocating memory"<<endl;

    for(int i=0; i<capacity; i++)
    {
        cards[i]= NULL;
    }
}

Hand::~Hand()
{
    clear();
    delete [] cards;
}

Card** Hand::getCards()const
{
    return cards;
}

int Hand::numberOfCards()const
{
    return currentSize;
}

Card** Hand::validRoundCards(Card* topCard, bool hasDeclaredSuit, CardSuit declaredSuit, int& outCount)const
{
    Card** valid_cards=new Card*[currentSize]; 
    outCount=0; 
    
    if(!hasDeclaredSuit && topCard->getValue()==1)
    {
        hasDeclaredSuit=true;
        declaredSuit=topCard->getSuit();
    }
    
    if(currentSize==1)
    {
        if(cards[0]->isSpecial())
            return valid_cards;
    }
    
    for(int i=0; i<currentSize; i++)
    {

        if(hasDeclaredSuit) 
        { 
            if((cards[i]->getSuit()==declaredSuit) && (cards[i]->getValue()!=1)) 
            {
                valid_cards[outCount]=cards[i];
                outCount++;
            }
        }
        else  
        {
            if(cards[i]->getSuit()==topCard->getSuit() || cards[i]->getValue()==topCard->getValue() || cards[i]->getValue()==1)
            {
                valid_cards[outCount]=cards[i];
                outCount++;
            }
        }
    }
    return valid_cards;
}

int Hand::calculatePoints()const
{
    int total_points=0;
    
    for(int k=0; k<currentSize; k++)
    {
        if (cards[k]!=nullptr)
        {
        total_points+=cards[k]->getPoints();
        }
    }
    return total_points;
}

void Hand::addCard(Card* card)
{
    if (card!=nullptr && currentSize<capacity)
    {
        cards[currentSize]=card;
        currentSize++;
    }
}

bool Hand::removeCard(Card* card)
{
    if (card == nullptr) return false;
    
    for (int i = 0; i < currentSize; i++)
    {
        if (cards[i] == card)
        {
            for(int j=i; j<currentSize-1; j++)
            {
                cards[j] = cards[j + 1];
            }
            cards[currentSize - 1] = nullptr;
            currentSize--;
            return true;
        }
    }
    return false;
}













