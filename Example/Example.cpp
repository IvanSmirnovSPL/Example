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

std::mutex mtx1;
std::mutex mtx2;

void doWork1()
{
    mtx1.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mtx2.lock();
    mtx2.unlock();
    mtx1.unlock();
}

void doWork2()
{
    mtx2.lock();
    mtx1.lock();
    mtx1.unlock();
    mtx2.unlock();
}

int main()
{
    std::thread th1(doWork1);
    std::thread th2(doWork2);
    
    th1.join();
    th2.join();
}
