#include <iostream>

using namespace std;

#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"

int main(){
    LinkedList<int, int> list;
    Queue<int,int> queue;
    Stack<int,int> stack;

    queue.PushBack(1,23);
    queue.PushBack(2,23);
    queue.PushBack(3,23);
    queue.PushBack(4,23);
    queue.Pop();
    queue.Top();
    queue.Print();

    cout<<endl;

    stack.Push(1,23);
    stack.Push(2,23);
    stack.Push(3,23);
    stack.Push(4,23);
    stack.Pop();
    stack.Top();
    stack.Print();

    /*list.InsertFront(1,23);
    list.InsertFront(2,12);
    list.InsertBack(3,45);
    list.Show();
    cout<<endl;
    list.InsertFront(4,21);
    list.InsertFront(5,48);
    list.Show();
    cout<<endl;
    list.RemoveFront();
    list.Show();
    cout<<endl;
    list.RemoveBack();
    list.Show();
    cout<<endl;
    list.InsertBack(7,23);
    list.Show();*/

    return 0;
}
