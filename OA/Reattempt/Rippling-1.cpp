#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getSmallestEncryptedString(const string &originalString)
{
  if (originalString.empty())
  {
    return "";
  }

  int n = originalString.length();

  // Step 1: Precompute the smallest character from index i to the end
  vector<char> min_char(n);
  min_char[n - 1] = originalString[n - 1];

  for (int i = n - 2; i >= 0; --i)
  {
    min_char[i] = min(originalString[i], min_char[i + 1]);
  }

  string tempString = "";
  string encryptedString = "";

  // Step 2: Process the string
  for (int i = 0; i < n; ++i)
  {
    // Operation 1: Append first of original to last of temp
    tempString.push_back(originalString[i]);

    // Operation 2: Append last of temp to encrypted
    // We pop if the stack is not empty AND the top of the stack is
    // smaller than or equal to any character left in originalString.
    while (!tempString.empty())
    {
      // If we are at the last character of originalString,
      // or the top of tempString is <= the smallest remaining char
      if (i == n - 1 || tempString.back() <= min_char[i + 1])
      {
        encryptedString.push_back(tempString.back());
        tempString.pop_back();
      }
      else
      {
        break; // Wait for a smaller character to be pushed later
      }
    }
  }

  return encryptedString;
}

int main()
{
  string s;cin>>s;
  cout << getSmallestEncryptedString(s) << "\n";


  return 0;
}