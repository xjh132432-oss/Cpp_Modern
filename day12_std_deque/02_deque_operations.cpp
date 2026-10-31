#include<iostream>
#include<deque>

int main()
{
    
    std::deque<int> d{10,20,30,40,50};

    d.push_front(2);
    d.push_front(1);

    d.push_back(60);
    d.push_back(70);

    d.pop_front();
    d.pop_front();

    d.pop_back();

    for(auto it=d.begin();it!=d.end();++it)
    {
        std::cout<<*it<<" ";
    }

    return 0;
}