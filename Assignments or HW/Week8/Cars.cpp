#include <iostream>

using namespace std;

enum CARS {Car0 = 1, Car1 = 2, Car2 = 4, Car3 = 8, Car4 = 16, Car5 = 32, Car6 = 64, Car7 = 128};
unsigned char* fleet;

void RentCar(char* fleet, CARS c);
void ReturnCar(char* fleet, CARS c);
bool RentalStatus(char* fleet, CARS c);
void ShowFleet();
CARS CarsSelector(int input);
void Menu();

int main(){
    fleet = new unsigned char;
    Menu();
    return 0;
}

/**
 * Picks a car from the fleet to be rented and the car bit is changed to a 1
 * @param fleet: Fleet of car in question
 *        c    : Specific car that is checked
 */
void RentCar(unsigned char* fleet, CARS c){
    (*fleet) |= (unsigned char)(c);
}

/**
 *  Returns a car back to the fleet by resetting the bit that is assigned to the car to zero
 *  @param fleet: Fleet of car in question
 *         c    : Specific car that is checked
 */
void ReturnCar(unsigned char* fleet, CARS c){
    (*fleet) &= (unsigned char)(~c);
}

/**
 *  Checks to see if a specific car in a fleet is rented or available
 * 
 *  @param fleet: Fleet of car in question
 *         c    : Specific car that is checked
 *  @return 1: Car is rented and not available
 *          0: Car is availble to rent
 */
bool RentalStatus(unsigned char* fleet, CARS c){
    return ((*fleet) & (unsigned char) (c));
}

/**
 * Shows the car fleet and it's rental status and outputs it to the console.
 */
void ShowFleet(){
    string rentalStatus;
    string carNum;

    for(int i = 0; i <= 7; i++){
        if(RentalStatus(fleet, CarsSelector(i))){
            rentalStatus = "Rented";
        }
        else{
            rentalStatus = "Available";
        }
        cout << "Car" << i << " Status: " << rentalStatus << endl;
    }
    cout << endl;
}

/**
 *  Recursive menu function that shows the available options.
 */
void Menu(){
    bool isInputInRange, rentCarInputInvalid, returnCarInputInvalid;
    int menuInput, optionInput;
    cout << "==========================\n" <<
            "Please enter your choice: \n" << 
            "0: Exit \n" <<
            "1: Show Fleet\n" <<
            "2: Rent Car\n" <<
            "3: Return Car\n" << endl;
    cin >> menuInput;
    switch(menuInput){
        case 0:
            exit(0);
        case 1:
            ShowFleet();
            break;
        case 2:
            do{
                cout << "[Enter -1 to Exit] Please choose from the following available cars: {";
                for(int i = 0; i <= 7; i++){  
                    if(!(RentalStatus(fleet, CarsSelector(i)))){
                        cout << "Car" << i << ", ";
                    }
                }
                cout << "}: ";

                cin >> optionInput;
                if(optionInput == -1){
                    Menu(); //To exit if no more available cars to rent or changing your mind
                }
                isInputInRange = (0 <= optionInput && optionInput <= 7);

                rentCarInputInvalid = (!isInputInRange) || RentalStatus(fleet, CarsSelector(optionInput));

                if(rentCarInputInvalid){
                    cout << "Sorry, this is not available. PLease enter another option.\n" << endl;
                }
            //Must check first if input is in range or else it will exit
            //If the input is not in range or the car is not available to rent, this will loop.

            } while(rentCarInputInvalid);
            RentCar(fleet, CarsSelector(optionInput));
            break;
        case 3:
            do{
                cout << "[Enter -1 to Exit] Please choose from the following rented cars to return: {";
                for(int i = 0; i <= 7; i++){        
                    if(RentalStatus(fleet, CarsSelector(i))){
                        cout << "Car" << i << ", ";
                    }
                }
                cout << "}:  ";
                cin >> optionInput;
                if(optionInput == -1){
                    Menu(); //To exit if no more rented cars to return or changing your mind
                }
                isInputInRange = (0 <= optionInput && optionInput <= 7);

                returnCarInputInvalid = !((isInputInRange) && RentalStatus(fleet, CarsSelector(optionInput)));
                if(returnCarInputInvalid){
                    cout << "Sorry, this is not available. PLease enter another option.\n" << endl;
                }
            } while(returnCarInputInvalid);
            ReturnCar(fleet, CarsSelector(optionInput));
            break;
        default:
            cout << "\nInvalid input" << endl;
            break;
    }
    Menu();
}

/**
 *  Turns int into CARS enum
 * 
 *  @param input: input in int format
 *  @retturn CARS: Returns CARS enum
 */
CARS CarsSelector(int input){
    switch(input){
        case 0:
            return Car0;
        case 1:
            return Car1;
        case 2:
            return Car2;
        case 3:
            return Car3;
        case 4:
            return Car4;
        case 5:
            return Car5;
        case 6:
            return Car6;
        case 7:
            return Car7; 
    }
    exit(0);
}

