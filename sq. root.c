#include <stdio.h>
double findSquareRoot(int x, int precision) {
    if (x == 0 || x == 1)
        return x;
    double low = 1;
    double high = x;
    double epsilon = 1.0;
    for(int i = 0; i < precision; i++) {
        epsilon /= 10;
    }
    double result = 0;
    while (high - low > epsilon) {
        double mid = (low + high) / 2;
        double sqr = mid * mid;
        if (sqr == x) {
            return mid;
        }
        else if (sqr < x) {
            low = mid;
            result = mid;
        }
        else {
            high = mid;
        }
    }
    
    return result;
}

int main() {
    int num, precision;
    printf("Enter number to find square root: ");
    scanf("%d", &num);
    printf("Enter precision (number of decimal places): ");
    scanf("%d", &precision);
    if (num < 0) {
        printf("Square root of negative number is not real\n");
        return 1;
    }
    double sqrt = findSquareRoot(num, precision);
    printf("Square root of %d is approximately %.10f\n", num, sqrt);
    return 0;
}