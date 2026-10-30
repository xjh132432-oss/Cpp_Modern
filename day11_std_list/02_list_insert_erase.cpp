#include<list>
#include<iostream>

int main()
{
    std::list<int> numbers{10,20,30,40,50};

    std::list<int>::iterator it30,it20,it40;
    for(std::list<int>::iterator it=numbers.begin();
        it!=numbers.end();it++)
    {
        if(*it==30) it30=it;
        if(*it==20) it20=it;
        if(*it==40) it40=it;

    }

    numbers.insert(it30,25);

    numbers.erase(it40);

    std::cout<<"20: "<<*it20<<'\n';

    for (auto it = numbers.begin(); it != numbers.end();)
    {
        if (*it % 2 == 0)
        {
            it = numbers.erase(it);
        }
        else
        {
            ++it;
        }
    }

    for(std::list<int>::iterator it=numbers.begin();
        it!=numbers.end();it++)
    {
        std::cout<<*it<<" ";
    }

    return 0;
}