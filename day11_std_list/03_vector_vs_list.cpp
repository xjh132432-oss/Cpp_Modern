#include<vector>
#include<list>
#include<iostream>
#include<iterator>

int main()
{
    std::vector<int> v{10,20,30,40,50};
    std::list<int> l{10,20,30,40,50};

    std::list<int>::iterator l30;
    std::vector<int>::iterator v30;
    

    for(std::vector<int>::iterator it=v.begin();
        it!=v.end();it++)
    {   
        std::cout<<*it<<" ";
    }

    std::cout<<'\n'<<"---------------------------"<<'\n';

    for(std::list<int>::iterator it1=l.begin();
        it1!=l.end();it1++)
    {   
        if(*it1==30) l30=it1;
        std::cout<<*it1<<" ";
    }

    v.insert(std::next(v.begin()),15);
    l.insert(std::next(l.begin()),15);

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (*it == 30)
        {
            v30 = it;
            break;
        }
    }

    l.erase(l30);
    v.erase(v30);
    
    std::cout << "\nvector: ";
    for (auto x : v)
    std::cout << x << " ";

    std::cout << "\nlist: ";
    for (auto x : l)
    std::cout << x << " ";


    return 0;

}