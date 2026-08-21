#include <iostream>
#include <thread>
#include <chrono>

static bool is_Finished = 0;
void DoWork(){
    using namespace std::chrono_literals;

    while (!is_Finished) {
        std::cout << "working..." << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main(){
    std::thread worker(DoWork);
    std::cin.get();
    is_Finished = true;
    std::cout << "the value of is_FInished : " << is_Finished << std::endl;
    //这个是等待完成 阻塞
    if (worker.joinable()) {
        worker.join();
        std::cout << " this thread has finished ! \n"; 
    }

    system("pause");
    return 0;
}
