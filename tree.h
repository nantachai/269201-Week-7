#include <queue>
#include <stack>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#ifndef Binary_Search_Tree
#define Binary_Search_Tree
template<class T> class Tree;
template<class T>
class Node {
public:
	Node() { left = right = NULL; }
	Node(const T& el, Node *l = 0, Node *r = 0) {
		key = el; left = l; right = r;
	}
	Node(const T& el, int line){ key = el; left = right = NULL; linenum = line; }

	int linenum;
	T key;
	Node *left, *right;
};
template<class T>
class Tree {
public:
	Tree() { root = 0; }
	~Tree() { clear(); }
	void clear() { clear(root); root = 0; }
	bool isEmpty() { return root == 0; }
	//void inorder() { inorder(root); }
	void insert(const T& el);
	//void deleteNode(Node<T> *& node);
	void deleteNode(Node<T> *& node, const T &el);
	void visit(Node<T> *p);
	int height(Node<T> *p);
	void balance(vector<T> myvector, int index_first, int index_last);
	void rand_to_tree(int num);
	void rand_to_del(int num);
	void inorder() { inorder(root); };// { inorder(root, myvector); }
	void search(Node<T> *p, const T& el);
	Node<T> *root;
	vector<T> myvector;
protected:
	//Node<T> *root;
	int l, r;
	void clear(Node<T> *p);
	void inorder(Node<T> *p);
};
template<class T>
void Tree<T>::clear(Node<T> *p)
{
	if (p != 0) {
		clear(p->left);
		clear(p->right);
		delete p;
	}
	root = 0;
}
template<class T>
void Tree<T>::inorder(Node<T> *p) {
	//TO DO! This is for an inorder tree traversal!
	if (p != 0) {
		inorder(p->left);
		visit(p);
		inorder(p->right);
	}
}

template<class T>
void Tree<T>:: search(Node<T> *p, const T& el)
{
	if (p != 0){
		while (p != 0)
		{
			if (el == p->key){ cout << p->key <<" have in Tree"<<  endl;}
			else if (el < p->key)
			{ 
				p = p->left; 
				search(p, el); 
			}
			else
			{ 
				p = p->right; 
				search(p, el); 
			}
			//else { cout << "Don't HAVE in Tree" << endl; }
			break;
		}
	}
	else { cout << "Don't HAVE in Tree" << endl;}
}


template<class T>
void Tree<T>::visit(Node<T> *p) {
	cout << p->key << " ";
	myvector.push_back(p->key);
}

template<class T>
void Tree<T>::insert(const T &el) {
	Node<T> *p = root, *prev = 0;
	while (p != 0) {
		prev = p;
		if (p->key < el)
			p = p->right;
		else
			p = p->left;
	}
	if (root == 0)
		root = new Node<T>(el);
	else if (prev->key<el)
		prev->right = new Node<T>(el);
	else
		prev->left = new Node<T>(el);
	//cout << el <<" has insert" << endl;
}

template<class T>
void Tree<T>::rand_to_del(int num) {
	int i = 0;
	while (i < num)
	{
		int number = rand() % 99 + 1;
		cout << "will delete " << number << endl;
		deleteNode(root,number);
		i++;
	}
}

template<class T>
void Tree<T>::deleteNode(Node<T> *&node, const T &el) {
	Node<T> *cur = node;
	Node<T> *pre = node;
	Node<T> *ro;
	ro = node;
	bool found = false;
	bool del = false;
	bool empty = false;
	if (cur == 0){
		cout << "Tree is empty" << endl;
		empty = true;
	}
		while (cur != 0)
		{
			if (cur->key == el)
			{
				cout << "cur now : " << cur->key << endl;
				cout << "pre now : " << pre->key << endl;
				found = true;
				break;
			}
			else
			{
				pre = cur;
				if (el > (cur->key))
					cur = cur->right;
				else
					cur = cur->left;
			}
		}
	if (!found)
	{
		cout << el << " not in Tree." << endl;
		cur = node;
		pre = node;
		del = true;
	}
	
	if (!empty){
		cout << "#########################" << endl;
		//Removing a Leaf Node ------ checked!!!
		if (cur->left == 0 && cur->right == 0 && del != true)
		{
			cout << "Leaf Node" << endl;
			if (pre->left == cur)
				pre->left = 0;
			else pre->right = 0;
			cout << cur->key << " has been removed from the Tree." << endl;
			delete cur;
			cur = node;
			pre = node;
			del = true;
		}

		//Removing a node with a single child
		if (cur->left == 0 && cur->right != 0 && del != true || cur->left != 0 && cur->right == 0 && del != true)
		{
			cout << "node with a single child" << endl;
			if (cur->left == 0 && cur->right != 0)
			{
				cout << "single child RIGHT" << endl;
				if (cur == ro)
				{
					Node<T> *tmp;
					tmp = cur->right;
					node = tmp;
					delete cur;
					cur = node;
				}
				else if (pre->left == cur)
				{
					cout << "LLL" << endl;
					pre->left = cur->right;
					cout << cur->key << " has been removed from the Tree." << endl;
					delete cur;
					cur = node;
					pre = node;

				}
				else
				{
					cout << "RRR" << endl;
					pre->right = cur->right;
					cout << cur->key << " has been removed from the Tree." << endl;
					delete cur;
					cur = node;
					pre = node;

				}
			}
			else
			{
				cout << "single child LEFT" << endl;
				if (cur == ro)
				{
					Node<T> *tmp;
					tmp = cur->left;
					node = tmp;
					delete cur;
					cur = node;
				}
				else if (pre->left == cur)
				{
					cout << "LLL" << endl;
					pre->left = cur->left;
					cout << cur->key << " has been removed from the Tree." << endl;
					delete cur;
					cur = node;
					pre = node;
				}
				else
				{
					cout << "RRR" << endl;
					pre->right = cur->left;
					cout << cur->key << " has been removed from the Tree." << endl;
					delete cur;
					cur = node;
					pre = node;
				}
			}
			del = true;
		}

		//Removing a Node has two children		
		if (cur->left != 0 && cur->right != 0 && del != true)
		{
			cout << "Node has two children" << endl;
			Node<T> *tmp;
			tmp = cur->left;
			pre = cur;
			while (tmp->right != 0) {
				pre = tmp;
				tmp = tmp->right;
			}
			cout << "Bigest is " << tmp->key << endl;
			cur->key = tmp->key;
			if (pre == cur)
				pre->left = tmp->left;
			else pre->right = tmp->left;
			delete tmp;
			cur = node;
			pre = node;
			del = true;
		}
	}
}
template<class T>
int Tree<T>::height(Node<T> *p)
{
	int left, right;

	if (p == NULL)
		return 0;
	left = height(p->left);
	right = height(p->right);
	if (left > right)
		return left + 1;
	else
		return right + 1;
}
template<class T>
void Tree<T>::balance(vector<T> myvector, int index_first, int index_last) {
	if (index_first <= index_last) {
		//index_last = index_last - 1;
		int middle = (index_first + index_last) / 2;
		//cout << "index " << middle << " Add is : " << myvector.at(middle) << endl;
		insert(myvector.at(middle));
		balance(myvector, index_first, middle - 1);
		balance(myvector, middle + 1, index_last);
	}
}
template<class T>
void Tree<T>::rand_to_tree(int num)
{
	int i = 0;
	while (i < num)
	{
		int number = rand() % 99 + 1;
		insert(number);
		i++;
	}
}
#endif // Binary_Search_Tree
