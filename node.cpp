#include "node.h"

node::node(const int& data, const int& height, node* left, node* right) :
	data(data), 
	height(height),
	left(left),
	right(right)
	{}

int node::get_data() const noexcept
{
	return data;
}

node* node::get_left() const noexcept
{
	return left;
}

node* node::get_right() const noexcept
{
	return right;
}
