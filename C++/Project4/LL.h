/*
  *  LL.h
  *
  *  COSC 052 Fall 2021
  *  Project #3
  *
  *  Due on: OCT 28, 2021
  *  Author: Patrick Cronin PJC269
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






#ifndef _COSC052_FALL2021_P3_LL_h_
#define _COSC052_FALL2021_P3_LL_h_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

#include "Exceptions.h"
#include "Resources.h"

#define DEBUG_LL_POP_BACK
//#define DEBUG_COPY_LIST
//#define DEBUG_LL_INSERT

using std::vector;
using std::string;
using std::endl;
using std::cout;


const int LOOP_OUTPUT_FREQUENCY = 5000;   //new for P3 (optional)
const int SORT_OUTPUT_FREQUENCY = 750;    //new for P3 (optional)

/**********************************************************
 *                                                        *
 *                                                        *
 *                  Project #3 classes                    *
 *                                                        *
 *                                                        *
 **********************************************************/



/****************************************************************************
 *                                                                          *
 *                       class Node declaration                             *
 *                                                                          *
 ****************************************************************************/


template <typename T>
class Node
{
public:
    T info;
    Node<T> *next;
    Node<T> *previous;

    Node(T = T(), Node<T> *next = NULL, Node<T> *previous = NULL);

}; //END declaration templatized class Node




/****************************************************************************
 *                                                                          *
 *                   class LL_iterator declaration                          *
 *                                                                          *
 ****************************************************************************/

template <typename T>
class LL_iterator
{

private:
    Node<T> *current;
    //pointer to point to the current
    //node in the linked list

public:

    LL_iterator()
    {
        current = NULL;
    }
    //default constructor
    //Postcondition: current = NULL;

    LL_iterator(Node<T> *ptr)
    {
        current=ptr;
    }
    //constructor with parameter
    //Postcondition: current = ptr;

    T& operator*()
    {
        return current->info;
    }
    //overloaded dereferencing operator
    //Postcondition: Returns a reference to the info contained in the node

    LL_iterator<T> operator++()
    {
        current = current->next;
        return current;
    }
    //overloaded pre-increment operator
    //Postcondition: The iterator is advanced to the next node in the linked list

    LL_iterator<T> operator--()
    {
        current = current->previous;
        return current;
    }
    //overloaded pre-decrement operator
    //Postcondition: The iterator is moved to the previous node in the linked list

    bool operator==(const LL_iterator<T> &rhsObj) const
    {
        bool truth = false;
        if(rhsObj == this)
        {
            truth = true;
        }

        return truth;
    }
    //overloaded equality operator
    //Postcondition: Returns true if this iterator is equal to the
    //               iterator specified on the right hand side
    //               otherwise returns false

    bool operator!=(const LL_iterator<T> &rhsObj) const
    {
        bool truth = false;
        if(rhsObj != this)
        {
            truth = true;
        }

        return truth;
    }
    //overloaded equality operator
    //Postcondition: Returns true if this iterator is NOT equal to the
    //               iterator specified on the right hand side
    //               otherwise returns false


}; //END class LL_iterator






/****************************************************************************
 *                                                                          *
 *                        class LL declaration                              *
 *                                                                          *
 ****************************************************************************/


template <typename T>
class LL
{
    template <typename F>
    friend std::ostream& operator<<(std::ostream& os, const LL<F> &rhsObj);

private:
    unsigned count;
    Node<T> *header;
    Node<T> *trailer;

    void initialize();
    void copyList(const LL<T>&);
    void remove(unsigned ndx);

public:

    LL();
    LL(const LL<T>&);
    ~LL();

    LL<T>& operator=(const LL<T>&);

    void insert(unsigned ndx, T);

    void push_back(T);
    void pop_back();
    T& back() const;

    void push_front(T);
    void pop_front();
    T& front() const;

    void clear();
    bool empty() const;
    unsigned size() const {return count;}

    T& at(unsigned ndx) const;
    T& operator[](unsigned ndx) const;

    T* toArray() const;

    void bubbleSort();
    void bubbleSortI();
    void selectionSort();
    void insertionSort();
    unsigned linearSearch(T lookFor) const;
    unsigned binarySearch(T lookFor) const;


}; //END declaration templatized class LL




/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                      class Node implementation                         **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/



/****************************************************************************
 *                         default constructor                              *
 ****************************************************************************/

template <typename T>
Node<T>::Node(T infoValue, Node<T> *nPtr, Node<T> *pPtr)
{
    info = infoValue;
    next = nPtr;
    previous = pPtr;
} //END Node<T>::Node(T infoValue, Node *nodePtr)


