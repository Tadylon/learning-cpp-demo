#include <iostream>
#include <chrono>


class Timer {
public:
    Timer(){
        m_Start_Timer = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        Stop();
    }

    void Stop(){
        auto endTimePoint = std::chrono::high_resolution_clock::now();
        
        auto start_time = std::chrono::time_point_cast< std::chrono::microseconds >(m_Start_Timer).time_since_epoch();
        auto end_time = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch();

        auto duration = end_time - start_time;

        auto ms = duration * 0.001;
        
        std::cout << duration << "us( "  << ms << ")ms" << std::endl;
    }   
private:
    std::chrono::time_point< std::chrono::high_resolution_clock> m_Start_Timer;
};


int main(){
    int value = 0;
    {
        Timer time;
        for (int i = 0 ; i < 20000 ; ++i ) {
            value += 2;
        }
        std::cout << value << std::endl;
    }

    // __debugbreak();
    system( "pause");
    return 0;
}



