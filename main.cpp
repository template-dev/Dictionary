#include <iostream>
#include <string>

#include "Dictionary.hpp"

int main()
{
  try {
    Dictionary<int, std::string> dictionary(1, "Hello");
    dictionary.set(2, "World");
    dictionary.set(3, "!");
    std::cout << dictionary.get(30);

    Dictionary<int, std::string> dictionary2(dictionary);
    Dictionary<int, std::string> dictionary3;
    dictionary3 = dictionary2;

    auto itBegin = dictionary2.begin();
    while(itBegin != dictionary2.end())
    {
      std::cout << itBegin->second << std::endl;
      itBegin++;
    }

  } catch(std::exception& ex) {
    std::cerr << ex.what() << std::endl;
  }

  return 0;
}