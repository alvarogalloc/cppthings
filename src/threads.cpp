#include <chrono>
#include <iostream>
#include <thread>

static bool thread_continue = true;

int main() {
  std::thread mythread([]() {
    while (1) {
      if (thread_continue) {
        std::cout << "Hello from thread\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
      } else {
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
