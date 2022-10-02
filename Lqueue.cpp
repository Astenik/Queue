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
      bool is_empty()const;
      void clear();

  public:
     Lqueue<T>& operator=(const Lqueue&);
     Lqueue<T> operator+(const Lqueue&)const;
  private:
     ListNode<T>* first;
     ListNode<T>* last;
};

template <typename T>

Lqueue<T>:: Lqueue()
        : first(nullptr)
        , last(nullptr)
        {}

template <typename T>

Lqueue<T>:: Lqueue(const T& val)
{
    ListNode<T> node(val);
    last = &node;
    first = &node;
}

template <typename T> 

Lqueue<T>:: Lqueue(const Lqueue& obj)
{
    ListNode<T>* ptr = obj.first;
    while(ptr != nullptr)
    {
        enqueue(ptr->value);
        ptr = ptr -> next;
    }
}

template <typename T>

Lqueue<T>:: Lqueue(const Lqueue&& tmp)
{
    first = tmp.first;
    last = tmp.last;
    tmp.first = nullptr;
    tmp.last = nullptr;
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
        last->next = new ListNode<T>;
        last = last->next;
        last->value = val;
    }
    else
    {
        last = new ListNode<T>;
        last->value = val;
    }
}

template <typename T>

void Lqueue<T>:: dequeue()
{
    if(!is_empty())
    {
       ListNode<T>* ptr = first;
       first = first->next;
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
    return ((last == nullptr) && (first == nullptr));
}

template <typename T>

void Lqueue<T>:: clear()
{
    while(!is_empty())
    {
        dequeue();
    } 
} 

template <typename T>

Lqueue<T>& Lqueue<T>:: operator=(const Lqueue& obj)
{
    Lqueue<T>* ptr = this;
    Lqueue<T> res(obj);
    this = &res;
    delete ptr;
    ptr = nullptr;
    return *this;
}

template <typename T>

Lqueue<T> Lqueue<T>:: operator+(const Lqueue& obj)const
{
    Lqueue<T> res = *this;
    ListNode<T>* ptr = obj.first;
    while(ptr != nullptr)
    {
        res.enqueue(ptr -> value);
        ptr = ptr -> next;
    }
    return res;
}
