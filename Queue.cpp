#include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;

    // Input operator from user
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    // Input two numbers from user
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    // Perform the operation based on the operator
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                result = num1 / num2;
            else {
                printf("Error! Division by zero.\n");
                return -1;
            }
            break;
        default:
            printf("Error! Invalid operator.\n");
            return -1;
    }

    // Output the result
    printf("Result: %.2lf\n", result);

    return 0;
}
