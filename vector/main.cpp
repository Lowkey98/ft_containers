#include "vector.hpp"
#include "helper.hpp"
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

template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };

class class_a{
    public:
        template<class T>
        int foo(class_a a, T b, T c)
        {
            (void)a;
            // std::cout << a;
            std::cout << *b;
            std::cout << *c;
            return (0);
        }
        int foo(class_a a,int b, int c)
        {
            (void)a;
            std::cout << b <<std::endl;
            std::cout << c <<std::endl;
            return (10);
        }
        // char operator*(){return  ('c');};
        // typename enable_if<std::is_integral<T>::value,T>::type
};


int main ()
{
    // std::enable_if<true,int>::type
    // std::cout << !ft::is_integral<int>::value;
    // class_a object_a;
    // int b = 1;
    // int *c = &b;
    // *c=10;
    // object_a.foo(object_a,c,c);
    // object_a.foo(object_a,3 ,3);
    ft::vector<int> v1;
    v1.assign(3, 3);
    // v1.insert(v1.begin() , 10, 5);
    ft::vector<int> v2;
    // v2.insert(v2.begin(),v1.begin(), v1.end());
    v2.assign(v1.begin(), v1.end());
    v1.push_back(4);
    pr(v1);
    pr(v2);
    std::cout << ft::equal(v1.begin(), v1.end(), v2.begin(),ft::pred);
    // // v2.insert(myvector.begin() + 1,3,2);
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


    // std::vector<int> v1;
    // v1.insert(v1.begin(),1,3);
    // v1.insert(v1.begin(),6);
    // v1.push_back(1);
    // v1.push_back(2);
    // v1.push_back(3);
    // v1.resize(2);
    // pr(v1);
    // ft::vector<int>::const_reverse_iterator i = v1.rbegin();
    // std::cout << *(v1.rbegin()) << std::endl;
    // std::cout << "*i= " << i << std::endl;
    // for (std::vector<int>::reverse_iterator i = v1.rend(); i != v1.rbegin(); i--)
    // *(i.base()) = 5;
    // v2.assign(3,3); // <--- uncomment this for idnerection requires pointer 
    // const int a = 10;
    // v1.push_back(a);
    // std::vector<int>::const_iterator a = v1.begin();

    // std::cout << *a;
    // v1.assign(a, a + 1);

    // ft::vector<int> v1(v2.begin(), v2.end() - 1);

    // std::vector<int> v2;
    // v1.push_back(1);
    // v1.push_back(2);
    // v1.push_back(3);
    // // v1.insert(v1.end(),3,7);

    // v2.insert(v2.begin(),0,0); // <----- uncomment this
    // v1.insert(v1.begin() + 2, v1.begin(),v1.end());
    // v2.assign(10,10);
    // v1.assign(5,5);

    // v1.assign(20,20);
    // pr(v1);
    // v1.assign(v2.begin(), v2.end());
    // pr(v1);
    // std::cout << *(v1.erase(v1.begin())) << std::endl;
    // v1.erase(v1.begin(), v1.end());
    // v1.erase(v1.begin());
    // v1.erase(v1.begin());
    // pr(v1);
    // ft::vector<int>::iterator i = v.begin();
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