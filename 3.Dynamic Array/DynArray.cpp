#include <iostream>
#include <stdio.h>
using namespace std;
class DynArray
{
private:
    int capacity;
    int lastindex;
    int *ptr;
    protected:
    void doubleArray();
    void halfArray();
public:
    DynArray(int);
    DynArray(DynArray &);
    DynArray &operator=(DynArray &);
    bool isEmpty();
    bool isFull();
    void append(int);
    void insert(int, int);
    void edit(int, int);
    void del(int);
    int getItem(int);
    int count();
    int find(int);
    ~DynArray();
    int getCapacity();
};
DynArray::DynArray(int size)
{
    if (size > 0)
    {
        capacity = size;
        lastindex = -1; // DynArray is empty now
        ptr = new int[capacity];
    }
    else
    {
        ptr = NULL;
    }
}
DynArray::DynArray(DynArray &a)
{
    capacity = a.capacity;
    lastindex = a.lastindex;
    ptr = new int[capacity];
    for (int i = 0; i <= lastindex; i++)
    {
        ptr[i] = a.ptr[i];
    }
}
DynArray &DynArray::operator=(DynArray &a)
{
    if (this != &a)
    {
        if(ptr!=NULL)
          delete []ptr;
        capacity = a.capacity;
        lastindex = a.lastindex;
        ptr = new int[capacity];
        for (int i = 0; i <= lastindex; i++)
        {
            ptr[i] = a.ptr[i];
        }
    }
}
void DynArray::doubleArray()
{
    int *temp;
    temp = new int[2*capacity];
    for(int i=0;i<=lastindex;i++)
    {
        temp[i]=ptr[i];
    }
    delete []ptr;
    ptr=temp;
    capacity=2*capacity;
}
void DynArray::halfArray()
{
    int *temp;
    temp = new int[capacity/2];
    for(int i=0;i<=lastindex;i++)
    {
        temp[i]=ptr[i];
    }
    delete []ptr;
    ptr=temp;
    capacity=capacity/2;
}
bool DynArray::isEmpty()
{
    return lastindex == -1;
}
bool DynArray::isFull()
{
    return lastindex == capacity - 1;
}
void DynArray::append(int data)
{
    if (isFull())
    {
        doubleArray();
    }
    lastindex++;
    ptr[lastindex] = data;
}
void DynArray::insert(int index, int data)
{
    if (index < 0 || index > lastindex + 1)
    {
        cout << "\nInvalid Index";
    }
    else
    { 
        if (isFull())
        {
            doubleArray();
        }
        for (int i = lastindex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = data;
        lastindex++;
    }
}
void DynArray::edit(int index, int data)
{
    if (index < 0 || index > lastindex)
    {
        cout << "\nInvalid Index or empty DynArrayarray";
    }
    else
    {
        ptr[index] = data;
    }
}
void DynArray::del(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "\nInvalid Index or empty DynArrayarray";
    }
    else
    {
        for (int i = index; i < lastindex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        lastindex--;
        if(capacity>1 && lastindex+1<=capacity/2)
           { 
                halfArray();
           }
    }
}
int DynArray::getItem(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "\nInvalid Index or Empty DynArray";
        throw new exception();
    }
    return ptr[index];
}
int DynArray::count()
{
    return lastindex + 1;
}
DynArray::~DynArray()
{
    delete[] ptr;
}
int DynArray::find(int data)
{
    for (int i = 0; i <= lastindex; i++)
    {
        if (ptr[i] == data)
        {
            return i + 1;
        }
    }
    return -1;
}
int DynArray::getCapacity()
{
    return capacity;
}
