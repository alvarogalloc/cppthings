export module example;

import <iostream>;
import <string>;

export class gallo
{
  public:
    void hello(std::string name)
    {
        std::cout << "Hello " << name << ", from cpp20 module!!\n";
    }
};
