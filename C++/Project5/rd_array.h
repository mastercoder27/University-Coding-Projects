/*
  * <FileName>.<file extension>
  *
  *  COSC 052 Fall 2021
  *  Project #5
  *
  *  Due on: Nov 30, 2021
  *  Author: Patrick Cronin  pjc269
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




#ifndef _COSC052_FALL2021_P5_RD_ARRAY_H_
#define _COSC052_FALL2021_P5_RD_ARRAY_H_


using std::bad_alloc;
using std::out_of_range;
using std::exception;
using std::vector;
using std::cout;
using std::endl;


template <typename T>
class RD_Array {

public:
    RD_Array();
    RD_Array( const unsigned long, const T& = T() );
    RD_Array( const RD_Array<T> & );
    ~RD_Array();

    const RD_Array<T> &operator=( const RD_Array<T>& );

    T& at( const unsigned long ) const;
    T& operator[]( const unsigned long ) const;

    unsigned long size() const { return currentSize; }
    unsigned long capacity() const { return currentCapacity; }

    void insert( const unsigned long, const T& );
    void push_back( const T& );
    void pop_back();

    void resize( const unsigned long, const T& = T() );
    void clear();
    bool empty() const;

private:
    T* contents;
    unsigned long currentSize;
    unsigned long currentCapacity;

    void increaseCapacity();

}; // END RD_Array<T> class declaration






/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                    class RD_Array implementation                       **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/



/****************************************************************************
 **                                                                        **
 **                            private methods                             **
 **                                                                        **
 ****************************************************************************/

/****************************************************************************
 *                           increaseCapacity                               *
 ****************************************************************************/


template <typename T>
void RD_Array<T>::increaseCapacity()
{
    if(currentCapacity==0)
    {
        cout<<"adding to empty array"<<endl;
        currentCapacity = 1;
        delete []contents;
        contents = new T[1];
    }
    else
    {
        cout<<"doubling capacity"<<endl;
        currentCapacity = currentCapacity*2;
        T *previous = contents;
        contents = new T[currentCapacity];
        for (int i = 0; i < currentSize; ++i)
        {
            contents[i]=previous[i] ;
        }
        delete []previous;
    }

} // END increaseCapacity method of RD_Array class



/****************************************************************************
 **                                                                        **
 **                            public methods                              **
 **                                                                        **
 ****************************************************************************/

/****************************************************************************
 *                         default constructor                              *
 ****************************************************************************/

template <typename T>
RD_Array<T>::RD_Array()
{
    cout<<"default constructor"<<endl;
    T * dynArr = NULL;
    contents = dynArr;
    currentCapacity = 0;
    currentSize = 0;

} // END default constructor RD_Array class



/****************************************************************************
 *                      constructor with parameters                         *
 ****************************************************************************/

template <typename T>
RD_Array<T>::RD_Array( const unsigned long size, const T& obj )
{
    cout<<"size constructor"<<endl;
    contents = new T[size];
    currentCapacity = size;
    currentSize = size;
    for (int i = 0; i<size; i++)
    {
        cout << "Element " << i << ": "<< obj<<endl;
        contents[i]= obj;
    }


} // END constructor with int, T parameters RD_Array class



/****************************************************************************
 *                           copy constructor                               *
 ****************************************************************************/

template <typename T>
RD_Array<T>::RD_Array( const RD_Array<T> & otherArray )
{

    T *dynArr = new T[otherArray.currentCapacity];
    for(int i = 0; i < otherArray.currentSize ; i++ )
    {
        this->push_back(otherArray.at(i));
    }
    contents = dynArr;
    currentCapacity = otherArray.currentSize;
    currentSize = otherArray.currentCapacity;

} // END copy constructor for class RD_Array



/****************************************************************************
 *                                destructor                                *
 ****************************************************************************/

template <typename T>
RD_Array<T>::~RD_Array()
{
    cout<<"destructor"<<endl;
    delete []contents;

} // END destructor for RD_Array class



/****************************************************************************
 *                  overloaded assignment operator                          *
 ****************************************************************************/

