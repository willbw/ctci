#include <iostream>
#include <string>

bool has_unique_chars(std::string& s) {
  bool chars[256] = {false};
  for (char& c : s) {
    int val = static_cast<int>(c);
    if (chars[val])
      return false;
    chars[val] = true;
  }
  return true;
}

int main() {
  std::string s;
  std::cout << "Enter a string: ";
  std::getline(std::cin, s);
  if (has_unique_chars(s)) {
    std::cout << "String has all unique characters." << std::endl;
  } else {
    std::cout << "String does not have all unique characters." << std::endl;
  }
}
