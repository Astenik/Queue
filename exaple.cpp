#include <iostream>

template <typename T>

struct ListNode
{
	T value;
	ListNode<T>* next;
	ListNode(const T& val = 0, ListNode<T>* n = nullptr)
		: value(val)
		, next(n)
	{}
	~ListNode() {}
};

template <typename T>

class Queue 
{
 public:
    virtual  ~Queue();
    virtual void enqueue(const T&) = 0;
    virtual void dequeue() = 0;
    virtual bool is_empty()const = 0;
    virtual void clear() = 0;
}; 

template <typename T> 

Queue<T>::~Queue()
{
    std::cout << "Queue destructor" << std::endl;
}

template <typename T> 

class Lqueue: public Queue<T>
{
  public:
     Lqueue();
     Lqueue(const T&);
     Lqueue(const Lqueue&);
     Lqueue(const Lqueue&&);
     virtual ~Lqueue();
    
  public:
     virtual void enqueue(const T&);
     virtual void dequeue();
     virtual bool is_empty()const;
     virtual void clear();

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
    ListNode<T>* ptr = new ListNode<T>();
    ptr->value = val;
    if(!is_empty())
    {
        last->next = ptr;
        last = ptr;
        ptr = nullptr;
    }
    else
    {
        last = ptr;
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
        throw "your Lqueue is empty. you can't dequeue just now.";
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
    while(first != nullptr)
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

int main()
{
    Lqueue<int> obj;
    std::cout << obj.is_empty() << std::endl;
    obj.enqueue(6);
    obj.enqueue(45);
    obj.enqueue(74);
    std::cout << obj.is_empty() << std::endl;
    obj.dequeue();
    obj.clear();
    std::cout << obj.is_empty() << std::endl;
    Lqueue<int> obj2(obj);
    obj2.enqueue(12);
    obj2.clear();
    std::cout << obj2.is_empty() << std::endl;
    return 0;
}
