// *****************************************************************************************************************************
// This program serves as a country data management system. It allows users to input and store details about various countries,
// including their names, populations, and areas. The core components of the program include two classes: Country and List.    
//
// Country Class:
// This class represents an individual country's data. It has attributes for storing the country's name, population, and area.
// Methods are provided to set and retrieve these attributes, calculate population density, and print country details.
//
// List Class:
// The List class manages a collection of Country objects. It maintains an array to store multiple country records.
// Functions are implemented to add, edit, remove, and display country data. The class includes features such as a guessing game
// and ticket generation for user engagement.
// *******************************************************************************************************************************
// Chew Zhi Boon Assignment 7 oct 2023
#include <iostream>
#include <string>
#include <iomanip>
#include "List.h"
using namespace std;

struct Class {
    string Name="";
    int Population=0;
    int length=0;
    double Area=0;
    List Details;
};
// The Struct attributes is reusable.

void toUpper(string);  // To Make letters uppercase
void switchMethod(int); //Switch Method
void editCountry(int,int); // To edit County
bool enterName(); // To enter name
bool enterPopulation(); // To enter Population
bool EnterArea() ; // To enter Area
void editCountryMethod(); // Have a list for the user to select what they want to edit
void gameMethod(); // A game method
void topupmethod(); // To topup money in the game
void startgame(); // starting the game

struct Class Member; // Programmer can call Member function in anywhere

int main(int argc, char** argv) {
    int Option;

    Member.Details.add(Country("China", 1444216107, 9596960));
    Member.Details.add(Country("India", 1393409038, 3287263));
    Member.Details.add(Country("Malaysia", 32365999, 330803));
    Member.length +=3;
    //Member.length+=50;
    
/*   Feel Free to use it
Member.Details.add(Country("United States", 331002651, 9372610));
Member.Details.add(Country("Indonesia", 273523615, 1910931));
Member.Details.add(Country("Pakistan", 220892340, 881913));
Member.Details.add(Country("Brazil", 212559417, 8515767));
Member.Details.add(Country("Nigeria", 206139589, 923768));
Member.Details.add(Country("Bangladesh", 164689383, 147570));
Member.Details.add(Country("Russia", 145912025, 17098246));
Member.Details.add(Country("Mexico", 128932753, 1964375));
Member.Details.add(Country("Japan", 126476461, 377975));
Member.Details.add(Country("Ethiopia", 114963588, 1104300));
Member.Details.add(Country("Philippines", 113862611, 300000));
Member.Details.add(Country("Egypt", 102334404, 1002450));
Member.Details.add(Country("Vietnam", 97338579, 331212));
Member.Details.add(Country("DR Congo", 89561404, 2344858));
Member.Details.add(Country("Turkey", 84339067, 783562));
Member.Details.add(Country("Iran", 83992949, 1648195));
Member.Details.add(Country("Germany", 83783942, 357022));
Member.Details.add(Country("Thailand", 69799978, 513120));
Member.Details.add(Country("United Kingdom", 67886011, 242495));
Member.Details.add(Country("France", 65273511, 551695));
Member.Details.add(Country("Italy", 60461826, 301340));
Member.Details.add(Country("South Africa", 59308690, 1220813));
Member.Details.add(Country("Myanmar", 54409800, 676578));
Member.Details.add(Country("Kenya", 53771296, 580367));
Member.Details.add(Country("South Korea", 51269185, 100210));
Member.Details.add(Country("Colombia", 50882891, 1141748));
Member.Details.add(Country("Spain", 46754778, 505990));
Member.Details.add(Country("Ukraine", 43733762, 603500));
Member.Details.add(Country("Tanzania", 59734218, 947303));
Member.Details.add(Country("Argentina", 45195777, 2780400));
Member.Details.add(Country("Poland", 37846611, 312696));
Member.Details.add(Country("Uganda", 45741007, 241038));
Member.Details.add(Country("Algeria", 43851044, 2381741));
Member.Details.add(Country("Sudan", 43849260, 1861484));
Member.Details.add(Country("Morocco", 36910560, 446550));
Member.Details.add(Country("Iraq", 40222493, 438317));
Member.Details.add(Country("Uzbekistan", 33469203, 448978));
Member.Details.add(Country("Saudi Arabia", 34813871, 2149690));
Member.Details.add(Country("Peru", 32971854, 1285216));
Member.Details.add(Country("Venezuela", 28435943, 916445));
Member.Details.add(Country("Ghana", 31072940, 238535));
Member.Details.add(Country("Mozambique", 31255435, 801590));
Member.Details.add(Country("Nepal", 29136808, 147516));
Member.Details.add(Country("Yemen", 29825968, 527968));
Member.Details.add(Country("Cameroon", 26545863, 475442));
Member.Details.add(Country("C?te d'Ivoire", 26378274, 322463));
Member.Details.add(Country("Madagascar", 27691018, 587041));
Member.Details.add(Country("Australia", 25499884, 7692024));
*/

    while (true) { // An infinite Loop
    
        cout << endl << setw(50) << "Global Size Showdown" << endl  // Menu pages
             << "_____________________________________________________________________________\n";
        cout << endl << "1-> Registrations" << endl
             << "2-> Insert Country Details" << endl
             << "3-> Edit Country" << endl
             << "4-> Delete Country" << endl
             << "5-> Games" << endl
             << "6-> Reward" << endl
             << "7-> Print" << endl
             << "8-> Exit" << endl
             << "Enter:";              

        
		if (cin >> Option) {       // Ask user to enter 
            cin.ignore();         // Clear the input buffer to handle extraneous characters
            
			if (Option >= 1 && Option <= 8) {  //The value entered by the user must be greater than 0 and less than or equal to 8
                switchMethod(Option); // If the condition is true, it will take the user to the selected page
            } else {
                cout << "Please Enter The Value Between 1 To 8" << endl; // else will return eror and ask user to enter again
            }
        } else {      // If user want to be funny enter invalid value, it will also show eror message
            cout << "Invalid Value, Please Enter Integer number." << endl; 
            cin.clear(); // It's to clear the eror and ensure the input in a valid state to continue reading input.
            cin.ignore(); // Clear the input buffer to handle extraneous characters
        }
    }

    return 0;
}


