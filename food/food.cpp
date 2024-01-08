#include "./food.h"

Food::Food(){
    numberIngredients = 0;
}
Food::Food(string* ing, int numIngredients){
    for(int i = 0; i < numIngredients; i++){
        ingredients[i] = ing[i];
    }
}
Food::Food(const Food& rhs){
    for(int i = 0; i < rhs.numberIngredients; i++){
        ingredients[i] = rhs.ingredients[i];
    }
}

string* Food::getIngredients(){
    return ingredients;
}
void Food::addIngredient(string ingredient){
    ingredients[numberIngredients] = ingredient;
    numberIngredients++;
}

int Food::getNumberIngredients() const {
    return numberIngredients;
}

void Food::displayItemInformation(){
    displayNameAndCost();
    cout << "INGREDIENTS: "<< endl;
    for(int i=0; i < numberIngredients; i++){
        cout << ingredients[i] << " ";
    }
}

 void Food::setAvailableExtras() {
    string itemName = getItemName();
    if(itemName== "Smoked Meat Sandwich" || itemName== "Meat Sandwich"){
        string tempArray[5] = {"BBQ Sauce ", "Toast ", "Potatoes ", "Ranch Dressing ", "Broccoli "};
        for(int index = 0; index < 6; index++){
            availableExtras[index] = tempArray[index];
        }
        numAvailableExtras = 5;
    }

    else if(itemName== "Meaty Meat Man Meal" || itemName == "Meat Man Meal" ){
        string tempArray2[4] = {"White Bread ", "Mustard ", "Swiss Cheese ", "Ranch Dressing "};
        for(int index = 0; index < 4; index++){
            availableExtras[index] = tempArray2[index];
            numAvailableExtras = 4;
        }
    }

    else if(itemName== "Tater Tots" ||  itemName== "Small Tater Tot"){
        string tempArray3[7] = {"Smoked Meat ", "White Bread ", "Mustard ", "Swiss Cheese ", "Toast ", "BBQ Sauce ", "Broccoli "};
        for(int index = 0; index < 7; index++){
            availableExtras[index] = tempArray3[index];
            numAvailableExtras = 7;
        }
    }
}

string* Food::getAvailableExtras() {
    return availableExtras;
}
int Food::getNumExtras(){

    return numAvailableExtras;

}
float Food::calculateMenuItemCost(){
    float extraCost; 
    float ingredientCost = numberIngredients * 0.50;
    extraCost = ingredientCost + getCost(); 
    setCost(extraCost);
    return extraCost;
}





