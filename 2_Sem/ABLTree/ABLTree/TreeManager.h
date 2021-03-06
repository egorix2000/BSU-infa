#pragma once
#include "Node.h"

int height(Node* p);
int bfactor(Node* p);
void fixheight(Node* p);
Node* rotateright(Node* p); // ?????? ??????? ?????? p
Node* rotateleft(Node* q); // ????? ??????? ?????? q
Node* balance(Node* p); // ???????????? ???? p
Node* insert(Node* p, int k); // ??????? ????? k ? ?????? ? ?????? p
Node* findmin(Node* p); // ????? ???? ? ??????????? ?????? ? ?????? p 
Node* removemin(Node* p); // ???????? ???? ? ??????????? ?????? ?? ?????? p
Node* remove(Node* p, int k); // ???????? ????? k ?? ?????? p
Node* find(Node* p, int k); // ?????????? ????? p ? ?????? p