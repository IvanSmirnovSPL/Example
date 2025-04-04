#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

using namespace std::chrono_literals;

// 1. передача методов класса

class MyClass
{
public:
    double someWork(int a, double b)
    {
        std::cout << "Начало работы, id: " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(3s);
        double res = a + b;
        std::cout << "a + b = " << res << std::endl;
        std::this_thread::sleep_for(3s);
        std::cout << "Конец работы, id: " << std::this_thread::get_id() << std::endl;
        return res;
    }

    void bar() {}
};

int main()
{
    setlocale(LC_ALL, "ru");

    double c = 0;
    std::cout << "C: " << c << std::endl;


    MyClass tmp;
    std::thread th([&c, &tmp]() { c = tmp.someWork(2, 5); });

    //auto f = std::bind(&MyClass::someWork, &tmp, std::placeholders::_1, std::placeholders::_2);
    //std::thread th(
    //    [&c, &tmp](std::function<double(int, double)> ff, int a, double b) { c = ff(a, b); },
    //    f, 2, 5
    //);


    for (int i = 0; i < 10; ++i)
    {
        std::this_thread::sleep_for(300ms);
        std::cout << "Номер потока main: "
            << std::this_thread::get_id() << ", итерация: " << i << std::endl;
    }

    th.join();
    std::cout << "C: " << c << std::endl;
    
}
