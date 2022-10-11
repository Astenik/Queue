#include <iostream>
#include "ArrQueue.h"

int main()
{
    DataQueue<int> obj(4);
    int x;
    while(std::cin >> x)
    {
        obj.enqueue(x);
        if(obj.full())
        {
            break;
        }

    }
    obj.dequeue();
    obj.dequeue();

    obj.enqueue(5);
    obj.enqueue(6);

    for(int i = 0; i <= obj.size(); ++i)
    {
        std::cout << obj.front() << " ";
        obj.dequeue();
    }
    std::cout << obj.front() << " ";
    obj.dequeue();
    return 0;
}
