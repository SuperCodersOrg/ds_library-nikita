#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstdlib>
#include <stdexcept>
#include "Memory.h"

// template<typename T>
// class DynamicArray
// {
// private:
//     static constexpr int MIN_CAPACITY = 4;

//     T* data;
//     int currSize;
//     int currCap;

//     void resize(int newCapacity)
//     {
//         T* newData = static_cast<T*>(
//             std::realloc(data, newCapacity * sizeof(T))
//         );

//         if(newData == nullptr)
//         {
//             throw std::bad_alloc();
//         }

//         data = newData;
//         currCap = newCapacity;
//     }

// public:
//     DynamicArray()
//     {
//         currSize = 0;
//         currCap = MIN_CAPACITY;

//         data = static_cast<T*>(
//             std::malloc(currCap * sizeof(T))
//         );

//         if(data == nullptr)
//         {
//             throw std::bad_alloc();
//         }
//     }

//     ~DynamicArray()
//     {
//         std::free(data);

//         data = nullptr;
//         currSize = 0;
//         currCap = 0;
//     }

//     DynamicArray(const DynamicArray& other)
//     {
//         currSize = other.currSize;
//         currCap = other.currCap;

//         data = static_cast<T*>(
//             std::malloc(currCap * sizeof(T))
//         );

//         if(data == nullptr)
//         {
//             throw std::bad_alloc();
//         }

//         for(int i = 0; i < currSize; i++)
//         {
//             data[i] = other.data[i];
//         }
//     }

//     DynamicArray& operator=(const DynamicArray& other)
//     {
//         if(this == &other)
//         {
//             return *this;
//         }

//         T* newData = static_cast<T*>(
//             std::malloc(other.currCap * sizeof(T))
//         );

//         if(newData == nullptr)
//         {
//             throw std::bad_alloc();
//         }

//         for(int i = 0; i < other.currSize; i++)
//         {
//             newData[i] = other.data[i];
//         }

//         std::free(data);

//         data = newData;
//         currSize = other.currSize;
//         currCap = other.currCap;

//         return *this;
//     }

//     void append(const T& value)
//     {
//         if(currSize == currCap)
//         {
//             resize(currCap * 2);
//         }

//         data[currSize] = value;
//         currSize++;
//     }

//     void insert(int index, const T& value)
//     {
//         if(index < 0 || index > currSize)
//         {
//             throw std::out_of_range(
//                 "DynamicArray::insert - index out of range"
//             );
//         }

//         if(currSize == currCap)
//         {
//             resize(currCap * 2);
//         }

//         for(int i = currSize; i > index; i--)
//         {
//             data[i] = data[i - 1];
//         }

//         data[index] = value;
//         currSize++;
//     }

//     void remove(int index)
//     {
//         if(index < 0 || index >= currSize)
//         {
//             throw std::out_of_range(
//                 "DynamicArray::remove - index out of range"
//             );
//         }

//         for(int i = index; i < currSize - 1; i++)
//         {
//             data[i] = data[i + 1];
//         }

//         currSize--;

//         if(currSize <= currCap / 4 &&
//            currCap / 2 >= MIN_CAPACITY)
//         {
//             resize(currCap / 2);
//         }
//     }

//     T get(int index) const
//     {
//         if(index < 0 || index >= currSize)
//         {
//             throw std::out_of_range(
//                 "DynamicArray::get - index out of range"
//             );
//         }

//         return data[index];
//     }

//     int size() const
//     {
//         return currSize;
//     }

//     int capacity() const
//     {
//         return currCap;
//     }


//     void shrinkToFit()
//     {
//         if(currSize == currCap)
//         {
//             return;
//         }

//         int newCapacity =
//             (currSize < MIN_CAPACITY)
//             ? MIN_CAPACITY
//             : currSize;

//         resize(newCapacity);
//     }
// };

template<typename T>
class DynamicArray
{
private:
    T* data;

    int currSize;
    int currCap;

    static const int MIN_CAPACITY = 4;

    void resize(int newCapacity);

public:
    // =========================
     // Constructor
   // =========================

   DynamicArray(){
    currSize = 0;
    currCap = MIN_CAPACITY;

    data = my_new_array<T>(currCap);
       }

// =========================
// Size
// =========================

    int size() const{
        return currSize;
        }

// =========================
// Capacity
// =========================

    int capacity() const{
        return currCap;
    }


};


#endif 