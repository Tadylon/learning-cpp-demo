#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Create a vector called cars that will store strings
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

int main() {
    const int a = 8;
    int  const * xyz;
    xyz = &a;
    // Sort cars alphabetically
    sort(cars.begin(), cars.end());
    for (const string & car : cars){
        cout << car << " " << endl;
    }
    vector<int> numbers_test = {1,7,6,4,2,6,8,};
    auto it = find(numbers_test.begin(), numbers_test.end(), 2);
    // 在 it 前面加一个星号，表示“取出这个位置存放的值”
    if (it != numbers_test.end()) {
        cout << *it << endl; 
    } else {
        cout << "没找到该数字" << endl;
    }
    cout << "索引位置" << distance(numbers_test.begin(), it) << endl;
    // Create a vector called numbers that will store integers
    vector<int> numbers = {1, 7, 3, 5, 9, 2};

    // Create a vector called copiedNumbers that should store 6 integers
    vector<int> copiedNumbers(6);

    // Copy elements from numbers to copiedNumbers
    copy(numbers.begin(), numbers.end(), copiedNumbers.begin());
}