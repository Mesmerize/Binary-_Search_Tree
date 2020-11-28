// Here is the file binarytree.h

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "LL.h"
#include <cstdlib>	// for size_t
//#include <list>

class binarytree {

public:
	typedef std::size_t size_type;
	LL<int> toLL();
	binarytree();
	binarytree(const binarytree& right);
	~binarytree();
	binarytree operator=(const binarytree& aTree);
	void insert(int item);
	void print() const;
	size_type size() const;
	int find(int target, bool& found) const;
	void del(int target, bool& found);
	static bool primeTest(int integer);
	int numPrimes() const;
private:
	struct treenode {
		int data;
		treenode* left;
		treenode* right;
	};
	size_t mSize;
	//static int mSize;
	treenode* root;
	static void toLL_aux(const treenode*, LL<int>&);
	static void insert_aux(treenode*& root, int item);
	static void print_aux(const treenode* root);
	static size_type size_aux(const treenode* root);
	static int find_aux(const treenode* root, int target, bool& found);
	static void del_aux(treenode*& root, int target, bool& found);
	static void remove_max(treenode*& root, int& max);
	static int numPrimes_aux(const treenode* root, int& primes);
	static void copy(treenode*& root1, treenode* root2);
	static void clear(treenode*);
}; 
#endif