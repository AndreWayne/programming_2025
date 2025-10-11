
#include <iostream>
#include <bitset>

int main()
{
    short A;
    int i;
    std::cin >> A >> i;
    int bit = (A >> i) & 1;
    if (bit == 1) {
        short x;
        short y;
        std::cin >> x >> y;
        short z = (A & ~(1 << i));
        if (x > y) {
            std::cout << x << std::endl;
            std::cout << z << "=" << std::bitset<8>(z)<<std::endl;

        }
        else {
            std::cout << y << std::endl;
            std::cout << z << "=" << std::bitset<8>(z)<<std::endl;
        }
    }
    else {
        std::cout << ~A << "="<< std::bitset<8>(~A)<< std::endl;
    }



    int monthNumber;
    std::cin >> monthNumber;
    switch (monthNumber) {
        case 1: std::cout << "January"; break;
        case 2: std::cout << "February"; break;
        case 3: std::cout << "March"; break;
        case 4: std::cout << "April"; break;
        case 5: std::cout << "May"; break;
        case 6: std::cout << "June"; break;
        case 7: std::cout << "July"; break;
        case 8: std::cout << "August"; break;
        case 9: std::cout << "September"; break;
        case 10: std::cout << "October"; break;
        case 11: std::cout << "November"; break;
        case 12: std::cout << "December"; break;
        default: std::cout << "Unknown month";
    }

}
