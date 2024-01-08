#include "./helperFunctions.h"

void calculateChange(Customer* currentCustomer){
    float customerMoney = 0;
    do{
        if(currentCustomer->calculateCost()  != 0){
            cout << endl << endl << "Please enter the amount you'd like to pay with: $";
            cin >> customerMoney;
            if(customerMoney < currentCustomer->calculateCost()){
                cout << "Insufficient Funds, Trying Again..." << endl;
            }
            else{
                
                cout << "Your change today is: $" << std::fixed <<setprecision(2) <<customerMoney - currentCustomer->calculateCost() << endl;
            }
        }
    }while(customerMoney < currentCustomer->calculateCost());
}

char getUserCharChoice(){
    char tempChar;
    cin >> tempChar;
    return tempChar;
}

int getUserIntChoice(){
    int tempInt;
    cin >> tempInt;
    return tempInt;
}

string getUserStringEntry(){
    string tempString;
    cin >> tempString;
    return tempString;
}

Customer createCustomer(){
    displayLoyaltyInformationPrompt();
    int loyaltyNum = getUserIntChoice();
    string first = getUserStringEntry();
    string last = getUserStringEntry();

    Customer newMember( first, last, loyaltyNum, 50);
    return newMember;
}

void displayLoyaltyInformationPrompt(){
    cout << "Enrolling in the Meat Man Mob Loyalty Program is simple!" << endl;
    cout << "Just enter your 7 digit phone number without any dashes and your first and last name!" << endl;
    cout << "For example: 1111111 Pete Wentz" << endl << endl;
}

void displayPointRedemptionMenu(){
    cout << "1.) Sandwich, 450 pts" << endl;
    cout << "2.) 32 oz. Drink, 50 pts" << endl;
    cout << "3.) Meat Man Meal, 500 pts" << endl;
    cout << "4.) Small Tater Tot, 75 pts" << endl;
}

void displayMemberJoin(){
    cout << endl << endl<<"Don't have a loyalty number?" << endl;
    cout << "Join today and earn a free large drink!" << endl;
    cout << "Being a member of the Meat Man Mob Loyalty Program provides the following benefits: " << endl;
    displayPointRedemptionMenu();
    cout << endl<< "Would you like to join the Meat Man Mob Loyalty Program?(y/n) ";
}

int runLoyaltyProgram(Customer* customers, int* numCustomers){
    cout <<endl << endl<< "Welcome to Meaty Meat Man's Market!" << endl;
    cout << endl << "Are you a member of the Meat Man Mob Loyalty Program? (y/n), or choose e to exit";
    char loyal = getUserCharChoice();
    char userChoice = '.';
    if(loyal == 'e' || loyal == 'E'){
        return -2;
    }

    do{
        if (loyal == 'y' || loyal == 'Y'){
            cout << endl<<"Please enter your loyalty number: ";
            int loyaltyNumber = getUserIntChoice();
            for(int i = 0; i < *numCustomers; i++){
                if(customers[i].getLoyaltyNumber() == loyaltyNumber){
                    customers[i].displayCustomerInformation();
                    return i;
                }
            }
            loyal = 'N';
        }
        if(loyal == 'N' || loyal == 'n'){
            char join;
            do{
                displayMemberJoin();
                join = getUserCharChoice();
            }while(join != 'y' && join != 'Y' && join != 'n' && join != 'N');
            if(join != 'y' && join != 'Y'){        
                return -1;
            }
            if(join == 'Y' || join == 'y'){
                Customer newMember = createCustomer();
                customers[*(numCustomers)] = newMember;
                *numCustomers += 1;
                newMember.displayCustomerInformation();
                return *(numCustomers)-1;
            }

            
        }
    }while(loyal != 'y' || loyal != 'Y' || loyal != 'n' || loyal != 'N');

    return -1;
}

int getLoyaltyDatabase(Customer* loyaltyCustomers){
    string firstName, lastName;
    long int loyaltyNumber, numberPoints;
    int numCustomers = 0;
    string space = " ";
    ifstream loyaltyMemberStream("loyalty.txt"); 
    if ( loyaltyMemberStream.is_open() ) { 
        while(loyaltyMemberStream.good()){
            loyaltyMemberStream >> loyaltyNumber >> firstName >> lastName >> numberPoints;
            Customer newCustomer(firstName, lastName, loyaltyNumber, numberPoints);
            loyaltyCustomers[numCustomers] = newCustomer;
            numCustomers++;
        }
    }
    return numCustomers;
}
void overwriteLoyaltyDatabase(Customer* customers, int numCustomers){
    ofstream loyaltyMemberStream("loyalty.txt"); 
    for(int i = 0; i < numCustomers; i++){
        loyaltyMemberStream << customers[i].getLoyaltyNumber() << " " << customers[i].getCustomerFirst() << " " << customers[i].getCustomerLast() << " " << customers[i].getNumberLoyaltyPoints();
        if(i!= numCustomers -1){
            loyaltyMemberStream << endl;
        }
    }
}

