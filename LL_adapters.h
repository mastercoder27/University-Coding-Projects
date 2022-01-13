/*
  *  LL_adapters.h
  *
  *  COSC 052 Fall 2021
  *  Project #4
  *
  *  Due on: NOV 11, 2021
  *  Author: <your name>  <your netID>
  *
  *
  *  In accordance with the class policies and Georgetown's
  *  Honor Code, I certify that, with the exception of the
  *  class resources and those items noted below, I have neither
  *  given nor received any assistance on this project.
  *
  *  References not otherwise commented within the program source code.
  *  Note that you should not mention any help from the TAs, the professor,
  *  or any code taken from the class textbooks.
  */



#ifndef __COSC052_P4_LL_ADAPTERS_H__
#define __COSC052_P4_LL_ADAPTERS_H__

#include "LL.h"

/****************************************************************************
 *                      class Stack declaration                             *
 ****************************************************************************/

template <typename T, typename S >
class Stack
{
private:
    S s;

public:
    bool empty() const;
    void pop();
    void push(T value);
    unsigned size() const;
    T& top() const;


    //
//    void pop(){stack.pop_front();}
//    void push(T value){stack.push_front();}
//    T& top(){return stack.front();}
//    unsigned long size(){return stack.size();}
//    bool empty(){return stack.empty();}

}; // END class Stack



/****************************************************************************
 *                      class Queue declaration                             *
 ****************************************************************************/

template <typename T, typename Q >
class Queue
{
private:
    Q q;

public:
    bool empty() const;
    void dequeue( T& value );
    void enqueue( T value );
    void clear();
    unsigned size() const;


//    unsigned size() { return queue.size();}
//    bool isempty(){return queue.empty();}
//    void clear(){queue.clear();}
//
//    void enqueue(T value){queue.push_back(value);}
//    void dequeue(T &value){ value=queue.front(); queue.pop_front();}
}; // END class Queue











/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                     class Stack implementation                         **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

template <typename T, typename S >
bool Stack<T,S>::empty() const
{
    return s.empty();

} // END empty method of Stack class



template <typename T, typename S >
void Stack<T,S>::pop()
{
    if(this->empty())
    {
        throw no_such_object("stack is empty \n");
    }

    s.pop_front();

} // END pop method of Stack class



template <typename T, typename S >
void Stack<T,S>::push(T value)
{

    s.push_front(value);

} // END push method of Stack class



template <typename T, typename S >
unsigned Stack<T,S>::size() const
{
    return s.size();
}



template <typename T, typename S >
T& Stack<T,S>::top() const
{
    if(this->empty())
    {
        throw no_such_object("stack is empty \n");
    }
    return s.front();
}



/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                     class Queue implementation                         **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

template <typename T, typename Q >
bool Queue<T, Q>::empty() const
{
    return q.empty();  // NOTE: Replace with your real code
}



template <typename T, typename Q >
void Queue<T, Q>::dequeue( T& value )
{
    if(this->empty())
    {
        throw no_such_object("queue is empty \n");
    }
    value = q.front();
    q.pop_front();
}


template <typename T, typename Q >
void Queue<T, Q>::enqueue( T value )
{
    q.push_back(value);
}



template <typename T, typename Q >
void Queue<T, Q>::clear()
{
    q.clear();
}



template <typename T, typename Q >
unsigned Queue<T, Q>::size() const
{
    return q.size();
}











#endif /*  __COSC052_P4_LL_ADAPTERS_H__  */