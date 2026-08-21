#include <iostream>
#include <memory>
#include <thread>
using namespace std;

class Logger
{
private:
    std::thread t1;
    bool keepalive;
public:
    void print_logs(){
        while(keepalive){
            cout << "I am alive"<<endl;
        }
    }
    Logger(){
        keepalive = true;
        t1 = thread(&Logger::print_logs, this);// if non sttic then we need to send this pointer, if static then without static this will work
    }
    ~Logger(){
        keepalive = false;
        if (t1.joinable())
            t1.join();
    }
};

int counter = 0;
void stats(){
    while(counter<10){
        cout <<"In stats"<<endl;
        counter++;
    }
}
int main(){
    {
        Logger L1;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    return 0;
}