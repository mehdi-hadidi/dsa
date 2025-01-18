#pragma once

#include <iostream>

namespace mh
{
    template<typename T , size_t S = 10>
    class array
    {
        private:
            T m_data[S];
            size_t m_capacity;
            size_t m_count;

            class iterator
            {
                private:
                    T* m_ptr;
                public:    
                    iterator(T* ptr) : m_ptr(ptr){}
                    bool operator!=(const iterator& that) { return that.m_ptr != m_ptr; }
                    iterator operator++() { return m_ptr++; }
                    T& operator*() { return *m_ptr; }
                    //const T& operator* { return *m_ptr; }
            };    

        public:
            array() : m_capacity{S} , m_count{0} {} 
            array(std::initializer_list<T> init) : m_capacity{S} , m_count{0} 
            {
                if(init.size() > S)
                {
                    throw std::out_of_range("size of init list is greater than size of array");
                }
                std::copy(init.begin() , init.end() , m_data);
            }
            T& operator[](size_t index)
            {
                return m_data[index];
            }    

            iterator begin()
            {
                return iterator(m_data);
            }
            iterator end()
            {   
                return iterator(m_data + S);
            }

    };
}