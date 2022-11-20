#include "map.hpp"
#include <map>
#include <string>
int main()
{
      ft::map<int, int> ft_m1;
      // for (size_t i = 0; i < 3; i++)
      //   ft_m1.insert(ft::make_pair(i, "string2"));
        ft_m1.insert(ft::make_pair(0, 2));
        ft_m1.insert(ft::make_pair(1, 2));
        // ft_m1.insert(ft::make_pair(2, "string2"));
      // ft_m1.erase(ft_m1.begin(), ft_m1.end());
      // ft_m1.erase(0);
        ft_m1.erase(1);
      // ft_m1.erase(2);
      // ft_m1.erase(3);
      // ft::map<int, std::string>::reverse_iterator it = ft_m1.rend();
      // ft::map<int, std::string>::const_reverse_iterator cit = it;
      // it--;
      // std::cout << (*it).first << std::endl;
    // while(1);
    return 0;
}