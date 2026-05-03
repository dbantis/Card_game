Hand::Hand()
{
    currentSize=0;
    capacity=52;

    cards=new Card* [capacity];
    if(!cards) 
    {
        cout<<"Error allocating memory."<<endl;
        exit(1);
    }

    for(int i=0; i<capacity; i++)
    {
        cards[i]=NULL;
    }
}

Hand::~Hand()
{
    delete [] cards;
}

Card** Hand::getCards() const
{
    return cards;
}

int Hand::numberOfCards() const
{
    return currentSize;
}

Card** Hand::validRoundCards(Card* topCard, bool hasDeclaredSuit, CardSuit declaredSuit, int& outCount) const
{
    outCount=0;
    
    if(currentSize==0)
        return NULL;
        
    Card** valid_cards=new Card* [currentSize]; 
    if(!valid_cards) 
    {
        cout<<"Error allocating memory."<<endl;
        return NULL;
    }

    for(int i=0; i<currentSize; i++)
        valid_cards[i]=NULL;

    if((!hasDeclaredSuit) && (topCard->getValue()==1))
    {
        declaredSuit=topCard->getSuit();
        hasDeclaredSuit=true;
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
            
            if((cards[i]->getSuit()==topCard->getSuit()) || (cards[i]->getValue()==topCard->getValue()) || (cards[i]->getValue()==1))
            {
                valid_cards[outCount]=cards[i];
                outCount++;
            }
        }
    }
    return valid_cards;
}

int Hand::calculatePoints() const
{
    int total_points=0;
    
    for(int i=0; i<currentSize; i++)
    {
        if(cards[i]!=NULL)
            total_points+=cards[i]->getPoints();
    }
    return total_points;
}

void Hand::addCard(Card* card)
{
    if(card!=NULL && currentSize<capacity)
    {
        cards[currentSize]=card;
        currentSize++;
    }
}

bool Hand::removeCard(Card* card)
{
    if(card==NULL) 
        return false;
    
    for (int i=0; i<currentSize; i++)
    {
        if(cards[i]==card)
        {
            for(int j=i; j<currentSize-1; j++)
            {
                cards[j]=cards[j+1];
            }
            cards[currentSize-1]=NULL;
            currentSize--;
            return true;
        }
    }
    return false;
}




















