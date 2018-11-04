#include "ComplexNumberQueueNode.h"
#include "ComplexNumber.h"

ComplexNumberQueueNode::ComplexNumberQueueNode(){
    ComplexNumber* value = new ComplexNumber(0, 0);
    this->value = *value;
    this->next = 0;
};

ComplexNumberQueueNode::ComplexNumberQueueNode(const ComplexNumber& value){
    this->value = value;
    this->next = 0;
};

ComplexNumberQueueNode::ComplexNumberQueueNode(const ComplexNumber& value, ComplexNumberQueueNode* next){
    this->value = value;
    this->next = next;
};