void displayMenuItems(){
    cout << endl<< "=====Meaty Meat Man's Restaurant Menu===== " << endl;
    cout << "1.) Smoked Meat Sandwich" << endl;
    cout << "2.) Meaty Meat Man Meal" << endl;
    cout << "3.) Fountain Drink" <<endl;
    cout << "4.) Tater Tots" << endl; 
    cout << "0.) Finish Order" << endl;
    cout <<endl<< "Please Enter a Value [0-4]: ";
}

void addItemToOrder(int numObject, Customer* currentCustomer){
   Drink* newDrink;
   Food* newFood;
    switch(numObject){
        case 0: 
        {
            break;
        }
        case 1:
        {
            newFood = new Food();
            
            newFood->setCost(12.99);
            newFood->addIngredient("Smoked Meat");
            newFood->addIngredient("White Bread");
            newFood->addIngredient("Mustard");
            newFood->addIngredient("Swiss Cheese");
            newFood->setItemName("Smoked Meat Sandwich");
            newFood->setPointWorth(450);
            promptFoodAddOns(newFood);
            currentCustomer->addItemToOrder(newFood);
            delete newFood;
            break;
        }
        case 2: {
            newFood = new Food();
            
            newFood->setCost(15.99);
            newFood->addIngredient("Smoked Meat");
            newFood->addIngredient("Toast");
            newFood->addIngredient("Potatoes");
            newFood->addIngredient("BBQ Sauce");
            newFood->addIngredient("Broccoli");
            newFood->setItemName("Meaty Meat Man Meal");
            newFood->setPointWorth(500);
            promptFoodAddOns(newFood);
            currentCustomer->addItemToOrder(newFood);
            delete newFood;
            break;
        }
        case 3: 
        {
            newDrink = new Drink();
            
            newDrink->setCost(2.99);
            newDrink->setNeedsIce(true);
            newDrink->setItemName("Fountain Drink");
            newDrink->setNeedsStraw(false);
            newDrink->setSize(16);
            newDrink->setPointWorth(50);
            promptDrinkExtras(newDrink);
            currentCustomer->addItemToOrder(newDrink);
            delete newDrink;
            break;
        }
        case 4:
        {
            newFood = new Food();
           
            newFood->setCost(3.99);
            newFood->addIngredient("Potatos");
            newFood->addIngredient("Ranch Dressing");
            newFood->setItemName("Tater Tots");
            newFood->setPointWorth(75);
            promptFoodAddOns(newFood);
            currentCustomer->addItemToOrder(newFood);
            delete newFood;
            break;
        }
        default:
        {
            cout << "Invalid option entered. Please enter a value [0-4]" << endl;
            break;
        }
    }

}

void placeOrder(Customer* currentCustomer){
    int menuItem = -1;
    do{
        displayMenuItems();
        menuItem = getUserIntChoice();
        addItemToOrder(menuItem, currentCustomer);
        
    }while(menuItem != 0);

}

