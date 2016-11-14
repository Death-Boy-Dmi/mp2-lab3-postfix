#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"
#include <iostream>

using namespace std;
#define MaxSizeString 1000
struct TablFunc
{
	char func[7];
	int priority[7];
	int amount;
	TablFunc()
	{
		func[0] = ')';	amount = 2;
		func[1] = '(';	priority[1] = 0;
		func[2] = '+';	priority[2] = 1;
		func[3] = '-';	priority[3] = 1;
		func[4] = '*';	priority[4] = 2;
		func[5] = '/';	priority[5] = 2;
		func[6] = '=';	priority[6] = 0;
	}
};

class TPostfix
{
	string infix;
	string postfix;
	string* variable;
	TablFunc functions;

public:
	TPostfix()
	{
		cin >> infix;
	}
  bool CheckChars() // Проверка на допустимые символы
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
  bool CheckAmount(string str) // Проверка соответствия кол-ва переменных кол-ву операций
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
  bool CheckBrackets(string str) // Проверка количества скобок
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
  bool CheckInfix() // Общая проверка
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
  /*string DeleteSpace(string inf) // Удаление пробелов
  {
	  infix = inf;
	  for (int i = 0; i < infix.size(); i++)
		  if (infix[i] == ' ')
			  infix.erase(i, 1);
  }*/
  string AddEqual (string inf) // Добавление равно в конец строки
  {
	  return inf += '=';
  }
  void ArrVarible(string inf) // Выделение из строки переменных и добавление их в массив
  {
	  size_t size = 0;
	  for (int i = 0; i < infix.size(); i++)
		  if (inf[i] == '+' || inf[i] == '-' || inf[i] == '*' || inf[i] == '/' || inf[i] == '(' || inf[i] == ')')
		  {
			  if (inf[i] == '=')
				  break;
			  else
			  {
				  size++;
			  }
		  }
	  variable = new string[size];
	  int k = 0;
	  for (int i = 0; i < inf.size(); i++)
		  while (k < size)
			  if (inf[i] == '+' || inf[i] == '-' || inf[i] == '*' || inf[i] == '/' || inf[i] == '(' || inf[i] == ')')
			  {
				  for (int j = 0; j < i; j++)
				  {
					  variable[k] += inf[j];
				  }
				  inf.erase(0, i);
				  k++;
			  }
  }
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  string ToPostfix();
  double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
