#include <iostream>
#include <sstream>
#include <string>

using namespace std;


//THIS IS A FUNCTION INTERPRETER, IT CAN ALSO BE USED AS A CALCULATOR
//EX: TYPING THE COMMAND/INPUT "add 3 -4" RESULTS IN THE OUTPUT "3 + (-4) = -1"
//ALL OF THE INTERPRETERS:
//1. add number1 number2 ---- OUTPUTS THE SUMMATION OF TWO NUMBERS
//2. mul number1 number2 ---- OUTPUTS THE MULTIPLICATION OF TWO NUMBERS
//3. div number1 number2 ---- OUTPUTS THE DIVISION OF TWO NUMBERS AS A DECIMAL
//4. eq number1 number2 ---- CHECKS IF BOTH NUMBERS ARE EQUAL
//5. lc number1 number2 ---- CHECKS IF BOTH NUMBERS ARE MULTIPLES OF EACH OTHER

//*****NOTE******
//FUTURE IMPLEMENTATIONS/INTERPRETERS WILL INVOLVE FINDING THE
//1. LCM (LEAST COMMON MULTIPLE) AND GCD (GREATEST COMMON MULTIPLE)
//2. THE DIVISION INTERPRETER WILL ALSO BE ADJUSTED TO OUTPUT THE NUMBER AS A SIMPLIFIED FRACTION

int main() {

    string input;
    getline(cin, input);
    int NUM;
    int arr[2];
    unsigned int j = 0;
    int flag = 0;
    string getType = "";
    for (unsigned int i = 0; i < input.size(); ++i) {
        while (input[i] >= 97 && input[i] <= 122) {
            getType = getType + input[i];
            i = i + 1;
        }
        if (input[i] == 32) {
            while (input[i] == 32) {
                i = i + 1;
            }
        }
        if (input[i] == 45) {
            flag = 1;
            i = i + 1;
        }
        NUM = input[i] - 48;
        i = i + 1;
        while (input[i] >= 48 && input[i] <= 57) {
            NUM = (NUM * 10) + input[i] - 48;
            i = i + 1;
        }
        if (flag == 1) {
            NUM = NUM * -1;
            flag = 0;
            arr[j] = NUM;
            j = j + 1;
        }
        else {
            arr[j] = NUM;
            j = j + 1;
        }
    }
    cout << endl;
    
    //Operations
    if (getType == "add") {
        if (arr[0] < 0) {
            cout << "(" << arr[0] << ")" << " + ";
        }
        else {
            cout << arr[0] << " + ";
        }
        if (arr[1] < 0) {
            cout << "(" << arr[1] << ")";
        }
        else {
            cout << arr[1];
        }
        cout << " = " << arr[0] + arr[1] << endl;
    }
    else if (getType == "mul") {
        if (arr[0] < 0) {
            cout << "(" << arr[0] << ")" << " x ";
        }
        else {
            cout << arr[0] << " x ";
        }
        if (arr[1] < 0) {
            cout << "(" << arr[1] << ")";
        }
        else {
            cout << arr[1];
        }
        cout << " = " << arr[0] * arr[1] << endl;
    }
    else if (getType == "div") {
        if (arr[0] < 0) {
            cout << "(" << arr[0] << ")" << " / ";
        }
        else {
            cout << arr[0] << " / ";
        }
        if (arr[1] < 0) {
            cout << "(" << arr[1] << ")";
        }
        else {
            cout << arr[1];
        }
        cout << " = " << (double)arr[0] / (double)arr[1] << endl;
        
    }
    else if (getType == "eq") {
        if (arr[0] == arr[1]) {
            cout << "TRUE " << arr[0] << " == " << arr[1] << endl;
        }
        else {
            cout << "FALSE " << arr[0] << " =/= " << arr[1] << endl;
        }
    }
    else if (getType == "lc") {
        if (arr[0] % arr[1] == 0) {
            cout << "TRUE " << arr[0] << " and " << arr[1] << " are multiple of each other." << endl;
        }
        else {
            cout << "TRUE " << arr[0] << " and " << arr[1] << " are not multiple of each other." << endl;
        }
    }


    return 0;
}