void toUpper(string name) {
    for (int i = 0; i < name.length(); i++) {
        name[i] = tolower(name[i]);  // Make all letters lowercase
    }

    if (!name.empty()) {
        name[0] = toupper(name[0]); // Capitalize the first letter
    }

    Member.Name = name; // After conversion, it stored in member.name
}

void switchMethod(int Option) {
    int Edit = 0;
    int Select = 0;

    switch (Option) {
        case 1: { // Option 1 is Register page
            int index = 1;
            index = Member.Details.member(index);

            if (index == 2) { // if return value is 2
                cout << "Your Registration has been successful" << endl;
            
			} else if (index == 1) { // if return value is 1
                cout << "Your Registration Update Successfully" << endl;
            
			} else if (index == 3) {// if return value is 3
                cout << "Thank You" << endl;
            
			} else { //If return value equal 1, 2 or 3
                cout << "Exit Successfully." << endl;
            }
            break; //exit the switch
        }

        case 2: {
            if (Member.length < 49) { // If length more than 49 it will show it's full
                bool Check = true;
                cout << "Enter 0 to Exit." << endl;
                Check = enterName(); // Enter name method
                if (!Check) { // if check is false will exit 
                    cout << "Exit Successfully" << endl;
                    break;
                }

                Check = enterPopulation(); // Enter Population method
                if (!Check) { // if check is false will exit 
                    cout << "Exit Successfully" << endl;
                    break;
                }

                Check = EnterArea();// Enter area method
                if (!Check) {   // if check is false will exit 
                    cout << "Exit Successfully" << endl;
                    break;
                }

                Member.Details.add(Country(Member.Name, Member.Population, Member.Area)); // Insert the value to the method
                Member.length++; //The length will be increased by 1 each time
                Member.Name = ""; 
                Member.Population = 0;
                Member.Area = 0;  // After finish insert, it will initialise all the attributes in Member

                cout << "Country Entered Successfully." << endl;
                break; // exit the switch
            } else {
                cout << "The Country List Is Full." << endl;
            }
            break; // exit the switch
        }

        case 3: {
            if (Member.length != 0) { // If no Country in the program it will return eror message
                cout << endl << "Enter 0 to Exit." << endl; // Tell the user can enter 0 to exit
                editCountryMethod(); // Enter the Method
            } else {
                cout << "Country List is Empty" << endl;
            }
            break; // exit the switch
        }

        case 4: {
            if (Member.length != 0) { // If no Country in the program it will return eror message
                while (Edit < 1 || Edit > Member.length + 1) {
                	
					cout << endl << "Enter 0 to Exit." << endl; // Tell the user can enter 0 to exit
                    cout << "Select The Country You Want To Delete." << endl; 
                    Member.Details.displayName(); // Display the country list
                    
					cout << "Enter:";
                    if (cin >> Edit) { 
                        cin.ignore(); // Clear the input buffer to handle extraneous characters
                       
					    if (Edit > 0 && Edit <= Member.length + 1) { // if user enter the valid value
                            cout << Member.Details.specificname(Edit) << " have been Remove." << endl; // tell user selected country have been remove
                            Member.Details.remove(Edit - 1); //remove the country method
                            Member.length--; // minus the length
                            break; // exit the switch
                        } else if (Edit == 0) { // if user want to exit
                            break;
                        
						} else if (Edit < 0) { // Ask user to enter positive number
                            cout << "Please Enter Positive value" << endl;
                        
						} else { // Ask user enter the number in a range
                            cout << "Please Enter between 1 to " << Member.length + 1 << endl;
                        
						}
                    } else {
                        cout << "Please enter an integer value" << endl;
                        cin.clear();  // It's to clear the eror and ensure the input in a valid state to continue reading input.
                        cin.ignore(); // Clear the input buffer to handle extraneous characters
                    }
                }
            } else { // If Country List is empty
                cout << "Country List is Empty" << endl;
                break;
            }

            if (Edit == 0) { // when user enter 0
                cout << "Exit Successfully." << endl << endl;
                break;
            }
            break; // exit the switch
        }

        case 5: {
            bool valid = Member.Details.isEmpty(); // Check if registered
            if (valid) {
                if (Member.length != 0) { // Check country list is empty or not 
                    gameMethod(); // Enter the game
                } else {
                    cout << "Country List is Empty" << endl;
                    break;
                }
            } else { //eror message
                cout << "Account not found. Please sign up to continue." << endl;
            }
            break; //exit the swtich
        }

        case 6: {
            int Check = Member.Details.getChecking(); // check user got reward or not

            if (Check == 2 || Check == 3) {  
                Member.Details.printTicket();
            } else {
                cout << "You Have No Reward yet." << endl; // eror message
            }
            break; // exit the switch
        }

        case 7: {
            if (Member.length != 0) {  // Check country list is empty or not 
                Member.Details.selectionSort();
                Member.Details.insertfile();
                Member.Details.printfile(); // Enter All the method
                break; // exit
            } else { // eror message
                cout << "Country List is Empty" << endl;
            }
            break; // exit the switch
        }

        case 8: {
            exit(0); // exit the programe
        }
    }
}


