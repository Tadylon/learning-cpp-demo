#include <iostream>
#include <thread>
#include <future>
#include <memory>

int heavy_task(int n) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return n * n;
}


// 模拟 std::async 的伪代码
template<typename F, typename... Args>
auto my_async(F&& f, Args&&... args) {
    // 1. 底层悄悄创建一个 promise
    auto prom = std::make_shared<std::promise<std::invoke_result_t<F, Args...>>>();
    
    // 2. 悄悄取出未来拿结果的凭证 future
    auto fut = prom->get_future();
    
    // 3. 悄悄启动线程，把 promise 传进去
    std::thread([prom, f, args...]() {
        try {
            prom->set_value(f(args...)); // 执行函数并设值
        } catch (...) {
            prom->set_exception(std::current_exception()); // 捕获异常
        }
    }).detach();
    
    // 4. 直接把 future 返回给用户
    return fut; 
}


int main () {
    // 只需要一个存放 future 的容器即可，不需要写 thread 和 promise 了
    std::vector<std::future<int>> futures;

    for (int i = 0; i < 100; ++i) {
        // std::launch::async 策略确保它一定会立即在新线程中异步执行
        // 隐式创建 promise 并返回对应的 future，按值捕获 i 保证安全
        futures.push_back(my_async( [i]() {
            return heavy_task(i); // 直接 return 即可，底层 promise 会自动接收这个返回值
        }));
    }

    // 收集结果
    for (int i = 0; i < 100; ++i) {
        // futures[i].get() 会自动阻塞等待该后台任务执行完毕
        std::cout << "Task " << i << " result: " << futures[i].get() << std::endl;
    }

    return 0;
}


