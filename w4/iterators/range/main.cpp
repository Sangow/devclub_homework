#include "Range.h"

int main() {
    // Range range(-10, 10, 3);

    // for ( ; range < range.end(); range++ ) {
    //     std::cout << *range << std::endl;
    // }
    // std::cout << *range << std::endl;

    Range<int> ari(-10, -3, 2);

    for ( ; !ari.over(); ari++ ) {
        std::cout << *ari << std::endl;
    }

    return 0;
}