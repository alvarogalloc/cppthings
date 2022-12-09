#pragma once
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

struct Person {
  std::string name;
  int age;
  float height;
  float weight;
};

struct Adult : Person {
  std::string job;
};

struct Parent;
struct Child : Person {
  std::string school;
};

struct Parent : Adult {
  Child children[5];
  void print() const {
    std::cout << "Parent: " << name << " " << age << " " << job << std::endl;
    for (const auto& child : children) {
      std::cout << "  Child: " << child.name << ' ' << child.age << std::endl;
    }
  }
};
