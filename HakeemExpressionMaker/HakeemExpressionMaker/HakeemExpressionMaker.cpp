// Ha#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>
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
	int randOp{ 0 };  //random num will determine which operator we will use from opChoice.
	int difficultyLevel{ 2 };  //will be used to determine the range of randNum (maybe use enum or restrict 1-4 later on).
	int randNum{ 0 };  //the newly generated randNum within appropriate range.
	int finalResult{ 0 };  //stores the final result of the expression using calculateFinalResult.
	int upBound{ 0 };  //initialised based on difficultyLevel.
	int lowBound{ 0 };  //initialised based on difficultyLevel.
	int expLength{ 0 };  //stores the length of the expression based on difficultyLevel.
	bool isPrevOpDiv = false;  //will be used to ensure division isn't consecutive to reduce BODMAS issues and time.
	string expression{ 0 };  //used for easy output of our expression
	const string opChoice[4] = { "+", "-", "*", "/" };
	vector<int> divisors{ 0 };  //used to store all the divisors of the prev randNum if / is the next randOp.
    vector<string> mathExp;  //used to store our expression.

public:
	//Someone make more constructors other than my default one lmao.
	//Idrk constructors, pointers, references, friends, etc in C++ properly yet.
	HakExpressionMaker() = default;
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
		int diff = getDifficultyLevel();
		switch (diff) {
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

	//POES FUNCTION USING VECTORS TO EVALUATE THE EXPRESSION (NEEDS TO BE FIXED)
    /*int calculateFinalResult(vector<string> expVector) {
        int resultantValue = 0;
        int index = 0;
        int i = 0;
        for (unsigned int precedence = 3; precedence >= 0; precedence--) {
            for (unsigned int c = 0; c < expVector.size() - 1; c++) {
                if ((expVector.at(c)).compare(opChoice[precedence]) == 0) {
                    i = 0;
                    while (expVector.at(index - i + 1) == "") {
                        i++;
                    }
                    int j = 1;
                    while (expVector.at(index + j - 1) == "") {
                        j++;
                    }
                    expVector.at(index) = "";
                    if (precedence == 0) {
                        expVector.at(index) = to_string(stoi(expVector.at(index - i)) + stoi(expVector.at(index + j)));
                        expVector.at(index - 1) = "";
                        expVector.at(index + 1) = "";
                    }
                    else if (precedence == 1) {
                        expVector.at(index) = to_string(stoi(expVector.at(index - i)) - stoi(expVector.at(index + j)));
                        expVector.at(index - 1) = "";
                        expVector.at(index + 1) = "";
                    }
                    else if (precedence == 2) {
                        expVector.at(index) = to_string(stoi(expVector.at(index - i)) * stoi(expVector.at(index + j)));
                        expVector.at(index - 1) = "";
                        expVector.at(index + 1) = "";
                    }
                    else if (precedence == 3) {
                        expVector.at(index) = to_string(stoi(expVector.at(index - i)) / stoi(expVector.at(index + j)));
                        expVector.at(index - 1) = "";
                        expVector.at(index + 1) = "";
                    }
                }
            }
        }
        unsigned int k = 0;
        while (k < expVector.size()) {
            if (expVector.at(k) != "_") {
                resultantValue = stoi(expVector.at(k));
                break;
            }
            i++;
        }
        expVector.clear();
        return resultantValue;
    }*/

	/*Generates the valid expression.*/
	void generateExpression() {
		genRange();
		register int c = 0; //counter used to change from generating a randNum to randOp and vice versa
		for (int i = 0; i < (expLength * 2) - 1; i++) {
			if (c % 2 == 0) {
				int ranum = 0;
				if (opChoice[randOp] == "/") {
					ranum = genRandNumForDiv();
					mathExp.push_back(to_string(ranum));
					if (ranum < 10) {
						expression = expression + to_string(ranum) + "    ";
					}
					else {
						expression = expression + to_string(ranum) + "   ";
					}
				}
				else {
					ranum = genRandNum();
					expression = expression + to_string(ranum) + "   ";
					mathExp.push_back(to_string(ranum));
				}
			}
			else {
				genRandOp();
				expression = expression + opChoice[randOp] + "   ";
				mathExp.push_back(opChoice[randOp]);
			}
			c++;
		}
		cout << expression << endl;
        /*if (mathExp.size() % 2 == 0) {
            if (mathExp.top() == "-9") {
                mathExp.pop();
                mathExp.push("/");
            }
            else if (mathExp.top() == "120") {
                mathExp.pop();
                mathExp.push("*");
            }
            else if (mathExp.top() == "43") {
                mathExp.pop();
                mathExp.push("+");
            }
            else if (mathExp.top() == "45") {
                mathExp.pop();
                mathExp.push("-");
            }
        }*/
        //finalResult = calculateFinalResult(mathExp);
        mathExp.clear();
		expression = ""; 
	}

    //Nikiel's functions:
	/*void reverse(stack<string>& original, stack<string>& temp) {
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

		string tempVal = "";*/
		/*
			tempVal is a variable which will help us iterate through a string and get numbers

			why is it important?
			well strings are char arrays which means the compiler does not see a string as 24
			but rather 2,4
			we wouldnt want the stack to be pushing in two different integers one after the other with no operator with it

		*/

		/*for (unsigned int i = 0; i < input.length() + 1; i++) {// for loop to iterate through the string
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
			else {*/
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
	/*			tempVal += input[i];
			}
		}

		temp.push(tempVal);*/
		/*
			since tempVal is only pushed onto the stack when it sees an operator we lose the last integers
			to overcome this we push one more time tempVal onto the stack as it will contain the last integer
		*/
		/*reverse(original, temp);

		 //reverse the stack so we end up with  the original expression that was given to us
		printstack(original);*/
		// this just prints a stack
	//}
};

int main() {
	srand(time(NULL));
	HakExpressionMaker myExpMaker;
	for (int i = 0; i < 125; i++) {
		myExpMaker.generateExpression();
        //cout << myExpMaker.getFinalResult() << endl;
	}
	return 0;
}

HakExpressionMaker::~HakExpressionMaker()
{

}