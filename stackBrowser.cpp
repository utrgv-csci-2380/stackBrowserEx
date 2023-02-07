
#include <iostream>
#include <string>
using namespace std;

class stack
{
private:
	string * items; //array to hold items in stack
	int capacity;  //size of array.
	int numItems;


public:
	stack()
	{
		capacity = 5;
		items = new string[5];
		numItems = 0;
	}

	//add x to top of stack
	void push(string x)
	{
		if (numItems == capacity)
		{
			cout << "Yo!  too many tacos, stack (stomach) is full!" << endl;
			//Try to implement a "resizing" method to create a bigger array.
		}
		else
		{
			items[numItems] = x;
			numItems++;
		}
	}

	//remove and return top item from stack
	string pop()
	{
		numItems--;
		return items[numItems];
	}
};

//A webbrowser!
//Uses the stack class to keep track of search history.
class webbrowser
{
private:
	string currentPage;
	stack history;

public:
	webbrowser()
	{
		currentPage = "www.google.com";
	}

	void surfTo(string newpage)
	{
		history.push(currentPage);
		currentPage = newpage;
	}

	string getPage()
	{
		return currentPage;
	}

	void back()
	{
		currentPage = history.pop();
	}
};

int main()
{
	stack tacoStack;

	tacoStack.push("bacon");
	tacoStack.push("chorizo");
	tacoStack.push("huevo");
	tacoStack.push("foqua");
	tacoStack.push("queue");
	tacoStack.push("stack");
	tacoStack.push("brisket");

	cout << tacoStack.pop() << endl;
	cout << tacoStack.pop() << endl;

	tacoStack.push("mushroom");
	cout << tacoStack.pop() << endl;
	cout << tacoStack.pop() << endl; //bacon

	//Testing our new fancy webbrowser
	webbrowser netscapeNavigator;

	netscapeNavigator.surfTo("www.google.com");
	netscapeNavigator.surfTo("www.cnn.com");
	netscapeNavigator.surfTo("www.forbes.com");
	netscapeNavigator.surfTo("www.youtube.com");

	cout << netscapeNavigator.getPage() << endl; //youtube
	netscapeNavigator.back();
	netscapeNavigator.back();
	cout << netscapeNavigator.getPage() << endl; //cnn

	netscapeNavigator.surfTo("www.twitch.com");
	netscapeNavigator.back();
	netscapeNavigator.back();
	cout << netscapeNavigator.getPage() << endl; //google

	return 0;
}
