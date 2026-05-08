#define API_USING 
#include <iostream>
#include <d3d11.h>
#include <tchar.h>
#include <dwmapi.h>
#pragma comment(lib,"d3d11.lib")

using namespace std;

API_USING void test(){
    cout << "hello" << endl;
}


int APIENTRY main(){
    test();
    system("pause");
    return 0;
}