#pragma once

namespace mh
{
    template<typename T>
    class vector
    {
        private:
            T* m_data;
            size_t m_capacity;
            size_t m_size;

            void resize()
            {
                T* new_data = new T[m_capacity * 2];
                for(int i = 0 ; i < m_size ; i++)
                {
                    new_data[i] = std::move(m_data[i]);
                }
                delete [] m_data;
                m_data = new_data;
                m_capacity *= 2;
            }
        public:
            vector(size_t size = 10) : m_data{new T[size]} , m_capacity{size} , m_size{0} {}
            ~vector() {delete [] m_data; m_capacity = m_size = 0;}
            void push_back(const T& data)
            {
                if(m_size >= m_capacity)
                {
                    resize();
                }
                m_data[m_size++] = data;
            }
            void push_back(T&& data)
            {
                if(m_size >= m_capacity)
                {
                    resize();
                }
                m_data[m_size++] = std::move(data);
            }

            T& operator[](size_t index) const
            {
                return m_data[index];
            }
            size_t size() const
            {
                return m_size;
            }


             
            friend std::ostream& operator<<(std::ostream& out , const mh::vector<T>& data)
            {
                out << "[";
                for(int i = 0 ; i < data[i] ; i++)
                {
                    out << data[i];
                    if(i + 1 < data.size())
                    {
                        out << " , ";
                    }
                    
                }
                out << "]";
                return out;
      
            }




    };
}