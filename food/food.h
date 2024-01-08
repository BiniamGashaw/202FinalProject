#ifndef FOOD_H
#define FOOD_H

#include "../menuItem/menuItem.h"
/*!
 * This is the Food class which inherits from MenuItem. 
 * It must have a default constructor, parameterized constructor, and copy constructor
 * It is responsible for getting and setting ingredients, and getting the number of ingredients 
*/
class Food : public MenuItem{
    string ingredients[MAX_NUMBER_INGREDIENTS]; /*< an array of strings for each ingredient*/
    int numberIngredients;
    int numAvailableExtras;
    string availableExtras[MAX_NUMBER_INGREDIENTS];


    
     /*< integer value number of ingredients in item*/

    public: 
        //! The default constructor. You can choose what to set values to.
        Food();
        
        Food(string*, int);
        
        Food(const Food&) ;

       
        string* getIngredients();
        
        void addIngredient(const string);

        
        int getNumberIngredients() const;
        void displayItemInformation() override;
        void setAvailableExtras();
        string* getAvailableExtras();
        int getNumExtras();
        float calculateMenuItemCost() override;

};
#endif