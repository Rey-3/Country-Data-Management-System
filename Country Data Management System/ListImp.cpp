#include "List.h"
#include "Country.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>

List::List() { //initialise all the attributes
    size = 50; //assume that size is 50, can't be change
    length = 0	;
    items = new Country[size];
    MemberName = "";
    StudentID = "";
    StudentEmail = "";
    Balance = 0;
    Checking = 1;
    Element1=0;
    Element2=0; 

}



List::~List() {  //destructor
    delete[] items;
}


void List::add(const Country& country) {  // adding the country to to item 
    if (length < size) {
        items[length] = country;
        toUpper(country.getName(), length); // Capitalize the first letter
        length++; // ading the length
    } 
}


void List::insertfile() const {
    fstream MyFile;
    MyFile.open("Country.txt", ios::out); // output a text file

    if (MyFile.is_open()) {
        MyFile << endl << setw(50) << "Global Size Showdown" << endl << endl;

        if (!MemberName.empty() && !StudentID.empty() && !StudentEmail.empty()) { // if user not register yet, it will not display to user
            MyFile << "Name: " << MemberName << endl
                   << "Student ID: " << StudentID << endl
                   << "Email: " << StudentEmail << endl << endl;
        }

        MyFile << "No" << setw(18) << "Country Name" << setw(18) << "Population"
               << setw(25) << "Area (Square km)\n"
               << "_____________________________________________________________________________\n";

        for (int i = 0; i < length; i++) {  // print out all the country
            MyFile << fixed << setprecision(2);
            MyFile << left << setw(8) << i + 1 << left << setw(20) << items[i].getName()
                   << left << setw(18) << items[i].getPopulation() << items[i].getArea() << endl;
        }

        MyFile << "_____________________________________________________________________________\n";
        MyFile.close();  // close the file
    } else {
        cout << "Input failed \n";
    }
}


void List::printfile() const {
    fstream MyFile;
    MyFile.open("Country.txt", ios::in);  // input the file

    if (MyFile.is_open()) {
        string Line;
        while (getline(MyFile, Line)) {  // print out all the data in Country.txt
            cout << Line << endl;
        }
        MyFile.close();
    }else{
    	cout << "Eror 404..." << endl;
	}
}


void List::selectionSort() {  // Rearrange country list ( Bigger area to smaller area)
    for (int i = 0; i < length - 1; i++) {
        int maxIndex = i;
        
        for (int j = i + 1; j < length; j++) {
            if (items[j].getArea() > items[maxIndex].getArea()) { // if the j is bigger than maxIndex, j will become maxIndex
                maxIndex = j;
            }
        }
        
        if (maxIndex != i) {
            swap(items[i], items[maxIndex]); // After that will swap with i
        }
    }
}


	void List::toUpper(string name, int index) {
	    for (int i = 0; i < name.size(); i++) {
	        name[i] = tolower(name[i]); // Make all letters lowercase
	    }
	
	    if (!name.empty()) {
	        name[0] = toupper(name[0]); // Capitalize the first letter
	    }
	
	    items[index].setName(name); // After conversion, it will replace the previous name
	}


void List::editName(string name,int index){  // edit the name
	items[index].setName(name);
}


void List::editPopulation(int population,int index){  // edit population
	items[index].setPopulation(population);
}


void List::editArea(float area,int index){ //edit area
	items[index].setArea(area);
}


void List::editAll(string name,int population,float area,int index){ //edit all 
	items[index].setName(name);
	items[index].setPopulation(population);
	items[index].setArea(area);
}


void List::displayName() {  // Display the all the country name
    for (int i = 0; i < length; i++) {
        cout << i + 1 << ": " << items[i].getName() << endl;
    }
}


void List::remove(int index) { // remove the country
    for (int i = index; i < length - 1; i++) {
        items[i] = items[i + 1];
    }
    
    length--;
}


void List::wallet(int amount, int select) { // Wallet
    int balance = getBalance(); // get the balance 

    if (select == 1) { // 1 is Top UP
        balance = balance + amount;
        setBalance(balance); 
    } else if (select == 2) { // 2 is Subtract 
        balance = balance - amount;
        if (balance >= 0) {  
            setBalance(balance);
        } else { // if  the balance is nagative
            cout << "Please Top Up" << endl;
            return;
        }
    } else {  // no meaning
        cout << "Don't hack My Money" << endl;
        return;
    }
}


