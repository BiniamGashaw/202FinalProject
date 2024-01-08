#include "./customer.h"
/// @cond
Customer::Customer(){
    customerFirst = "Jane";
    customerLast = "Doe";
    loyaltyNumber = 0;
    numberLoyaltyPoints = 1111111;
    numItemsInOrder = 0;
}
Customer::Customer(string first, string last, long int id, long int numPts){
    customerFirst = first;
    customerLast = last;
    loyaltyNumber = id;
    numberLoyaltyPoints = numPts;
    numItemsInOrder = 0;
}
Customer::Customer(const Customer& rhs){
    customerFirst = rhs.customerFirst;
    customerLast = rhs.customerLast;
    loyaltyNumber = rhs.loyaltyNumber;
    numberLoyaltyPoints = rhs.numberLoyaltyPoints;
    numItemsInOrder = rhs.numItemsInOrder;
    for(int i = 0; i < numItemsInOrder; i++){
        currentOrder[i] = rhs.currentOrder[i];
    }
}

string Customer::getCustomerFirst(){
    return customerFirst;
}
void Customer::setCustomerFirst(string name){
    customerLast = name;
}

string Customer::getCustomerLast(){
    return customerLast;
}
void Customer::setCustomerLast(string name){
    customerLast = name;
}


long int Customer::getLoyaltyNumber(){
    return loyaltyNumber;
}
void Customer::setLoyaltyNumber(long int id){
    loyaltyNumber = id;
}   

long int Customer::getNumberLoyaltyPoints(){
    return numberLoyaltyPoints;
}
void Customer::setNumberLoyaltyPoints(long int numPts){
    numberLoyaltyPoints = numPts;
}

MenuItem** Customer::getCurrentOrder(){
    return currentOrder;
}
void Customer::addItemToOrder(MenuItem* newItem){
    currentOrder[numItemsInOrder] = newItem;
    numItemsInOrder++;
}

int Customer::getNumItemsInOrder(){
    return numItemsInOrder;
}

float Customer::calculateCost(){
    float customerTotal = 0;
    float currentTaxRate = 1.0827;
    for(int i = 0; i < numItemsInOrder; i++){
        customerTotal += currentOrder[i]->getCost();
    }
    customerTotal *= currentTaxRate;
    return customerTotal;
}

void Customer::displayOrder(){
    cout <<endl << "=====Your Order=====" << endl;
    for(int i = 0; i < numItemsInOrder; i++){
       cout << currentOrder[i]->getItemName() << " " << currentOrder[i]->getCost() << endl;
       currentOrder[i]->displayItemInformation();
    }
    cout << "\nYour Total Today Is: $" << std::fixed << setprecision(2) << calculateCost()<< endl << endl;
    
}

void Customer::displayCustomerInformation(){
    cout <<endl << "Welcome " <<getCustomerFirst() <<" " << getCustomerLast() << "!" << endl;
    cout << "You have " << getNumberLoyaltyPoints() << " Loyalty Points." << endl;
}

void Customer::setNumItemsInOrder(int numItem){
    numItemsInOrder = numItem;
}

