#include <iostream>
#include <string>


// 1. 声明但不初始化（里面的值是内存垃圾）
int arr1[3][4]; // 3行4列的二维数组

// 2. 分行完全初始化（最清晰、可读性最好，推荐）
int arr2[2][3] = {
    {1, 2, 3}, // 第 0 行
    {4, 5, 6}  // 第 1 行
};

// 3. 连续完全初始化（不分行，编译器会自动按行排列）
int arr3[2][3] = {1, 2, 3, 4, 5, 6}; // 效果同上

// 4. 部分初始化，未指定的元素自动补 0
int arr4[2][3] = {
    {1},    // 第0行为 {1, 0, 0}
    {4, 5}  // 第1行为 {4, 5, 0}
};

// 5. 自动推导大小（⚠️注意：只能省略第一维/行数，绝对不能省略第二维/列数！）
int arr5[][3] = {{1, 2, 3}, {4, 5, 6}}; // 正确，编译器能推导出是 2 行
// int arr6[2][] = ...; // 错误！编译失败

void processMatrix(int arr[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] *= 2; // 修改会影响 main 函数中的原数组
        }
    }
}

// 严格限制只能传入 2行3列 的 int 二维数组
void processRefMatrix(int (&arr)[2][3]) {
    // 内部可以直接使用标准的 sizeof(arr) 求出总大小
    int rows = sizeof(arr) / sizeof(arr[0]);    // 2
    int cols = sizeof(arr[0]) / sizeof(arr[0][0]); // 3
}

// R 是行数（Rows），C 是列数（Columns）
template <typename T, unsigned int R, unsigned int C>
void printAnyMatrix(T (&arr)[R][C]) {
    std::cout << "收到一个 " << R << " 行 " << C << " 列的矩阵：" << std::endl;
    for (unsigned int i = 0; i < R; i++) {
        for (unsigned int j = 0; j < C; j++) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}


int main(){
    int matrix[2][3] = {{10, 20, 30}, {40, 50, 60}};
    // 访问单个元素
    int val = matrix[1][2]; // 第1行第2列（都是从0开始计），结果是 60

    // 方式 A：传统的双重 for 循环遍历
    for (int i = 0; i < 2; i++) { // 外层循环控制行
        for (int j = 0; j < 3; j++) { // 内层循环控制列
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // 方式 B：C++11 范围 for 循环遍历多维数组（⚠️非常考验对引用的理解）
    // 外层循环的 row 必须是引用类型，否则 row 会退化成指针，导致内层循环报错！
    for (const auto& row : matrix) { 
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    int myMatrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // 传参时直接写数组名
    processMatrix(myMatrix, 2);


    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    double b[3][4] = {
        {1.1, 1.2, 1.3, 1.4},
        {2.1, 2.2, 2.3, 2.4},
        {3.1, 3.2, 3.3, 3.4}
    };
    printAnyMatrix(a); // 自动识别为 int, 2行3列
    printAnyMatrix(b); // 自动识别为 double, 3行4列

    return 0;
}