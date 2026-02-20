#include <iostream>
#include "address.h"

int main() {
    Address a;
    a.init("123 W Main St", "Muncie", "IN", "47303");
    a.printAddress();
    return 0;
}