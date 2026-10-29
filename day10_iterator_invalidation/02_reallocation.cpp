#include<iostream>
#include<vector>

int main()
{
    std::vector<int> ls;

    ls.insert(ls.begin(),10);
    ls.insert(ls.begin()+1,20);
    ls.insert(ls.begin()+2,30);

    auto it=ls.begin();

    std::cout<<"first cap: "<<ls.capacity()<<'\n';

    ls.reserve(ls.capacity()+1);

    std::cout<<"second cap: "<<ls.capacity()<<'\n';

    auto new_it=ls.begin();

    std::cout<<*new_it<<'\n';
    std::cout<<*it;

    return 0;
}