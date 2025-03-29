// Example.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <filesystem>

int main()
{
    setlocale(LC_ALL, "ru_RU");

    std::string someString{ R"(C:\Workspace\с++ practice\Example\Example)" };
    std::filesystem::path somePath(someString);
    std::cout << "somePath: " << somePath.string() << std::endl;

    std::filesystem::path curPath = std::filesystem::current_path();
    std::cout << "curPath: " << curPath.string() << std::endl;

    auto parent = curPath.parent_path();
    std::cout << "Parent: " << parent.string() << std::endl;

    auto myDir = parent / "myDir";
    std::cout << "MyDir: " << myDir.string() << std::endl;

    std::cout << std::endl;
    for (auto& line : std::filesystem::directory_iterator(myDir))
    {
        std::cout << "Path: " << line.path().string() << ", filename: "
            << line.path().filename().string() << std::endl;
    }
    std::cout << std::endl;

    auto fooPath = myDir / "foo.txt";
    if (std::filesystem::exists(fooPath))
    {
        std::filesystem::remove(fooPath);
    }
    std::filesystem::copy(myDir / "tmp.txt", myDir / "foo.txt");

    auto barPath = myDir / "bar.txt";
    if (std::filesystem::exists(barPath))
    {
        std::filesystem::remove(barPath);
    }
    std::filesystem::rename(fooPath, barPath);
}
