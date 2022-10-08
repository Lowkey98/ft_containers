#include "bst.hpp"
#include <map>
#include "map.hpp"
#include "../helper.hpp"
int main()
{
	Tree <int,int> a;
	// a.root = a.insert(a.root,1);
	// a.root = a.insert(a.root,2);
	// a.root = a.insert(a.root,3);
	// a.inorder(a.root);
	ft::map<int,int> mymap;
	ft::map<int,int>::iterator it;
	mymap.insert (ft::pair<int,int>(3,3) );
	mymap.insert (ft::pair<int,int>(1,3) );
	mymap.insert (ft::pair<int,int>(13,7) );
	mymap.insert (ft::pair<int,int>(4,7) );
	mymap.insert (ft::pair<int,int>(80,7) );
	mymap._tree.inorder(mymap._tree.root);
	// mymap.insert (ft::pair<int,int>(3,7) );
	// mymap._tree.inorder(mymap._tree.root);
	// mymap.erase(13);
	// mymap.insert (ft::pair<int,int>(13,7) );
	// for (it=mymap.begin(); it!=mymap.end(); it++)
	// {
	//     std::cout << it->first << " => " << it->second << '\n';
	// }
	// it++;
		// std::cout << it->first << " => " << it->second << '\n';

	return 0;
}