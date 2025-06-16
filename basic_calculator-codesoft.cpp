//Program for a Basic Calculator Operations

#include <iostream>
using namespace std;

//Functions and theis definitions
double add(double a, double b) { 
	return a + b;
}

double subtract(double a, double b) { 
	return a - b;
}

double multiply(double a, double b) { 
	return a * b; 
}

double divide(double a, double b) { 
	return a / b; 
}

int main() {
    double num1, num2;
    char operation;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "\nAvailable operations: + - * /"<<endl;
    cout << "Choose an operation: ";
    cin >> operation;

    switch (operation) {
        case '+':
            cout << "Result: " << add(num1, num2) << endl;
            break;
        case '-':
            cout << "Result: " << subtract(num1, num2) << endl;
            break;
        case '*':
            cout << "Result: " << multiply(num1, num2) << endl;
            break;
        case '/':
            if (num2 == 0){
                cout << "Error: Division by zero is not allowed." << endl;
        	}
            else{
                cout << "Result: " << divide(num1, num2) << endl;
            }
            break;
        default:
            cout << "Invalid operation selected." << endl;
    }
    return 0;
}



