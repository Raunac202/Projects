#include <iostream>
#include <vector>

using namespace std;

#include "SortedSet.h"
#include "IntList.h"

SortedSet::SortedSet(){

}
SortedSet::SortedSet(const SortedSet &y) : IntList(y){
  //  IntList(y);
}
SortedSet::SortedSet(const IntList &x) : IntList(x){
  //  IntList(x);
    selection_sort();
    remove_duplicates();
}
SortedSet::~SortedSet(){
    
}
bool SortedSet::in(int value){
    IntNode* tmp = head;
    bool y = false;
    while (tmp != nullptr){
        if (tmp -> value == value){
            y = true;
        }
        else{
            
        }
        tmp = tmp -> next;
    }
    return y;
}
void SortedSet::add(int value){
    IntNode* list = head;
    if (list == nullptr){
        IntNode* temp = new IntNode(value);
        temp -> next = head;
        head = temp;
        if (tail == nullptr){
            tail = head;
        }
        else{
        
        }
    }
    else if (list != nullptr){
        int counter = 0;
        while (list != nullptr){
            if (list -> value == value){
                counter++;
            }
            else{
            
            }
            list = list -> next;
        }
        if (counter > 0){
        
        }
        else{
            insert_ordered(value);
        }
    }
}
void SortedSet::push_front(int val){
    add(val);
}
void SortedSet::push_back(int value){
    add(value);
}
void SortedSet::insert_ordered(int value){
    IntNode* node = new IntNode(value);
    
    //The special cases
    if (head == nullptr){
        node -> next = head; 
        head = node;
        if (tail == nullptr){
            tail = head;
        }
    }
    else if (value <= head -> value){
        int counter = 0;
        IntNode* list = head;
        while (list != nullptr){
            if (list -> value == value){
                counter++;
            }
            else{
            
            }
            list = list -> next;
        }
        if (counter > 0){
        
        }
        else{
            node -> next = head; 
            head = node;
            if (tail == nullptr){
                tail = head;
            }
        }
    }
    else if (value >= tail -> value){
        int counter = 0;
        IntNode* list = head;
        while (list != nullptr){
            if (list -> value == value){
                counter++;
            }
            else{
            
            }
            list = list -> next;
        }
        if (counter > 0){
        
        }
        else{
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
    }
    else{
        int counter = 0;
        IntNode* list = head;
        while (list != nullptr){
            if (list -> value == value){
                counter++;
            }
            else{
            
            }
            list = list -> next;
        }
        if (counter > 0){
        
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
}
SortedSet SortedSet::operator|(const SortedSet &set){
    IntNode* x = head;
    IntNode* y = set.head;
    vector<int> myVector;
    SortedSet list;
    while (x != nullptr && y != nullptr){
        myVector.push_back(x -> value);
        myVector.push_back(y -> value);
        x = x -> next;
        y = y -> next;
    }
    if (x == nullptr){
        while (y != nullptr){
            myVector.push_back(y -> value);
            y = y -> next;
        }
    }
    else if (y == nullptr){
        while (x != nullptr){
            myVector.push_back(x -> value);
            x = x -> next;
        }
    }
    //REUSING CODE FROM PROGRAM 5
    int small;
    for (unsigned int i = 0; i < myVector.size(); ++i){
        small = i;
        for (unsigned int j = i + 1; j < myVector.size(); ++j){
            if (myVector.at(j) == myVector.at(small)){
                myVector.erase(myVector.begin() + j);
            }
            else{

            }
        }
    }
    for (unsigned int i = 0; i < myVector.size(); ++i){
        list.push_front(myVector.at(i));
    }
    return list;
}
SortedSet SortedSet::operator&(const SortedSet &set){
    IntNode* x = head;
    IntNode* y = set.head;
    vector<int> myVector;
    while (x != nullptr && y != nullptr){
        myVector.push_back(x -> value);
        myVector.push_back(y -> value);
        x = x -> next;
        y = y -> next;
    }
    if (x == nullptr){
        while (y != nullptr){
            myVector.push_back(y -> value);
            y = y -> next;
        }
    }
    else if (y == nullptr){
        while (x != nullptr){
            myVector.push_back(x -> value);
            x = x -> next;
        }
    }
    //REUSING CODE FROM PROGRAM 5
    int small;
    SortedSet list;
    for (unsigned int i = 0; i < myVector.size(); ++i){
        small = i;
        for (unsigned int j = i + 1; j < myVector.size(); ++j){
            if (myVector.at(j) == myVector.at(small)){
                list.push_front(myVector.at(j));
            }
        }
    }
    return list;
}
SortedSet SortedSet::operator|=(const SortedSet &set){
    IntNode* x = head;
    IntNode* y = set.head;
    vector<int> list;
    while (x != nullptr && y != nullptr){
        list.push_back(x -> value);
        list.push_back(y -> value);
        x = x -> next;
        y = y -> next;
    }
    if (x == nullptr){
        while (y != nullptr){
            list.push_back(y -> value);
            y = y -> next;
        }
    }
    else if (y == nullptr){
        while (x != nullptr){
            list.push_back(x -> value);
            x = x -> next;
        }
    }
    clear();
    for (unsigned int i = 0; i < list.size(); ++i){
        push_front(list.at(i));
    }
    return *this;
}
SortedSet SortedSet::operator&=(const SortedSet &set){
    IntNode* x = head;
    IntNode* y = set.head;
    vector<int> myVector;
    while (x != nullptr && y != nullptr){
        myVector.push_back(x -> value);
        myVector.push_back(y -> value);
        x = x -> next;
        y = y -> next;
    }
    if (x == nullptr){
        while (y != nullptr){
            myVector.push_back(y -> value);
            y = y -> next;
        }
    }
    else if (y == nullptr){
        while (x != nullptr){
            myVector.push_back(x -> value);
            x = x -> next;
        }
    }
    //REUSING CODE FROM PROGRAM 5
    int small;
    vector<int> list;
    for (unsigned int i = 0; i < myVector.size(); ++i){
        small = i;
        for (unsigned int j = i + 1; j < myVector.size(); ++j){
            if (myVector.at(j) == myVector.at(small)){
                list.push_back(myVector.at(j));
            }
        }
    }
    clear();
    for (unsigned int i = 0; i < list.size(); ++i){
        push_front(list.at(i));
    }
    return *this;
}