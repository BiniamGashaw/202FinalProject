#include "./menuItem.h"

MenuItem::MenuItem(){
    itemName = "NONE";
    cost = -1;
    pointWorth = 0;
}
MenuItem::MenuItem(const MenuItem& rhs){
    itemName = rhs.itemName;
    cost = rhs.cost;
    pointWorth = rhs.pointWorth;
}
MenuItem::MenuItem(float val, string name, int pts){
    itemName = name;
    cost = val;
    pointWorth = pts;
}

float MenuItem::getCost(){
    return cost;
}
void MenuItem::setCost(float val){
    cost = val;
}

string MenuItem::getItemName(){
    return itemName;
}
void MenuItem::setItemName(string name){
    itemName = name;
}

int MenuItem::getPointWorth(){
    return pointWorth;
}
void MenuItem::setPointWorth(int pts){
    pointWorth = pts;
}

void MenuItem::displayNameAndCost(){
   
    cout << itemName << endl;
    cout << cost << endl;
}
