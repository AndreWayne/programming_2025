

#include <iostream>
#include <algorithm>
#include <locale.h>



int CalculateExpression(int a, int b){
    setlocale(LC_ALL, "Russian");
    std::cout << "исп. функция вычисления знач.выражения" << std::endl;
    return a + 2 * b + 3;
}


int MaxSum(int c,int d,int e){
    setlocale(LC_ALL, "Russian");
    std::cout << "исп. функция нахождения макс. парной суммы" << std::endl;
    int sum1 = c + d;
    int sum2 = c + e;
    int sum3 = d + e;
    return std::max({ sum1,sum2,sum3 });
}



/*int p1() {
    int x, y, z;
    std::cin >> x >> y >> z;
    int nonZeroCount = (x != 0) + (y != 0) + (z != 0);
    if (nonZeroCount == 2) {
        std::cout << CalculateExpression(x, y) << std::endl;
    
    }
    else if (nonZeroCount == 3) {
        std::cout << MaxSum(x, y, z) << std::endl;
    }
    else {
        std::cout << "Недостаточно чисел для выполнения операций" << std::endl;
    }
    
}*/

int main()
{
    setlocale(LC_ALL, "Russian");
    int x, y, z;
    std::cin >> x >> y >> z;
    int nonZeroCount = (x != 0) + (y != 0) + (z != 0);
    if (nonZeroCount == 2) {
        std::cout << CalculateExpression(x, y) << std::endl;

    }
    else if (nonZeroCount == 3) {
        std::cout << MaxSum(x, y, z) << std::endl;
    }
    else {
        std::cout << "Недостаточно чисел для выполнения операций" << std::endl;
    }
    
}

