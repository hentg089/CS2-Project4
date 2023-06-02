//
//Mark Hentges 5814125 - 3/16/2023
//

#ifndef PROJECT4_DIVIDEBYZERO_H
#define PROJECT4_DIVIDEBYZERO_H


#include <stdexcept>

class DivideByZero : std::overflow_error {
    std::string message = "";
public:
    explicit DivideByZero(const std::string& message);

    std::string what();

    virtual ~DivideByZero() noexcept = default;
};


#endif //PROJECT4_DIVIDEBYZERO_H
