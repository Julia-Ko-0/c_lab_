#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>
#include <ctime>
#include <sstream>
#include <iomanip>

struct book
{
   int num;
   std::string aftor;
   std::string name;
   int year;
   std::string izd;
   int count_str;

};

void createNewFile() {
    std::ofstream file("book.txt");
    file.close();
    std::cout << "Файл успешно создан." << std::endl;
}
void readFile() {
    std::ifstream file("book.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else {
        std::cout << "Файл не найден." << std::endl;
    }
}

void correctFile() {
    std::ofstream file("book.txt", std::ios::app);
    if (file.is_open()) {
        book newBook;
        std::cout << "Введите регистрац. номер книги: ";
        std::cin >> newBook.num;
        std::cout << "Введите автораа: ";
        std::cin >> newBook.aftor;
        std::cout << "Введите название: ";
        std::cin >> newBook.name;
        std::cout << "Введите дату издания: ";
        std::cin >> newBook.year;
         std::cout << "Введите издательство: ";
         std::cin >> newBook.izd;
         std::cout << "Введите колво страниц: ";
         std::cin >> newBook.count_str;

        file << newBook.num << " " << newBook.aftor << " " << newBook.name << " " << 
        newBook.year << " "<< newBook.izd<<" " << newBook.count_str << std::endl;
        file.close();
    }
    else {
        std::cout << "Файл не найден." << std::endl;
    }
}

bool corBook(const book& item1, const book& item2) {
    return item1.aftor < item2.aftor;
}
void readCorectFile(){
      std::vector<book> New_Book;
    int Year_N;
    std::cout << "Введите год" << std::endl;
    std::cin >> Year_N;
     std::ifstream file("book.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
              std::istringstream iss(line);
              book newBook;
              iss>>
              newBook.num>>newBook.aftor >> newBook.name>> newBook.year
              >> newBook.izd >> newBook.count_str;
              New_Book.push_back(newBook);
        }
        file.close();
           std::vector<book> correctBook;
             for (const auto & newBook : New_Book){
                //Получаем инф (читает тексты)
                //  std::istringstream ss(newBook.year);
           if(newBook.year>Year_N){
                correctBook.push_back(newBook);
           }
             }
          std::sort(begin(correctBook), end(correctBook),corBook);
          for(const auto & newBook:correctBook){
            std::cout << "Автор: " << newBook.aftor <<
             ", Название книги: " << newBook.name << std::endl;
        }
    }
   
    else {
        std::cout << "Файл не найден." << std::endl;
    }


}
int main() {
    setlocale(LC_CTYPE, "ru_RU");
    int choice;
    do {
        std::cout << "Меню,нажмите цифру чтобы" << std::endl;
        std::cout << "1 - Создание нового файла" << std::endl;
        std::cout << "2 -  Просмотр созданного файла" << std::endl;
        std::cout << "3- Изменение файла" << std::endl;
        std::cout << "4 - Вывести авторов в алф порядке, после заданного года" << std::endl;
        std::cout << "5 - Выход" << std::endl;
        std::cin >> choice;
        switch (choice) {
        case 1:
            createNewFile();
            break;
        case 2:
            readFile();
            break;
        case 3:
            correctFile();
            break;
        case 4:
            readCorectFile();
            break;
        case 5:
            std::cout << "Выход" << std::endl;
            break;
        default:
            std::cout << "Вводите корректно" << std::endl;
            break;
        }
    } while (choice != 5);

    return 0;
}