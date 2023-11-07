#include <iostream>
#include "browser.h"
#include "tab.h"

using namespace std;
int main() {
	cout << "==== Part 1 Launch a browser ====" << endl;
	Browser browser;
	cout << endl;
	cout << "==== Part 2 Open a tab ====" << endl;
	Tab* tab = browser.open_tab();
	cout << endl;

	cout << "==== Part 3 Navigate on tab history ====" << endl;
	tab->forward();
	tab->open("https://cse.hkust.edu.hk/");
	tab->open("https://www.google.com/");
	tab->backward();
	tab->backward();
	cout << endl;
	
	cout << "==== Part 4 Use another tab ====" << endl;
	tab = browser.open_tab();
	tab->open("https://course.cse.ust.hk/comp2012h");
	tab->backward();
	cout << endl;
	
	cout << "==== Part 5 Find tab ====" << endl;
	tab = browser.get_tab(0);
	cout << endl;

	cout << "==== Part 6 Close tab ====" << endl;
	browser.close_tab(tab);
	cout << endl;
	
	cout << "==== Part 7 Close browser ====" << endl;
}
