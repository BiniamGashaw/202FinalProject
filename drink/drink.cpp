#include "./drink.h"

Drink::Drink(){
    size = 0;
    needsIce = false;
    needsStraw = false;
}
Drink::Drink(int sz, bool ice, bool straw){
    size = sz;
    needsIce = ice;
    needsStraw = straw;
}
Drink::Drink(const Drink& rhs){
    size = rhs.size;
    needsIce = rhs.needsIce;
    needsStraw = rhs.needsStraw;
}

int Drink::getSize() const {
    return size;
}
void Drink::setSize(const int sz) {
    size = sz;
}
 
bool Drink::getNeedsStraw(){
    return needsStraw; 
}
void Drink::setNeedsStraw( bool straw) {
    needsStraw = straw;
}

bool Drink::getNeedsIce() {
    return needsIce;
}
void Drink::setNeedsIce( bool ice){
    needsIce = ice;
}

void Drink::displayItemInformation() {
    displayNameAndCost();
    cout << "INCLUDE:";
    cout << "fuckçing jefery" << endl;
    if(getNeedsIce() == true){
        cout << "Ice" << endl;
    }
    if(getNeedsStraw() == true){
        cout << " Straw" << endl;
    }
}

float Drink::calculateMenuItemCost() {
    float sizeCost = 0;
    float drinkCost = 0;
    float iceCost = 0;
    // cout << "What size? (16, 20, 32) oz: ";
    // cin >> size;
    // setSize(size);
    if(getSize() == 16){
        sizeCost = 2.99;
        return sizeCost;
    }
    else if(getSize() == 20){
        sizeCost = 3.25;
        return sizeCost;
    }
    else if(getSize() == 32){
        sizeCost = 3.75;
        return sizeCost;
    }
    else {
        sizeCost = 0.0;
        return sizeCost;
    }

    if(getNeedsStraw() == true){
        sizeCost += 0.75;
        return sizeCost;
    }
    else if(getNeedsIce() == true){
        sizeCost += 0.25;
        return sizeCost;
    }
    
}
