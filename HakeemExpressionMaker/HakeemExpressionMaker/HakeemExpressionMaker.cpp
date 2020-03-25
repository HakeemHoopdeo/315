// Authors :
// Hakeem Hoopdeo
// Nikiel Ramawthar 

#include <string>
#include <vector>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

//Please add more constructors and call setDifficultyLevel() in it

/*Note: - difficulty level of 0: Easy will generate numbers from 1-9 with 2 operators
		- difficulty level of 1: Medium will generate numbers from 10-20 with 4 operators
		- difficulty level of 2: Hard will generate numbers from 20-50 with 6 operators
		- difficulty level of 3: MasterMath will pop in equations into it (May not do)
		- If currentOperator is Divison, we must calculate all divisors for the 
		  currentRandom number and pick a random divisor of a vector of divisors
		- we still need to generate multiple random numbers
		- This class generates multiple random expressions
		- Some expressions can result in a negative answer 
	      depending on the situation but it's fairly rare*/

class HakExpressionMaker {
private:
	int randOp = 0;  //random num will determine which operator we will use from opChoice.
	int difficultyLevel;  //will be used to determine the range of randNum (maybe use enum or restrict 1-4 later on).
	int randNum{ 0 };  //the newly generated randNum within appropriate range.
	int finalResult{ 0 };  //stores the final result of the expression using calculateFinalResult.
	int upBound{ 0 };  //initialised based on difficultyLevel.
	int lowBound{ 0 };  //initialised based on difficultyLevel.
	int expLength{ 0 };  //stores the length of the expression based on difficultyLevel.
	bool isPrevOpDiv = false;  //will be used to ensure division isn't consecutive to reduce BODMAS issues and time.
	string expression{ 0 };  //used for easy output of our expression
	const string opChoice[4] = {"/", "*","+","-"};
	vector<int> divisors{ 0 };  //used to store all the divisors of the prev randNum if / is the next randOp.
    vector<string> mathExp;  //used to store our expression.

public:
	//Someone make more constructors other than my default one lmao.
	//Idrk constructors, pointers, references, friends, etc in C++ properly yet.
	HakExpressionMaker() {

		this->difficultyLevel = 0;
		this->finalResult = 0;
		genRange();
		cout << endl;
	}

	HakExpressionMaker(int difficulty) {// constructor to set difficulty level

		this->difficultyLevel = difficulty;
		this->finalResult = 0;
		genRange();
		cout << endl;

	}
	~HakExpressionMaker();

	inline int getDifficultyLevel() {
		return this->difficultyLevel;
	}

	inline void setDifficultyLevel(int difficultyLevel) {  //call in constructor or where necessary
		this->difficultyLevel = difficultyLevel;
	}

    inline int getFinalResult() {
        return finalResult;
    }
    
    inline string getExpression() {
        return expression;
    }

	/*Initializes the range according to the difficulty level, please note, the only time you will see
	  numbers that are in other ranges , it's because of finding all the divisors and picking a random
	  divisor that will enable us to get an integer result*/
	void genRange() {

		switch (difficultyLevel) {
		case 0:
			this->lowBound = 1;
			this->upBound = 9;
			this->expLength = 2;
			break;
		case 1:
			this->lowBound = 10;
			this->upBound = 20;
			this->expLength = 4;
			break;
		case 2:
			this->lowBound = 20;
			this->upBound = 50;
			this->expLength = 6;
			break;
		}
	}

	/*Generates a random number for addition, subtraction and multiplication*/
	inline int genRandNum() {
		randNum = lowBound + (rand() % (upBound - lowBound + 1));
		return randNum;
	}

	/*This function generates a vector of divisors of the previous randNum should the new randOp
	  be division. Used in tandem with genRandNumForDiv() to choose a random element from the vector
	  divisors to force the result to be an integer*/
	void genDivisors() {
		divisors.push_back(1);
		if (randNum > 1) {
			for (int i = 2; i <= randNum/2; i++) {
				if (randNum % i == 0) {
					divisors.push_back(i);
				}
			}
		}
		divisors.push_back(randNum);
		//When called we must use a pointer and see how to save space
	}

	/*This function will call the generateDivisors() method which initialises a vector of divisors called divisors
	  and then select a random element from that vector to be the divisor before destroying the vector*/
	int genRandNumForDiv() {
		genDivisors();
		if (randNum != 1) {
			if (divisors.size() > 2) {
				randNum = divisors.at(1 + (rand() % (divisors.size() - 1)));
			}
			else {
				randNum = divisors.at(rand() % divisors.size());
			}
		}
		divisors.clear();
		return randNum;
	}

	/*Generates(set method) a random operator for the equation and also
	  ensures that the division operator isn't consecutive.*/
	void genRandOp() {
		if (isPrevOpDiv == false) {
			randOp = rand() % 4;
		}
		else {
			randOp = rand() % 3;
		}
		if (randOp == 3) {
			isPrevOpDiv = true;
		}
		else {
			isPrevOpDiv = false;
		}
	}


