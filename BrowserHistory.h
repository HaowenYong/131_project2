#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <stdexcept>
#include "Webpage.h"
using namespace std;

class BrowserHistory {
public:
    BrowserHistory();
    ~BrowserHistory();

    void visitSite(Webpage newSite);
    string back();
    string forward();

    void readHistory(string fileName);

    string getURL();
    size_t getNavSize();

    void printBackSites();
    void printForwardSites();
    void printFullHistory();
	

private:
    // Add private member variables for your class along with any
    // other variables required to implement the public member functions
    // TO BE COMPLETED
	
	Webpage* head; //the head of the doubly linked list that stores browser history
	Webpage* tail; //the tail of the doubly linked list that stores browser history
	Webpage* cursor; // points to the "current website" that the user is on
	list<Webpage> fullHistory; //stores all the sites that the user has visited
};
