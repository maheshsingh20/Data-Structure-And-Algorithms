#include <iostream>
using namespace std;

class Stack {
public:
    int top1;
    int top2;
    int* arr;
    int size;

    // Constructor to initialize stack size and top positions
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Function to push data into the first stack
    void push1(int data) {
        if (top2 - top1 == 1) {
            cout << "Stack 1 Overflow" << endl;
        } else {
            top1++;
            arr[top1] = data;
        }
    }

    // Function to push data into the second stack
    void push2(int data) {
        if (top2 - top1 == 1) {
            cout << "Stack 2 Overflow" << endl;
        } else {
            top2--;
            arr[top2] = data;
        }
    }

    // Function to pop data from the first stack
    void pop1() {
        if (top1 == -1) {
            cout << "Stack 1 Underflow" << endl;
        } else {
            arr[top1]=0;
            top1--;
        }
    }

    // Function to pop data from the second stack
    void pop2() {
        if (top2 == size) {
            cout << "Stack 2 Underflow" << endl;
        } else {
            arr[top2]=0;
            top2++;
        }
    }

    // Function to print stack contents
    void print() {
        cout << endl;
        cout << "Top1: " << top1 << endl;
        cout << "Top2: " << top2 << endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s(9);

    // Testing push operations
    s.push1(10);
    s.print();
    s.push1(20);
    s.print();
    s.push1(30);
    s.print();
    s.push1(40);
    s.print();
    s.push1(50);
    s.print();

    s.push2(100);
    s.print();
    s.push2(90);
    s.print();
    s.push2(80);
    s.print();
    s.push2(70);
    s.print();

    // Testing pop operations
    s.pop2();
    s.print();

    // Testing overflow conditions
    s.push1(60);  // Should be successful
    s.print();
    s.push2(60);  // Should cause overflow
    s.print();

    // Testing underflow conditions
    for (int i = 0; i < 6; i++) {
        s.pop1();  // Pop all elements from Stack 1
    }
    s.print();

    s.pop1();  // Should cause underflow
    s.print();

    return 0;
}
