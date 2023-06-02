//
//Mark Hentges 5814125 - 3/16/2023
//


#ifndef PROJECT4_INFIX_H
#define PROJECT4_INFIX_H

#include <string>
#include "LinkedStack.cpp"

class Infix {
private:
    std::string infix = "";
    bool isPrecedenceGreater(char check, char compare);
    void performOperation(LinkedStack<int>& valueStack, LinkedStack<char>& operators);

public:
    Infix() = default;

    void setInfixString(std::string infix);

    std::string getInfixString();

    int getEvaluatedInfix();

    ~Infix() = default;


};

#endif //PROJECT4_INFIX_H
