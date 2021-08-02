export module greetings;
 
import <string>;
 
namespace hola
{
  
export std::string get_greeting_text()
{
    return "Hola mundoooo";
}
export struct greeter
{
   constexpr static const char* hellos[] {"Hello", "Hi", "Hey"};
   std::string operator()()
   {
      return hellos[rand() % 3] + std::string{", World!"};
   }
};
}