/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                       class LL implementation                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/



/****************************************************************************
 *              non-member function overloaded operator<<                   *
 ****************************************************************************/

template <typename T>
std::ostream& operator<<(std::ostream& os, const LL<T> &rhsObj)
{
    Node<T> *current = rhsObj.header->next;

    while (current != rhsObj.trailer)
    {
        os << current->info;
        current = current->next;
    }

    return os;

} //END overloaded stream insertion operator for LL<T> class



/****************************************************************************
 *                  private method copyList of LL class                     *
 ****************************************************************************/

template <typename T>
void LL<T>::copyList(const LL<T> &otherLL)
{

    if(!this->empty())
    {
        this->clear();
        //this->initialize(); ???
    }

    if(!otherLL.empty())
    {
        for (int i = 0; i < otherLL.size(); i++)
        {
            this->push_back(otherLL.at(i));
        }
    }




} //END function copyList(const LL &otherLL)



/****************************************************************************
 *                 private method initialize of LL class                    *
 ****************************************************************************/

template <typename T>
void LL<T>::initialize()
{

    header ->previous = header;
    trailer->next = trailer;
    header ->next =trailer;
    trailer->previous = header;

    count = 0;


} //END private method LL<T>::initialize



/****************************************************************************
 *                 private method remove of LL class                    *
 ****************************************************************************/

template <typename T>
void LL<T>::remove(unsigned ndx)
{
    if(count-1<ndx || ndx < 0)
    {
        throw std::out_of_range("error in insert function");
    }

    Node<T> *current = header->next;
    Node<T> *trailCurrent, *headCurrent;

    for (int i = 0; i < ndx; ++i)
    {
        current=current->next;
    }
    trailCurrent = current->previous;
    headCurrent = current->next;
    trailCurrent->next=headCurrent;
    headCurrent->previous=trailCurrent;
    delete current;

    count--;


} // END remove member function of class LL



/****************************************************************************
 *                         default constructor                              *
 ****************************************************************************/

template <typename T>
LL<T>::LL()
{
    cout << "entered constructor for LL class" << endl;

    count=0;
    header= new Node<T>;
    trailer = new Node<T>;
    initialize();

    cout << "exiting constructor for LL class" << endl;


} //END default constructor for LL class



/****************************************************************************
 *                    copy constructor of LL class                          *
 ****************************************************************************/

template <typename T>
LL<T>::LL(const LL<T> &otherLL)
{
    header= new Node<T>;
    trailer = new Node<T>;
    initialize();
    count=0;
    copyList(otherLL);

} //END LL<T>::LL(const LL<T> &otherLL)



/****************************************************************************
 *                         destructor of LL class                           *
 ****************************************************************************/

template <typename T>
LL<T>::~LL()
{
    cout << "entered destructor for LL class" << endl;

    this->clear();

    delete header;
    delete trailer;

    cout << "exiting destructor for LL class" << endl;

} //END LL<T>::~LL()



/****************************************************************************
 *                 member function overloaded operator=                     *
 ****************************************************************************/


template <typename T>
LL<T>& LL<T>::operator=(const LL<T> &rhsLL)
{
    if(!this->empty())
    {
        this->clear();
    }

    this->copyList(rhsLL);
    return *this;

} // END LL<T>::operator=(const LL<T> &rhsLL)



/****************************************************************************
 *                         member function insert                           *
 ****************************************************************************/

template <typename T>
void LL<T>::insert(unsigned ndx, T infoToAdd)
{
    if(count-1<ndx || ndx < 0)
    {
        throw std::out_of_range("error in insert function");
    }

    Node<T> *addMe= new Node<T>(infoToAdd, NULL, NULL);


    Node<T> *trailCurrent = header;
    Node<T> *current = header->next;

    for(int i =0; i<ndx; i++)
    {
        current = current->next;
    }


    trailCurrent = current->previous;


    addMe->next = current;
    addMe->previous = trailCurrent;
    current->previous = addMe;
    trailCurrent->next = addMe;

    count++;



} //END memmber function insert



/****************************************************************************
 *                        member function push_back                         *
 ****************************************************************************/

