#include<iostream>
#include<deque>
#include<vector>
#include<iterator>
#include<list>

int main()
{   
    std::vector<int> v{10,20,30,40,50};
    v.insert(v.begin(),5);
    v.pop_back();

    std::list<int> l{10,20,30,40,50};
    l.insert(l.begin(),5);
    l.pop_back();

    std::deque<int> d{10,20,30,40,50};
    d.push_front(5);
    d.pop_back();

    std::cout<<"V3 "<<v[2]<<'\n'
            <<"l3 "<<*std::next(d.begin(),2)<<'\n'
            <<"d3 "<<d[2]<<'\n';

    for(auto it=v.begin();it!=v.end();++it)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<"\n------------------------\n";
    for(auto it=l.begin();it!=l.end();++it)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<"\n------------------------\n";
    for(auto it=d.begin();it!=d.end();++it)
    {
        std::cout<<*it<<" ";
    }
    
    return 0;
}