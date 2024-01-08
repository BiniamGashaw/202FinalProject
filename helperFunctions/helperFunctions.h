
#include "../customer/customer.h"
#include "../drink/drink.h"
#include "../food/food.h"

#include <fstream>


#define MAX_NUM_CUSTOMERS 1000


int runLoyaltyProgram(Customer*, int*);


void overwriteLoyaltyDatabase(Customer*, int);


bool pointSystemPrompt(Customer*);

/*!
 * Displays rewards and their point values.
*/
void displayPointRedemptionMenu();

/*!
 * Displays a prompt for a new user to input user loyalty information (7 digit number, first name, last name)
*/
void displayLoyaltyInformationPrompt();

/*!
 * Gathers integer userInput 
*/
int getUserIntChoice();

/*!
 * Gathers char userInput
*/
char getUserCharChoice();

/*!
 * gathers string user input
*/
string getUserStringEntry();

/*!
 * Displays the join message, calls displayPointRedemptionMenu, and the prompts user if they'd like to join
*/
void displayMemberJoin();

/*!
 * Prompts for user input using displayMenuItems
 * Gets user input using getUser method
 * Adds input repeatedly using addItemToOrder until user chooses to exit
 \param customer; a pointer to the current customer that has been passed in from main
*/
void placeOrder(Customer*);

/*!
 * displays contents of the restaurant menu
*/
void displayMenuItems();


/*!
 * Prompt the user for their loyalty information
 * get each entry
 * Use the customer parameterized constructor to create the customer
 * return the customer
*/
Customer createCustomer();

int getLoyaltyDatabase(Customer*);


void addItemToOrder(int, Customer*);


void calculateChange(Customer*);


int getNumberOfPointsToRedeem(string*, int);



void useLoyalty(Customer*, int, int);

void promptFoodAddOns(Food*);
void selectIngredient(Food*);
void promptDrinkExtras(Drink*);
