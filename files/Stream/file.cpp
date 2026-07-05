#include <iostream>
#include <fstream>

using namespace std;


void test01(){
    ofstream ofs;
    ofs.open("README.md", ios::out);
    ofs << "hello" <<endl;

    ofs.close();
}

void test02(){
    ifstream ifs_file;
    ifs_file.open("README.md",ios::in);

    if (!ifs_file.is_open()) {
        cout << "file open fail!" <<endl;
        return;
    }
    char buf[100] = {0};
    while (ifs_file >> buf) {
        cout << buf << endl;
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
    ofs.open("README.md",ios::out |ios::binary);
    Person p = {"enthus",18};

    ofs.write((const char*) &p, sizeof(Person));
    ofs.close();
}


int main(){

    open_file();
    system("pause");
    return 0;
}
