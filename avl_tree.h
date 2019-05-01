#pragma once
#include "node.h"
#include <ostream>
#include <vector>

class avl_tree
{
public:
	explicit avl_tree();
	//~avl_tree();
	void push(const int& data);
	void pop(const int& data);
	void print_lrd(node* _node);
	node* find(const int& data);
	node* get_root();

	std::vector<int> post(node* _node);
	friend std::ostream& operator<<(std::ostream& os, avl_tree& tree);

private:
	node* root;
	node* push(node* _node, const int& data);
	node* pop(node* _node, const int& data);
	node* find(node* _node, const int& data);
	node* findMin(node* _node);
	node* removeMin(node* _node);
	node* rotateRight(node* _node);
	node* rotateLeft(node* _node);
	node* balance(node* _node);

	unsigned char height(node* _node);

	int bfactor(node* _node);

	void fixHeight(node* _node);
	void delete_tree(node* _node);
};

