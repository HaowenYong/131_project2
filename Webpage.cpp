#include "Webpage.h"

Webpage::Webpage() {
    // TO BE COMPLETED
	url= "";
	t = 0;
	next = NULL;  //next = new Webpage;
	prev = NULL; // prev = new Webpage;
}

Webpage::Webpage(const string& webpageURL, const time_t& timeVisited) {
    // TO BE COMPLETED
	url = webpageURL;
	t = timeVisited;
	next = NULL;
	prev = NULL;
}

string Webpage::getURL() {
    // TO BE COMPLETED
	return url;
}

time_t Webpage::getTime() {
    // TO BE COMPLETED
	return t;
}

bool Webpage::operator == (const Webpage &web) {
	//ovverloaded to compare Webpage objects
	if (this != &web)
	{
		return false;
	}
	return true;
}

ostream& operator << (ostream& out, Webpage wp) {
	//overloaded to print out Webpage objects
	out << wp.getURL();
	return out;
}
