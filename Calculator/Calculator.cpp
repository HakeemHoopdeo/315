// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
// please note the calculator does not work with doubles yet in the sense that
// if you gave it 3/4 it would not return 0.75 since idfk string to double conversion


// ALSO IF ANYONE IS LOOKING AT MY COMMENTS AND CODE
// I APOLOGISE FOR THE LANGUAGE 
// I HAVE BEEN TRYING TO CODE THIS FOR ABOUT 2 WEEKS 
// AND IM TIRED AS HELL TO BE PROPERLY COMMENTING WITH FORMAL LANGUAGE
// ANYWAYS HAVE FUN ANALYSING IT 
// IT SHOULD GIVE YOU A HEADACHE
// BECAUSE IT GAVE ME ANXIETY AND DEPRESSION CODING IT

#include <iostream>
#include<string>
#include<stack>

using namespace std;
int calculator(stack<string>& x);
void reverse(stack<string> &first, stack<string> &second);

int main()
{
    std::cout << "WELCOME TO CALCULATOR BABY: I AM YOUR VIRTUAL CALCULAT0R - MICHHHEEEELLLLEEEEEEES!\n";
    stack<string> x;
    x.push("24");
    x.push("-");
    x.push("72");
    x.push("*");
    x.push("11");
    x.push("/");
    x.push("28");

    cout << calculator(x);
}

/*
            DO I HONESTLY HAVE TO FUCKING EXPLAIN WHAT THE FUCK THIS FUNCTION DOES
*/
void print(stack<string> x) {
    while (x.size()>0) {
        cout << x.top() << endl;
        x.pop();
    }
}


/*
         OH BOY AM I ABOUT TO MIND FUCK YALL WITH THIS FUNCTION THAT TOOK ME AN ETERNITY TO COMPLETE
*/
int calculator(stack<string> &x) {

    stack<string> temp; //create a temp stack 
    int num1, num2;// create two number variables to hold
    string op;// holds the type of operator
    double tmpval;// temparary value for maths stuff

    while (true) {// stupid coding i know leave me alone yall can fix it

        /*
                reminder the way the stack is implemented such that the sequence will always be

                number (operator, number)+ and will always end in a number
        
                also most of the code is recurring but IT FUCKING WORKS so leave my bad coding alone ill fix it later
        */
        while (x.size() > 1 ) {// checks if there will only be one element in the stack, if the size is 1 it means we went through the whole stack
            num1 = std::stoi(x.top());// gets first number value
            x.pop();
            op = x.top();// gets whatever operator it sees
            x.pop();
            num2 = std::stoi(x.top());// gets second value
            x.pop();
            // pos the first three values of the stack into variables
            //pops from x stack
            // I SEE I'VE JUST REPETED MYSELF 
            // SORRY IM TIRED
            if (op.compare("/") == 0) {  // compares the operator it took from the string to the divsion symbol
                tmpval = num1 / num2;// if it is a division symbol its gonna divide the two numbers
                x.push(to_string(tmpval));// then push that fucker onto the original stack
                //looking back i shouldve named my variables better
                //BUT IT FUCKING WORKS
            }
            else {

                /*
                    if it isnt the operator we wanted its gonna push the first numebr and operator back onto a temporary stack
                    while pushing the second number back onto the original stack
                    this is because as i said the program goes through the stack in and order
                    get a number
                    get an operator
                    get a number
                */
                temp.push(to_string(num1));
                temp.push(op);
                x.push(to_string(num2));
            }

        }//ends the while loop

        tmpval = std::stoi(x.top()); 
        x.pop();

        /*
            AAANNNYYYYY WAYS
            above statement just pops a value from the original stack now wait 
            you see if the original stack is empty after this pop
            and the temporary stack is empty 
            then there are no more operators or numbers in the program and as such it can terminate
        
        */
        if (x.empty() && temp.empty()) {
            return tmpval;
        }
        else {
            x.push(to_string(tmpval));
            reverse(x,temp);


            /*
                    but lets say there is a chance that the temp stack isnt empty because it chose to be a cunt
                    the we reverse the temp stack onto the original stack so we still have our original equation but now with the edits


                    think if it like this

                    the expression 27/3 x 9 

                    because we was only looking for the division then the original stack would have 9 while the temp stack would have a multiplication sign and 9 as well

                    so im reversing the cunt and at the same time
                    remeber that temp value i popped just before this if else loop 
                    YEAH IM POPPING IT BACK ONTO THE ORIGINAL STACK TO AVOID A MESS I JUST MADE
            */
        }

        /*
        
                    well the rest of the stuff is just the same code but i just changed what i was searching for for the operators

                    have fun analysing my code muhhhfuckeeerrrrssssss
        */
       while (x.size() > 1) {
            num1 = std::stoi(x.top());
            x.pop();
            op = x.top();
            x.pop();
            num2 = std::stoi(x.top());
            x.pop();
            // pos the first three values of the stack into variables
            //pops from x stack
            if (op.compare("*") == 0) {
                tmpval = num1 * num2;
                x.push(to_string(tmpval));
            }
            else {
                temp.push(to_string(num1));
                temp.push(op);
                x.push(to_string(num2));
            }

        }//ends the while loop

        tmpval = std::stoi(x.top());
        x.pop();
        if (x.empty() && temp.empty()) {
            return tmpval;
        }
        else {
            x.push(to_string(tmpval));
            reverse(x, temp);
        }
        

        while (x.size() > 1) {
            num1 = std::stoi(x.top());
            x.pop();
            op = x.top();
            x.pop();
            num2 = std::stoi(x.top());
            x.pop();
            // pos the first three values of the stack into variables
            //pops from x stack
            if (op.compare("+") == 0) {
                tmpval = num1 + num2;
                x.push(to_string(tmpval));
            }
            else {
                temp.push(to_string(num1));
                temp.push(op);
                x.push(to_string(num2));
            }

        }//ends the while loop

        tmpval = std::stoi(x.top());
        x.pop();
        if (x.empty() && temp.empty()) {
            return tmpval;
        }
        else {
            x.push(to_string(tmpval));
            reverse(x, temp);
        }
        while (x.size() > 1) {
            num1 = std::stoi(x.top());
            x.pop();
            op = x.top();
            x.pop();
            num2 = std::stoi(x.top());
            x.pop();
            // pos the first three values of the stack into variables
            //pops from x stack
            if (op.compare("-") == 0) {
                tmpval = num1 - num2;
                x.push(to_string(tmpval));
            }
            else {
                temp.push(to_string(num1));
                temp.push(op);
                x.push(to_string(num2));
            }

        }//ends the while loop

        tmpval = std::stoi(x.top());
        x.pop();
        if (x.empty() && temp.empty()) {
            return tmpval;
        }
        else {
            return 0;

        }
        //DONT FUCKING TOUCH FROM AFTER THIS STATEMENT
        
    }
}


void reverse(stack<string> &first, stack<string> &second) {
    while (!second.empty()) {
        first.push(second.top());
        second.pop();
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