template <typename T>
void LL<T>::push_back(T infoToAdd)
{
#ifdef DEBUG_LL_PUSH_BACK
    cout << "Entered function LL<T>::push_back() " << endl;
#endif




    Node<T> *addMe = new Node<T>(infoToAdd, NULL, NULL);

    if(!addMe)
    {
        throw std::bad_alloc();
    }

    if ( header->next == trailer )
    {

        header->next = addMe;
        trailer->previous = addMe;
        addMe->previous=header;
        addMe->next=trailer;
    }
    else
    {


        Node<T> *current = trailer->previous;

        current->next = addMe;
        trailer->previous = addMe;

        addMe->previous=current;
        addMe->next=trailer;


    }

    count++;

#ifdef DEBUG_LL_PUSH_BACK
    cout << "Exiting function LL::push_back() " << endl;
#endif

} //END LL<T>::push_back(T infoToAdd)



/****************************************************************************
 *                        member function pop_back                          *
 ****************************************************************************/

template <typename T>
void LL<T>::pop_back()
{
    if(this->empty())
    {
        throw no_such_object("error in back function");
    }

    if ( header->next == trailer )
    {
        std::cout << "list is empty... nothing to do." << std::endl;
        // throw an exception here
    }
    else if ( header->next->next == trailer )
    {
        delete header->next;

        header->next=trailer;
        trailer->previous=header;

        count--;
    }
    else
    {
        Node<T> *current = trailer->previous->previous;

        delete current->next;
        current->next=trailer;
        trailer->previous= current;

        count--;
    }



} //END LL<T>::pop_back()



/****************************************************************************
 *                          member function back                            *
 ****************************************************************************/

template <typename T>
T& LL<T>::back() const
{
    if(this->empty())
    {
        throw no_such_object("error in back function");
    }
    Node<T> * current = trailer->previous;
    return current->info; // NOTE!!! replace with correct return

} // END function back, class LL



/****************************************************************************
 *                       member function push_front                         *
 ****************************************************************************/

template <typename T>
void LL<T>::push_front(T infoToAdd)
{
    Node<T> *addMe = new Node<T>(infoToAdd, NULL, NULL);

    if(!addMe)
    {
        throw std::bad_alloc();
    }


    if ( header->next == trailer )
    {

        header->next = addMe;
        trailer->previous = addMe;
        addMe->previous=header;
        addMe->next=trailer;
    }
    else
    {

        Node<T> *current = header->next;

        current->previous = addMe;
        header->next = addMe;

        addMe->previous=header;
        addMe->next=current;

    }

    count++;

#ifdef DEBUG_LL_PUSH_BACK
    cout << "Exiting function LL::push_back() " << endl;
#endif


} //END LL::push_front(T infoToAdd)



/****************************************************************************
 *                       member function pop_front                          *
 ****************************************************************************/

template <typename T>
void LL<T>::pop_front()
{
    if ( header->next == trailer )
    {
        std::cout << "list is empty... nothing to do." << std::endl;
        // throw an exception here
    }
    else if ( header->next->next == trailer )
    {
        delete header->next;

        header->next=trailer;
        trailer->previous=header;

        count--;
    }
    else
    {
        Node<T> *current = header->next->next;

        delete current->previous;
        current->previous=header;
        header->next= current;

        count--;
    }




} //END LL<T>::pop_front()



/****************************************************************************
 *                          member function front                           *
 ****************************************************************************/

template <typename T>
T& LL<T>::front() const
{
    if(this->empty())
    {
        throw no_such_object("error in front function");
    }
    Node<T> * current = header->next;
    return current->info; // NOTE!!! replace with correct return

    //return NULL; // NOTE!!! replace with correct return

} // END method front of class LL



/****************************************************************************
 *                         member function clear                            *
 ****************************************************************************/

template <typename T>
void LL<T>::clear()
{
    cout << "entered clear method, there are " << count << " Nodes on the linked list\n";
    Node<T> *current = header->next;
    Node<T> *delNode;

    int curCount = count;

    unsigned long deleteCount = 0;

    for(int i=0; i<curCount; i++)
    {
        delNode = current;
        current = current->next;

        delete delNode;

        count--;

        deleteCount++;
    }

    header->next = trailer;
    trailer->previous=header;

    cout << "leaving clear method, there were " << deleteCount << " Node objects deallocated\n";
    cout<<count;


} //END LL<T>::clear()



/****************************************************************************
 *                        method empty of LL class                          *
 ****************************************************************************/

template <typename T>
bool LL<T>::empty() const
{
    bool answer = true;

    if(count!=0)
    {
        answer= false;
    }

    return answer;

} // END LL<T>::empty



/****************************************************************************
 *                         member function at const                         *
 ****************************************************************************/

