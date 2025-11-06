// godbolt.org/z/Gd4j6nnv3
#include <stdbool.h>

// compiles on GCC trunk with -std=c2x

// see: https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3007.htm
// see: https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3037.pdf

#define pair(T, U) struct pair_##T##_##U { T first; U second; }

pair(int, float) do_thing(int a, bool b) {
    return (pair(int, float)){a * 2, b ? 1.0f : 2.0f };
}

#include <stdio.h>

int main () {
    auto result = do_thing(50, false);
    printf("%zu-byte sized struct: { %d, %f }", 
        sizeof(result), 
        result.first, 
        result.second); 
}
