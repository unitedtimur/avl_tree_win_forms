#pragma once

class node
{
public:
	node(const int& data = 0, const int& height = 1, node* left = nullptr, node* right = nullptr);

	int get_data() const noexcept;
	node* get_left() const noexcept;
	node* get_right() const noexcept;

private:
	int data,
		height;
	node* left,
		* right;
	friend class avl_tree;
};

