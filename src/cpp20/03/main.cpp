import <iostream>;
import <cstdlib>;
import greetings;

int main() {
  std::cout << hola::get_greeting_text() << '\n';
  std::srand(std::time(0));
  std::cout << hola::greeter()() << '\n';
}
