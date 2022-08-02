#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//THIS IS A LOGIC OPERATOR PROGRAM
//FIRST TWO SETS ARE CREATED WITH RANDOM INTEGERS, NO DUPLICATE VALUES ARE PRESENT
//THE USER CHOOSES THE SIZE OF BOTH SETS
//EX: IF SET1 SIZE IS 9, THEN SET1 WILL HAVE 9 RANDOM ELEMENTS THAT ARE RANGED FROM -9 TO +9
//AFTER BOTH SETS ARE CREATED, USER CAN PEFORM LOGIC OPERATIONS
//EX: THE INTERSECTION/AND OPERATION OUTPUTS ELEMENTS THAT ARE PRESENT IN BOTH SET1 AND SET2

//THESE ARE THE AVALIABLE OPTIONS THE USER CAN CHOOSE:
// 1. SET1 OR SET2 (Values that belong in SET1 or SET2)
// 2. SET1 AND SET2 (Values that belong in SET1 and SET2)
// 3. SET1 - SET2 (Values that belong in SET1 and not SET2)
// 4. SET2 - SET1 (Values that belong in SET2 and not SET1)
// 5. SET1 SYMMETRIC SET2 (Values that belong in SET1 or SET2, but not their intersection)

//****NOTE: THE SYMMETRIC OPERATION SOMETIMES DOES NOT WORK DUE TO "OUT OF RANGE" ERRORS, 
//HOWEVER, FUTURE IMPLEMENTATIONS WILL FIX THIS ERROR

int rand_custom();
int Size, Size1, Size2;

void ask_usertologic(int[], int, int[], int);
void or_operation(int[], int, int[], int, string);
void and_operation(int[], int, int[], int, string);
void relative_operation(int[], int, int[], int, string);
void symmetric_operation(int[], int, int[], int, string);

void print_elements(string, int[], int);

