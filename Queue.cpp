//Queue.h
#include "ListNode.h"

template <typename T>
class Queue 
{
 public:
    virtual  ~Queue();
    virtual void enqueue(const T&) = 0;
    virtual void dequeue() = 0;
    virtual bool is_empty() const = 0;
    virtual void clear() = 0;
    virtual T front() const = 0;
}; 

template <typename T> 
Queue<T>::~Queue()
{
    std::cout << "Queue destructor" << std::endl;
}
