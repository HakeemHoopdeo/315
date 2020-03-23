// stupid_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stack>
#include<string>


using namespace std;
void reverse(stack<string>& s1, stack<string> &s2);
int calculator(stack<string>& x);
void printstack(stack<string> s1);


int main()
{
	stack<string> x;
	x.push("3");
	x.push("+");
	x.push("3");
	x.push("-");
	x.push("3");
	cout << calculator(x);

}

void reverse(stack<string>& s1, stack<string> &s2) {
	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
}

void printstack(stack<string> s1) {
	while (!s1.empty()) {
		cout << s1.top()<<endl;
		s1.pop();
	}
}
int calculator(stack<string>& x) {
	stack<string> tempstack;
	double num1, num2;
	string operatorVar;
	double tempVal = 0;
	bool val = true;
	while (val) {// just for it to run multiple times
		while (x.size() > 1 ) {// while there are more than one element in the stack
			num1 = std::stoi(x.top());// converts a number to integer type 
			x.pop();
			operatorVar = x.top();// pops the operator after number
			x.pop();
			num2 = std::stoi(x.top()); // convert number to integer
			x.pop();
			if (operatorVar.compare("+") == 0) {// checks to see if the operator is a plus symbol
				num1+= num2;// adds the two numbers and sets it to num 1
				x.push(to_string(num1));// pushes this value onto the stack
			}
			else {// if operator isnt equal 
				tempstack.push(to_string(num1));// pushes value into temp stack also converts string to int
				tempstack.push(operatorVar);// pushes the operator into the temp stack
				x.push(to_string(num2));// pushes the 2nd into the top of the original stack so it can now look for next value
			}

		}// ends while loop


		tempVal = std::stoi(x.top());// gets a temp value
		x.pop();
		if (x.empty() && tempstack.empty()) {// checks if both are empty if both are empty then the temp is the result
			return tempVal;// returns result
			val = false;// for while loop to stop 
		}
		else {
			reverse(tempstack, x);// else it should push all values back into the original stack and move on with iyts life 
			// but does the bitch program do that NOOOOOO it wants to bitch thats there isnt errors but give sme A FUCKING HUNDRED 
		}

	}

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
