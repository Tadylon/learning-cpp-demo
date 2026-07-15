#include <iostream>
#include "print_obj.h"

using namespace std;
int main() {
        char szBuf[60];
        char szBuf1[60];
        cout << "请输入一个字符串：";
        int n = cin.get();        //特殊情况可使用get提取'\n'
        cout__(n);
        
        cin.get(szBuf1, 60);
        cout__(szBuf1);

        cline__("----------------------");
        cin.getline(szBuf, 60);
        cout << n << endl;
        cout << "The received string is:" << szBuf << endl;
        //cout << "The received string is:" << szBuf1 << endl;
        
        return 0;
}