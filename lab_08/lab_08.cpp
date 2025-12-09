#include <iostream>
#include <string>
#include <locale.h>




struct Season {
    std::string name;           
    std::string months[3];      
    std::string nextSeason;
    Season* next;
};


void printElement(const Season seasons[]) {
    setlocale(LC_ALL, "Russian");
    int choice;
    std::cout << "Выберите Элемент для просмотра (1-4):"<<std::endl;
    std::cin >> choice;
    
    std::cout << seasons[choice-1].name << "["
    << seasons[choice-1].months[0] << ", "
    << seasons[choice-1].months[1] << ", "
    << seasons[choice-1].months[2] << "] ";
    
    std::cout << std::endl;
}


void printYear(const Season seasons[], int size) {
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i < size; i++) {
        std::cout << seasons[i].name << "["
            << seasons[i].months[0] << ", "
            << seasons[i].months[1] << ", "
            << seasons[i].months[2] << "] ";
    }
    std::cout << std::endl;
}




void swapMonths(Season& seasonA, int monthIndexA, Season& seasonB, int monthIndexB) {
    setlocale(LC_ALL, "Russian");
    std::string temp = seasonA.months[monthIndexA];
    seasonA.months[monthIndexA] = seasonB.months[monthIndexB];
    seasonB.months[monthIndexB] = temp;
}


void showMenu() {
    setlocale(LC_ALL, "Russian");
    std::cout << "1. Поменять местами два месяца" << std::endl;
    std::cout << "2. Показать весь год" << std::endl;
    std::cout << "3. Выйти из программы" << std::endl;
    std::cout << "4. Просмотр Элемента" << std::endl;
    std::cout << "5. Просмотр цикла от сезона" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Выберите действие (1-5): ";
}


void setCalendar(Season seasons[]) {
    setlocale(LC_ALL, "Russian");
    
    seasons[0].name = "Зима";
    seasons[0].months[0] = "дек.";
    seasons[0].months[1] = "янв.";
    seasons[0].months[2] = "февр.";
    seasons[0].nextSeason = "Весна";

    
    seasons[1].name = "Весна";
    seasons[1].months[0] = "март";
    seasons[1].months[1] = "апр.";
    seasons[1].months[2] = "май";
    seasons[1].nextSeason = "Лето";

    
    seasons[2].name = "Лето";
    seasons[2].months[0] = "июнь";
    seasons[2].months[1] = "июль";
    seasons[2].months[2] = "авг.";
    seasons[2].nextSeason = "Осень";

    
    seasons[3].name = "Осень";
    seasons[3].months[0] = "сент.";
    seasons[3].months[1] = "окт.";
    seasons[3].months[2] = "нояб.";
    seasons[3].nextSeason = "Зима";

    
}


int chooseSeason() {
    setlocale(LC_ALL, "Russian");
    int choice;
    std::cout << "\nВыберите сезон:" << std::endl;
    std::cout << "1. Зима" << std::endl;
    std::cout << "2. Весна" << std::endl;
    std::cout << "3. Лето" << std::endl;
    std::cout << "4. Осень" << std::endl;
    std::cout << "Ваш выбор (1-4): ";
    std::cin >> choice;

    while (choice < 1 || choice > 4) {
        std::cout << "Неверный выбор! Пожалуйста, выберите от 1 до 4: ";
        std::cin >> choice;
    }

    return choice - 1; 
}


int chooseMonth(const Season& season) {
    setlocale(LC_ALL, "Russian");
    int choice;
    std::cout << "\nВыберите месяц в сезоне " << season.name << ":" << std::endl;
    std::cout << "1. " << season.months[0] << std::endl;
    std::cout << "2. " << season.months[1] << std::endl;
    std::cout << "3. " << season.months[2] << std::endl;
    std::cout << "Ваш выбор (1-3): ";
    std::cin >> choice;

    while (choice < 1 || choice > 3) {
        std::cout << "Неверный выбор! Пожалуйста, выберите от 1 до 3: ";
        std::cin >> choice;
    }

    return choice - 1; 
}

void CicleYear(Season* A) {
    Season* current = A;
    int count = 0;

    
    do {
        std::cout << A->name << "["
            << A->months[0] << ", "
            << A->months[1] << ", "
            << A->months[2] << "] ";

        A = A->next; 
        count++;

        
        if (count < 4) {
            std::cout << "-> ";
        }

    } while (current != A && count < 4);

    std::cout << "..." << std::endl;
    
}

int main() {
    setlocale(LC_ALL, "Russian");

    
    
    Season seasons[4];
    seasons[0].next = &seasons[1];
    seasons[1].next = &seasons[2];
    seasons[2].next = &seasons[3];
    seasons[3].next = &seasons[0];

    
    setCalendar(seasons);

    int choice;
    bool running = true;

    

    while (running) {
        showMenu();
        std::cin >> choice;

        

        switch (choice) {
        case 1: 
        {
            std::cout << "\n=== ОБМЕН МЕСЯЦАМИ ===" << std::endl;

            std::cout << "Первый месяц для обмена:" << std::endl;
            int season1 = chooseSeason();
            int month1 = chooseMonth(seasons[season1]);

            std::cout << "\nВторой месяц для обмена:" << std::endl;
            int season2 = chooseSeason();
            int month2 = chooseMonth(seasons[season2]);

            
            if (season1 == season2 && month1 == month2) {
                std::cout << "Вы выбрали один и тот же месяц! Обмен не выполнен." << std::endl;
            }
            else {
                swapMonths(seasons[season1], month1, seasons[season2], month2);

                std::cout << "\nОбмен выполнен успешно!" << std::endl;
                std::cout << "Поменялись местами: "
                    << seasons[season1].months[month1]
                    << " (" << seasons[season1].name << ") и "
                    << seasons[season2].months[month2]
                    << " (" << seasons[season2].name << ")" << std::endl;
            }
        }
            break;

        case 2: 
            printYear(seasons, 4);
            break;

        case 3: 
            running = false;
            break;
        case 4:
            printElement(seasons);
            break;
        case 5: {
            int choice = chooseSeason();
            Season* A = &seasons[choice];
            CicleYear(A);
            break;

        }
            



        default:
            std::cout << "Неверный выбор! Пожалуйста, выберите действие от 1 до 4." << std::endl;
        }
    }


   

    return 0;

}


