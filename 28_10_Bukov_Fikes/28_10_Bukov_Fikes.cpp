#include <iostream>
#include <fstream>
#include <string>

class FileHandler
{
public:
    // Виртуальная функция для отображения содержимого файла
    virtual void Display(const char* path)
    {
        // открытие файла для чтения
        std::ifstream file(path);

        // проверка успешного открытия
        if (file.is_open()) 
        {
            std::string line;

            std::cout << "Вывод содержимого файла в обычном режиме: " << path << std::endl;
            // чтение файла построчно и вывод в консоль
            while (getline(file, line)) 
            {
                std::cout << line << std::endl;
            }
            file.close();
        }
        else 
        {
            std::cerr << "Не удается открыть файл: " << path << std::endl;
        }
    }
};

// Класс для обработки файлов в виде ASCII-кодов символов
class AsciiFileHandler : public FileHandler
{
public:
    // Переопределенная функция для отображения в виде ASCII-кодов
    void Display(const char* path) override
    {
        // открытие файла для чтения
        std::ifstream file(path);

        // проверка успешного открытия
        if (file.is_open())
        {
            int ch;

            std::cout << "\nВывод содержимого файла в виде ASCII-кодов: " <<std::endl;
            // чтение файла посимвольно и выводим ASCII-коды в консоль
            while ((ch = file.get()) != EOF) 
            {
                std::cout << ch << " ";
            }
            std::cout << std::endl;
            file.close();
        }
        else 
        {
            std::cerr << "Не удается открыть файл: " << path << std::endl;
        }
    }
};

// Класс для обработки файлов в двоичном виде
class BinaryFileHandler : public FileHandler
{
public:
    // Переопределенная функция для отображения в двоичном виде
    void Display(const char* path) override
    {
        std::ifstream file(path, std::ios::binary);

        // проверка успешного открытия
        if (file.is_open())
        {
            char byte;

            std::cout << "\nВывод содержимого файла в виде двоичных значений байтов" << std::endl;
            // чтение файла по байтам и вывод в консоль шестнадцатеричных значений байтов
            while (file.read(&byte, sizeof(byte))) 
            {
                std::cout << std::hex << static_cast<int>(byte) << " ";
            }
            std::cout << std::endl;
            file.close();
        }
        else
        {
            std::cerr << "Не удается открыть файл: " << path << std::endl;
        }
    }
};

int main() 
{
    setlocale(LC_ALL, "rus");
    const char* filePath = "test.txt"; // нужно создать файл test.txt, либо он будет лежать на гитхабе

    FileHandler baseHandler;
    baseHandler.Display(filePath);

    AsciiFileHandler asciiHandler;
    asciiHandler.Display(filePath);

    BinaryFileHandler binaryHandler;
    binaryHandler.Display(filePath);

    return 0;
}
