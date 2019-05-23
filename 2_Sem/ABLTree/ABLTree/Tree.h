#pragma once
#include "Node.h"

unsigned char height(Node* p);
int bfactor(Node* p);
void fixheight(Node* p);
Node* rotateright(Node* p); // правый поворот вокруг p
Node* rotateleft(Node* q); // левый поворот вокруг q
Node* balance(Node* p); // балансировка узла p
Node* insert(Node* p, int k); // вставка ключа k в дерево с корнем p
Node* findmin(Node* p); // поиск узла с минимальным ключом в дереве p 
Node* removemin(Node* p); // удаление узла с минимальным ключом из дерева p
Node* remove(Node* p, int k); // удаление ключа k из дерева p

