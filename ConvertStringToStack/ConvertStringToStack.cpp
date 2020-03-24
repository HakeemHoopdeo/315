// ConvertStringToStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stack>
#include<string>


using namespace std;
void reverse(stack<string>& s1, stack<string>& s2);
int calculator(stack<string>& x);
void printstack(stack<string> s1);
void setup(string input);
stack<string> temp, original;



int main()
{

	string s = "23+24-25";
	setup(s);
}


void reverse(stack<string>& original, stack<string>& temp) {
	while (!temp.empty()) {
		original.push(temp.top());
		temp.pop();
	}
}

// reverses the contents of a stack and puts it into our expression stack

void printstack(stack<string> s1) {
	while (!s1.empty()) {
		cout << s1.top();
		s1.pop();
	}
}

// prints a stack

void setup(string input) {

	string tempVal = "";
	/*
		tempVal is a variable which will help us iterate through a string and get numbers

		why is it important?
		well strings are char arrays which means the compiler does not see a string as 24
		but rather 2,4
		we wouldnt want the stack to be pushing in two different integers one after the other with no operator with it

	*/

	for (unsigned int i = 0; i < input.length() + 1; i++) {// for loop to iterate through the string
		if (input[i] == ' ') {// checks to see if the char at position i in the string is a blank
			//if it is we do nothing
		}
		else if (input[i] == '/' || input[i] == '*' || input[i] == '+' || input[i] == '-') {// checks to see if char at position i is an operator

			// if it is this means there is no more numbers to collect before the operator
			// eg 24 + 25
			// it means in tempVal the value 24 is there
			temp.push(tempVal);// we push onto the stack whatever is in tempVal
			temp.push(std::string(1, input[i])); // std::string(1,input[i]) is a conversion from character to string
			// this push statement pushes the operator onto the stack
			tempVal.clear();// we clear the contents of temVal so it can get a new string of numbers



		}
		else {
			// if the character at position i is neither a space or an operator
			// then it must be a number
			// now this step is curicial in getting all the numbers
			/*
				back to our example 24 +25

				since compiler knows its all characters
				24 would not be pushed onto the stack but rather 2 the 4
				 to overcome this i created the tempval value whcih will know to append 2 then 4 to the variable tempVal
				 so it will push the value onto the stack when it sees an operator


			*/
			tempVal += input[i];
		}
	}

	temp.push(tempVal);
	/*
		since tempVal is only pushed onto the stack when it sees an operator we lose the last integers
		to overcome this we push one more time tempVal onto the stack as it will contain the last integer
	*/
	reverse(original, temp);

	// reverse the stack so we end up with  the original expression that was given to us
	printstack(original);
	// this just prints a stack
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
