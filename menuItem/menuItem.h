#ifndef MENU_H
#define MENU_H


#include <iostream>
using namespace std;
#define MAX_NUMBER_INGREDIENTS 50

class MenuItem{
    float cost;/*< float value item cost*/
    string itemName; /*< string value item name*/
    int pointWorth; /*< int value point worth*/

    public:
        //! The default constructor. You can choose what to set values to.
        MenuItem();
        
        MenuItem(float, string, int);
       
        MenuItem(const MenuItem&);
      
        float getCost();
       
        void setCost(float);

        
        string getItemName();
       
        void setItemName(string);
        
       
        int getPointWorth();
     
        void setPointWorth(int);
        void displayNameAndCost();
        virtual float calculateMenuItemCost() = 0;
        virtual void displayItemInformation() = 0;
};
#endif