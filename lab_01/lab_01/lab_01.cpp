#include <iostream>
#include <cmath>
#include <limits>
#include <locale.h>


int main()
{
    setlocale(LC_ALL, "Russian");
    int x; //Катеты целочисленные
    int y;
    double z; //Гипотенуза может быть нецелым числом
    double p;
    std::cin >> x >> y;
    z = sqrt(x * x + y * y);
    p = x + y + z;
    std::cout << "z=" << z << " " << "double" << " " << "p=" << p << " " << "double" << std::endl;
    std::cout << "int, занимает " << sizeof(int) * 8 << "бит, мин. значение=" << std::numeric_limits<int>::min() << " макс. значение=" << std::numeric_limits<int>::max() << std::endl;
    std::cout << "double, занимает " << sizeof(double) * 8 << "бит, мин. значение=" << std::numeric_limits<double>::min() << " макс. значение=" << std::numeric_limits<double>::max() << std::endl;
}

