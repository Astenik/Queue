#include <iostream>
#include <cassert>

#include "queue.h"

template <typename T>
class DataQueue: public Queue<T>
{
public:
    DataQueue(int);
    DataQueue(const DataQueue&);
    DataQueue(const DataQueue&&);
    virtual ~DataQueue();
public:

    virtual void enqueue(const T&);
    virtual void dequeue();
    virtual bool is_empty() const;
    virtual T front() const;
    int size() const;
    virtual void clear();

private:
    int m_size;
    int m_front;
    int m_rear;
    T* m_arr;
};

template <typename  T>
DataQueue<T>::DataQueue(int size)
              : m_size(size + 1)
              , m_front(1)
              , m_rear(0)
              , m_arr(new T [m_size])
{
    assert(m_arr);
}

template <typename  T>
DataQueue<T>::DataQueue(const DataQueue& obj)
              : m_front(1)
              , m_rear(0)
{
    m_size = obj.m_size;
    m_arr = new T [m_size];
    int i = obj.m_front;
    while(i <= obj.m_rear)
    {
        enqueue(obj.m_arr[i]);
        ++i;
    }
}

template <typename  T>
DataQueue<T>::DataQueue(const DataQueue&& tmp)
             : m_size(tmp.m_size)
             , m_front(tmp.m_front)
             , m_rear(tmp.m_rear)
             , m_arr(tmp.m_arr)
{
    tmp.m_arr = nullptr;
    tmp.m_size = 0;
    tmp.m_front = 0;
    tmp.m_rear = 0;
}

template <typename  T>
DataQueue<T>::~DataQueue()
{
    delete [] m_arr;
    m_arr = nullptr;
    std::cout << "arrQueue destructor" << std::endl;
}

template <typename  T>
void DataQueue<T>::enqueue(const T& item)
{
    m_rear = (m_rear + 1) % m_size;
    m_arr[m_rear] = item;
}

template <typename  T>
void DataQueue<T>::dequeue()
{
    if(!is_empty())
    {
        m_front = (m_front + 1) % m_size;
    }
    else
    {
        throw "your queue is empty and you can't dequeue something";
    }
}

template <typename  T>

bool DataQueue<T>::is_empty() const
{
    return  size() == 0;
}

template <typename  T>
T DataQueue<T>::front() const
{
    return m_arr[m_front];
}

template <typename T>
int DataQueue<T>::size() const
{
    return ((m_rear - m_front + 1 + m_size) % m_size);
}

template <typename  T>
void DataQueue<T>::clear()
{
    while (!is_empty())
    {
        dequeue();
    }
}
