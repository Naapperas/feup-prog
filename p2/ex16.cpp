#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    vector<double> memory;
    double result; // store result outside so we can save latest calculation in memory

    char answer;

    string calculatorOperation;

    cout << "A\tperform basic arithmetic\nM\tstore last value in calculator memory\nM-\tsubtract from the last value in calculator memory\nM+\tadd to the last value in calculator memory\nMC\tclear memory contents\nMR\tshow contents of memory on display\nC\tclear the contents of the screen\nQ\tquit calulator" << endl;
    do {

        double op1, op2;
        char operation;

        cout << "Please write the operation to perform: " ;
        cin >> calculatorOperation;
        if (calculatorOperation == "Q" || calculatorOperation == "q"){
            break;
        } else if (calculatorOperation == "A" || calculatorOperation == "a") {
            
            string op1s, operations, op2s;
            cin >> op1s >> operations >> op2s;

            if (operations != "+" && operations != "-" && operations != "*" && operations != "/") {
                cout << "Erro: operação inválida" << endl;
                answer = 'y';
                continue;
            }
            
            op1 = stod(op1s);
            operation = operations[0];
            op2 = stod(op2s);

        } else if (calculatorOperation == "M" || calculatorOperation == "m") {
            
            memory.push_back(result);
            answer = 'y';
            continue;

        } else if (calculatorOperation == "M+" || calculatorOperation == "m+") {

            memory[memory.size() - 1] += result; // maybe there is a better way to implement this
            answer = 'y';
            continue;

        } else if (calculatorOperation == "M-" || calculatorOperation == "m-") {

            memory[memory.size() - 1] -= result;
            answer = 'y';
            continue;

        } else if (calculatorOperation == "MC" || calculatorOperation == "mc") {
            
            memory.clear();
            cout << "Cleared memory" << endl;
            answer = 'y';
            continue;

        } else if (calculatorOperation == "MR" || calculatorOperation == "mr") {
            
            for (int i = 0; i < memory.size(); i++) {
                cout << "Mem[" << i << "] = " << memory[i] << ';' << endl;
            }
            answer = 'y';
            continue;
            
        } else if (calculatorOperation == "C" || calculatorOperation == "c") {
            for (int i = 0; i < 20; i++) cout << '\n';
            cout << endl;
            answer = 'y';
            continue;
        } else {
            
            cout << "Invalid operation, please try again." << endl;
            answer = 'y';
            continue;
        }

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

        cout << "Do you want to make any more operations(y/n/Y/N)? "; 
        cin >> answer;
    } while (answer == 'y' || answer == 'Y');

    return 0;
}