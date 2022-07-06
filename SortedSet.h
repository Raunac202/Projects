#ifndef SORTEDSET_H
#define SORTEDSET_H

#include <iostream>
#include <vector>
#include <ostream>

using namespace std;

#include "IntList.h"

class SortedSet : public IntList{
    public:
    // Constructors and Destructors
    SortedSet();
    SortedSet(const SortedSet &);
    SortedSet(const IntList &);
    ~SortedSet();
    
    public:
    // Accessors
    bool in(int value);
    SortedSet operator|(const SortedSet &);
    SortedSet operator&(const SortedSet &);
    
    public:
    // Mutators
    void add(int value);
    void insert_ordered(int);
    void push_front(int);
    void push_back(int);
    SortedSet operator|=(const SortedSet &);
    SortedSet operator&=(const SortedSet &);
};

#endif