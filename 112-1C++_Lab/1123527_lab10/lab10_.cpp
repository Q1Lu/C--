#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;

string generatePassWd(int &passLen)
{
  string tempStr = "";
  string number[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
  string upperCase[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
  string lowerCase[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
  srand(time(0));
  passLen = rand() % 4 + 1;
  for(int i = 0; i < passLen; i++)
  {
    int tNum = rand() % 62;
    if(tNum >= 0 && tNum <= 9)
    {
      tempStr[i] ='0' + tNum;
      tempStr = tempStr + to_string(tempStr[i] % 48);
    }
    else if(tNum >= 10 && tNum <= 35)
    {
      tempStr[i] = 'A' + tNum - 10;
      tempStr = tempStr + upperCase[tempStr[i] % 65];
    }
    else
    {
      tempStr[i] = 'a' + tNum - 36;
      tempStr = tempStr + lowerCase[tempStr[i] % 97];
    }
  }
  return tempStr;
}

enum status{TH, TL, RT};
status guess(string guessPassword, string realPassword)
{
  unsigned long long guessPaswordDecimal = 0;
  unsigned long long realPaswordDecimal = 0;
  for(int n = guessPassword.length() - 1; n >= 0; n--)
  {
    int guessNum = 0;
    if(guessPassword[n] >= 48 && guessPassword[n] <= 57)
    {
      guessNum = guessPassword[n] - 48 + 1;
    }
    else if(guessPassword[n] >= 65 && guessPassword[n] <= 90)
    {
      guessNum = guessPassword[n] - 54;
    }
    else if(guessPassword[n] >= 97 && guessPassword[n] <= 122)
    {
      guessNum = guessPassword[n] - 60;
    }
    guessPaswordDecimal = guessPaswordDecimal + guessNum * pow(62,n);
  }
  for(int j = realPassword.length() - 1; j >= 0; j--)
  {
    int realNum = 0;
    if(realPassword[j] >= 48 && realPassword[j] <= 57)
    {
      realNum = realPassword[j] - 48 + 1;
    }
    else if(realPassword[j] >= 65 && realPassword[j] <= 90)
    {
      realNum = realPassword[j] - 54;
    }
    else if(realPassword[j] >= 97 && realPassword[j] <= 122)
    {
      realNum = realPassword[j] - 60;
    }
    realPaswordDecimal = realPaswordDecimal + realNum * pow(62,j);
  }
  status GuessStatus;
  if(guessPaswordDecimal > realPaswordDecimal)
  {
    GuessStatus = TH;
    return GuessStatus;
  }
  else if(guessPaswordDecimal < realPaswordDecimal)
  {
    GuessStatus = TL;
    return GuessStatus;
  }
  else 
  {
    GuessStatus = RT;
    return GuessStatus;
  }
}

int main()
{
  string aGuess;
  string passWd;
  int passLen;
  string userinput;
  passWd = generatePassWd(passLen);
  cout << "PassWord: " << passWd << endl;
  cout << "Guessing a password at most having four symbols (0~9, A~Z, a~z). My guess is as follows: " << endl;
  int index = 1;
  int x = ceil(log2(pow(62,passLen + 1) / 61))+ 3;
  bool right = false;
  do{
     do{
    if(index == 1)
    {
      cout << index << "-st guess = ";
    }
    else if(index == 2)
    {
      cout << index << "-nd guess = ";
    }
    else if(index == 3)
    {
      cout << index << "-rd guess = ";
    }
    else if(index >= 4)
    {
      cout << index << "-th guess = ";
    }
    cin >> aGuess;
    status result = guess(aGuess, passWd);
    if(result == TH)
    {
      cout << "Too high. Try again." << endl;
    }
    else if(result == TL)
    {
      cout << "Too low. Try again." << endl;
    }
    else if(result == RT)
    {
      cout << "Bravo, you guess it right!" << endl;
      right = true;
    }
    index = index + 1;
  }while(!right);
  if(index <= x)
  {
    cout << "You know the secret!" << endl;
  }
  else if(index > x)
  {
    cout << "You should be able to do better." << endl;
  }
  cout << "## Your score = " << min(100.0,(1 - 0.5 * (index - x) / x) * 100) << endl;
  cout << "Play the game again (Y or y for yes): ";
  cin >> userinput;
  }while(userinput != "n" && userinput != "N");
}