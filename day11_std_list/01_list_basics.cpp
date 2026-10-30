#include<iostream>
#include<list>

int main()
{
    std::list<int> numbers{10,20,30};

    numbers.push_back(40);

    numbers.push_front(5);

    std::cout<<"size: "<<numbers.size()<<'\n';

    for(std::list<int>::iterator it=numbers.begin();
        it!=numbers.end();it++)
        {
            std::cout<<*it<<" ";
        }

    std::cout<<'\n'<<"front: "<<numbers.front()<<'\n'
            <<"back: "<<numbers.back();

    return 0;
}