int main() {
    cout << endl;

    srand(time(0)); //Time function

    //Set size for both Sets
    cout << "Please enter the number of elements for the first set: ";
    cin >> Size;
    Size1 = Size;
    std::vector<int> Set1(Size);
    cout << "Please enter the number of elements for the second set: ";
    cin >> Size;
    Size2 = Size;
    std::vector<int> Set2(Size);

   //Generate random for both sets
    Size = Size1;
    int counter = Set1.size();
    while (counter != 0) {
        for (unsigned int i = 0; i < Set1.size(); ++i) {
            for (unsigned int j = i + 1; j < Set1.size(); ++j) {
                if (Set1[j] == Set1[i]) {
                    Set1[j] = rand_custom();
                }
            }
        }
        counter--;
    }
    Size = Size2;
    counter = Set2.size();
    while (counter != 0) {
        for (unsigned int i = 0; i < Set2.size(); ++i) {
            for (unsigned int j = i + 1; j < Set2.size(); ++j) {
                if (Set2[j] == Set2[i]) {
                    Set2[j] = rand_custom();
                }
            }
        }
        counter--;
    }

    cout << "SET1 consists of " << Set1.size() << " random numbers generated between -" << Set1.size() << " and +" << Set1.size() << endl;
    cout << "SET2 consists of " << Set2.size() << " random numbers generated between -" << Set2.size() << " and +" << Set2.size() << endl;
    cout << endl;

    // Sort both sets in ascending order
    int temp, small;
    for (unsigned int i = 0; i < Set1.size(); ++i) {
        small = i;
        for (unsigned int j = i + 1; j < Set1.size(); ++j) {
            if (Set1[j] < Set1[small]) {
                small = j;
            }
        }
        temp = Set1[i];
        Set1[i] = Set1[small];
        Set1[small] = temp;
    }
    for (unsigned int i = 0; i < Set2.size(); ++i) {
        small = i;
        for (unsigned int j = i + 1; j < Set2.size(); ++j) {
            if (Set2[j] < Set2[small]) {
                small = j;
            }
        }
        temp = Set2[i];
        Set2[i] = Set2[small];
        Set2[small] = temp;
    }

    //Convert vectors to arrays
    int* arr1 = &Set1[0];
    int* arr2 = &Set2[0];
    
    //Print both sets
    print_elements("SET1", arr1, Set1.size());
    print_elements("SET2", arr2, Set2.size());

    //Logical Operations
    string input;
    cout << "Would you like to perform an Operation (yes/no)?: ";
    cin >> input;
    if (input == "yes") {
        ask_usertologic(arr1, Set1.size(), arr2, Set2.size());
        while (input == "yes") {
            cout << "Would you like to perform another Operation (yes/no)?: ";
            cin >> input;
            if (input != "yes") {
                cout << endl;
                break;
            }
            else {
                ask_usertologic(arr1, Set1.size(), arr2, Set2.size());
            }
        }
    }
    else {
        cout << endl;
        cout << "End of Program." << endl;
    }

    cout << "End of Program." << endl;
    cout << endl;

    return 0;
}
int rand_custom() {
    return (rand() % (Size * 2 + 1)) - Size;
}
void print_elements(string set, int arr[], int sz) {
    cout << set << ": ";
    for (unsigned int i = 0; i < sz; ++i) {
        if (sz - 1 == i) {
            cout << arr[i];
        }
        else {
            cout << arr[i] << ", ";
        }
    }
    cout << endl;
    cout << endl;
    return;
}
void ask_usertologic(int arr1[], int sz1, int arr2[], int sz2) {
    string input;
    cout << "Which Operation should be performed on SET1 and SET2 (1/2/3/4/5)?" << endl;
    cout << "1. SET1 OR SET2 (Values that belong in SET1 or SET2)" << endl;
    cout << "2. SET1 AND SET2 (Values that belong in SET1 and SET2)" << endl;
    cout << "3. SET1 - SET2 (Values that belong in SET1 and not SET2)" << endl;
    cout << "4. SET2 - SET1 (Values that belong in SET2 and not SET1)" << endl;
    cout << "5. SET1 SYMMETRIC SET2 (Values that belong in SET1 or SET2, but not their intersection)" << endl;
    cout << endl;
    cout << "Operation: ";
    cin >> input;
    cout << endl;
    if (input == "1") {
        or_operation(arr1, sz1, arr2, sz2, "SET1 OR SET2");
    }
    else if (input == "2") {
        and_operation(arr1, sz1, arr2, sz2, "SET1 AND SET2");
    }
    else if (input == "3") {
        relative_operation(arr1, sz1, arr2, sz2, "SET1 - SET2");
    }
    else if (input == "4") {
        relative_operation(arr2, sz2, arr1, sz1, "SET2 - SET1");
    }
    else if (input == "5") {
        symmetric_operation(arr1, sz1, arr2, sz2, "SET1 SYMMETRIC SET2");
    }
    return;
}
void or_operation(int arr1[], int sz1, int arr2[], int sz2, string set) {
    std::vector<int> Set3;
    std::vector<int> Set3_cpy;
    for (unsigned int i = 0; i < sz1; ++i) {
        Set3.push_back(arr1[i]);
    }
    for (unsigned int i = 0; i < sz2; ++i) {
        Set3.push_back(arr2[i]);
    }

    int cnt = 0;
    for (unsigned int i = 0; i < Set3.size(); ++i) {
        for (unsigned int j = i + 1; j < Set3.size(); ++j) {
            if (Set3[j] == Set3[i]) {
                cnt++;
            }
            else {

            }
        }
        if (cnt == 0) {
            Set3_cpy.push_back(Set3[i]);
        }
        else {
            cnt = 0;
        }
    }
    //Sort vector in ascending order
    int temp, small;
    for (unsigned int i = 0; i < Set3_cpy.size(); ++i) {
        small = i;
        for (unsigned int j = i + 1; j < Set3_cpy.size(); ++j) {
            if (Set3_cpy[j] < Set3_cpy[small]) {
                small = j;
            }
        }
        temp = Set3_cpy[i];
        Set3_cpy[i] = Set3_cpy[small];
        Set3_cpy[small] = temp;
    }

    //Convert vector to array and print new set
    int* arr3 = &Set3_cpy[0];
    print_elements("SET1 OR SET2", arr3, Set3_cpy.size());
    return;
}
void and_operation(int arr1[], int sz1, int arr2[], int sz2, string set) {
    vector<int> Set3;
    int cnt = 0;
    for (unsigned int i = 0; i < sz1; ++i) {
        for (unsigned int j = 0; j < sz2; ++j) {
            if (arr2[j] == arr1[i]) {
                cnt++;
            }
            else {

            }
        }
        if (cnt > 0) {
            Set3.push_back(arr1[i]);
            cnt = 0;
        }
        else {
            cnt = 0;
        }
    }
    //Convert vector to array and print new set
    int* arr3 = &Set3[0];
    print_elements(set, arr3, Set3.size());
    return;
}
void relative_operation(int arr1[], int sz1, int arr2[], int sz2, string set) {
    vector<int> Set3;
    int cnt = 0;
    for (unsigned int i = 0; i < sz1; ++i) {
        for (unsigned int j = 0; j < sz2; ++j) {
            if (arr2[j] == arr1[i]) {
                cnt++;
            }
            else {

            }
        }
        if (cnt == 0) {
            Set3.push_back(arr1[i]);
        }
        else {
            cnt = 0;
        }
    }
    //Convert vector to array and print new set
    int* arr3 = &Set3[0];
    print_elements(set, arr3, Set3.size());
    return;
}
void symmetric_operation(int arr1[], int sz1, int arr2[], int sz2, string set) {
    std::vector<int> Set3;
    int cnt = 0;
    int cnt2 = 0;

    while (cnt != sz1) {
        for (unsigned int i = 0; i < sz1; ++i) {
            if (arr1[i] == arr2[cnt]) {
                cnt2++;
            }
            else {

            }
        }
        if (cnt2 == 0) {
            Set3.push_back(arr2[cnt]);
        }
        else {
            cnt2 = 0;
        }
        cnt++;
    }
    cnt = 0;
    cnt2 = 0;
    while (cnt != sz2) {
        for (unsigned int i = 0; i < sz2; ++i) {
            if (arr2[i] == arr1[cnt]) {
                cnt2++;
            }
            else {

            }
        }
        if (cnt2 == 0) {
            Set3.push_back(arr1[cnt]);
        }
        else {
            cnt2 = 0;
        }
        cnt++;
    }

    //Sort vector in ascending order
    int temp, small;
    for (unsigned int i = 0; i < Set3.size(); ++i) {
        small = i;
        for (unsigned int j = i + 1; j < Set3.size(); ++j) {
            if (Set3[j] < Set3[small]) {
                small = j;
            }
        }
        temp = Set3[i];
        Set3[i] = Set3[small];
        Set3[small] = temp;
    }

    //Convert vector to array and print new set
    int* arr3 = &Set3[0];
    print_elements("SET1 SYMMETRIC SET2", arr3, Set3.size());
    return;
}