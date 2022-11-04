#include "avl.hpp"
#include <map>
#include "map.hpp"
#include "../helper.hpp"
int main()
{
	// Tree <int,int> a;
	// // a.insert(ft::pair<int,int>(100,3));
	// // a.insert(ft::pair<int,int>(40,3));
	// a.insert(ft::pair<int,int>(20,3));
	// a.insert(ft::pair<int,int>(110,3));
    // a.delete_node(110);
    // a.delete_node(20);
    // // a.delete_node(20);
	// a.insert(ft::pair<int,int>(110,3));
    // // a.delete_node(110);
	// a.insert(ft::pair<int,int>(10,3));
	// a.insert(ft::pair<int,int>(19,3));

    // a.inorder(a.root);
    // std::cout << a.findPredecessorIterative(a.root,110)->data.first;
    std::map<int, int> m;
    m.insert(std::pair<int,int>(1,3));
    m.insert(std::pair<int,int>(2,3));
    m.insert(std::pair<int,int>(3,5));
    m.insert(std::pair<int,int>(4,5));
    // std::map<int, int>::reverse_iterator r_it = m.rbegin();
    // std::cout << (*r_it).first << std::endl;
    // std::map<int, int>::reverse_iterator r_it = m.rbegin();
    // std::cout << (*r_it).first << std::endl;
    for (std::map<int, int>::reverse_iterator r_it = m.rbegin(); r_it != m.rend(); ++r_it)
    {
        // std::cout << r_it[3].first;
        std::cout << (*r_it).first  << "base: " << (*r_it.base()).first << std::endl;
    }
    
    // ft::map<int, int> m1;
    // m1.insert(ft::pair<int,int>(11,3));
    // m1.insert(ft::pair<int,int>(21,3));
    // m1.insert(ft::pair<int,int>(31,5));
    // m1.insert(ft::pair<int,int>(41,5));
    // m.swap(m1);
    // allocate an array of 5 elements using mymap's allocator:
// std::cout << (*m._bound(2)).first << std::endl;
    // ft::map<int,int>::key_compare mycomp = m.key_comp();
    // std::cout << mycomp(2,3);
    // m[2] = 10;
    // m.erase(3);
    // ft::map<int,int>::iterator it = m.begin();
    // m.insert(ft::pair<int,int>(4,3));
    // ft::map<int, int> m1;
    // m1.insert(m.begin(), m.end());
    // for (it = m1.begin(); it != m1.end(); ++it)
    // {
    //     std::cout << it->first << std::endl;
    // }
    // m1.erase(m1.begin(), m1.end());
    // ++it;
    // ++it;
    // ++it;
    // --it;
    // ++it;
    // ++it;
    // ++it;
    // --it;
    // ++it;
    // --it;
    // --it;
    // --it;
    // --it;
    // std::cout << it->first << std::endl;
    // m1.clear();
	// for (it=mymap.begin(); it!=mymap.end(); it++)
	// {
	//     std::cout << it->first << " => " << it->second << '\n';
	// }
    // ++it;
	// a.insert(ft::pair<int,int>(30,3));
    // a.delete_node(30);
    // a.delete_node(40);
    // a.delete_node(100);
    // a.delete_node(100);
    // a.delete_node(100);
    // a.delete_node(50);
    // a.delete_node(25);
    // a.delete_node(4);
    // a.inorder(a.root);
	// a.root = a.insert(a.root,2);
	// a.root = a.insert(a.root,3);
	// a.inorder(a.root);
	// ft::map<int,int> mymap;
	// ft::map<int,int>::iterator it;
	// mymap.insert (ft::pair<int,int>(1,3) );
	// mymap.insert (ft::pair<int,int>(3,3) );
	// mymap.insert (ft::pair<int,int>(13,7) );
    // mymap.erase(mymap.begin(), mymap.end());
	// mymap.erase(1);
	// mymap.erase(1);
	// mymap.erase(3);
	// mymap.erase(13);
	// mymap.insert (ft::pair<int,int>(1,3) );
	// mymap.insert (ft::pair<int,int>(13,7) );
	// mymap.insert (ft::pair<int,int>(4,7) );
	// mymap.insert (ft::pair<int,int>(4,7) );
	// mymap.erase(4);
	// mymap.insert (ft::pair<int,int>(8,7) );
	// mymap._tree.inorder(mymap._tree.root);
	// mymap.insert (ft::pair<int,int>(3,7) );
	// mymap._tree.inorder(mymap._tree.root);
	// mymap.insert (ft::pair<int,int>(13,7) );
	// it++;
		// std::cout << it->first << " => " << it->second << '\n';

	return 0;
}