#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"
#include <iostream>
using namespace std;
template <class K, class D>
class Stack
{
private:
    LinkedList<K,D> List;
public:
    Stack();
    void Push(const K & p_key, const D & p_dato);
    void Pop();
    K Top();
    void Print();
    ~Stack();

};

#include "Stack.inl"
#endif // STACK_H