template <typename T>
const RD_Array<T> &RD_Array<T>::operator=( const RD_Array<T> &otherArray )
{
    cout<<"overloaded assignment operator"<<endl;


    while(this->currentCapacity<=otherArray.currentCapacity)
    {
        this->increaseCapacity();
//        cout<< "size: "<< this->size()<<endl;
//        cout<< "capacity: "<< this->capacity()<<endl;
    }

    this->currentSize = otherArray.currentSize;
    this->contents = otherArray.contents;

    return *this;

} // END overloaded assignment operator class RD_Array



/****************************************************************************
 *                              at method                                   *
 ****************************************************************************/

template <typename T>
T& RD_Array<T>::at( const unsigned long ndx ) const
{
    if( 0> ndx || ndx > this->currentSize-1 || this->currentSize==0)
    {
        throw out_of_range("inappropriate index");
    }

    return contents[ndx];

} // END at method class RD_Array



/****************************************************************************
 *                    overloaded subscript operator                         *
 ****************************************************************************/

template <typename T>
T& RD_Array<T>::operator[]( const unsigned long ndx ) const
{
    if( 0> ndx || ndx > this->currentSize-1 || this->currentSize==0)
    {
        throw out_of_range("inappropriate index");
    }

    return contents[ndx];


} // END overloaded subscript operator class RD_Array



/****************************************************************************
 *                             insert method                                *
 ****************************************************************************/

template <typename T>
void RD_Array<T>::insert( const unsigned long ndx, const T& value )
{

    if( 0> ndx || ndx > this->currentSize)
    {
        cout<<"invalid int"<<endl;
        throw out_of_range("inappropriate index");
    }

    T remember1, remember2;

    remember1= contents[ndx];
    contents[ndx]=value;

    if (currentSize==currentCapacity)
    {
        this->resize(currentSize*2, T());
    }

    for (int i = ndx+1; i <= this->currentSize+1; ++i)
    {
        remember2 = contents[i];
        contents[i] = remember1;
        remember1 = remember2;
    }

    currentSize++;

} // END insert method class RD_Array



/****************************************************************************
 *                           push_back method                               *
 ****************************************************************************/

template <typename T>
void RD_Array<T>::push_back( const T& value)
{
//    if(this->currentCapacity==0)


    if(currentSize>=currentCapacity)
    {
        cout<<"make bigger"<<endl;
        this->increaseCapacity();
    }
    contents[currentSize]=value;
    currentSize++;
} // END push_back method class RD_Array



/****************************************************************************
 *                            pop_back method                               *
 ****************************************************************************/

template <typename T>
void RD_Array<T>::pop_back()
{
    if(this->empty())
    {
        throw no_such_object("inappropriate index");
    }

    currentSize--;
} // END pop_back method class RD_Array



/****************************************************************************
 *                             resize method                                *
 ****************************************************************************/

template <typename T>
void RD_Array<T>::resize( const unsigned long newSize, const T& value )
{
    if(newSize<currentSize)
    {
        currentSize = newSize;
    }

    else if(newSize<=currentCapacity)
    {
        for (int i = currentSize; i < newSize; ++i)
        {
            contents[i]=value;
        }
        currentSize = newSize;
    }
    else if(newSize>currentCapacity)
    {
        int diff = newSize-currentSize;
        for (int i = 0; i < diff; ++i)
        {
            this->push_back(value);
        }
    }


} // END resize method class RD_Array



/****************************************************************************
 *                             empty method                                *
 ****************************************************************************/

template <typename T>
bool RD_Array<T>::empty() const
{

    bool truth = false;
    if(currentSize==0)
    {
        truth= true;
    }

    return truth;
} // END empty method class RD_Array



/****************************************************************************
 *                             clear method                                 *
 ****************************************************************************/

template <typename T>
void RD_Array<T>::clear()
{
    if(!this->empty())
    {
//        int holdSize = currentSize;
//        for(int i = 0; i <= holdSize ; i++)
//        {
//            this->pop_back();
//        }
        this->currentSize=0;
    }

} // END clear method class RD_Array

















#endif /* _COSC052_FALL2021_P5_RD_ARRAY_H_ */