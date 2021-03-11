#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<double> memory;
    double result; // store result outside so we can save latest calculation in memory

    char answer;

    string calculatorOperation;

    cout << "A - perform basic arithmetic" << endl << "M - store last value in calculator memory" << endl << "MC - clear memory contents" << endl << "MR - show contents of memory on display" << endl;
    do {
        
        cout << "Please write the operation to perform: " ;
        cin >> calculatorOperation;

        if (calculatorOperation == "A") {
            
            continue;

        } else if (calculatorOperation == "M") {
            
            continue;

        } else if (calculatorOperation == "MC") {
            
            memory.clear();
            cout << "Cleared memory" << endl;
            continue;

        } else if (calculatorOperation == "MR") {
            
            for (int i = 0; i < memory.size(); i++) {
                cout << "Mem[" << i << "] = " << memory[i] << ';' << endl;
            }
            continue;
            
        } else {
            
            cout << "Invalid operation, please try again." << endl;
            continue;
        }

        double op1, op2;
        char operation;

        //TODO: parse input correctly

        switch (operation) {

            case '+':
                result = op1 + op2;
                break;

            case '-':
                result = op1 - op2;
                break;

            case '*':
                result = op1 * op2;
                break;

            case '/':
                result = op1 / op2;
                break;
            
            default:
                cout << "Invalid operator" << endl;
        }

        cout << op1 << " " << operation << " " << op2 << " = " << result << endl;

        cout << "What memory changes do you want to make ? (or 'none' if no memory changes should be made)";

        //TODO: memory saving options

        cout << "Do you want to make any more operations(y/n/Y/N)? "; 
        cin >> answer;
    } while (answer == 'y' || answer == 'Y');

    return 0;
}