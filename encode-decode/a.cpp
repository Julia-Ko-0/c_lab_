
// #include <iostream>
// #include <string>
// // #include <windows.h>
// // #include <cstring>
// // using namespace std;

// // Функция для шифрования текста шифром Цезаря на англ языке
// std::string encryptCaesar(std::string text, int shift) {
//     std::string result = "";
//     for (char c : text) {
//         if (isalpha(c)) {
//             char base = isupper(c) ? 'A' : 'a';
//             result += (c - base + shift) % 26 + base;
//         } else {
//             result += c;
//         }
//     }
//     return result;
// }
// // Функция для дешифрования текста шифром Цезаря на англ языке
// std::string decryptCaesar(std::string text, int shift) {
//     return encryptCaesar(text, 26 - shift);
// }

// // Функция для шифрования текста шифром Цезаря на русском языке
// std::string encryptCaesarRu(std::string text, int shift) {
//     //  
//     // char8_t slova[2] ={'a','b'};
//      int slova[32] ={'а','б','в','г','д','е','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я'};
//     std::string result = "";
//     for (char c : text) {
//         std::string result = "";
//     for (int i = 0; i< (sizeof(slova)/sizeof(*slova));i++) {
//          std::cout << static_cast<char>(slova[i])<<"  ";
//             //  std::cout <<"////////////"<< slova[i]<<"  ";
//        if(slova[i] == c){
       
//              if (isalpha(c)) {
//             char base = isupper(c) ? 'А' : 'а';
//             result += (c - base + shift) % 32 + base;
//         } else {
//             result += c;
//         }
//        }
       
//     }
//     }
//     return result;
// }
// // Функция для дешифрования текста шифром Цезаря на англ языке
// std::string decryptCaesarRu(std::string text, int shift) {
//     return encryptCaesarRu(text, 32 - shift);
// }
// int main() {
// //      SetConsoleCP(1251);
// //     SetConsoleOutputCP(1251);
// //    setlocale(LC_ALL, "ru_RU");
//     std::string text;
//     int shift;
//     char choice;
//     char lang;
//      std::cout << "Enter text to encrypt/decrypt: ";
//         std::getline(std::cin, text);
//     std::cout<<"Какой язык r или a";
//     std::cin>>lang;
//     if(lang =='a'){
           
//         std::cout << "Enter shift value: ";
//         std::cin >> shift;
//         std::cout << "Encrypt (e) or decrypt (d) text? ";
//         std::cin >> choice;
//         if (choice == 'e') {
//             std::cout << "Encrypted text: " << encryptCaesar(text, shift) << std::endl;
//         } else if (choice == 'd') {
//             std::cout << "Decrypted text: " << decryptCaesar(text, shift) << std::endl;
//         } else {
//             std::cout << "Invalid choice" << std::endl;
//         }
//         return 0;
//     }
//     else if (lang == 'r')
//     {
   
//         std::cout << "Enter shift value: ";
//         std::cin >> shift;
//         std::cout << "Encrypt (e) or decrypt (d) text? ";
//         std::cin >> choice;
//         if (choice == 'e') {
//             std::cout << "Encrypted text: " << encryptCaesarRu(text, shift) << std::endl;
//         } else if (choice == 'd') {
//             std::cout << "Decrypted text: " << decryptCaesarRu(text, shift) << std::endl;
//         } else {
//             std::cout << "Invalid choice" << std::endl;
//         }
//         return 0;
//     }
    
   
// }






#include <iostream>
#include <string>
#include <windows.h>
#include <cstring>
using namespace std;

// Функция для шифрования текста шифром Цезаря на англ языке
std::string encryptCaesar(std::string text, int shift) {
    std::string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += (c - base + shift) % 26 + base;
        } else {
            result += c;
        }
    }
    return result;
}
// Функция для дешифрования текста шифром Цезаря на англ языке
std::string decryptCaesar(std::string text, int shift) {
    return encryptCaesar(text, 26 - shift);
}


int main() {
//      SetConsoleCP(1251);
//     SetConsoleOutputCP(1251);
//    setlocale(LC_ALL, "ru_RU");
    std::string text;
    int shift;
    char choice;
    char lang;
     std::cout << "Введите текст для шифрации/дешифрации(на англискомы): ";
        std::getline(std::cin, text);

           
        std::cout << "введите значение ключа: ";
        std::cin >> shift;
        std::cout << "Зашифровать (e) или расшифровать(d) текст? ";
        std::cin >> choice;
        if (choice == 'e') {
            std::cout << "Зашифрованный текст: " << encryptCaesar(text, shift) << std::endl;
        } else if (choice == 'd') {
            std::cout << "Расшифрованный текст: " << decryptCaesar(text, shift) << std::endl;
        } else {
            std::cout << "Неверное значение" << std::endl;
        }
        
        return 0;
    
    
    
   
}










