#include "BrowserHistory.h"
#include <fstream>

BrowserHistory::BrowserHistory() {
    // TO BE COMPLETED
	head = new Webpage;
	tail = new Webpage;
	cursor = new Webpage;
	head->next = tail;
	tail->prev = head;
	cursor = head;
}

BrowserHistory::~BrowserHistory() {
    // TO BE COMPLETED
}

void BrowserHistory::visitSite(Webpage newSite) {
    // TO BE COMPLETED
	
	/*
	create a temporary cursor that stores the url and time of newSite, 
	then create a Webpage object with newSite's url and time
	*/
	Webpage* temp_cursor = new Webpage(newSite.url, newSite.t);
	Webpage a(newSite.url, newSite.t);

	/*
	if the list is empty, then point head and tail to the temporaary cursor and then have
	temporary cursor point back at them
	else, put the temporary at the end of the doubly linked list that was created to store browser history
	*/
	if (head->next == tail) {
		head->next = temp_cursor;
		temp_cursor->prev = head;
		temp_cursor->next = tail;
		tail->prev = temp_cursor;
		cursor = temp_cursor;
	}
	else
	{
		cursor->next = temp_cursor;
		temp_cursor->prev = cursor;
		tail->prev = temp_cursor;
		temp_cursor->next = tail;
		cursor = temp_cursor;
	}

	/*
	loop through the list that is used to store the full history, if it already has the website stored inside 
	it(the website has been visited before ), then nothing happens, but if it doesn't have the website, then 
	object a which stores the website is pushed into the list
	*/
	bool x = false;
	list<Webpage>::iterator it;
	for (it = fullHistory.begin(); it != fullHistory.end(); it++)
	{
		if (*it == *temp_cursor)
			x = true;
	}

	if (x == false)
	{
		fullHistory.push_back(a);
	}
	
}

string BrowserHistory::getURL() {
    // TO BE COMPLETED
	return cursor->getURL();
}

size_t BrowserHistory::getNavSize() {
    // TO BE COMPLETED
	
	//loop through the doubly linked list(browser history), then count how many items it contains
	int count = 0;
	Webpage* tcursor = new Webpage;
	for (tcursor = head->next; tcursor != tail; tcursor = tcursor->next)
	{
		count++;
	}
	return count;
}

string BrowserHistory::back() {
    // TO BE COMPLETED
	
	/*
	if the node prior to where the cursor is pointing to right now, then it means that the cursor is already at the beginning
	of browser history. If this is the case, then it doesn't do anything, but if not, then the cursor points to the previous node
	and return the url of that node.
	*/
	if (cursor->prev == head)
		return "already at the beginning of browsing history";
	else
	{
		cursor = cursor->prev;
		return cursor->getURL();
	}

}

string BrowserHistory::forward() {
    // TO BE COMPLETED
	
	/*
	test and see if the cursor is already pointing at the last node, if so, return a string that informs the user, if not
	cursor moves to the next node and return the url
	*/
	if (cursor->next == tail)
		return "already at the very end of browsing history";
	else
	{
		cursor = cursor->next;
		return cursor->getURL();
	}
}

void BrowserHistory::readHistory(string fileName) {
    // TO BE COMPLETED
	string status;
	string url;
	time_t time;
	ifstream file(fileName);

	/*
	first test if it is a new website, if it is "new", then initialize a new Webpage object with the url and time, and then
	the object is sent to the visitSite() function
	if status is not "new", if it is "back", then back function is called, and then the next word in the file is stored into 
	status, if it is "forward", then forward function is called.
	The function stops when the file reaches its end
	*/
	file >> status;
	while (!file.eof())
	{
		if (status == "new")
		{
			file >> url >> time;
			Webpage a(url, time);
			visitSite(a);
			file >> status;
		}
		if (status == "back")
		{
			back();
			file >> status;
		}
		if (status == "forward")
		{
			forward();
			file >> status;
		}
	}
}

void BrowserHistory::printBackSites() {
    // TO BE COMPLETED

	//loop until the node before where cursor is currently pointing at, and print each node's url and time visited
	Webpage* tcursor = new Webpage;
	for (tcursor = head->next; tcursor != cursor; tcursor = tcursor->next)
	{
		cout << tcursor->getURL()<<"   Time visited: "<<tcursor->getTime() << endl;
	}
}

void BrowserHistory::printForwardSites() {
    // TO BE COMPLETED
	
	//starting from where the cursor is pointed at, loop until tail(stops before tail), print ot each url and time visited
	Webpage* tcursor = new Webpage;
	for (tcursor = cursor; tcursor != tail; tcursor = tcursor->next)
	{
		cout << tcursor->getURL() << "   Time visited: " << tcursor->getTime() << endl;
	}
}

void BrowserHistory::printFullHistory() {
    // TO BE COMPLETED
	
	//using an iterator to loop through the list that stores the full history, print out each object with an overloaded <<
	list<Webpage>::iterator it;
	for (it = fullHistory.begin(); it != fullHistory.end(); it++)
	{
		cout << *it << " ";
		cout << endl;
	}
}
