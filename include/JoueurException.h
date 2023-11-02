//
// Created by Fatih BOZLAK on 02/11/2023.
//

#ifndef TP3_JOUEUREXCEPTION_H
#define TP3_JOUEUREXCEPTION_H

#include <iostream>

class JoueurException : public std::exception {
private :
    std::string message;

public:
    JoueurException(std::string message);

    [[nodiscard]] const char *what() const noexcept override;
};

#endif //TP3_JOUEUREXCEPTION_H
