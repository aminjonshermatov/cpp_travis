#include <iostream>
#include "lib.h"

int main() {
    std::cout << "from lib: " << lib::version() << std::endl;

    return 0;
}
