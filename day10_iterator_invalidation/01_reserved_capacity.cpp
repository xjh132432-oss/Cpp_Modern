#include<iostream>
#include<vector>

int main()
{
    std::vector<int> ls{10,20,30};

    ls.reserve(10);

    auto it=ls.begin();

    ls.push_back(40);

    std::cout<<*it<<" size: "<<ls.size()<<
            '\n'<<"cap: "<<ls.capacity();


    return 0;
}