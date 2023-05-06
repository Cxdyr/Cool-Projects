#include "FinalCard.h"

FinalCard::FinalCard()
{
    this->id = 0;
    this->rarity = "";
    this->value = 0;
    this->sold = "Available";
}

FinalCard::~FinalCard()
{
    //dtor
}

void FinalCard::ShowCard()
{
    cout << "Card Value $" << this->value << ", Stack ID: " << this->id << ", Type: " << this->type << ", Rarity: " << this->rarity << ", " << this->sold << endl;
}

