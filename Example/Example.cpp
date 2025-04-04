#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

// 1. передача параметров

void someWork(int a, double b)
{
    std::cout << "Начало работы, id: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << "a + b = " << a + b << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << "Конец работы, id: " << std::this_thread::get_id() << std::endl;
}

int main()
{
    setlocale(LC_ALL, "ru");

    //someWork(1, 2);
    std::thread th(someWork, 1, 2);

    for (int i = 0; i < 10; ++i)
    {
        std::this_thread::sleep_for(300ms);
        std::cout << "Номер потока main: "
            << std::this_thread::get_id() << ", итерация: " << i << std::endl;
    }

    th.join();
    
}