template <typename T>
T& LL<T>::at(unsigned location) const
{
    if(count-1<location || location < 0)
    {
        throw std::out_of_range("error in at function");
    }
    Node<T> *current = header;
    for(int i=0; i<=location; i++)
    {
        current=current->next;
    }
    return current->info; // NOTE!!! Replace with correct return


} //END LL::at(int location)



/****************************************************************************
 *                       overloaded operator[] const                        *
 ****************************************************************************/

template <typename T>
T& LL<T>::operator[](unsigned ndx) const
{
    if(count-1<ndx || ndx < 0)
    {
        throw std::out_of_range("help");
    }
    T inf = this->at(ndx);
    return inf; // NOTE!!! Replace with correct return
    // Think of ways to reuse existing code

} //END overloaded subscript operator



/****************************************************************************
 *                         member function toArray                          *
 ****************************************************************************/

template <typename T>
T* LL<T>::toArray() const
{
    T array[count];
    for(int i=0; i<count; i++)
    {
        array[i]=this->at(i);
    }

    // IMPORTANT NOTE!!!
    // remember that the code calling this method is responsible
    // for deallocating this dynamically allocated array



    return array;  // NOTE!!!!  Replace with correct return

} // END LL<T>::toArray()



/****************************************************************************
 *                       member function bubbleSort                         *
 ****************************************************************************/

template <typename T>
void LL<T>::bubbleSort()
{
    cout << "Entered member function bubbleSort()" << endl;

    unsigned swapCount = 0;

    char temp = '?';
    int iteration = 0;
    int index = 0;
    unsigned length = size();

    double outputPercent = 0.1;
    int outputNumber = ( (outputPercent * length > 1)? outputPercent * length : 1 );

    bool hadSwap = true;

    T compInfo;

    Node<T> *current;


    for ( iteration = 1; iteration < length && hadSwap; iteration++ )
    {
        current = header->next;
//        cout << current->info;
        hadSwap = false;
        for ( index = 0; index < length - iteration; index++ )
        {
#ifdef __DEBUG_BUBBLE_SORT__
            cout << "checking order " << list[index] << " " << list[index+1] << endl;
#endif
            if (this->at(index) > this->at(index+1))
            {
#ifdef __DEBUG_BUBBLE_SORT__
                cout << "swapping values" << endl;
#endif
                hadSwap = true;
                compInfo = this->at(index);


                current->info= this->at(index+1);
                current=current->next;
                current->info = compInfo;
                swapCount++;
            }
            else
            {
                current=current->next;
            }

        } // END inner loop

        // output diagnostic information for outputPercent% of the iterations
        if ( iteration == 1 || iteration % outputNumber == 0 )
        {
            cout << "Iteration " << iteration << " ";
            cout << ( (hadSwap) ? "made swap this iteration." : "no swaps, all done" ) << endl;
        }

    } // END outer loop
    cout << "Exiting member function bubbleSort() \nresults: swapCount = " << swapCount << endl;

} //END member function LL<T>::bubbleSort()




/****************************************************************************
  *                      member function bubbleSortI                         *
  ****************************************************************************/

template <typename T>
void LL<T>::bubbleSortI()
{
    cout<< this->header->next->info;
    LL_iterator<T> iterFirst(this->header);
    LL_iterator<T> iterSec(this->header->next);

//    cout<< "first: " << iterFirst.operator*()<<endl;
//    cout<< "sec: " << iterSec.operator*()<<endl;




    cout << "Entered member function bubbleSortI()" << endl;

    unsigned swapCount = 0;


    unsigned length = size();

    double outputPercent = 0.1;
    int outputNumber = ( (outputPercent * length > 1)? outputPercent * length : 1 );
    int iteration;

    bool hadSwap = true;

    T compInfo;


    for ( int iteration = 1; iteration < length && hadSwap; iteration++ )
    {
        LL_iterator<T> iterFirst(this->header);
        LL_iterator<T> iterSec(this->header->next);
        iterFirst.operator++();
        iterSec.operator++();

        hadSwap = false;
        for (int index = 0; index < length - iteration; index++ )
        {


#ifdef __DEBUG_BUBBLE_SORT__
            cout << "checking order " << list[index] << " " << list[index+1] << endl;
#endif
            if (iterFirst.operator*() > iterSec.operator*())
            {
#ifdef __DEBUG_BUBBLE_SORT__
                cout << "swapping values" << endl;
#endif
                hadSwap = true;

                compInfo = iterFirst.operator*();

                iterFirst.operator*()= iterSec.operator*();
                iterSec.operator*() = compInfo;
                iterFirst.operator++();
                iterSec.operator++();
                swapCount++;
            }
            else
            {
               iterFirst.operator++();
               iterSec.operator++();
            }

        } // END inner loop

        // output diagnostic information for outputPercent% of the iterations
        if ( iteration == 1 || iteration % outputNumber == 0 )
        {
            cout << "Iteration " << iteration << " ";
            cout << ( (hadSwap) ? "made swap this iteration." : "no swaps, all done" ) << endl;
        }

    } // END outer loop
    cout << "Exiting member function bubbleSort() \nresults: swapCount = " << swapCount << endl;


} //END member function LL<T>::bubbleSortI()







