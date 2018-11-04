#include "ComplexNumberStackNode.h"
#include "ComplexNumber.h"

ComplexNumberStackNode::ComplexNumberStackNode(){
    ComplexNumber* value = new ComplexNumber(0, 0);
    this->value = *value;
    this->next = 0;
};

ComplexNumberStackNode::ComplexNumberStackNode(const ComplexNumber& value){
    this->value = value;
    this->next = 0;
};

ComplexNumberStackNode::ComplexNumberStackNode(const ComplexNumber& value, ComplexNumberStackNode* next){
    this->value = value;
    this->next = next;
};