void List::games() {
    srand(time(0)); // random number
    Element1 = (rand() % length);
    Element2 = (rand() % length);
    int Answer;

    while (true) {
        cout << endl << "Enter 0 to Exit." << endl;
        cout << "Who Is Bigger or Same?" << endl
             << "1: " << items[Element1].getName() << endl // getting the name
             << "2: " << items[Element2].getName() << endl
             << "3: " << items[Element1].getName() << " and " << items[Element2].getName() << " have the same size" << endl
             << "Enter: ";

        if (cin >> Answer) {
            if (Answer > 0 && Answer <= 3) {
                if (Answer == 1) {
                    if (items[Element1].isLarge(items[Element2])) { // if user guess correctly
                        cout << "Congratulations. You guessed it!" << endl;
                        wallet(5,1); // reward
                        cout << "You will receive 5 gold cash back" << endl;
                        items[Element1].print();
                        if (Checking == 1) { // this will be display only once
                            cout << "Please Check Your Reward In Menu Page" << endl << endl;
                            ticket(items[Element1].getName(), MemberName); // Generate the ticket
                            Checking = 2; 
                        }
                        break;
                    } else {
                        cout << "Better Next Time... " << endl << endl;
                        break;
                    }
                } else if (Answer == 2) {
                    if (items[Element2].isLarge(items[Element1])) { // if user guess correctly
                        cout << "Congratulations. You guessed it!" << endl;
                        items[Element2].print();
                        wallet(5,1); // reward 
                        cout << "You will receive 5 gold cash back" << endl;
                        if (Checking == 1) { // this will be display only once
                            cout << "Please Check Your Reward In Menu Page" << endl << endl;
                            ticket(items[Element2].getName(), MemberName); // Generate the ticket
                            Checking = 3;
                        }
                        break;
                    } else {
                        cout << "Better Next Time... " << endl << endl;
                        break;
                    }
                } else if (Answer == 3) {
                    if (items[Element1].getArea() == items[Element2].getArea()) { // if user guess correctly
                        cout << "Congratulations. You guessed it!" << endl;
                        wallet(5,1); // reward, no ticket will be given
                        break;  
                    } else {
                        cout << "Better Next Time... " << endl << endl;
                        break;
                    }
                }
            } else if (Answer == 0) { // exit the method 
                cout << "Exit Successfully." << endl << endl;
                wallet(10, 1); // give back user money
                break;
            } else if (Answer < 0) { // the value should be positive 
                cout << "Please Enter a Positive Number" << endl;
            } else {
                cout << "Please Enter a Value Between 1 or 2" << endl;
            }

        } else {
            cout << "Invalid value" << endl;
            cin.clear();  // It's to clear the eror and ensure the input in a valid state to continue reading input.
            cin.ignore(); // Clear the input buffer to handle extraneous characters
        }
    }
}


void List::ticket(string name, string membername) {
    string from = "Malaysia";

    if (from == name) { // to prevent 'from" and 'go" value are same
        from = "SINGAPORE";
    }

    int membernamesize = membername.size();  // its to let the "|" is fix wtih other |
    int fromsize = from.size();
    int namesize = name.size();

    fstream MyFile;
    MyFile.open("FlightTicket.txt", ios::out);
    if (MyFile.is_open()) {
        MyFile << endl << setw(50) << "Global Size Showdown" << endl
               << "_____________________________________________________________________________\n"
               << endl << "Name: " << membername
               << endl << "Student ID: " << getStudentID()
               << endl << "Student Email: " << getStudentEmail() << endl
               << "_____________________________________________________________________________" << endl
               << "| " << "Boarding PASS" << setw(58) << "Air Company" << setw(4) << "|" << endl
               << "_____________________________________________________________________________" <<endl << "|" << setw(76) << "|" << endl
               << "| " << "FLIGHT: ABC123" << setw(30) << "BOARDING TIME: 10:20" << setw(12) << "GATE:15" << setw(13) << "SEAT:11A"
               << setw(6) << "|" << endl << "|" << setw(76) << "|" << endl
               << "| " << "PASSENGER NAME: " << membername << setw(49 - membernamesize) << "CLASS:BUSINESS" << setw(10) << "|" << endl << "|"
               << setw(76) << "|" << endl << "| "
               << "FROM:  " << from << setw(34 - fromsize) << "TO:  " << name << setw(34 - namesize) << "|" << endl << "|"
               << setw(76) << "|" << endl << "| "
               << "DATE: 3/10" << setw(65) << "|" << endl << "|" << setw(76) << "|" << endl << "| "
               << "E-TICKET 230-1387601" << setw(55) << "|" << endl
               << "_____________________________________________________________________________" << endl;

        MyFile.close();
    } else {
        cout << "EROR 404...." << endl;
    }
}


void List::printTicket() {
	
    fstream MyFile;
    MyFile.open("FlightTicket.txt", ios::in); // input the flight ticket text file
    
    if (MyFile.is_open()) {
        string Line;  // input all the data in the file 
        while (getline(MyFile, Line)) {
            cout << Line << endl;
        }
        MyFile.close();
    }
}



void List::setBalance(int balance){  // set balance
	Balance=balance;
}


int List::getBalance()const{ // get balance
	return Balance;
}

