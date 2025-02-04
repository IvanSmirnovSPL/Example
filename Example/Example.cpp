// Example.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template<typename T, int Size>
struct Array {
    T& operator [] (int idx) { return _arr[idx]; }
    T _arr[Size];
};

template<typename T>
class Vector {
public:
    Vector() {}
    Vector(int size) : _size(size), _capacity(size) { _arr = new T[_size]; }
    ~Vector() { delete[] _arr; }
    T& operator [] (int idx) { return _arr[idx]; }
    void push_back(const T& elem)
    {
        if (_size == _capacity)
        {
            T* tmp = new T[_size];
            for (int idx = 0; idx < _size; ++idx) { tmp[idx] = _arr[idx]; }
            delete[] _arr;
            _capacity = _capacity * 2;
            _arr = new T[_capacity];
            for (int idx = 0; idx < _size; ++idx) { _arr[idx] = tmp[idx]; }
            delete[] tmp;
            _arr[_size] = elem;
            ++_size;
        }
        else
        {
            _arr[_size] = elem;
            ++_size;
        }
            
    }

    int size() const { return _size; }
    int capacity() const { return _capacity; }
private:
    int _size = 1;
    int _capacity = 1;
    T* _arr;
};

// MyArray deduction guides:
// similar code was added to std::array in C++17 to allow the
// creation of a2 below, without providing template arguments
//template <class _First, class... _Rest>
//MyArray(_First, _Rest...) -> MyArray<_First, 1 + sizeof...(_Rest)>;

int main()
{
    Array<int, 5> myArr = {1, 2, 3, 4, 5};
    myArr[2] = 1;
    std::cout << myArr[2] << std::endl;

    Vector<float> v(5);
    std::cout << "Size: " << v.size() << ", capacity: " << v.capacity() << std::endl;
    v.push_back(1);
    std::cout << "Size: " << v.size() << ", capacity: " << v.capacity() << std::endl;
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
