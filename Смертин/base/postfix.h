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
  bool CheckChars()
  {
	  string valval = "()*/-+.0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	  for (size_t i = 0; i < infix.length(); i++)
	  {
		  if (valval.find(infix[i]) != std::string::npos)
		  {
			  return false;
			  throw "An invalid character was fond";
		  }
	  }
	  return true;
  }
  bool CheckAmount(string str)
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
  bool CheckBrackets(string str)
  {
	  string temp = str;
	  if (temp.find("()"))
	  {
		  return false;
		  throw "Detected is ''()''";
	  }
	  while (temp.find('(') == std::string::npos && temp.find(')') == std::string::npos)
	  {
		  if (temp.find('(') != std::string::npos)
			  if (temp.find(')') != std::string::npos)
			  {
				  temp[temp.find('(')] = ' ';
				  temp[temp.find(')')] = ' ';
			  }
			  else
			  {
				  return false;
				  throw "Incorrect number of brackets";
			  }
	  }
	  return true;
  }
  bool CheckInfix()
  {
	  if (CheckChars() == false) 
		  return false;
	  if (infix[0] == ')' || infix[0] == '*' || infix[0] == '/' || infix[0] == '-' || infix[0] == '+')
		  return false;
	  if (infix[infix.length()] == '(' || infix[infix.length()] == '*' || infix[infix.length()] == '/' || infix[infix.length()] == '-' || infix[infix.length()] == '+')
		  return false;
	  if (CheckAmount(infix) == false)
		  return false;
	  if (CheckBrackets(infix) == false)
		  return false;

	  return true;
  }
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  string ToPostfix();
  double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
