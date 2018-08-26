#include <string>
#include <iostream>

using namespace std;

/* For a string to be a palindrome, it must have the same
 * number of letters, and two copies of each letter if it is of even length.
 * If it is of odd length, then we need the extra letter to be the same
 */
bool is_palindrome_permutation(string& s) {
  int len = s.length();
  int number_of_odds = 0;
  int letters[256] = {0};
  for (char c : s) {
    if (c != ' ')
      letters[static_cast<int>(tolower(c))]++;
    else
      len--;
  }
  // compare length without spaces
  bool is_even = !(len & 1);
  for (int i = 0; i < 256; i++) {
    if (letters[i] > 0) {
      // If count is odd
      if (letters[i] & 1) {
        if (is_even || ++number_of_odds > 1)
          return false;
      }
    }
  }
  return true;
}

// Textbook interpretation
bool is_palindrome_textbook(string& s) {
  int len = s.length();
  int number_of_odds = 0;
  int letters[256] = {0};
  for (char c : s) {
    if (c != ' ') {
      int char_val = static_cast<int>(tolower(c));
      // Moving from an odd count to an even one
      if (letters[char_val] > 0 && letters[char_val] & 1)
          number_of_odds--;
      // moving from an even count to an odd one
      else
        number_of_odds++;
      letters[char_val]++;
    } else {
      // decrement the length without spaces
      len--;
    }
  }
  // compare length without spaces
  bool is_even = !(len & 1);
  if (number_of_odds > 1 || (number_of_odds > 0 && is_even))
    return false;
  return true;
}

// Using bitset to test that there are either 1 or 0 letters with an odd count in the string
// Assumes only letters a-z and A-Z are present in the string, along with spaces
bool is_palindrome_bits(string& s) {
  bitset<26> bits;
  for (char& c : s) {
    if (c != ' ')
      bits.flip(static_cast<int>(tolower(c) - 'a'));
  }
  return bits.count() <= 1;
}

int main() {
  string s;
  cout << "Enter a string: ";
  getline(cin, s);
  if (is_palindrome_permutation(s))
    cout << "True\n";
  else
    cout << "False\n";
  cout << "And textbook version says:\n";
  if (is_palindrome_textbook(s))
    cout << "True\n";
  else
    cout << "False\n";
  cout << "And bits version says:\n";
  if (is_palindrome_bits(s))
    cout << "True\n";
  else
    cout << "False\n";
}
