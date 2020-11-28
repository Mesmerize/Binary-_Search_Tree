// Here is the file binarytree.cpp

#include <iostream>
#include <cassert>
//#include <list>
#include "binarytree.h"
#include "LL.h"
using namespace std;


//int binarytree::mSize = 0;
binarytree::binarytree() {
	root = nullptr;
	mSize = 0;
}

binarytree::~binarytree()
{
	clear(root);
}

void binarytree::clear(treenode* root)
{
	if (root != nullptr)
	{
		clear(root->left);
		clear(root->right);

		delete root;
	}
	else
		delete root;
}

binarytree binarytree::operator=(const binarytree& aTree)
{
	if (this != &aTree)
	{
		clear(this->root);
		copy(this->root, aTree.root);
	}

	return *this;
}

binarytree::binarytree(const binarytree& right)
{
	copy(this->root, right.root);
}

void binarytree::print() const {
	print_aux(root);
}


void binarytree::insert(int item) {
	mSize++;
	insert_aux(root, item);
}


binarytree::size_type binarytree::size() const {
	//return size_aux(root);
	return mSize;
}


int binarytree::find(int target, bool& found) const {
	return find_aux(root, target, found);
}


void binarytree::del(int target, bool& found) {
	del_aux(root, target, found);
	if (found == true)
		mSize--;
}

bool binarytree::primeTest(int num)
{
	
	bool prime = false;

	//Case for if 2 is detected
	if (num == 2)
		return true;

	for (int i = 2; i < num; i++)
	{
		
		if (num % i == 0)
		{
			prime = true;
			break;
		}
	}

	return prime;
}

int binarytree::numPrimes() const
{
	int max = 0;
	numPrimes_aux(root, max);
	return max;
}

int binarytree::numPrimes_aux(const treenode* root, int& primes)
{
	if (root != nullptr)
	{
		numPrimes_aux(root->left, primes);

		if (!primeTest(root->data))
		primes++;

		numPrimes_aux(root->right, primes);

	}

	return primes;
}

LL<int> binarytree::toLL()
{
	LL<int> ll;
	toLL_aux(root, ll);
	return ll;
}

void binarytree::toLL_aux(const treenode* root, LL<int>& newList)
{
	if (root != nullptr)
	{
		toLL_aux(root->right, newList);
		newList.push_front(root->data);
		toLL_aux(root->left, newList);
	}
}

void binarytree::del_aux(treenode*& root,int target,bool& found) {

	if (root == nullptr) {
		found = false;
	}
	else if (target < root->data) {
		del_aux(root->left, target, found);
	}
	else if (target > root->data) {
		del_aux(root->right, target, found);
	}
	else if (root->left == nullptr) {
		treenode* tempptr = root;
		root = root->right;
		delete tempptr;
		found = true;
		//mSize--;
	}
	else {
		int max;
		remove_max(root->left, max);
		root->data = max;
		found = true;
		//mSize--;
	}
}

// pre: root != nullptr

void binarytree::remove_max(treenode*& root, int& max) {
	if (root->right == nullptr) {
		max = root->data;
		treenode* tempptr = root;
		root = root->left;
		delete tempptr;
	}
	else {
		remove_max(root->right, max);
	}
}



int binarytree::find_aux(const treenode* root,
	int target,
	bool& found) {

	if (root == nullptr) {
		found = false;
		return 0;
	}
	else if (target == root->data) {
		found = true;
		return root->data;
	}
	else if (target < root->data) {
		return find_aux(root->left, target, found);
	}
	else {
		return find_aux(root->right, target, found);
	}
}

void binarytree::copy(treenode*& root1, treenode* root2)
{
	if (root2 != nullptr)
	{
		root1 = new treenode;
		root1->data = root2->data;
		//root1->left = root2->left;
		copy(root1->left, root2->left);
		//root1->right = root2->right;
		copy(root1->right, root2->right);
	}

	else
		root1 = nullptr;
}

binarytree::size_type binarytree::size_aux(const treenode* root) {
	if (root == nullptr) {
		return 0;
	}
	else {
		return size_aux(root->left)
			+ size_aux(root->right)
			+ 1;
	}
}


void binarytree::insert_aux(treenode*& root, int item) {
	if (root == nullptr) {
		root = new treenode;
		root->data = item;
		root->left = nullptr;
		root->right = nullptr;
		//mSize++;
	}
	else if (item <= root->data) {
		insert_aux(root->left, item);
	}
	else {
		insert_aux(root->right, item);
	}
}


void binarytree::print_aux(const treenode* root) {
	if (root != nullptr) {
		print_aux(root->left);
		cout << root->data << " ";
		print_aux(root->right);
	}
}


