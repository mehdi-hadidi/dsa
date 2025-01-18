#pragma once

namespace mh
{
    template<typename T>
    class linked_list
    {
        private:
            struct node
            {
                T     m_data;
                node* m_next;
                node(const T& data) : m_data(data) , m_next(nullptr) {}
            };

            node* m_first;
            node* m_last;


        public:
            linked_list() : m_first{nullptr} , m_last {nullptr} { }  
            ~linked_list() 
            {
                 node* n = m_first;
                 while(n)
                 {
                    node* next = n->m_next;
                    delete n;
                    n = next;

                 }
            }  
            void add_last(const T& data)
            {
               node* n = new node(data);
               if(!m_first) 
               {
                    m_first = m_last = n;
               }
               else
               {
                    m_last->m_next = n;
                    m_last = n;
               }    
            }

            void add_first(const T& data)
            {
               node* n = new node(data);
               if(!m_first) 
               {
                    m_first = m_last = n;
               }
               else
               {
                   n->m_next = m_first;
                   m_first = n;
               }    
            }


            void print()
            {
                node* n = m_first;
                while(n)
                {
                    std::cout << n->m_data << std::endl;
                    n = n->m_next;
                }
            }
    };
}