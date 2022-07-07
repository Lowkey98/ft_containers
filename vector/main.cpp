#include "vector.hpp"
#include <vector>
#include <cstdio>
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
//         // printf("capacity = %ld\n", v.capacity());
//         // v.resize(40,5);
//         // v.push_back(1);
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

int main ()
{
  std::vector<int> myvector;

  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);
  printf("Size = %ld\n", myvector.size());
  printf("capacity = %ld\n", myvector.capacity());
  myvector.resize(5);
  printf("Size = %ld\n", myvector.size());
  printf("capacity = %ld\n", myvector.capacity());
  myvector.resize(8,100);
  printf("Size = %ld\n", myvector.size());
  printf("capacity = %ld\n", myvector.capacity());
  myvector.resize(100);
  printf("Size = %ld\n", myvector.size());
  printf("capacity = %ld\n", myvector.capacity());

  std::cout << "myvector contains:";
  for (size_t i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
}