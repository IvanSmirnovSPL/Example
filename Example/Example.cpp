#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

// 1. возврат параметров

void someWork(int a, double b, double &res)
{
    std::cout << "Начало работы, id: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(3s);
    res = a + b;
    std::cout << "a + b = " << res << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << "Конец работы, id: " << std::this_thread::get_id() << std::endl;
}

int main()
{
    setlocale(LC_ALL, "ru");

    double c = 1;
    std::cout << "C: " << c << std::endl;
    std::thread th(someWork, 1, 2, std::ref(c)); // std::cref

    for (int i = 0; i < 10; ++i)
    {
        std::this_thread::sleep_for(300ms);
        std::cout << "Номер потока main: "
            << std::this_thread::get_id() << ", итерация: " << i << std::endl;
    }

    th.join();
    std::cout << "C: " << c << std::endl;
    
}
