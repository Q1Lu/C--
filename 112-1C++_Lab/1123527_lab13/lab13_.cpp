#include<iostream>
using namespace std;

struct NODE{
  int coef;
  int expnt;
  NODE *link = NULL;
};

void printPolynomial(NODE *head)
{
  NODE *ptr = head;
  while(ptr != NULL){
    if(ptr -> coef != 0)
    {
      if(ptr == head)
      {
        if(ptr -> coef > 0 && ptr -> coef == 1)
           int x = 1;
        else if(ptr -> coef > 0)
           cout << ptr -> coef;
        else if(ptr -> coef == -1)
           cout << '-';
        else 
           cout << ptr -> coef;
        if(ptr -> expnt > 1)
           cout << "x^" << ptr -> expnt;
        else if(ptr -> expnt == 1)
           cout << 'x';
        else if(ptr -> coef < 0)
           cout << -(ptr -> coef);
        else 
           cout << ptr -> coef;
      }
      else
      {
        if(ptr -> coef > 0 && ptr -> coef == 1 && ptr -> expnt > 0)
           cout << " + " << 'x';
        else if(ptr -> coef > 0 && ptr -> expnt > 0)
           cout << " + " << ptr -> coef << 'x';
        else if(ptr -> coef == -1 && ptr -> expnt > 0)
           cout << " - " << "x";
        else if(ptr -> expnt > 0)
           cout << " - " << -(ptr -> coef) << 'x';
        else if(ptr -> coef > 0)
           cout << " + " << ptr -> coef;
        else
           cout << " - " << -(ptr -> coef);
        if(ptr -> expnt > 1)
           cout << '^' << ptr -> expnt;
      }
    }
    ptr = ptr -> link;
  }
  cout << endl;

  NODE *fptr;
  while(head != NULL){
    fptr = head;
    head = head -> link;
    delete fptr;
  }
}

int main()
{
  int testcases;
  int rank;
  int power;
  cin >> testcases;
  NODE *headNode = nullptr;
  for(int i = 0; i < testcases; i++)
  {
    cin >> rank;
    int *coef = new int [rank];
    for(int k = rank - 1; k >= 0; k--)
    {
      cin >> coef[k];
    }

    NODE *headNode = new NODE; 
    NODE *nowNode = headNode;

    power = rank - 1;
    while(power >= 0)
    {
      nowNode -> coef = coef[power];
      nowNode -> expnt = power;
      if(power != 0)
      {
        nowNode -> link = new NODE;
        nowNode = nowNode->link;
      }
      power--;
    }
    printPolynomial(headNode);
    delete [] coef;
  }
  return 0;
}