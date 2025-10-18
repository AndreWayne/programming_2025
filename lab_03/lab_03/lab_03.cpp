#include <iostream>
#include <cmath>

int main()
{
    int n;
    int sum=0;
    int max=0;
    int i_max=0;
    std::cin >> n;
    for (int i = 1;i <= n;++i) {
        int a;
        std::cin >> a;
        if (a % 2 == 0) {
            sum += a;
            if (a > max) {
                max = a;
                i_max = i;
            }

        }

       
    }
    if (sum == 0) {
        std::cout << "error" << std::endl;
    }
    else {
        std::cout << "sum=" << sum << std::endl;
        std::cout << "max=" << max << std::endl;
        std::cout << "i_max=" << i_max << std::endl;
    }











    int x;
    int min_digit = 9;
    std::cin >> x;
    x = std::abs(x);
    while (x > 0) {
        int digit = x % 10;
        if (digit < min_digit && digit != 7 && digit != 0) {
            min_digit = digit;
        }
        x = x / 10;
    }
    std::cout << "min_digit=" << min_digit << std::endl;

    
}

