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


int heavy_task(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return n * n;
}

int main() {
    using namespace std::literals::chrono_literals;
    auto start_time = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(1s);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = end_time - start_time;
    std::chrono::duration<float> duration_float = end_time - start_time;

    std::cout << "the all using time : " << duration << std::endl;
    // std::cout << "the all using time : " << duration.count() << std::endl;
    std::cout << "the all using time : " << duration_float << std::endl;
    // std::cout << "the all using time : " << duration_float.count() << " s" << std::endl;
    
    std::thread thread_1(heavy_task,2);
    {
        Timer time;
        auto result = thread_1.get_id();
        std::cout << "the result is : " << result << std::endl;
        thread_1.join();
        
    }
    std::cin.get();
    return 0;
}


