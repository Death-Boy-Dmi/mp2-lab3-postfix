#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
  double res;
  string inf;
  setlocale(LC_ALL, "Russian");
  cout << "Enter the expression (variable names - Latin letters):" << endl;
  cin >> inf;
  TPostfix postfix(inf);
  cout << "Арифметическое выражение: " << postfix.GetInfix() << endl;
  postfix.ToPostfix();
  cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
  res = postfix.Calculate();
  cout << res << endl;

  return 0;
}
