
#include "tree.h"

#include <iostream>
#include <vector>
using namespace std;

void main()
{
	Tree<int> mytree;
	bool exit = false;
	mytree.rand_to_tree(10);
	cout << "the height of the tree is : " <<mytree.height(mytree.root)<<endl;
	mytree.inorder();
	cout << endl;
	cout <<"Size : "<< mytree.myvector.size() << endl;
	mytree.clear();  //clear tree
	mytree.balance(mytree.myvector, 0, mytree.myvector.size() - 1);  //balance tree
	cout << "NEW the height of the tree after balancing is : " << mytree.height(mytree.root) << endl;
	int x,y;
	while (exit == false)
	{
		cout << "-------------------------------------------------------------" << endl;
		cout << "What do you want to do ?" << endl;
		cout << "insert press 1" << endl;
		cout << "search press 2" << endl;
		cout << "delete press 3" << endl;
		cout << "find height prees 4" << endl;
		cout << "clear tree prees 5" << endl;
		cout << "balance press 6" << endl;
		cout << "exit press 7" << endl;
		cin >> x;
		if (x > 7 || x < 1 || !cin.good()){ cout << "Please input new" << endl; }
		else{
			switch (x)
			{
			case 1:
				cout << "how many random numbers do you want to insert : ";
				cin >> y;
				mytree.rand_to_tree(y);
				break;
			case 2:
				cout << "what number do you search : ";
				cin >> y;
				mytree.search(mytree.root, y);
				break;
			case 3:
				cout << "how many random number do you want to delete : ";
				cin >> y;
				mytree.rand_to_del(y);
				break;
			case 4:
				cout << "your tree height : " << mytree.height(mytree.root) << endl;
				break;
			case 5:
				mytree.clear();
				break;
			case 6:
				mytree.myvector.clear();
				mytree.inorder();
				mytree.clear();
				mytree.balance(mytree.myvector, 0, mytree.myvector.size() - 1);
				break;
			case 7:
				exit = true;
				break;

			}
		}
	}
}
