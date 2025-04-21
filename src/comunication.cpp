#include "comunication.h"

comunication::~comunication()
{
    if (result != nullptr) {
        delete result;
    }
}