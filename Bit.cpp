#include <iostream>
#include <string>
#include <algorithm>  // for reverse
using namespace std;

int bintodecimal(const string& bin) {
    int dec = 0;
    for (char bit : bin) {
        dec = (dec << 1) | (bit - '0');  // Shift left and add current bit
    }
    return dec;
}

string decitobin(int decimal) {
    if (decimal == 0) return "0";
    
    bool isNegative = decimal < 0;
    if (isNegative) {
        decimal = ~decimal + 1;  // Get two's complement of negative number
    }
    
    string binary;
    while (decimal > 0) {
        binary += (decimal & 1) ? '1' : '0';  // Append the least significant bit
        decimal >>= 1;  // Shift the decimal number to the right
    }
    
    reverse(binary.begin(), binary.end());  // Reverse the string for the correct order

    if (isNegative) {
        binary = "Two's complement: -" + binary;  // Indicate two's complement form
    }

    return binary;
}

int main() {
    int a = 5;
    int b = 3;
    cout << "And: " << (a & b) << endl;
    cout << "Or: " << (a | b) << endl;
    cout << "Xor: " << (a ^ b) << endl;
    cout << "Left shift: << " << (a << 1) << endl;   // x << k = x * 2^k
    cout << "a: " << a << endl;
    cout << "Right shift: >> " << (a >> 1) << endl;  // x >> k = x / 2^k
    cout << "NOT: " << (~a) << endl;
    cout << "Binary to Decimal of \"10\": " << bintodecimal("10") << endl;
    cout << "Decimal to Binary of -6: " << decitobin(-6) << endl;
    
 }
