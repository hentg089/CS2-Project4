//
//Mark Hentges 5814125 - 3/16/2023
//

#include "DivideByZero.h"

DivideByZero::DivideByZero(const std::string& message) : std::overflow_error(message){
    this->message = message;
}

std::string DivideByZero::what() {
    return message;
}