void editCountry(int select, int Edit) {
    int index = 1;
    bool Check=true;
    
	switch (select) {
        case 1: {
            
        	    Check=enterName(); 
				if(!Check){ // If the user enters 0 it will exit the input
					cout << "Exit Successfully" << endl;
					break;
					
				}
		    
		    // Let the user know that the edit was successful
            cout << Member.Details.specificname(Edit) << " Edited to " << Member.Name << " Successfully." << endl << endl;
			Member.Details.editName(Member.Name, Edit - 1); // edit the name
            Member.Name = ""; // Initialise attribute
            break;
        }

        case 2: {
            Check=enterPopulation();
        	    if(!Check){ //If the user enters 0 it will exit the input
					cout << "Exit Successfully" << endl;
					break;
				}
				
			// Let the user know that the edit was successful
			cout << Member.Details.specificname(Edit) << " Population has been change to "<< Member.Population 
			     << " Successfully." << endl << endl;
            Member.Details.editPopulation(Member.Population, Edit - 1); // edit the Population
            Member.Population = 0; // Initialise attribute
            break;
        }

        case 3: {
            Check=EnterArea();
            
			if(!Check){ //If the user enters 0 it will exit the input
					cout << "Exit Successfully" << endl;
					break;
				}
            
            // Let the user know that the edit was successful
            cout << Member.Details.specificname(Edit) << " Area (Square km) has been change to "<< Member.Area 
			     << " Successfully." << endl << endl;
            Member.Details.editArea(Member.Area, Edit - 1); // edit the Area
            Member.Area = 0; // Initialise attribute
            break;
        }

        case 4: {
            Check = enterName();
            if (!Check) { //If the user enters 0 it will exit the input
                cout << "Exit Successfully" << endl;
                break;
            }
            
            Check = enterPopulation();
            if (!Check) { //If the user enters 0 it will exit the input
                cout << "Exit Successfully" << endl;
                break;
            }
            
            Check = EnterArea();
            if (!Check) { //If the user enters 0 it will exit the input
                cout << "Exit Successfully" << endl;
                break;
            }

            Member.Details.editAll(Member.Name,Member.Population,Member.Area,Edit-1); // edit the Country
            Member.Name = "";      // Initialise attribute
            Member.Population = 0;
            Member.Area = 0;
            cout << "Country Edited Successfully." << endl << endl; // Let the user know that the edit was successful
            break; //exit the switch
        }

        default: {
            cout << "Error 404....." << endl; // eror message
            break;
        }
    }
}

