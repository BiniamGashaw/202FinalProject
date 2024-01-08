#ifndef DRINK_H
#define DRINK_H
#include "../menuItem/menuItem.h"

class Drink : public MenuItem{
    int size; /*< int size of drink in fluid oz*/
    bool needsStraw; /*< bool value of if the customer wants a straw*/
    bool needsIce; /*< bool value of if the customer wants ice*/

    public:
        //! The default constructor. You can choose what to set values to.
        Drink();
       
        Drink(int, bool, bool);
        
        Drink(const Drink&);

       
        int getSize() const;
       
        void setSize(const int);

        bool getNeedsStraw();
        
        void setNeedsStraw(bool) ;

       
        bool getNeedsIce();
       
        void setNeedsIce(bool);
        void displayItemInformation() override; 
        float calculateMenuItemCost() override;

};
#endif