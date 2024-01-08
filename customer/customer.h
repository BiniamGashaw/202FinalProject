#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <iomanip>
using namespace std;
#include "../menuItem/menuItem.h"


#define MAX_SIZE_ORDER 50
class Customer{
    string customerFirst, customerLast; /*< string value of first name and last name*/
    long int loyaltyNumber; /*< long int value of loyalty number*/
    long int numberLoyaltyPoints; /*< long int value of number loyalty points customer has*/
    int numItemsInOrder; /*< int value of number items in current order*/
    MenuItem** currentOrder = new MenuItem*[MAX_SIZE_ORDER]; /*< an array of menyItems */

    public:
        //! The default constructor. You can choose what to set values to.
        Customer();
        
        Customer(string, string, long int, long int);
        
        Customer(const Customer&);
        
        string getCustomerFirst();
       
        void setCustomerFirst(string);

        
        string getCustomerLast();
       
        void setCustomerLast(string);
       
        long int getLoyaltyNumber();
       
        void setLoyaltyNumber(long int);

        
        long int getNumberLoyaltyPoints();
       
        void setNumberLoyaltyPoints(long int);

        
        MenuItem** getCurrentOrder();
       
        void addItemToOrder(MenuItem*);
        
        
        int getNumItemsInOrder();
        
        void setNumItemsInOrder(int);

        /*! sums each item's cost from the current order and applies a 8.27% tax to it, which is returned as the customer's total. */
        float calculateCost();
        /*! displays the current order menu to the user when it's time to check out and outputs the total after calling calculate cost*/
        void displayOrder();
        /*!Displays the welcome message and number of loyalty*/
        void displayCustomerInformation();
};
#endif