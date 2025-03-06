#include <iostream>

int main() {
    int a = 5;  // Binary: 0101
    int b = 9;  // Binary: 1001

    // Bitwise AND
    int and_result = a & b; // Binary: 0001 (Decimal: 1)
    std::cout << "a & b = " << and_result << std::endl;

    // Bitwise OR
    int or_result = a | b; // Binary: 1101 (Decimal: 13)
    std::cout << "a | b = " << or_result << std::endl;

    // Bitwise XOR
    int xor_result = a ^ b; // Binary: 1100 (Decimal: 12)
    std::cout << "a ^ b = " << xor_result << std::endl;

    // Bitwise NOT
    int not_result = ~a; // Binary: 1010 (Decimal: -6)
    std::cout << "~a = " << not_result << std::endl;

    // Left Shift
    int left_shift_result = a << 1; // Binary: 1010 (Decimal: 10)
    std::cout << "a << 1 = " << left_shift_result << std::endl;

    // Right Shift
    int right_shift_result = b >> 1; // Binary: 0100 (Decimal: 4)
    std::cout << "b >> 1 = " << right_shift_result << std::endl;

    return 0;
}
