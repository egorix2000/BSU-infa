#pragma once
class Node
{
public:
	int key;
	unsigned char height;
	Node* left;
	Node* right;
	Node(int k);
};

