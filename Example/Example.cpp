// Example.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <barrier>
#include <latch>
#include <functional>
#include <chrono>

using namespace std::chrono_literals;

// 1. mutex
// 2. lock_guard
// 3. dead_lock
// 4. recursive_lock, unick_lock
// 5. barrier std::barrier my_barrier{ 3 }; my_barrier.arrive_and_wait(); latch 

std::latch bar{2};

void doWork1()
{
    std::this_thread::sleep_for(1s);
    std::cout << "Sleep is finished: " << std::this_thread::get_id() << std::endl;
    bar.arrive_and_wait();
    std::this_thread::sleep_for(1s);
    std::cout << "Sleep is finished: " << std::this_thread::get_id() << std::endl;
    std::cout << "The end: " << std::this_thread::get_id() << std::endl;
}

void doWork2()
{
    std::this_thread::sleep_for(2s);
    std::cout << "Sleep is finished: " << std::this_thread::get_id() << std::endl;
    bar.arrive_and_wait();
    std::this_thread::sleep_for(2s);
    std::cout << "Sleep is finished: " << std::this_thread::get_id() << std::endl;
    std::cout << "The end: " << std::this_thread::get_id() << std::endl;
}

int main()
{
    std::thread th1(doWork1);
    std::thread th2(doWork2);
    
    th1.join();
    th2.join();
}
