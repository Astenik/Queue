#include <iostream>
#include "ArrQueue.h"

int main()
{
    DataQueue<int> obj(4);
    std::cout << obj.is_empty() << std::endl;

    obj.enqueue((1));
    obj.enqueue((2));
    obj.enqueue((3));
    obj.enqueue((4));
    std::cout << obj.is_empty() << std::endl;

    obj.dequeue();
    obj.dequeue();

    obj.enqueue(5);
    obj.enqueue(6);

    for(int i = 0; i <= obj.size(); ++i)
    {
        std::cout << obj.front() << " ";
        obj.dequeue();
    }

    return 0;
}
