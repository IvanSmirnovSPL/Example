// Example.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "ExampleClass.h"
#include <concepts>

template <typename T>
concept Comparable = requires(T a, T b) { { a >= b } -> std::convertible_to<bool>; };

template<Comparable Kate>
Kate MaxOf(Kate a, Kate b) {
    return a >= b ? a : b;
}


template <typename T>
class Vector3Dim
{
public:
    Vector3Dim() : _x(0.), _y(0.), _z(0.) {}
    Vector3Dim(T x, T y, T z) : _x(x), _y(y), _z(z) {}

    T x() const { return _x; }
    T y() const { return _y; }
    T z() const { return _z; }

    friend std::ostream& operator << (std::ostream& out, const Vector3Dim& v)
    {
        return out << "[" << v.x() << ", " << v.y() << ", " << v.z() << "]";
    }

    Vector3Dim operator + (const Vector3Dim& v) const
    {
        return Vector3Dim{_x + v.x(), _y + v.y(), _z + v.z()};
    }

    Vector3Dim operator - (const Vector3Dim& v) const
    {
        return Vector3Dim{ _x - v.x(), _y - v.y(), _z - v.z() };
    }

    T operator * (const Vector3Dim& v) const
    {
        return _x * v.x() + _y * v.y() + _z * v.z();
    }

private:
    T _x, _y, _z;
};

//std::ostream& operator << (std::ostream& out, const Vector3Dim& v)
//{
//    return out << "[" << v.x() << ", " << v.y() << ", " << v.z() << "]";
//}

int main()
{

    Vector3Dim vec{-5, -4, -3};
    std::cout << vec << std::endl;

    Vector3Dim qeq{1, 2, 3};
    std::cout << qeq << std::endl;

    auto lol = vec + qeq;
    std::cout << lol << std::endl;

    std::cout << vec - qeq << std::endl;
    std::cout << vec * qeq << std::endl;

    //std::cout << "Hello World!\n";
    //auto a = 5;
    //int b;
    //std::cin >> a >> b;
    //std::cout << MaxOf(a, b)<< std::endl;

    //lessonFirst::Human<lessonFirst::Male> man("Apollon", lessonFirst::Male{});

    //std::cout << man.sayInfo() << std::endl;
    //man.spentYear();
    //std::cout << man.sayInfo() << std::endl;
    //// std::cout << man << std::endl; ошибка!

    //using namespace lessonFirst;
    //SmartHuman<Female> woman("Olga", Female{});
    //std::cout << woman << std::endl;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
