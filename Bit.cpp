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


bool ithbitissetornot(int num1, int num2) {
    return (num1 & (1 << num2)) != 0;
}

int settheIthbit(int num1, int num2){
    num2=(1<<num2);
    return num1|num2;
}

int cleartheithbit(int num1, int num2){
    return num1^(1<<num2);
}

int clearfirstset(int num){
    int num2=num-1;
    return num & num2;
}




int main() {
    /*
    int a = 5;
    int b = 3;
    cout << "And: " << (a & b) << endl;
    cout << "Or: " << (a | b) << endl;
    cout << "Xor: " << (6^ 5) << endl;
    cout << "Left shift: << " << (a << 1) << endl;   // x << k = x * 2^k
    cout << "a: " << a << endl;
    cout << "Right shift: >> " << (a >> 1) << endl;  // x >> k = x / 2^k
    cout << "NOT: " << (~(-5)) << endl;
    //for not of a positive number=> Step: 1 first flip if you get -ve sign get 2's complement and it return that number with that negative sign mean's the number what we get afer 
    // 2's complement is the answer of not of that number with negative sign.
    // for not of a negative number=> Step 1: get 1's of it's positive number then 2's
    //Step: 2 now flip if you get -ve sign get 2's complement and it return that number with that positive sign mean's the number what we get afer
    cout << "Binary to Decimal of \"110\": " << bintodecimal("110") << endl;
    cout << "Decimal to Binary of 6: " << decitobin(6) << endl;

    cout<<"a before swap: "<<a<<endl;
    cout<<"b before swap: "<<b<<endl;
    cout<<"a after swap: "<<((a^b)^a)<<endl;   
    cout<<"b after swap: "<<((a^b)^b)<<endl;

    if(ithbitissetornot(5,1)){
        cout<<"set"<<endl;
    }else{
        cout<<"Not a set"<<endl;
    }

    */
//    int a=7;
//    cout<<(a>>3);


    //cout<<settheIthbit(9,2);
   // cout<<cleartheithbit(7,1);
   cout<<clearfirstset(1000)<<endl;
   return 0;
 }
