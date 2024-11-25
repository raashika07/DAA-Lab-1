#include <stdio.h>
#include <stdlib.h>
double divide(int dividend, int divisor, int precision) {
    if (divisor == 0) {
        printf("Error: Division by zero\n");
        exit(1);
    }
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    dividend = abs(dividend);
    divisor = abs(divisor);
    int quotient = 0;
    int low = 0;
    int high = dividend;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid * divisor == dividend) {
            quotient = mid;
            break;
        }
        else if (mid * divisor < dividend) {
            quotient = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    double result = quotient;
    double factor = 0.1;
    for (int i = 0; i < precision && dividend != quotient * divisor; i++) {
        while (result * divisor <= dividend) {
            result += factor;
        }
        result -= factor;
        factor /= 10;
    }   
    return sign * result;
}
int main() {
    int dividend, divisor, precision;
    printf("Enter dividend: ");
    scanf("%d", &dividend);
    printf("Enter divisor: ");
    scanf("%d", &divisor);
    printf("Enter precision (decimal places): ");
    scanf("%d", &precision);
    double result = divide(dividend, divisor, precision);
    printf("%d / %d = %.10f\n", dividend, divisor, result);
    return 0;
}