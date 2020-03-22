// Testing class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector> 
#include<cmath>
#include <ctime>
#include<string>
using namespace std;

void Create();

int main()
{
	Create();
}

void Create() {
	srand((int) time(0));
	string x;
	int ran;
	int ran2;
	string opera[] = {"+","-","*","/"};

	for ( int i = 0; i < 3;i++) {

		ran = rand()%100 ;
		x += to_string(ran) + " ";
		ran2 = rand() % 4;
		x += " " + opera[ran2] + " ";

	}
	ran = rand()%100;
	x += to_string(ran) + " ";
	cout << x << endl;
	
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
