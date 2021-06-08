#include <chrono>
#include <iostream>
#include <thread>

static bool thread_continue = true;

int main()
{
    std::thread mythread([]() {
        using namespace std::literals::chrono_literals;
        while (1)
        {
            if (thread_continue)
            {
                std::cout << "Hello from thread\n";
                std::this_thread::sleep_for(1s);
            }
            else
            {
                std::cout << "Thread stopped\n";
                break;
            }
        }
    });
    std::cin.get();
    thread_continue = false;
    mythread.join();
    std::cout << std::is_empty<bool>::value;
    return 0;
}
