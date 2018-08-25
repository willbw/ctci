#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void urlify(string& s) {
  for (auto it = s.begin(); it != s.end(); it++) {
    // If we encounter a space, we know that in the problem definition there are 
    // enough spaces at the end of the string for a urlified string
    // 
    // So, we can reverse the remainder of the string, change three characters to be "%20"
    // and then reverse the string back after that. 
    if (*it == ' ') {
      auto it_2 = it;
      reverse(next(it), s.end());
      *it_2 = '%';
      advance(it_2, 1);
      *it_2 = '2';
      advance(it_2, 1);
      *it_2 = '0';
      reverse(next(it_2), s.end());
    }
  }
}

// Textbook implementation
void urlify_alt(string& s) {
  int space_count = 0;
  string::iterator last_non_space;
  for (auto it = s.begin(); it != s.end(); it++) {
    if (*it == ' ')
      space_count++;
    else 
      last_non_space = it;
  }

  string::iterator back = s.end();
  for (auto it = last_non_space; it != prev(s.begin()); it--) {
    if (*it == ' ') {
      advance(back, -1);
      *back = '0';
      advance(back, -1);
      *back = '2';
      advance(back, -1);
      *back = '%';
    } else {
      advance(back, -1);
      *back = *it;
    }
  }

}

int main() {
  string s;
  cout << "Enter a string: ";
  getline(cin, s);
  string s_copy = s;
  // My implementation
  urlify(s);
  cout << s << endl;
  // Test textbook implementation
  cout << s_copy << endl;;
  urlify_alt(s_copy);
  cout << s_copy << endl;
}
