#include <iostream>

using namespace std;

#include "IntList.h"
#include "SortedSet.h"

int main(){
    
/*    //Testing in function
    SortedSet test1;
    test1.push_front(1);
    test1.push_front(2);
    test1.push_front(3);
    test1.push_front(5);
    test1.push_front(4);
    if (test1.in(5)){
        cout << "value found" << endl;
    }
    else{
        cout << "Value NOT found" << endl;
    }
*/
    //Testing | operator
    SortedSet test;
    test.push_front(1);
    test.push_front(2);
    test.push_front(3);
    test.push_front(5);
    test.push_front(4);
    SortedSet test2;
    test2.push_front(10);
    test2.push_front(9);
    test2.push_front(8);
    SortedSet test3;
    test3 = test | test2;
    cout << test3 << endl;

/*    //Testing add function
    SortedSet test4;
    test4.add(14);
    test4.add(37);
    test4.add(55);
    test4.add(14);
    cout << test4 << endl;
*/
/*    //Testing insert (override version)
    SortedSet test5;
    test5.insert_ordered(11);
    test5.insert_ordered(11);
    test5.insert_ordered(39);
    test5.insert_ordered(39);
    test5.insert_ordered(52);
    test5.insert_ordered(52);
    cout << test5 << endl;
*/
/*    //Testing push_front() and push_back() functions (override versions)
    SortedSet test6;
    test6.push_back(21);
    test6.push_back(23);
    test6.push_back(25);
    test6.push_back(27);
    test6.push_back(29);
    cout << test6 << endl;
*/   
/*    //Testing & operator
    SortedSet test7;
    test7.push_front(31);
    test7.push_front(33);
    test7.push_front(24);
    test7.push_front(40);
    SortedSet test8;
    test8.push_front(1);
    test8.push_front(24);
    test8.push_front(31);
    test8.push_front(59);
    SortedSet test9;
    test9 = test7 & test8;
    cout << test9 << endl;
*/
/*    //Testing |= operator
    SortedSet test10;
    test10.push_front(1);
    test10.push_front(33);
    test10.push_front(24);
    test10.push_front(40);
    SortedSet test11;
    test11.push_front(10);
    test11.push_front(87);
    test11.push_front(31);
    test11.push_front(59);
    test10 |= test11;
    cout << test10 << endl;
*/
/*    //Testing &= operator
    SortedSet test12;
    test12.push_front(3);
    test12.push_front(5);
    test12.push_front(7);
    test12.push_front(9);
    SortedSet test13;
    test13.push_front(17);
    test13.push_front(18);
    test13.push_front(5);
    test13.push_front(9);
    test12 &= test13;
    cout << test12 << endl;
*/    
    return 0;
}