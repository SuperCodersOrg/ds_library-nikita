#ifndef MEMORY_H
#define MEMORY_H

#include <cstdlib>
#include <new>
#include <utility>

template<typename T, typename... Args>
T* my_new(Args&&... args)
{
    void* memory = std::malloc(sizeof(T));

    if (memory == nullptr)
    {
        throw std::bad_alloc();
    }

    try
    {
        return new (memory) T(std::forward<Args>(args)...);
    }
    catch (...)
    {
        std::free(memory);
        throw;
    }
}

template<typename T>
void my_delete(T* ptr)
{
    if (ptr == nullptr)
    {
        return;
    }

    ptr->~T();
    std::free(ptr);
}

template<typename T>
T* my_new_array(std::size_t count)
{
    T* array = static_cast<T*>(std::malloc(sizeof(T) * count));

    if (array == nullptr)
    {
        throw std::bad_alloc();
    }

    std::size_t i = 0;

    try
    {
        for (; i < count; ++i)
        {
            new (&array[i]) T();
        }

        return array;
    }
    catch (...)
    {
        while (i > 0)
        {
            --i;
            array[i].~T();
        }

        std::free(array);
        throw;
    }
}

template<typename T>
void my_delete_array(T* array, std::size_t count)
{
    if (array == nullptr)
    {
        return;
    }

    while (count > 0)
    {
        --count;
        array[count].~T();
    }

    std::free(array);
}

#endif 