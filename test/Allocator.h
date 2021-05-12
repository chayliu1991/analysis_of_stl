#pragma once
#include <new>      //@ for placement new
#include <cstddef>  //@ for size_t and ptrdiff_t
#include <cstdlib>  //@ for exit
#include <climits>  //@ for UINT_MAX
#include <iostream> //@ for cerr

namespace stl
{
    template <typename T>
    inline T *_allocate(ptrdiff_t size, T *)
    {
        std::set_new_handler(0);
        T *t = (T *)::operator new((size_t)(size * sizeof(T)));
        if (t == 0)
        {
            std::cerr << "malloc error\n";
            exit(1);
        }
        return t;
    }

    template <typename T>
    inline void _deallocate(T *buffer)
    {
        ::operator delete(buffer);
    }

    template <typename T1, typename T2>
    inline void _construct(T1 *p, const T2 &value)
    {
        new (p) T1(value); //@ placement new and type conversion
    }

    template <class T>
    inline void _destroy(T *ptr)
    {
        ptr->~T();
    }

    template <class T>
    class Allocator
    {
    public:
        typedef T value_type;
        typedef T *pointer;
        typedef const T *const_pointer;
        typedef T &reference;
        typedef const T &const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;

        template <typename U>
        struct rebind
        {
            typedef Allocator<U> other;
        };

        pointer allocate(size_type n, const void *hint = 0)
        {
            return _allocate((difference_type)n, (pointer)0);
        }

        void deallocate(pointer p, size_type n)
        {
            _deallocate(p);
        }

        void construct(pointer p, const T &value)
        {
            _construct(p, value);
        }

        void destroy(pointer p)
        {
            _destroy(p);
        }

        pointer address(reference x)
        {
            return (pointer)(&x);
        }

        const_pointer address(const_reference x)
        {
            return (const_pointer)(&x);
        }

        size_type max_size() const
        {
            return size_type(UINT_MAX / sizeof(T));
        }
    };
}
