#include "avl_tree.h"
#include <iostream>

avl_tree::avl_tree() : root(nullptr) {}

//avl_tree::~avl_tree()
//{
//	delete_tree(root);
//}

void avl_tree::push(const int& data)
{
	root = push(root, data);
}

void avl_tree::pop(const int& data)
{
	root = pop(root, data);
}

node* avl_tree::find(const int& data)
{
	return find(root, data);
}

node* avl_tree::get_root()
{
	return root;
}

std::vector<int> avl_tree::post(node* _node)
{
	static std::vector<int> vec;

	if (_node->left) post(_node->left);
	if (_node->right) post(_node->right);

	vec.push_back(_node->data);

	return vec;
}

void avl_tree::print_lrd(node* _node)
{
	if (_node->left) print_lrd(_node->left);
	if (_node->right) print_lrd(_node->right);
	std::cout << _node->data << " ";
}

node* avl_tree::push(node* _node, const int& data)
{
	if (_node == nullptr) return new node(data);

	data < _node->data ? _node->left = push(_node->left, data) : _node->right = push(_node->right, data);

	return balance(_node);
}

node* avl_tree::pop(node * _node, const int& data)
{
	if (_node == nullptr) return nullptr;

	if (data < _node->data)
	{
		_node->left = pop(_node->left, data);
	}
	else if (data > _node->data)
	{
		_node->right = pop(_node->right, data);
	}
	else
	{
		node* left_node = _node->left;
		node* right_node = _node->right;

		delete _node;

		if (right_node == nullptr) return left_node;

		node * min = findMin(right_node);
		min->right = removeMin(right_node);
		min->left = left_node;

		return balance(min);
	}

	return balance(_node);
}

node* avl_tree::find(node * _node, const int& data)
{
	if (_node == nullptr) return nullptr;

	if (data < _node->data)
	{
		_node->left = find(_node->left, data);
	}
	else if (data > _node->data)
	{
		_node->right = find(_node->right, data);
	}
	else
	{
		return _node;
	}
}

node* avl_tree::findMin(node* _node)
{
	return _node->left ? findMin(_node->left) : _node;
}

node* avl_tree::removeMin(node* _node)
{
	if (_node->left == nullptr) return _node->right;

	_node->left = removeMin(_node->left);

	return balance(_node);
}

node* avl_tree::rotateRight(node * _node)
{
	node* left_node = _node->left;
	_node->left = left_node->right;
	left_node->right = _node;

	fixHeight(_node);
	fixHeight(left_node);

	return left_node;
}

node* avl_tree::rotateLeft(node * _node)
{
	node* right_node = _node->right;
	_node->right = right_node->left;
	right_node->left = _node;

	fixHeight(_node);
	fixHeight(right_node);

	return right_node;
}

node* avl_tree::balance(node * _node)
{
	fixHeight(_node);

	if (bfactor(_node) == 2)
	{
		if (bfactor(_node->right) < 0)
		{
			_node->right = rotateRight(_node->right);
		}

		return  rotateLeft(_node);
	}

	if (bfactor(_node) == -2)
	{
		if (bfactor(_node->left) > 0)
		{
			_node->left = rotateLeft(_node->left);
		}

		return rotateRight(_node);
	}

	return _node;
}

unsigned char avl_tree::height(node * _node)
{
	return _node ? _node->height : 0;
}

int avl_tree::bfactor(node * _node)
{
	return height(_node->right) - height(_node->left);
}

void avl_tree::fixHeight(node * _node)
{
	unsigned char hL = height(_node->left);
	unsigned char hR = height(_node->right);

	_node->height = (hL > hR ? hL : hR) + 1;
}

void avl_tree::delete_tree(node* _node)
{
	if (_node->left) delete_tree(_node->left);
	if (_node->right) delete_tree(_node->right);

	delete _node;
}

std::ostream& operator<<(std::ostream& os, avl_tree& tree)
{
	if (tree.get_root() != nullptr)
	{
		tree.print_lrd(tree.get_root());
	}

	return os;
}
