// Example.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <filesystem>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "ru_RU");

    std::filesystem::path curPath = std::filesystem::current_path();
    auto parent = curPath.parent_path();
    auto myDir = parent / "myDir";

    std::ofstream fout;
    fout.open(myDir / "tmp.txt");

    fout << "FAKI IS THE CHAMPION" << std::endl;
    fout << "PER ASPERA AD ASTRA" << std::endl;

    fout.close();

    std::filesystem::rename(myDir / "tmp.txt", myDir / "input.data");

    std::ifstream fin(myDir / "input.data");

    std::string someInfo;
    std::getline(fin, someInfo);
    std::cout << someInfo << std::endl;

    char c;
    while (fin.get(c))
    {
        std::cout << c << std::endl;
    }

    fin.close();

    

}
