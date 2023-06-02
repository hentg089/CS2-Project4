//Mark Hentges 5814125 - 3/16/2023

#include <iostream>


#include "Infix.h"
#include "DivideByZero.h"

int main() {
    Infix infixObject;
    std::string experession;

    while (getline(std::cin, experession)) {
        try{
            infixObject.setInfixString(experession);
            std::cout << experession << " = " << infixObject.getEvaluatedInfix() << std::endl;
        } catch(DivideByZero& e){
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "your terminal commands do not work brp";





    return 0;
}