bool enterName() {
    int index = 0;
    while (index != -1) {  //if index is -1 will exit
        
	while(true){
		cout << "Please Enter Country Name:"; 
		getline(cin, Member.Name);
		
		if(Member.Name.empty()){
			cout << "Invalid Value, Please Try Again." << endl;
		}else{
			break;
		}
	}
		
    if (Member.Name != "0") {  // if user not enter 0 
        toUpper(Member.Name);  // Capitalize the first letter
        index = (Member.Details.check(Member.Name)); // After that, check the name is same with other or not
        if (index != -1) {  // if yes, it will tell user the name is exist
            cout << Member.Name << " is Exist." << endl;
    }
        } else {
            return false;
        }
    }
    return true; // if user enter the valid data
}


bool enterPopulation() {
    while (Member.Population < 1) { 
        cout << "Please Enter Country Population:";
        if (cin >> Member.Population) {
            if (Member.Population == 0) { // when user want to exit
                return false;
            } else if (Member.Population < 1) {  // when user enter negative value
                cout << "Please Enter Positive Value" << endl;
            } else if (Member.Population < 100) { // no meaning 
                cout << "This Country Population Quite More!" << endl << endl;
            }
        } else {
            cout << "Please enter an integer value" << endl; // if user try to be funny 
            cin.clear(); // It's to clear the eror and ensure the input in a valid state to continue reading input.
            cin.ignore();  // Clear the input buffer to handle extraneous characters
        }
    }
    return true; 
}


bool EnterArea() {
    while (Member.Area < 1) {
        cout << "Please Enter Country Area:";
        if (cin >> Member.Area) {
            if (Member.Area == 0) { // if user wan to exit 
                return false;
            } else if (Member.Area < 1) { // if user enter negative value
                cout << "Please Enter a Positive Number" << endl;
            } else if (Member.Area < 100 && Member.Population < 100) { // no meaning 
                cout << "Stronger Country!!!" << endl;
            } else if (Member.Area < 100) {  // no meaning
                cout << "Bigger Country In the World!" << endl;
            }
        } else {
            cout << "Please enter an integer value" << endl;
            cin.clear();  // It's to clear the eror and ensure the input in a valid state to continue reading input.
            cin.ignore(); // Clear the input buffer to handle extraneous characters
        }
    }
    return true; 
}
   
