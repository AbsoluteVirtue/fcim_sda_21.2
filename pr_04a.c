#ifdef FUNCTIONS
// see: https://www.eecg.utoronto.ca/~amza/www.mindsec.com/files/x86regs.html
// see: https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf

// void f(void) { return; }
f:
        push    rbp      ; создание области на стеке (base pointer)
        mov     rbp, rsp ; копирование (stack pointer) в новую область
                         ; тело функции
        pop     rbp      ; освобождение области - удаление со стека
        ret              ; возврат управления программой в место вызова функции
// вызов функции: f();
        call    f

// int g(void) { return 0; }
g:
        push    rbp
        mov     rbp, rsp
        mov     eax, 0   ; копирование 0 в специальный регистр (accumulator), откуда вызывающая сторона сможет прочитать возвращенное значение функции
        pop     rbp
        ret

// int h(char c, int i) { return i + (int)c; }
h:
        push    rbp
        mov     rbp, rsp
        mov     eax, edi               ; подготовка вызова функции - копирование данных из (destination index) в (accumulator)
        mov     DWORD PTR [rbp-8], esi ; копирование второго аргумента на стек из (source index)
        mov     BYTE PTR [rbp-4], al   ; копирование первого аргумента на стек из первых 8 байтов (accumulator low)
        movsx   edx, BYTE PTR [rbp-4]  ; подготовка к операции сложения, копирование второго аргумента в (data)
        mov     eax, DWORD PTR [rbp-8] ; копирование первого аргумента в (accumulator)
        add     eax, edx               ; изменение значения (accumulator) на значение в (data)
        pop     rbp
        ret
// вызов функции: h(1, 2);
        mov     esi, 2 ; копирование аргумента (int)2  в (source index)
        mov     edi, 1 ; копирование аргумента (char)1 в (destination index)
        call    h
// вызов функции с присваиванием возвращаемого значения: int x = h(1, 2);
        mov     esi, 2
        mov     edi, 1
        call    h
        mov     DWORD PTR [rbp-4], eax ; копирование значения функции из регистра (accumulator) на стек (в переменную int x)
#endif

#ifndef FUNCTIONS
// godbolt.org/z/Gd4j6nnv3
// compiles on GCC trunk with -std=c2x

// see: https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3007.htm
// see: https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3037.pdf

// макро для генерации кода структур с двумя полями произвольных типов
// типы полей first и second будут заменены на указанные в коде программы
#define pair(T, U) struct pair_##T##_##U { T first; U second; }

// будет создана структура с именем pair_int_float, т.к. символ T будет заменен на int, а символ U - на float
pair(int, float) do_thing(int a, int b) {
    return (pair(int, float)){a * 2, b ? 1.0f : 2.0f };
}

#include <stdio.h>

int main () {
    auto result = do_thing(50, 0);
    printf("%zu-byte sized struct: { %d, %f }", sizeof(result), result.first, result.second);
//  8-byte sized struct: { 100, 2.000000 }
}
#endif
