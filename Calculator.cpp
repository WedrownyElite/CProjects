#include <iostream>
#include <string>
using namespace std;

int getNum(string number)
{
    string st;
    cout << "Type your " + number + " integer: ";
    cin >> st;

    // Try-Catch error loop (int | st)
    while (true) {
        try {
            return stoi(st);
            break;
        }
        catch (invalid_argument ex) {
            cout << "Not an integer. Type your " + number + " integer: ";
            cin >> st;
        }
    }
}

int main()
{
    string op;

    // Operation
    cout << "Type the operation ( + | - | */x | / ): ";
    cin >> op;

    // Operation Check
    if (op == "+" || op == "-" || op == "/" || op == "x" || op == "*") {
        int intx, inty;
        intx = getNum("first");
        inty = getNum("second");

        // Equation
        if (op == "+") {
            cout << "Answer: " << intx + inty << "\n";
        }
        else if (op == "-") {
            cout << "Answer: " << intx - inty << "\n";
        }
        else if (op == "x" || op == "*") {
            cout << "Answer: " << intx * inty << "\n";
        }
        else if (op == "/") {
            cout << "Answer: " << intx / inty << "\n";
        }
    }
}
