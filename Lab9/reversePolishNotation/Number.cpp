#include "Number.h"

Number::Number(int value, Item* previous, Item* next){
    this->value = value;
    this->prev = previous;
    this->next = next;
}

int Number::calc(){
    return this->value;
}

int Number::getValue(){
    return this->value;
}

void Number::setValue(int value){
    this->value = value;
}