int List::getChecking()const{ // get the checking value
	return Checking;
}


	int List::member(int i) {
	    cout << "Enter 0 to Exit." << endl; 
	
	    if (MemberName.empty() && StudentID.empty() && StudentEmail.empty()) {
	        // Check if member details have been input or not
	       
	        while (MemberName.empty()) {
	            // Ensure the user enters a valid value
	            cout << "Please Enter Your Name:";
	            getline(cin, MemberName);
	            
	            if (MemberName.empty()) {
	                // If the user enters an invalid value, prompt them to re-enter
	                cout << "Invalid Value, Please Try Again." << endl;
	            }
	        }
	        
	        if (MemberName == "0") {
	            // If the user wants to exit
	            MemberName = "";
	            i = -1;
	            return i;
	        }
	        
	        while (StudentID.empty()) {
	            // Ensure the user enters a valid value
	            cout << "Please Enter Your Student ID:";
	            getline(cin, StudentID);
	             
	            if (StudentID.empty()) {
	                // If the user enters an invalid value, prompt them to re-enter
	                cout << "Invalid Value, Please Try Again." << endl;
	            }
	        }
	        
	        if (StudentID == "0") {
	            // If the user wants to exit
	            MemberName = "";
	            StudentID = "";
	            i = -1;
	            return i;
	        }
	        
	        while (StudentEmail.empty()) {
	            // Ensure the user enters a valid value
	            cout << "Please Enter Your Student Email:";
	            getline(cin, StudentEmail);
	            
	            if (StudentEmail.empty()) {
	                // If the user enters an invalid value, prompt them to re-enter
	                cout << "Invalid Value, Please Try Again." << endl;
	            }
	        }
	        
	        if (StudentEmail == "0") {
	            // If the user wants to exit
	            MemberName = "";
	            StudentID = "";
	            StudentEmail = "";
	            i = -1;
	            return i;
	        }
	
	        i = 2;
	        return i;
	
	    } else { // If the user wants to re-enter the data
	        string Choice;
	        string index1 = MemberName;
	        string index2 = StudentID;
	        string index3 = StudentEmail;
	
	        cout << "You are already logged in" << endl;
	
	        while (true) {
	            cout << "Do you want to change it? [Yes/No]: ";
	            cin >> Choice;
	            cin.ignore();
	
	            for (int i = 0; i < Choice.size(); i++) {
	                Choice[i] = tolower(Choice[i]); 
	            }
	            Choice[0] = toupper(Choice[0]); // Capitalize the first letter
	
	            if (Choice == "Yes") {
	                while (true) {
	                    // Ensure the user enters a valid value
	                    cout << "Please Enter Your Name:";
	                    getline(cin, MemberName);
	                    
	                    if (MemberName.empty()) {
	                        // If the user enters an invalid value, prompt them to re-enter
	                        cout << "Invalid Value, Please Try Again." << endl;
	                    } else {
	                        break;
	                    }
	                }
	                
	                if (MemberName == "0") {
	                    // If the user wants to exit
	                    MemberName = index1;
	                    i = -1;
	                    return i;
	                }
	                
	                while (true) {
	                    // Ensure the user enters a valid value
	                    cout << "Please Enter Student ID:";
	                    getline(cin, StudentID);
	                    
	                    if (StudentID.empty()) {
	                        // If the user enters an invalid value, prompt them to re-enter
	                        cout << "Invalid Value, Please Try Again." << endl;
	                    } else {
	                        break;
	                    }
	                }
	
	                if (StudentID == "0") {
	                    // If the user wants to exit
	                    MemberName = index1;
	                    StudentID = index2;
	                    i = -1;
	                    return i;
	                }
	
	                while (true) {
	                    // Ensure the user enters a valid value
	                    cout << "Please Enter Student Email:";
	                    getline(cin, StudentEmail);
	                    
	                    if (StudentEmail.empty()) {
	                        // If the user enters an invalid value, prompt them to re-enter
	                        cout << "Invalid Value, Please Try Again." << endl;
	                    } else {
	                        break;
	                    }
	                }
	
	                if (StudentEmail == "0") {
	                    // If the user wants to exit
	                    MemberName = index1;
	                    StudentID = index2;
	                    StudentEmail = index3;
	                    i = -1;
	                    return i;
	                }
	
	                if (Checking == 2) {  
	                    ticket(items[Element1].getName(), MemberName);
	                    return i;
	                } else if (Checking == 3) {
	                    ticket(items[Element2].getName(), MemberName);
	                    return i;
	                } else {
	                    return i;
	                }
	
	            } else if (Choice == "No") {
	                i = 3;
	                return i;
	            } else {
	                cout << "Invalid Value, Reenter Again" << endl << endl;
	            }
	        }
	    }
	}



int List::check(string name) {  // check method
    for (int i = 0; i < length; i++) {
        if (items[i].getName() == name) {
            return i; 
        }
    }
    return -1; 
}


string List::specificname(int i){ // get the specific name
    return items[i-1].getName();
}


string List::getMemberName()const{ // get the member name
	return MemberName;
}


string List::getStudentID()const{ // get the student id 
	return StudentID;
}


string List::getStudentEmail()const{ // get student email
	return StudentEmail;
}


bool List::isEmpty(){  // check is empty or not
	return MemberName != "";
}
