#include <iostream>
#include <string>

using namespace std;

// Checks to see if the character counts are equal for two strings
bool is_permutation(string& a, string& b) {
  if (a.length() != b.length()) {
    return false;
  }
  int char_counts_a[256] = {0};
  int char_counts_b[256] = {0};
  for (char& c : a) {
    int char_val = static_cast<int>(c);
    char_counts_a[char_val]++;
  }
  for (char& c : b) {
    int char_val = static_cast<int>(c);
    if (char_counts_a[char_val] == 0) {
      return false;
    }
    char_counts_b[char_val]++;
  }
  for (int i = 0; i < 256; i++){
    if (char_counts_a[i] != char_counts_b[i]) {
      return false;
    }
  }
  return true;
}

// Smarter way of checking if they are permutations - uses half the space
bool is_permutation_alt(string&a, string& b) {
  if (a.length() != b.length()) {
    return false;
  }
  int char_counts[256] = {0};
  for (char& c : a) {
    int char_val = static_cast<int>(c);
    char_counts[char_val]++;
  }
  for (char& c : b) {
    int char_val = static_cast<int>(c);
    if (--char_counts[char_val] < 0) {
      return false;
    }
  }
  return true;
}

int main() {
  string a;
  string b;
  cout << "Enter string #1: ";
  getline(cin, a);
  cout << "Enter string #2: ";
  getline(cin, b);
  if (is_permutation_alt(a, b)) {
    cout << "The strings are permutations of each other.\n";
  } else {
    cout << "The strings are NOT permutations of each other\n";
  }

}
