#include "Card.h"

Card::Card()
{
    this->id = 0;
    this->rarity = "";
    this->value = 0;
}

Card::~Card()
{
    //dtor
}

void Card::ShowCard()
{
    cout << "Card Value $" << this->value << ", Stack ID: " << this->id << ", Type: " << this->type << ", Rarity: " << this->rarity << endl;
}

