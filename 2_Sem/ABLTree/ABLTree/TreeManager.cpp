﻿#include "TreeManager.h"

int height(Node* p)
{
	return p ? p->height : 0;
}

int bfactor(Node* p)
{
	return height(p->right) - height(p->left);
}

void fixheight(Node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

Node* rotateright(Node* p)
{
	Node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

Node* rotateleft(Node* q)
{
	Node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

Node* balance(Node* p)
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

Node* insert(Node* p, int k)
{
	if (!p) return new Node(k);
	if (k < p->key)
		p->left = insert(p->left, k);
	else if (k > p->key)
		p->right = insert(p->right, k);
	else {
		return p;
	}
	return balance(p);
}

Node* find(Node* p, int k) {
	if (!p) return nullptr;
	if (k < p->key)
		return find(p->left, k);
	else if (k > p->key)
		return find(p->right, k);
	else {
		return p;
	}
}

Node* findmin(Node* p)
{
	return p->left ? findmin(p->left) : p;
}

Node* removemin(Node* p)
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

Node* remove(Node* p, int k)
{
	if (!p) return 0;
	if (k < p->key)
		p->left = remove(p->left, k);
	else if (k > p->key)
		p->right = remove(p->right, k);
	else //  k == p->key 
	{
		Node* q = p->left;
		Node* r = p->right;
		delete p;
		if (!r) return q;
		Node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