/****************************************************************************
 *                     member function selectionSort                        *
 ****************************************************************************/

template <typename T>
void LL<T>::selectionSort()
{
    cout << "Entered function selectionSort() " << endl;

    unsigned swapCount = 0;

    int index;
    int smallestIndex;
    int location=0;
    T temp;

    int length=size();



    for (index=0; index<length-1; index++)
    {
        smallestIndex = index;

        for(location=index; location<length; location++)
        {
            if(this->at(location)<this->at(smallestIndex))
                smallestIndex = location;
        }


        temp= this->at(smallestIndex);
        Node<T> *current = header->next;
        for(int i=0; i<smallestIndex;i++)
        {
            current = current->next;
        }
        current->info = this->at(index);

        current = header->next;
        for(int i=0; i<index;i++)
        {
            current = current->next;
            swapCount++;
        }
        current->info=temp;


    }


    cout << "Exiting function selectionSort() \nresults: swapCount = " << swapCount << endl;

} // END void LL<T>::selectionSort()



/****************************************************************************
 *                     member function insertionSort                        *
 ****************************************************************************/

template <typename T>
void LL<T>::insertionSort()
{

    unsigned swapCount = 0;

    int firstOutOfOrder, location;
    T temp;
    int listLength=size();
    Node<T> *current, *dest;


    for (firstOutOfOrder = 1; firstOutOfOrder < listLength; firstOutOfOrder++)
    {
        current = header;
        if (this->at(firstOutOfOrder) < this->at(firstOutOfOrder - 1))
        {

            temp = this->at(firstOutOfOrder);
            location = firstOutOfOrder;

            for (int i = 0; i < firstOutOfOrder; i++) {
                current = current->next;
            }
            dest = current->next->next;
            current->next=dest;
            dest->previous=current;

            do {
                location--;
            } while (location > 0 && this->at(location - 1) > temp);

            insert(location, temp);
            count--;
            swapCount++;
        }
    }

    cout << "Exiting function InsertionSort() \nresults: swapCount = " << swapCount << endl;

} // END void LL<T>::insertionSort()



/****************************************************************************
 *                      member function linearSearch                        *
 ****************************************************************************/

template <typename T>
unsigned LL<T>::linearSearch(T lookFor) const
{
//    cout << "Entered function linearSearch(" << lookFor << ")" << endl;

    int index = -1;

    for(int i=0; i<size(); i++)
    {
        if(lookFor== this->at(i))
        {
            index=i;
        }
    }

    if (index == -1)
    {
        throw no_such_object("error in binary search function");
    }


//    cout << "Exiting function linearSearch()" << endl;

    return index;


} // END unsigned LL<T>::linearSearch(T lookFor)



/****************************************************************************
 *                      member function binarySearch                        *
 ****************************************************************************/

template <typename T>
unsigned LL<T>::binarySearch(T lookFor) const
{
    cout << "Entered function binarySearch" << endl;

    bool found = false;

    long  first = 0;
    long  last = size() - 1;
    long  middle  = 0;
    long position = -1;

    Node<T> *current =header;
    middle = (last - first)/2;

    while(!found && (middle<this->size() || middle == 0))
    {
        cout<<"middle:"<<middle<<endl;

        if(this->at(middle)>lookFor)
        {
            last = middle;
            middle = (last - first)/2;
        }
        else if(this->at(middle)<lookFor)
        {
            first = middle;
            middle = middle+(last - first)/2 +1;
        }
        else if(this->at(middle)==lookFor)
        {
            position = middle;
            found = true;
        }
        else if((middle == this->size()-1) && (this->at(middle)!=lookFor))
        {
            throw no_such_object("error in binary search function");
        }
    }





    if (position ==-1)
    {
        throw no_such_object("error in binary search function");
    }


    return position;

} // END unsigned LL<T>::binarySearch(T lookFor)






#endif /*  _COSC052_FALL2021_P3_LL_h_  */