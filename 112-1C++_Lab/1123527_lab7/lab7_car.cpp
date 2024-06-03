#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

string getPattern(int, unsigned int);
vector<int> getTap(string);
void displayTap(vector<int>);
string getNewPattern(vector<int>, string);
int hammingDistance(string, string);

int main(){
 int numberOfCases = 0;
 cin >> numberOfCases;
 cout << "Number of test cases: " << numberOfCases << endl;
 while(numberOfCases--)
 {
  int k;
  unsigned  int minDis, maxDis, seeder, step, ans;
  minDis = UINT_MAX;
  maxDis = 0;
  set<string> myMap;
  cin >> k >> seeder;
  cout << "Length of LFSR: " << k << endl;
  cout << "Integer determines tap bits and seed: " << seeder << endl;
  string pattern = getPattern(k, seeder);
  string originalPattern = pattern;
  vector<int> tap = getTap(pattern);
  displayTap(tap);
  cout << pattern << endl;
  unsigned  int maxStep = pow(2, k) - 1;
  ans = 0;
  for(step=1; step<=maxStep; step++)
  {
   string newPattern = getNewPattern(tap,pattern);
   int distance = hammingDistance(pattern, newPattern);
   if (distance > maxDis)
    maxDis = distance;
   if (distance < minDis)
    minDis = distance;
   if (myMap.find(newPattern) != myMap.end())
   {
    if (originalPattern == newPattern)
     ans = step;
    break;
   }
   myMap.insert(newPattern);
   pattern = newPattern;
  }
  cout << ans << ' ' << minDis << ' ' << maxDis << endl;
  
 }
 return 0;
}

int hammingDistance(string pattern, string newPattern)
{
 int distance = 0;
 for (int pos = 0; pos < pattern.length(); pos++)
 {
  if (pattern[pos] != newPattern[pos])
   distance++;
 }
 return distance;
}

string getPattern(int k, unsigned int seeder)
{
 string pattern = "";
 while(true)
 {
  if (seeder == 0 || pattern.length() >= k)
   break;
  int digit = seeder % 2;
  seeder /= 2;
  // pattern -> '101' '0' '1010'
  pattern += (digit + '0'); //asscii code
 }
 
 if (pattern.length() < k)
  while(true)
  {
   if (pattern.length() == k)
    break;
   pattern += '0';
  }
 return pattern;
}

string getNewPattern(vector<int> tap, string pattern)
{
 string newPattern = "";
 int count = 0;
 
 for (int pos = 0; pos < tap.size(); pos++)
 {
  if (pattern[tap[pos]] == '1')
   count++;
 }
 
 if (count % 2 == 0)
  newPattern += '0';
 else
  newPattern += '1';

 for (int pos = 0; pos < pattern.size()-1; pos++)
  newPattern += pattern[pos];

 return newPattern;
}


vector<int> getTap(string pattern)
{
 vector<int> tap;
 for (int pos = 0; pos < pattern.length(); pos++)
 {
  if (pattern[pos] == '1')
   tap.push_back(pos);
 }
 return tap;
}

void displayTap(vector<int> tap)
{
 for (int pos = 0; pos < tap.size(); pos++)
 {
  cout << tap[pos] + 1;
  if (pos == tap.size()-1)
   cout << endl;
  else
   cout << ' ';
 }
}
