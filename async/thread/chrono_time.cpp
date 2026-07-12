#include <iostream>
#include <chrono>
#include <thread>

struct Timer 
{
    std::chrono::time_point<std::chrono::steady_clock> start, end; 
    std::chrono::duration<float> duration;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;

        std::cout << "Timer took : " << ms << " ms" << std::endl;
    }
};


void FunctionDo() {
    Timer s_timer;
    for (int i  = 0; i < 100 ; ++i) {
        std::cout << "Hello\n " ;
    }
}

int main(){
    using namespace std::literals::chrono_literals;

    auto start_time = std::chrono::high_resolution_clock::now();
    
    std::this_thread::sleep_for(1s);
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = end_time - start_time;
    std::chrono::duration<float> duration_float = end_time - start_time;

    std::cout << "the all using time : " << duration << std::endl;
    // std::cout << "the all using time : " << duration.count() << std::endl;
    
    
    std::cout << "the all using time : " << duration_float << std::endl;
    std::cout << "the all using time : " << duration_float.count() << " s" << std::endl;
    
    FunctionDo();
    system("pause");
    return 0;
}