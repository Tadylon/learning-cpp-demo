#include <iostream>
#include <fstream>

using namespace std;


void test01(){
    ofstream ofs;
    ofs.open("a.txt", ios::out);
    ofs << "hello";

    ofs.close();
}

void test02(){
    ifstream ifs_file;
    ifs_file.open("a.txt",ios::in);

    if (!ifs_file.is_open()) {
        cout << "file open fail!";
        return;
    }
    char buf[100] = {0};
    while (ifs_file >> buf) {
        cout << buf;
    }
    ifs_file.close();
}

class Person{
public:
    char m_Name[64];
    int m_Age;

};

void open_file(){
    ofstream ofs ;
    ofs.open("a.txt",ios::out |ios::binary);
    Person p = {"enthus",18};

    ofs.write((const char*) &p, sizeof(Person));
    ofs.close();
}

void open_file_text(){
    ofstream ofs("a.txt");  // 默认文本模式，不用 ios::binary
    Person p = {"enthus", 18};
    ofs << "Name: " << p.m_Name << ", Age: " << p.m_Age;
    ofs << endl;
    ofs << "Name: " << p.m_Name << ", Age: " << p.m_Age;
    ofs.close();
}

int main(){

    open_file_text();
    // system("pause");
    return 0;
}
