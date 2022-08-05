#include "vector.hpp"
#include <vector>
#include <cstdio>
#include <iterator>
// int main()
// {
//     {
//         std::vector<int> v;
//         // v.push_back(1);
//         // printf("size = %ld\n", v.size());
//         // printf("capacity = %ld\n", v.capacity());
//         // v.push_back(1);
//         // printf("size = %ld\n", v.size());
//         // printf("capacity = %ld\n", v.capacity());
//         // printf("size = %ld\n", v.size());
//         // v.resize(40,5);
//         // v.push_back(1);
//         // printf("capacity = %ld\n", v.capacity());
//         // printf("size = %ld\n", v.size());
//         // printf("capacity = %ld\n", v.capacity());
//     }
//     // printf("-----------------------------------\n");
//     {
//         ft::vector<int> v;
//         printf("size = %ld\n", v.size());
//         printf("capacity = %ld\n", v.capacity());
//         v.push_back(123);
//         printf("size = %ld\n", v.size());
//         printf("capacity = %ld\n", v.capacity());
//         v.push_back(555);
//         printf("size = %ld\n", v.size());
//         printf("capacity = %ld\n", v.capacity());
//         v.push_back(666);
//         printf("size = %ld\n", v.size());
//         printf("capacity = %ld\n", v.capacity());
//         printf("%d\n", v.back());
//         v.pop_back();
//         printf("%d\n", v.back());
//         v.pop_back();
//         printf("%d\n", v.back());
//         v.pop_back();
//     }
	
// }
// 

// resizing vector
#include <iostream>
#include <vector>
template <class T>  
void pr(ft::vector<T> &a)
{
    printf("size = %lu  capacity = %lu\n", a.size(), a.capacity());
    std::cout << "elements: ";
    for (std::size_t i = 0; i < a.size(); i++)
    {
        std::cout << a[i];
        std::cout << " ";
    }
    std::cout  << "|";
    for (std::size_t i = a.size(); i < a.capacity(); i++)
    {
        std::cout << a[i];
        std::cout << " ";
    }
    std::cout << std::endl;
}
template <class T>  
void pr(std::vector<T> &a)
{
    printf("size = %lu  capacity = %lu\n", a.size(), a.capacity());
    std::cout << "elements: ";
    for (std::size_t i = 0; i < a.size(); i++)
    {
        std::cout << a[i];
        std::cout << " ";
    }
    std::cout  << "|";
    for (std::size_t i = a.size(); i < a.capacity(); i++)
    {
        std::cout << a[i];
        std::cout << " ";
    }
    std::cout << std::endl;
}
int main ()
{
//   std::vector<int> myvector;

//   // set some initial content:
//   for (int i=1;i<10;i++) myvector.push_back(i);
//   printf("Size = %ld\n", myvector.size());
//   printf("capacity = %ld\n", myvector.capacity());
//   myvector.resize(5);
//   printf("Size = %ld\n", myvector.size());
//   printf("capacity = %ld\n", myvector.capacity());
//   myvector.resize(8,100);
//   printf("Size = %ld\n", myvector.size());
//   printf("capacity = %ld\n", myvector.capacity());
//   myvector.resize(100);
//   printf("Size = %ld\n", myvector.size());
//   printf("capacity = %ld\n", myvector.capacity());

//   std::cout << "myvector contains:";
//   for (size_t i=0;i<myvector.size();i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';
    // v1.push_back(1);
    // v1.insert(v1.begin(),6,6);
    // v1.reserve(8);
    // pr(v1);
    // v1.insert(v1.begin(),9,6);
    // pr(v1);
    
    // v1.push_back(1);
    // v1.reserve(10);

    // v1.insert(v1.begin(),1,3);
    // v1.insert(v1.begin(),6);

    ft::vector<int> v2;
    ft::vector<int> v1;
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);
    v1.insert(v1.end(),3,7);
    pr(v1);
    v2.insert(v2.begin(),11,3);
    v1.insert(v1.begin() + 2, v2.begin(),v2.end());
    pr(v1);
    // v1.erase(v1.begin() + 2);
    // std::vector<int>::iterator i = v.begin();
    // for (std::vector<int>::iterator i = v.end(); i != v.begin(); i--)
    // {
    //     std::cout << *i << std::endl;
    // }
    // std::cout << v.end() - v.begin() << std::endl;
    // v.insert(v.end(), 2);
    // v.insert(v.end(), 2);

    // std::cout << "distance: " << ft::distance(v.end(), v.begin()) << std::endl;
    // std::cout << *(v.end() + -1) << std::endl;
    return 0;
}