#pragma once

#include <string>
#include <list>
using namespace std;

class Webpage {
public:
    Webpage();
    Webpage(const string& webpageURL, const time_t& timeVisited);
    string getURL();
    time_t getTime();
	friend ostream& operator << (ostream& out, Webpage wp); //overload outpupt operator to print out Webpage objects
	bool operator == (const Webpage &web);//overload assignment operator to compare Webpage objects


private:
    // Add private member variables for your class along with any
    // other variables required to implement the public member functions
    // TO BE COMPLETED
	string url; // stores the url of a webpage
	time_t t; // stores the time when a site is visited
	Webpage* next; // points to the next node(next site visited) of the doubly linked list
	Webpage* prev; // points to the previous node(site previously visited) of the doubly linked list
	friend class BrowserHistory; // make BrowserHistory a friend class so that it has the access to url, t, next, prev
};
