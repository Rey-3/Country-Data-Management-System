#ifndef LIST_H
#define LIST_H

#include "Country.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class List :public Country{
	private:
		Country* items;
        int size;                           
        int length;
        int Balance;
        int Checking;
        int Element1;
        int Element2;
        string MemberName ;
        string StudentID;
        string StudentEmail;
 
    public:
        List();
        ~List();
        void add(const Country& country);
        void insertfile() const;
        void printfile() const;
        void selectionSort();
        void toUpper(string,int);
        void editName(string,int);
        void editPopulation(int,int);
        void editArea(float,int);
        void editAll(string,int,float,int);
        void displayName();
        void remove(int );
        void wallet(int,int);
        void games();
        void ticket(string,string);
        void printTicket();
        void setBalance(int);
        int getBalance() const;
        int getChecking() const;
        int member(int);
        int check(string );
        string specificname	(int i);
        string getMemberName() const;
        string getStudentID()const;
        string getStudentEmail() const;
        bool isEmpty();
};

#endif

