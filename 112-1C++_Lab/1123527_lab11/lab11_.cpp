#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int intResult;
double doubleResult;
string stringResult;

int& find13(int integer[], int length, int &objectNum)
{
  intResult = integer[0];
  double numElm = length;
  for(int i = 0; i < length; i++)
  {
    if(integer[i] > intResult)
    {
      intResult = integer[i];
    }
    int smallerThan = 0;
    for(int k = 0; k < length; k++)
    {
      if(integer[i] > integer[k])
      {
        smallerThan++;
      }
    }
    if(smallerThan == ceil(numElm / 3) - 1)
    {
      intResult = integer[i];
      return intResult;
    }
  }
  return intResult;
}

double& find13(double floating[], int length, int &objectNum)
{
  doubleResult = floating[0];
  double numElm = length;
  for(int i = 0; i < length; i++)
  {
    if(floating[i] > doubleResult)
    {
      doubleResult = floating[i];
    }
    int smallerThan = 0;
    for(int k = 0; k < length; k++)
    {
      if(floating[i] > floating[k])
      {
        smallerThan++;
      }
    }
    if(smallerThan == ceil(numElm / 3) - 1)
    {
      doubleResult = floating[i];
      return doubleResult;
    }
  }
  return doubleResult;
}

string& find13(string words[], int length, int &objectNum)
{
  stringResult = words[0];
  double numElm = length;
  for(int i = 0; i < length; i++)
  {
    if(words[i] > stringResult)
    {
      stringResult = words[i];
    }
    int smallerThan = 0;
    for(int k = 0; k < length; k++)
    {
      if(words[i] > words[k])
      {
        smallerThan++;
      }
    }
    if(smallerThan == ceil(numElm / 3) - 1)
    {
      stringResult = words[i];
      return stringResult;
    }
  }
  return stringResult;
}

template <typename T>
T find13Tempt(T anAry[], int numElm, int &num13Obj)
{
  T maximum = anAry[0];
  double length = numElm;
  for(int i = 0; i < numElm; i++)
  {
    if(anAry[i] > maximum)
    {
      maximum = anAry[i];
    }
    int smallerThan = 0;
    for(int k = 0; k < numElm; k++)
    {
      if(anAry[i] > anAry[k])
      {
        smallerThan++;
      }
    }
    if(smallerThan == ceil(length / 3) - 1)
    {
      return anAry[i];
    }
  }
  return maximum;
}

int main()
{
  int numTest;
  int intList[100];
  double doubleList[100];
  string strList[100];
  int numElm;
  string dataType;
  cin >> numTest;
  for(int j = 0; j < numTest; j++)
  {
    cin >> dataType;
    cin >> numElm;
    int num13Obj = 0;
    if(dataType == "int")
    {
      for(int i = 0; i < numElm; i++)
      {
        cin >> intList[i];
      }
      cout << "Test " << j + 1 << ": " << find13(intList, numElm, num13Obj) << " ";
      for(int n = 0; n < numElm; n++)
      {
        if(intList[n] == find13(intList, numElm, num13Obj))
        {
          num13Obj++;
        }
      }
      cout << num13Obj << endl;
      num13Obj = 0;
      cout << "Test " << j + 1 << ": " << find13Tempt(intList, numElm, num13Obj) << " ";
      for(int m = 0; m < numElm; m++)
      {
        if(intList[m] == find13Tempt(intList, numElm, num13Obj))
        {
          num13Obj++;
        }
      }
      cout << num13Obj << endl;
    }

    else if(dataType == "double")
    {
      for(int i = 0; i < numElm; i++)
      {
        cin >> doubleList[i];
      }
      cout << "Test " << j + 1 << ": " << find13(doubleList, numElm, num13Obj) << " ";
      for(int n = 0; n < numElm; n++)
      {
        if(doubleList[n] == find13(doubleList, numElm, num13Obj))
        {
          num13Obj++;
        }
      }
      cout << num13Obj << endl;
      num13Obj = 0;
      cout << "Test " << j + 1 << ": " << find13Tempt(doubleList, numElm, num13Obj) << " ";
      for(int m = 0; m < numElm; m++)
      {
        if(doubleList[m] == find13Tempt(doubleList, numElm, num13Obj))
        {
          num13Obj++;
        }
      }
      cout << num13Obj << endl;
    }

    else 
    {
      for(int i = 0; i < numElm; i++)
      {
        cin >> strList[i];
      }
      cout << "Test " << j + 1 << ": " << find13(strList, numElm, num13Obj) << " ";
      for(int n = 0; n < numElm; n++)
      {
        if(strList[n] == find13(strList, numElm, num13Obj))
        {
          num13Obj++;
        }
      }
      cout << num13Obj << endl;
      num13Obj = 0;
      cout << "Test " << j + 1 << ": " << find13Tempt(strList, numElm, num13Obj) << " ";
      for(int m = 0; m < numElm; m++)
      {
        if(strList[m] == find13Tempt(strList, numElm, num13Obj))
        {
          num13Obj++;
        }
      }
      cout << num13Obj << endl;
    }
  }
  return 0;
}