void editCountryMethod() {
    int Edit = 0;
    int Select = 0;

    while (true) {
        cout << "Please Select The Country You Want To Edit." << endl;
		Member.Details.displayName(); // it will display the list of the country
		cout << "Enter:";

        if (cin >> Edit) {
            if (Edit > 0 && Edit <= Member.length) {
                cout << endl;
                cout << "1 -> Edit " << Member.Details.specificname(Edit) << " Name" << endl
                     << "2 -> Edit " << Member.Details.specificname(Edit) << " Population" << endl
                     << "3 -> Edit " << Member.Details.specificname(Edit) << " Area" << endl
                     << "4 -> All on Above" << endl;


                while (true) {
                    cout << "Enter:";

                    if (cin >> Select) {
                        cin.ignore();  // Clear the input buffer to handle extraneous characters

                        if (Select > 0 && Select <= 4) {
                            editCountry(Select, Edit); // Enter the method 
                            break;
                        } else if (Select == 0) {  // if user want to exit
                            cout << "Exit Successfully." << endl << endl;
                            break;
                        } else { // Ask user to enter valid data
                            cout << "Please Enter The Value Between 1 to 4" << endl;
                        }
                    } else {
                        cout << "Please Enter Integer Value" << endl;
                        cin.clear();  // It's to clear the eror and ensure the input in a valid state to continue reading input.
                        cin.ignore(); // Clear the input buffer to handle extraneous characters
                    }
                }
                break;
            } else if (Edit == 0) { //will be exit if user enter 0
                cout << "Exit Successfully." << endl << endl;
                break;
            } else if (Edit < 1) {  // it will display if user enter negative number
                cout << "Please Enter Positive Number." << endl;
            } else {
                cout << "Please Enter The Value Between 1 to " << Member.length << endl;
            }
        } else {
            cout << "Please enter integer value" << endl;
            cin.clear();  // It's to clear the eror and ensure the input in a valid state to continue reading input.
            cin.ignore(); // Clear the input buffer to handle extraneous characters
        }
    }
}

void gameMethod(){
	int Option=0;

	while(true){	// infinite loop
	cout << endl;
	cout << setw(50) << "Guess the Giant" << endl
	     << "_____________________________________________________________________________\n" << endl;
    
	cout << "Your Wallet Balance: " << Member.Details.getBalance() << endl << endl; // To get the wallet amount
	
		cout << "1-> Top Up" << endl
	         << "2-> Start The Game (10 gold/Round)" << endl
	         << "3-> Exit" << endl
	         << "Enter:";  // menu page
	         
	    if(cin >> Option){
	    	cout << endl;
	    	if(Option > 0 && Option <= 3){ // check user got enter valid data or not
	    		if(Option == 1){
	    			topupmethod(); // Top up method
				}else if (Option == 2){
					startgame(); // Starting the game
				}else{ //exit the game
					cout << "Exit Successfully." << endl << endl;
					break;
				}
			}else{
				cout << "Please Enter The Value Between 1 to 3" << endl;
			}
		}else{
			cout << "Please Enter an Integer Value" << endl; // if user want to be funny 
            cin.clear();  // It's to clear the eror and ensure the input in a valid state to continue reading input.
            cin.ignore(); // Clear the input buffer to handle extraneous characters
		}
	}
}

void topupmethod(){
	int TopUp=0;
	
	while(true){
		cout << "Please Enter The Amount You Want To Top Up:";
		
		if(cin >> TopUp){
			if(TopUp == 0){
				cout << "Exit Successfully." << endl;
				return;
			}else if(TopUp >0){
				Member.Details.wallet(TopUp,1); // enter the topup method
			    cout << "$ "<< TopUp << " has been added to your wallet." << endl << endl; // tell user the top up is success
			    break;
			}else{ // must be positive number
				cout << "The Enter the Positive value" << endl;
			}
			
		}else{
			cout << "Please Enter an Integer Value" << endl;
            cin.clear();  // It's to clear the eror and ensure the input in a valid state to continue reading input.
            cin.ignore(); // Clear the input buffer to handle extraneous characters
		}
	}
}

void startgame(){
	if(Member.Details.getBalance() >= 10){ // check user wallet got money or not
		Member.Details.wallet(10,2); // Subtract wallet amount
		Member.Details.games(); // enter game
		
	}else{
		cout << "Your wallet is less than 10 gold. Please Top Up and Try Again." << endl;
		return;
	}
	
	
}



