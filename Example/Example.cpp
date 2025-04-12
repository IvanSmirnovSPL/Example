// Example.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <barrier> 
#include <functional>
#include <chrono>

// 1. mutex
// 2. lock_guard
// 3. dead_lock
// 4. recursive_lock, unick_lock
// 5. barrier std::barrier my_barrier{ 3 }; my_barrier.arrive_and_wait(); latch 

double pi = 3.14159265358;

std::mutex mtx1;
std::mutex mtx;

double func(double x)
{
    double y = 5 * x * x * std::cos(x);
    return y;
}

void integrate(
    double a,
    double b,
    std::function<double(double)> f,
    double& res
)
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    int N = 1000000; // кол-во отрезков разбиения
    double step = std::abs(b - a) / N;
    double tmp = 0;
    for (int i = 0; i < N; ++i)
    {
        tmp += step * f(std::min(a, b) + step * i);
    }
    mtx.lock();
    res += tmp;
    mtx.unlock();
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main()
{
    auto t = std::chrono::system_clock::now();
    double res = 0;
    //integrate(- pi, pi, func, std::ref(res));


    //integrate(-pi, 0, func, std::ref(res));
    //integrate(0, pi, func, std::ref(res));

    std::thread th1(integrate, -pi, 0, func, std::ref(res));
    std::thread th2(integrate, 0, pi, func, std::ref(res));
    
    th1.join();
    th2.join();

    std::cout << res << std::endl;

    using dseconds = std::chrono::duration<double, std::chrono::seconds::period>;
    std::cout << dseconds{std::chrono::system_clock::now() - t}.count() << std::endl;
}
