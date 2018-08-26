#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string compress(string& s) {
  stringstream ss;
  if (s.empty())
    return s;
  // initialise count and 'previous' character
  int count = 1;
  char previous = s[0];
  for (unsigned int i = 1; i < s.length(); i++) {
    if (s[i] == previous) {
      count++;
    } else {
      // Add the previous char and its count to our compressed stringstream
      ss << previous << count;
      previous = s[i];
      count = 1;
    }
  }
  // Add in the last character
  ss << previous << count;
  string c = ss.str();
  return c.length() < s.length() ?  c : s;
}

int main() {
  string s;
  cout << "Enter a string: ";
  getline(cin, s);
  cout << "Compressed string : " << compress(s) << endl;
}
