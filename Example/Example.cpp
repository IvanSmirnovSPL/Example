#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

// 1. процесс и поток
// 2. когда это нужно, минусы и плюсы
// 3. методы засыпания
// 4. someWork

void someWork()
{
    for (int i = 0; i < 5; ++i)
    {
        std::this_thread::sleep_for(1s);
        std::cout << "Номер потока someWork: "
            << std::this_thread::get_id() << ", итерация: " << i << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    //someWork();
    //std::thread th(someWork);
    //th.detach();
    //th.join();

    for (int i = 0; i < 10; ++i)
    {
        std::this_thread::sleep_for(100ms);
        std::cout << "Номер потока main: "
            << std::this_thread::get_id() << ", итерация: " << i << std::endl;
    }
    std::cout << "Цикл закончился" << std::endl;
    auto timePoint = std::chrono::system_clock::now() + 1s;
    std::this_thread::sleep_until(timePoint);
    std::cout << "Второй sleep закончился" << std::endl;
    std::cout << "Конец программы" << std::endl;
}
