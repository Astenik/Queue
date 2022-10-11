#include <iostream>
#include "Lqueue.h"

int main()
{
    Lqueue<int> obj;
    std::cout << obj.is_empty() << std::endl;
    
    obj.enqueue(78);
    obj.enqueue(23);
    obj.enqueue(89);
    obj.dequeue();
    std::cout << obj.front() << std::endl;
    
    Lqueue<int> k;
    k = obj;
    
    k.enqueue(9);
    k.dequeue();
    
    std::cout << k.is_empty() << std::endl;
    std::cout << k.front() << std::endl;
    
    obj.clear();
    
    return 0;
}
