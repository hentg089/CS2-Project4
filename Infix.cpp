//
//Mark Hentges 5814125 - 3/16/2023
//

#include "DivideByZero.h"
#include "Infix.h"

bool Infix::isPrecedenceGreater(char check, char compare){
    if((check == 42 || check == 47) && (compare == 43 || compare == 45 || compare == 40)) {
        return true;
    } else if((check == 43 || check == 45) && (compare == 40)){
        return true;
    }
    else{
        return false;
    }
}

void Infix::performOperation(LinkedStack<int>& valueStack, LinkedStack<char>& operators){
    int RHSoperand = valueStack.peek();
    valueStack.pop();
    int LHSoperand = valueStack.peek();
    valueStack.pop();
    char op = operators.peek();
    operators.pop();
    int result = 0;
    switch (op) {
        case '+':
            result = LHSoperand + RHSoperand;
            break;
        case '-':
            result = LHSoperand - RHSoperand;
            break;
        case '*':
            result = LHSoperand * RHSoperand;
            break;
        case '/':
            if(RHSoperand == 0){
                throw DivideByZero("Infinite result - Cannot handle division-by-zero.");
            }
            result = LHSoperand / RHSoperand;
            break;
    }
    valueStack.push(result);
}

void Infix::setInfixString(std::string infix){
    this->infix = infix;
}

std::string Infix::getInfixString(){
    return infix;
}

int Infix::getEvaluatedInfix(){
    LinkedStack<char> operators;
    LinkedStack<int> value;

    for(char c : infix){
        switch(c){
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                value.push(c - 48); //shifts the char values
                break;
            case '(':
                operators.push(c);
                break;
            case '*': case '+': case '-': case '/':
                if(operators.isEmpty() || isPrecedenceGreater(c, operators.peek())){
                    operators.push(c);
                }
                else{
                    while(!operators.isEmpty() && !isPrecedenceGreater(c, operators.peek())){
                        performOperation(value, operators);
                    }
                    operators.push(c);
                }
                break;
            case ')':
                while(operators.peek() != '('){
                    performOperation(value, operators);
                }
                operators.pop();
                break;
        }
    }

    while(!operators.isEmpty()){
        performOperation(value, operators);
    }

    return value.peek();
}




