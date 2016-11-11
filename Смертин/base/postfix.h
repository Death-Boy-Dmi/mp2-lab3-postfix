#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"
#include <iostream>

using namespace std;

class TablFunc
{
	char func[6];
	int priority[6];
	int amount;
public:
	TablFunc()
	{
		func[0] = ')';	amount = 2;
		func[1] = '(';	priority[1] = 0;
		func[2] = '+';	priority[2] = 1;
		func[3] = '-';	priority[3] = 1;
		func[4] = '*';	priority[4] = 2;
		func[5] = '/';	priority[5] = 2;
	}
	bool ChekAmount(string str)
	{
		string arop = "-*/+";
		string var = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		for (size_t i = 0; i < str.length(); i++)
			if (arop.find(str[i]) != std::string::npos)
				if (var.find(str[(arop.find(str[i])) - 1]) != std::string::npos
					&& var.find(str[(arop.find(str[i])) + 1]) != std::string::npos)
					return true;
				else
					return false;
			else
				throw "The arithmetic operation is not found";
	}
};

class TPostfix
{
  string infix;
  string postfix;
public:
  TPostfix()
  {
	  cin >> infix;
  }
  bool CheckChars(string inf)
  {
	  infix = inf;
	  string valval = "()*/-+.0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	  for (size_t i = 0; i < infix.length(); i++)
	  {
		  if (valval.find(infix[i]) != std::string::npos)
			  throw "An invalid character was fond";
	  }
  }
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  string ToPostfix();
  double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
