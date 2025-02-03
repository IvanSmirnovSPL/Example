// Example.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

void compute()
{
    std::unique_ptr<int[]> data = std::make_unique<int[]>(1024);
    //std::unique_ptr<int[]> ptr_copy = data; // ОШИБКА! Копирование запрещено
} // `data` выходит из области действия здесь: она автоматически уничтожается

void compute2()
{
    std::shared_ptr<int> ptr = std::make_shared<int>(100);
    std::cout << ptr.use_count() << std::endl;
    std::shared_ptr<int> ptr_copy = ptr;   // Сделать копию: с shared_ptr возможно!
    std::cout << ptr.use_count() << std::endl;
    // ptr_copy.use_count() == 2, в конце концов, это одни и те же базовые данные.
} // Здесь `ptr` и `ptr_copy` выходят из области действия. Больше никаких ссылок  
  // исходные данные (т.е. use_count() == 0), поэтому они автоматически убираются.

struct Player
{
    std::shared_ptr<Player> companion;
    ~Player() { std::cout << "~Player\n"; }
};

struct Player2
{
    std::weak_ptr<Player2> companion;
    ~Player2() { std::cout << "~Player2\n"; }
};

int main()
{
    // unique
    std::unique_ptr<int[]>  pU1(new int[50]);
    std::unique_ptr<int[]>  pU2 = std::make_unique<int[]>(50);
    std::unique_ptr<int[]>  pU3 = std::move(pU2);

    //shared
    std::shared_ptr<int[]> pS1(new int[50]);
    std::shared_ptr<int>   pS2 = std::make_shared<int>(50);

    std::shared_ptr<Player> jasmine = std::make_shared<Player>();
    std::shared_ptr<Player> albert = std::make_shared<Player>();
    jasmine->companion = albert; // (1)
    albert->companion = jasmine; // (2)

    // weak только из shared или другого weak
    std::shared_ptr<int> p_shared = std::make_shared<int>(100);
    std::weak_ptr<int>   p_weak1(p_shared);
    std::weak_ptr<int>   p_weak2(p_weak1);

    // можно работать только после преобразование
    if (p_weak1.expired())
        std::cout << "Object was deleted" << std::endl;
    std::shared_ptr<int> p_shared_orig = p_weak1.lock();

    std::shared_ptr<Player2> jasmine2 = std::make_shared<Player2>();
    std::shared_ptr<Player2> albert2 = std::make_shared<Player2>();
    jasmine2->companion = albert2; // (1)
    albert2->companion = jasmine2; // (2)
}
