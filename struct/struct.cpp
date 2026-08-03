#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

// using namespace std;

// 声明一个结构体类型 Books 
struct Books
{
    char  title[50];
    char  author[50];
    char  subject[100];
    int   book_id;
};

int main( )
{
   Books Book1;        // 定义结构体类型 Books 的变量 Book1
   Books Book2;        // 定义结构体类型 Books 的变量 Book2

   // Book1 详述
    std::strcpy( Book1.title, "C++ Toturial");
    std::strcpy( Book1.author, "Runoob"); 
    std::strcpy( Book1.subject, "Coding Languages");
    Book1.book_id = 12345;

   // Book2 详述
    std::strcpy( Book2.title, "CSS Toturial");
    std::strcpy( Book2.author, "Runoob");
    std::strcpy( Book2.subject, "Frontback Tech");
    Book2.book_id = 12346;

   // 输出 Book1 信息
    std::cout << "The name of the first book : " << Book1.title <<std::endl;
    std::cout << "The author of the first book : " << Book1.author <<std::endl;
    std::cout << "the subject of the first book : " << Book1.subject <<std::endl;
    std::cout << "The ID of the first book : " << Book1.book_id <<std::endl;

    // 输出 Book2 信息
    std::cout << "The name of the second book : " << Book1.title <<std::endl;
    std::cout << "The author of the second book : " << Book1.author <<std::endl;
    std::cout << "the subject of the second book : " << Book1.subject <<std::endl;
    std::cout << "The ID of the second book : " << Book1.book_id <<std::endl;
    
    return 0;
}