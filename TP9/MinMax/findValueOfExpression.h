#pragma once
#ifndef LAB_FINDVALUEOFEXPRESSION_H
#define LAB_FINDVALUEOFEXPRESSION_H

#include <cctype>
#include <cstring>
#include "Stack.h"

int findMin(int a, int b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}

int findMax(int a, int b){
    if (a > b){
        return a;
    } else {
        return b;
    }
}

int findValueOfExpression(const char *s, Stack<int>& expression){
    int min = -1;
    int max = 10;
    int ans;
    int temp1;
    int temp2;
    int temp3;
    for (int i = 0; i < strlen(s); i++){
        if (isdigit(s[i])){
            expression.push(s[i]-'0');
        } else if (s[i] == '('){
            if (s[i-2] == 'i'){ // min
                expression.push(min);
            } else { // max
                expression.push(max);
            }
        } else if (s[i] == ')') {
            temp1 = expression.getTop();
            expression.pop();
            temp2 = expression.getTop();
            expression.pop();
            if (expression.getTop() == min){
                temp3 = findMin(temp1, temp2);
            } else {
                temp3 = findMax(temp1, temp2);
            }
            expression.pop();
            expression.push(temp3);
        }
    }
    ans = expression.getTop();
    return ans;
}

#endif //LAB_FINDVALUEOFEXPRESSION_H
