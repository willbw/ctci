#include <iostream>
#include <string>

using namespace std;


bool one_away(string& a, string& b) {
  unsigned char has_difference = 0;
  auto it_a = a.begin();
  auto it_b = b.begin();

  while (it_a != a.end() && it_b != b.end()) {
    if (*it_a == *it_b) {
      it_a++; it_b++;
    } else {
      // We have already encountered a differing character
      if (has_difference++)
        return false;
      // We are at the end of the string, can replace the character
      if (next(it_a) == a.end() && next(it_b) == b.end()) {
        return true;
      }
      // the next chars match, so we could just do a replacement
      else if (*next(it_a) == *next(it_b)) {
        it_a++; it_b++;
      }
      // The next char matches, so we could do an insertion in a or a deletion in b
      else if (next(it_b) != b.end() && *next(it_b) == *it_a) {
        advance(it_b, 2);
        it_a++;
      }
      // The next char matches, so we could do an insertion in b or a deletion in a
      else if (next(it_a) != a.end() && *next(it_a) == *it_b) {
        advance(it_a, 2);
        it_a++;
      }
      else {
        return false;
      }
    }
  }
  return true;
}

int main() {
  string a;
  string b;
  cout << "Enter a string: ";
  getline(cin, a);
  cout << "Enter another string: ";
  getline(cin, b);
  one_away(a, b) ?
    cout << "True\n" :
    cout << "False\n";
}
