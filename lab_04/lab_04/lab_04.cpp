

#include <iostream>
#include <cmath>
#include <climits>
int main()
{
    const int NMax = 4;
    int A[NMax];
    for (int i = 0; i < NMax; ++i) {
        std::cin >> A[i];
    }
    int min_digit_A0 = 9;
    int min_digit_A3 = 9;
    int tmp1 = std::abs(A[0]);
    int tmp2 = std::abs(A[3]);

    while (tmp1 > 0) {
        int digit = tmp1 % 10;
        if (digit < min_digit_A0) {
            min_digit_A0 = digit;
        }
        tmp1 = tmp1 / 10;
    }

    while (tmp2 > 0) {
        int digit = tmp2 % 10;
        if (digit < min_digit_A3) {
            min_digit_A3 = digit;
        }
        tmp2 = tmp2 / 10;
    }

    if (min_digit_A0 == min_digit_A3) {
        for (int i = 0; i < NMax - 1; ++i) {
            for (int j = i + 1; j < NMax; ++j) {
                if (A[i] > A[j]) {
                    std::swap(A[i], A[j]);
                }
            }
        }
    }

    

    for (int i = 0; i < NMax; ++i) {
        std::cout << A[i] << std::endl;
    }

















    const int MMax = 3;
    int index = 0;
    int min_abs_sum = INT_MAX;
    int matrix[MMax][NMax];
    for (int i = 0; i < MMax; ++i) {
        for (int j = 0; j < NMax; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < MMax; ++i) {
        int s = 0;
        for (int j = 0; j < NMax; ++j) {
            s = s + matrix[i][j];
        }
        
        if (std::abs(s) < min_abs_sum) {
            min_abs_sum = std::abs(s);
            index = i;

        }
        
    }
    for (int i = 0; i < MMax; ++i) {
        for (int j = 0; j < NMax; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << index << std::endl;

    for (int j = 0; j < NMax; ++j) {
        matrix[index][j] = 0;
    }

    for (int i = 0; i < MMax; ++i) {
        for (int j = 0; j < NMax; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    
}


