#include<iostream>
#include<vector>

int main()
{
    std::vector<int> ls{10,20,30};

    for(std::vector<int>::iterator it=ls.begin();
        it!=ls.end();it++)
    {
        std::cout<<*it<<" "<<'\n';
    }
    ls.push_back(40);

    std::cout<<"----------push------------"<<'\n';

    for(std::vector<int>::iterator it=ls.begin();
        it!=ls.end();it++)
    {
        std::cout<<*it<<" "<<'\n';
    }
    


    return 0;
}