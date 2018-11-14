#include "Item.h"

Item* Item::getNext(){
    return this->next;
}

Item* Item::getPrev(){
    return this->prev;
}

void Item::setNext(Item* next){
    this->next = next;
}
void Item::setPrev(Item* prev){
    this->prev = prev;
}