	void printVector(vector<string>& v ) {

		for (auto const& i : v) {
			std::cout << i << " ";
		}
		cout << endl;
	}
	//FUNCTION USING VECTORS TO EVALUATE THE EXPRESSION 
    int calculateFinalResult(vector<string>& expVector) {
        int resultantValue = 0;
     //   int i = 0;
        for (unsigned int precedence = 0; precedence < 2 ; precedence++) {
			for (unsigned int c = 0; c < expVector.size(); c++) {
                if ((expVector[c]).compare(opChoice[precedence]) == 0) {
                   int  i = c - 1;
                    while (expVector[i] == " ") {
                        i--;
                    }
                    int j = c+1;
                    while (expVector[j] == " ") {
                        j++;
                    }

					string previousNumber = expVector[i];
					string forwardNumber = expVector[j];
					int num1 = std::stoi(previousNumber);// number before the operator
					int num2 = std::stoi(forwardNumber);// number after the operator
					expVector[c] = to_string((doOperation(precedence, num1, num2)));
					expVector[i] = " ";
					expVector[j] = " ";
                }
            }
			printVector(expVector);
        }
		/*
		first we iterate through the vector and doing only division and multiplication
		*/


		for (unsigned int c = 0; c < expVector.size(); c++) {
			if ((expVector[c].compare("+") == 0) || (expVector[c].compare("-") == 0)) {// compares to see if the character is a + or  - symbol
			int  i = c - 1;
			while (expVector[i] == " ") {
				i--;
			}
			/*
				this while loop gets the position of the number before the operator 
			*/
			int j = c + 1;
			while (expVector[j] == " ") {
				j++;
			}

			/*
				this while loop gets the position of the number before the operator
			*/
			string previousNumber = expVector[i];
			string forwardNumber = expVector[j];
			int num1 = std::stoi(previousNumber);// number before the operator
			int num2 = std::stoi(forwardNumber);// number after the operator
			int operate = 0;// variable for later use
			if (expVector[c].compare("+") == 0) {
				operate = 2;
			}
			else if (expVector[c].compare("-") == 0) {
				operate = 3;
			}

			/*
				we convert the previous and foward number  to type int 
				while at the same time checking what type of operator it is 
				
				i have defined a method DoOperation which takes in the position of the operator in the OpChoice array and two numbers as parameters
				and according to what position it is it carrys out the required equation
				eg if it send 0 it know to carry our division between two numbers and so on


			*/

			expVector[c] = to_string((doOperation(operate, num1, num2)));
			expVector[i] = " ";
			expVector[j] = " ";

			}
		}


		/*
			now we iterate through the vector doing normal math addition and subtraction
			because it is only addition and subtraction it does not matter which comes first 


			the reason why i created two different loops for the divison and multiplication 
			as well as a loop for addition and subtraction is
			addition and subtraction does not worry about order
			eg 2+4-6-8 
			it doesnt matter if you do addition or subtraction first althought the sign before the integer matters

			sticking with that number we could do 2+4  = 6 
			then 6-6 =0
			then 0 - 8 = 0

			but lets say we have the equation 4-6+10-30
			if we do addition first its not 6+10 = 16
			the 4-16 = -12
			at this point the original program would read it at 12-30 and not -12-30 
			it is due to that error i decided to split two for loops
			one to cater for division and multipliaction //will get to why division and multiplication seperate is also important
			and one to cater for addition and subtraction


			now why division and multipolication first? 

			well 5+3*6/2


			saying we just read left to right so 
			5+3 = 8
			8*6 = 48
			and 48/2 = 24

			now if we do division first 6/2 = 3

			then multiplication
			3*3 = 9
			 and then normal arithmetic operation 
			 9+5 = 14 
			 theres an offset of 10 in this case that is why the division and multiplication loop preceeds 
			 the addition and subtraction loop

		*/
        unsigned int k = 0;

        while (k < expVector.size()) {
            if (expVector[k] != " ") {
                resultantValue = std::stoi(expVector[k]);
                break;
            }
           k++;
        }

		/*
			while loop to get the resultant value as at this point there should only be 1 value in the vector
		*/
        expVector.clear();
        return resultantValue;
    }


	/*
	
		I hope my commentation makes it easier to understand what i did and why i did so
	*/


	inline int doOperation(int Operater, int &num1, int &num2) {

		switch (Operater) {
		case 0:
			return num1 / num2;
		case 1 :
			return num1 * num2;
		case 2://if the Operater is 2 it means we found a plus sign and should do addition
			return num1 + num2;
		case 3:// if the Operater is a 3 it means we found a minus sign and should do subtraction
			return num1 - num2;

		}
	}
	/*Generates the valid expression.*/
	void generateExpression() {

		register int c = 0; //counter used to change from generating a randNum to randOp and vice versa
		for (int i = 0; i < (expLength * 2) - 1; i++) {
			if (c % 2 == 0) {
				int ranum = 0;
				if (opChoice[randOp] == "/") {
					ranum = genRandNumForDiv();
					mathExp.push_back(to_string(ranum));
					expression += to_string(ranum) + " ";
				}

				else {
					ranum = genRandNum();
					expression += to_string(ranum) + " ";
					mathExp.push_back(to_string(ranum));
				}
			}
			else {
				genRandOp();
				expression += opChoice[randOp] + " ";
				mathExp.push_back(opChoice[randOp]);
			}
			c++;
		}
		cout << expression << endl;
        finalResult = calculateFinalResult(mathExp);
		printVector(mathExp);
        mathExp.clear();
		expression = ""; 
	}

 
};

int main() {
	srand(time(0));


	cout << "Easy = 0 " << endl;
	cout << "Challenging = 1 " << endl;
	cout << "God Mode = 2 " << endl;
	cout << "Enter difficulty Level : ";
	
	int diff;
	cin >> diff;

	while (diff > 2) {
		cout << "Invalid difficulty, Enter Difficulty : ";
		cin >> diff;
	}

	HakExpressionMaker myExpMaker(diff);
	myExpMaker.generateExpression();
	cout << myExpMaker.getFinalResult();


	return 0;

}

HakExpressionMaker::~HakExpressionMaker()
{

}