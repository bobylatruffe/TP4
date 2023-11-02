//
// Created by Fatih BOZLAK on 02/11/2023.
//

#include "JoueurException.h"

JoueurException::JoueurException(std::string message) : message(message) {}

const char *JoueurException::what() const noexcept {
    return message.c_str();
}