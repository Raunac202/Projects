#include <iostream>
#include <vector>

using namespace std;

#include "IntList.h"

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}
IntList::~IntList(){
    while (head != nullptr && tail != nullptr){
        pop_front();
    }
} 
void IntList::push_front(int val){
    IntNode* temp = new IntNode(val);  
    temp -> next = head; 
    head = temp;
    if (tail == nullptr){
        tail = head;
    }
    else{
        
    }
}
void IntList::pop_front(){
    if (head != nullptr){
        IntNode* tmp;
        tmp = head;
        tmp = tmp -> next;
        delete head;
        head = tmp;
    }
    if (head == nullptr){
        tail = nullptr;
    }
}
bool IntList::empty() const{
    bool x = false;
    if (head == nullptr && tail == nullptr){
        x = true;
    }
    else{
        x = false;
    }
    return x;
}
const int & IntList::front() const{
    IntNode* tmp;
    tmp = head;
    return tmp -> value;
}
const int & IntList::back() const{
    IntNode* tmp;
    tmp = tail;
    return tmp -> value;
}
ostream & operator<<(ostream &out, const IntList &y){
    IntNode* x;
    x = y.head;
    while (x != nullptr){
        if (x == y.tail){
            out << x->value;
            x = x -> next;
        }
        else{
            out << x -> value << ' ';
            x = x -> next;
        }
    }
    return out;
}
void IntList::push_back(int value){
    vector<int> myVec;      //NOT NEEDED
    myVec.push_back(value); //NOT NEEDED

    IntNode* node = new IntNode(value);
    IntNode* x = head;
    if (head == nullptr){     // If list is empty make head point to the new "node"
        head = node;
    }
    if (tail == nullptr){    // If List is empty make tail point to the same "node" as head.
        tail = head;
    }
    else{   
        while (x != nullptr){                                                              
            x = x -> next; 
        }
        if (x == nullptr){
            x = node;
        }
        else{
            
        }
        tail -> next = x;
    }
    tail = node;
}
void IntList::selection_sort(){
    IntNode* x = head;
    vector<int> myVector;
    while (x != nullptr){
        myVector.push_back(x -> value);
        x = x -> next;
    }
    //REUSING CODE FROM PROGRAM 1
    int temp, small;
    for (unsigned int i = 0; i < myVector.size(); ++i){
        small = i;
        for (unsigned int j = i + 1; j < myVector.size(); ++j){
            if (myVector.at(j) < myVector.at(small)){
                small = j;
            }
        }
        temp = myVector.at(i);
        myVector.at(i) = myVector.at(small);
        myVector.at(small) = temp;
    }
    IntNode* y = head;
    for (unsigned int i = 0; i < myVector.size(); ++i){
        y -> value = myVector.at(i);
        y = y -> next;
    }
}
void IntList::insert_ordered(int value){
    IntNode* node = new IntNode(value);

    //The special cases
    if (head == nullptr){
        push_front(value);
    }
    else if (value <= head -> value){
        push_front(value);
    }
    else if (value >= tail -> value){
        push_back(value);
    }
    
    else{
        IntNode* prev = head;
        IntNode* curr = head -> next;
        if (node -> value <= curr -> value && node -> value >= prev -> value){
                prev -> next = node;
                node -> next = curr;
        }
        else{
            while (curr -> next != nullptr){
                prev = prev -> next;
                curr = curr -> next;
                if (node -> value <= curr -> value && node -> value >= prev -> value){
                    prev -> next = node;
                    node -> next = curr;
                    break;
                }
            }
        }
    }
}
void IntList::remove_duplicates(){
    IntNode* i = head;
    
    if (i == nullptr){
        
    }
    else{
        IntNode* temp = head;
        IntNode* temp2 = head -> next;
        while (i -> next != nullptr){
            if (i -> value == temp2 -> value){
                temp -> next = temp2 -> next;
                if (temp2 == tail){
                    tail = temp;
                }
                delete temp2;
                temp2 = nullptr;
                temp2 = temp -> next;
            }
            else{
                temp = temp -> next;
                temp2 = temp2 -> next;
            }
            if (temp2 == nullptr){
                i = i -> next;
                temp = i;
                temp2 = i;
                if (temp2 != nullptr){
                    temp2 = temp2 -> next;
                }
                if (i == nullptr){
                    break;
                }
            }
        }
    }
}
void IntList::clear(){
    while (head != nullptr && tail != nullptr){
        pop_front();
    }
}
IntList::IntList(const IntList &cpy){
    IntNode* curr = cpy.head;
    IntNode* temp;
    head = nullptr;
    tail = nullptr;
    while (curr != nullptr) {
        if (head == nullptr && tail == nullptr) {
            temp = new IntNode(curr -> value);
            head = temp;
            tail = head;
        }
        else {
            temp = new IntNode(curr -> value);
            tail -> next = temp;
        }
        curr = curr -> next;
        tail = temp;
        if (curr != nullptr){
            temp = temp -> next;
        }
    }
}
IntList & IntList::operator=(const IntList &rhs){
    if (this != &rhs){
        IntNode* x = rhs.head;
        if (x != nullptr){
            clear();
        }
    
        IntNode* curr = rhs.head;
        IntNode* temp;
        head = nullptr;
        tail = nullptr;
        while (curr != nullptr) {
            if (head == nullptr && tail == nullptr) {
                temp = new IntNode(curr -> value);
                head = temp;
                tail = head;
            }
            else {
                temp = new IntNode(curr -> value);
                tail -> next = temp;
            }
            curr = curr -> next;
            tail = temp;
            if (curr != nullptr){
                temp = temp -> next;
            }
        }
    }
    else{
        
    }
    return *this;
}

//NOT USED IN PROGRAM 5
IntNode * IntList::min(IntNode *){
    return nullptr;
}
void IntList::copy(const IntList &){
    return;
}