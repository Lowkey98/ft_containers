#include "bst.hpp"
#include <map>
#include "map.hpp"
#include "../helper.hpp"
int main()
{
    ft::map<int,int> mymap;
    ft::map<int,int>::iterator it;
    mymap.insert (pair<int,int>(1,1) );
    mymap.insert (pair<int,int>(2,2) );
    mymap.insert (pair<int,int>(3,3) );
    it=mymap.begin();
    // exit(0);
    // std::cout << it->first;
    for (it=mymap.begin(); it!=mymap.end(); it++)
    {
        std::cout << it->first << " => " << it->second << '\n';
    }
    return 0;
}