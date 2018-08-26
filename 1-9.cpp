#include <string>
#include <iostream>

using namespace std;

bool is_substring(string& super, string& sub) {
  return super.find(sub) == string::npos ? false : true;
}

// I didn't get this one efficiently, had to resort to the 
// text's solution in order to use only one call to is_substring
bool is_rotation(string& s1, string& s2) {
    if (s1.length() != s2.length()) return false;
  string s1s1 = s1 + s1;
  return is_substring(s1s1, s2);
}

int main() {
  string s1 = "waterbottle";
  string s2 = "erbottlewat";
  is_rotation(s1, s2) ?  cout << "True\n" : cout << "False\n";
}
