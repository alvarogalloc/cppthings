#include <fmt/core.h>

#include <array>
#include <functional>
#include <future>
#include <iostream>
#include <string_view>
#include <utility>
#include <vector>

class Executor {
 public:
  Executor() = delete;
  static Executor getInstace() {
    static auto instance = Executor(true);
    return instance;
  }
  static void add_task(auto func) { getInstace().functions.push_back(func); }

  static void execute_all() {
    fmt::print("num of functions {}\n", getInstace().functions.size());
    std::vector<std::future<void>> handles;
    for (auto fn : getInstace().functions) {
      handles.push_back(std::async(std::launch::async, fn));
    }
    for (auto &handle : handles) {
      handle.wait();
    }
  }
  ~Executor() = default;

 private:
  std::vector<std::function<void()>> functions{};
  Executor(bool real) {
    functions = {[]() { fmt::print("Helloworld1\n"); },
                 []() { fmt::print("Helloworld2\n"); },
                 []() { fmt::print("Helloworld3\n"); },
                 []() { fmt::print("Helloworld4\n"); },
                 []() { fmt::print("Helloworld5\n"); },
                 []() { fmt::print("Helloworld6\n"); }};
  }
};

void output() { fmt::print("Helloworld1\n"); }
int main() {
  using namespace std::literals;
  Executor::add_task(output);
  Executor::add_task([]() { fmt::print("Helloworld1\n"); });
  Executor::add_task([]() { fmt::print("Helloworld2\n"); });
  Executor::add_task([]() { fmt::print("Helloworld3\n"); });
  Executor::add_task([]() { fmt::print("Helloworld4\n"); });
  Executor::add_task([]() { fmt::print("Helloworld5\n"); });
  Executor::add_task([]() { fmt::print("Helloworld6\n"); });
  Executor::execute_all();
}
