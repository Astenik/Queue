#pragma once

#include "Queue.h"
#include "ListNode.h"

template <typename T> 
class Lqueue: public Queue<T>
{
  public:
     Lqueue();
     Lqueue(const T&);
     Lqueue(const Lqueue&);
     Lqueue(const Lqueue&&);
     ~Lqueue();
    
  public:
      void enqueue(const T&);
      void dequeue();
      bool is_empty() const;
      void clear();
      T front() const;

  public:
     Lqueue<T>& operator=(const Lqueue&);
     Lqueue<T> operator+(const Lqueue&)const;
  private:
     ListNode<T>* m_front;
     ListNode<T>* m_last;
};

template <typename T>
Lqueue<T>:: Lqueue()
        : m_front(nullptr)
        , m_last(nullptr)
        {}

template <typename T>
Lqueue<T>:: Lqueue(const T& val)
{
    ListNode<T>* node = new ListNode<T>(val); 
    m_front = m_last = node;
}

template <typename T> 
Lqueue<T>:: Lqueue(const Lqueue& obj)
{
    ListNode<T>* ptr = obj.m_front;
    while(ptr != nullptr)
    {
        enqueue(ptr->value);
        ptr = ptr -> next;
    }
}

template <typename T>
Lqueue<T>:: Lqueue(const Lqueue&& tmp)
{
    m_front = tmp.m_front;
    m_last = tmp.m_last;
    tmp.m_front = nullptr;
    tmp.m_last = nullptr;
}

template <typename T>
Lqueue<T>:: ~Lqueue()
{
    clear();
    std::cout << "Lqueue destructor" << std::endl;
}

template <typename T>
void Lqueue<T>:: enqueue(const T& val)
{
    if(!is_empty())
    {
        m_last->next = new ListNode<T>(val);
        m_last = m_last->next;
    }
    else
    {
        m_last = m_front = new ListNode<T>(val);
    }
}

template <typename T>
void Lqueue<T>:: dequeue()
{
    if(!is_empty())
    {
       ListNode<T>* ptr = m_front;
       m_front = m_front->next;
       delete ptr;
       ptr = nullptr;
    }
    else
    {
        throw "your Lqueue is empty.";
    }
}

template <typename T>
bool Lqueue<T>:: is_empty()const
{
    return ((m_last == nullptr) && (m_front == nullptr));
}

template <typename T>
void Lqueue<T>:: clear()
{
    while(m_front != nullptr)
    {
        dequeue();
    } 
    m_front = m_last = nullptr;
} 
template <typename T>
T Lqueue<T>:: front() const
{
   return m_front -> value;
}

template <typename T>
Lqueue<T>& Lqueue<T>:: operator=(const Lqueue& obj)
{
    ListNode<T>* cpy = obj.m_front;
    while(cpy != nullptr)
    {
        enqueue(cpy->value);
        cpy = cpy -> next;
    }
    return *this;
}

template <typename T>
Lqueue<T> Lqueue<T>:: operator+(const Lqueue& obj)const
{
    Lqueue<T> res = *this;
    ListNode<T>* ptr = obj.m_front;
    while(ptr != nullptr)
    {
        res.enqueue(ptr -> value);
        ptr = ptr -> next;
    }
    return res;
}
