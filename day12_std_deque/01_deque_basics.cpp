#include<iostream>
#include<deque>

int main()
{
    std::deque<int> d{10, 20, 30, 40, 50};

    d.push_back(60);
    d.push_front(5);

    std::cout<<"front: "<<d.front()<<'\n'
            <<"back: "<<d.back()<<'\n';

    std::cout<<d[3]<<" "<<d.at(3)<<'\n';

    for(std::deque<int>::iterator it=d.begin();
        it!=d.end();it++)
    {
        std::cout<<*it<<" ";
    }

    return 0;
}