bool pointSystemPrompt(Customer* customer){
    char useLoyalty;
    int availablePts = customer->getNumberLoyaltyPoints();
    if(availablePts >= 50){
        do{
            cout << endl << "Would you like to use any of your " <<availablePts<< " Loyalty Points (y/n)? ";
            int temp;
            cin >> useLoyalty;
        }while(useLoyalty != 'y' && useLoyalty != 'Y' && useLoyalty != 'n' && useLoyalty != 'N');
        if((useLoyalty == 'N' || useLoyalty == 'n') ){
            cout << "Cool, we'll bank those points for later!" <<endl;
            return false;
        }
        return true;
    }
    else{
        return false;
    }
}
void useLoyalty(Customer* customer, int numCustomers, int availablePts){
    int userOption, numPts;
    string foodName; 

    do{
        displayPointRedemptionMenu();
        cout << "0.) I've changed my mind!" << endl;
        cout << endl<< "Which offer would you like to redeem? [0-4] ";
        userOption = getUserIntChoice();
        numPts = getNumberOfPointsToRedeem(&foodName, userOption);
        
        bool found = false;
        for( int i=0; i < customer->getNumItemsInOrder(); i++){

            if(customer->getCurrentOrder()[i]->getItemName() == foodName){
                found = true;
                if(numPts <= availablePts){
                    availablePts -= numPts;
                    int ptsToAdd = customer->calculateCost();
                    availablePts+=ptsToAdd;
                    customer->getCurrentOrder()[i]->setCost(0);
                    customer->setNumberLoyaltyPoints(availablePts);
                }
                else{
                    cout << endl<< "Insufficient number of points! Try again another time :) " << endl << endl;


                }
            }
        }
        
        if(!found){
            cout <<endl << "Sorry you didn't order that! Try again another time :)" << endl << endl;
            userOption = -1;
        }

    } while((userOption < 0 || userOption >4));
}

int getNumberOfPointsToRedeem(string* foodName, int userOption){
    int numPts;
    switch(userOption){
        case 1:
            *foodName = "Smoked Meat Sandwich";
            numPts = 450;
            break;
        case 2:
            *foodName = "Fountain Drink";
            numPts = 50;
            break;
        case 3:
            *foodName = "Meaty Meat Man Meal";
            numPts = 500;
            break;
        case 4:
            *foodName = "Tater Tots";
            numPts = 75;
            break;
        case 0:
            break;
    }
    return numPts;
}


void promptFoodAddOns(Food* currentOrder){
    char userChoice;
    cout << "Would you like to add any additioinal ingredients? (y/n): ";
    cin >> userChoice;
    if(userChoice == 'y' || userChoice == 'Y'){
    //cout << "\nWhat would you like to add? ";
    selectIngredient(currentOrder);

    }
    
}

void selectIngredient(Food* currentOrder){
    
    //currentCustomer->getAvailableExtras();
    int userChoiceA;
    int userChoiceB;
    int stop;
    cout << "AVAILABLE ADD ONS\n\n";
    //currentOrder->setAvailableExtras();
    userChoiceB = 99;

    currentOrder->setAvailableExtras();
    stop = currentOrder->getNumExtras();
    while(userChoiceB != stop + 1){
       
    for(int i = 0; i < stop; i++){
       //problem with display right here
       //cout<< stop;
      // cout<< "hiiiii" << endl;
        cout << i+1  << ". " << currentOrder->getAvailableExtras()[i] << endl;
        //cout << stop << endl;
        // cout << currentOrder->getNumExtras() +1 << ". " << "Done adding" << endl;

        
    }
    cout << currentOrder->getNumExtras() +1 << ". " << "Done adding" << endl;

    cout << "\nWhat would you like to add? ";
    cin >> userChoiceB;
    if(currentOrder->getAvailableExtras()[userChoiceB]== "" ){
        //6 is null
        //i have to properly allocate the memory for this part to move on from gettting a segmentaion fault
       // cout << "error" << endl;
        
    }
     
    currentOrder->setAvailableExtras();
    
    string choice = currentOrder->getAvailableExtras()[userChoiceB];
    //cout << choice << "sc=uck it" << endl;
    currentOrder->addIngredient(choice);

    currentOrder-> calculateMenuItemCost();
    
    }


}

void promptDrinkExtras(Drink* currentOrder){
    //int userChoiceC;
    char strawChoice;
    char iceChoice;
    int size;

    // cout << "Please Enter a Value [0-4]: " << endl;
    cout << "What size? (16, 20, 32) oz: ";
    cin >> size;
    currentOrder->setSize(size);
    // currentOrder->calculateMenuItemCost();
    cout << "Would you like a straw? (y/n): ";
    cin >> strawChoice;

    if (strawChoice == 'y' || strawChoice == 'Y'){
        currentOrder->setNeedsStraw(true);
    }


    else if(strawChoice == 'n' || strawChoice == 'N'){  
        currentOrder->setNeedsStraw(false);
    }

     cout << "Would you like ice? (y/n): ";
    cin >> iceChoice;
    if(iceChoice == 'y' || iceChoice == 'Y'){
        currentOrder-> setNeedsIce(true);
    }
    else if(iceChoice == 'n' || iceChoice == 'N'){

        currentOrder-> setNeedsIce(false);
    }

    currentOrder->calculateMenuItemCost();









}






