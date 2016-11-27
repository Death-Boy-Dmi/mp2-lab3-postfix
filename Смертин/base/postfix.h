#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"
#include <iostream>
#include <sstream>

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
	size_t varSize;
	TablFunc functions;

public:
	TPostfix(string inf)
	{
		infix = inf;
		CheckInfix();
	}
	bool CheckChars() // Проверка на допустимые символы
	{
		string valval = "()*/-+abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.";
		for (size_t i = 0; i < infix.length(); i++)
		{
			if (valval.find(infix[i]) == std::string::npos)
			{
				throw "An invalid character was found";
			}
		}
		return true;
	}
	bool CheckAmount() // Проверка соответствия кол-ва переменных кол-ву операций
	{
		string str = " " + infix + " ";
		string arop = "-*/+";
		string var = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		for (size_t i = 0; i < str.length(); i++)
			if (arop.find(str[i]) >= 0 && arop.find(str[i]) <= str.length())
			{
				if ((var.find(str[i - 1]) >= 0 && var.find(str[i - 1]) <= var.length())
					&& (var.find(str[i + 1]) >= 0 && var.find(str[i - 1]) <= var.length()))
					continue;
				else
					throw "the number of variables does not correspond to the numbers of operations";
			}
		return true;
	}
	bool CheckBrackets() // Проверка количества скобок
	{
		string temp = infix;
		if (temp.find('(') == std::string::npos && temp.find(')') == std::string::npos)
			return true;
		if (temp.find("()") >= 0 && temp.find("()") <= temp.length())
		{
			throw "Detected is ''()''";
		}
		while (temp.find('(') != std::string::npos || temp.find(')') != std::string::npos)
		{
			if (temp.find('(') >= 0 && temp.find('(') <= temp.length())
				if (temp.find(')') == std::string::npos)
				{
					throw "Incorrect number of brackets";
				}
				else
				{
					temp[temp.find('(')] = ' ';
					temp[temp.find(')')] = ' ';
				}
			else throw "Incorrect number of brackets";
		}
		return true;
	}
	bool CheckInfix() // Общая проверка
	{
		CheckChars();
		CheckAmount();
		CheckBrackets();
		if (infix[0] == ')' || infix[0] == '*' || infix[0] == '/' || infix[0] == '-' || infix[0] == '+')
			throw "First character is operations";
		if (infix[infix.length() - 1] == '(' || infix[infix.length() - 1] == '*' || infix[infix.length() - 1] == '/' || infix[infix.length() - 1] == '-' || infix[infix.length() - 1] == '+')
			throw "Last character is operations";
		return true;
	}
	void ArrVarible() // Выделение из строки переменных и добавление их в массив
	{
		string inf = infix;
		size_t size = 0;
		CheckInfix();
		inf = inf + "=";
		for (int i = 0; i < inf.size(); i++)
			if (inf[i] == '+' || inf[i] == '-' || inf[i] == '*' || inf[i] == '/' || inf[i] == '=')
				size++;
		variable = new string[size];
		for (int i = 0; i < size; i++)
			variable[i] = "";
		varSize = size;
		int k = 0;
		for (int i = 0; i < inf.length(); i++)
		{
			if (inf[i] == '+' || inf[i] == '-' || inf[i] == '*' || inf[i] == '/' || inf[i] == '=')
				inf[i] = ' ';
		}
		while (inf.find('(') != std::string::npos || inf.find(')') != std::string::npos)
		{
			if (inf.find(')') >= 0 && inf.find(')') <= inf.length())
				inf.erase(inf.find(')'), 1);
			if (inf.find('(') >= 0 && inf.find('(') <= inf.length())
				inf.erase(inf.find('('), 1);
		}
		while (inf.length() != 0)
		{
			if (inf.find(' ') >= 0 && inf.find(' ') <= inf.length())
			{
				size_t pos = inf.find(' ');
				for (int j = 0; j < pos; j++)
				{
					variable[k] += inf[j];
				}
				inf.erase(0, pos + 1);
				k++;
			}
		}
	}
	string ToPostfix()
	{
		string inf = infix;
		postfix = "";
		CheckInfix();
		ArrVarible();
		inf = inf + "=";
		TStack<char> operations(MaxSizeString);
		int i = 0;
		while (inf.length() != 0)
		{
			while (i < varSize)
			{
				if (inf.find(variable[i]) == 0)
				{
					postfix += variable[i] + ' ';
					inf.erase(0, variable[i].length());
					i++;
					break;
				}
				else
					break;
				i++;
			}

			if (inf[0] == '(')
			{
				operations.Put('(');
				inf.erase(0, 1);
			}

			if (inf[0] == functions.func[2] || inf[0] == functions.func[3] || inf[0] == functions.func[4] || inf[0] == functions.func[5])
			{
				while (true)
				{
					if (operations.IsEmpty())
					{
						operations.Put(inf[0]);
						break;
					}
					int i = 2;
					int j = 2;
					while (i < 6)
					{
						if (inf[0] == functions.func[i])
							break;
						else
							i++;
					}
					while (j < 6)
					{
						if (operations.GetValTop() == functions.func[j])
							break;
						else
							j++;
					}
					if (functions.priority[i] <= functions.priority[j])
					{
						postfix += operations.Get();
						operations.Put(inf[0]);
						break;
					}
					else
					{
						operations.Put(inf[0]);
						break;
					}

				}
				inf.erase(0, 1);
			}

			if (inf[0] == ')')
			{
				while (operations.GetValTop() != '(')
					postfix += operations.Get();
				operations.Get();
				inf.erase(0, 1);
			}

			if (inf[0] == '=')
			{
				while (operations.IsEmpty() != true)
					postfix += operations.Get();
				inf.erase(0, 1);
			}
		}
		return postfix;
	}
	double Calculate() // Ввод переменных, вычисление по постфиксной форме
	{
		cout << "Enter the arguments:" << endl;
		double* var = new double[varSize];
		for (int i = 0; i < varSize; i++)
		{

			string ce = "0123456789.";
			int j = 0;
			while (j < variable[i].length())
			{
				if (ce.find(variable[i][j]) != std::string::npos)
					j++;
				else
					break;
			}
			if (j == variable[i].length())
			{
				std::stringstream temp(variable[i]);
				temp >> var[i];
			}
			else
			{

				cout << variable[i] << " = ";
				cin >> var[i];
				string c = "0123456789.";
				if (c.find(var[i]) != std::string::npos)
					throw "Permission incorrect value";
				cout << endl;
			}
		}
		string post = postfix;
		for (int i = 0; i < post.size(); i++)
			if (post[i] == ' ')
				post.erase(i, 1);
		double tempResult = 0;
		double result = 0;
		TStack<double> varStack(varSize);
		int i = 0;
		while (post.length() != 0)
		{
			while (i < varSize)
			{
				if (post.find(variable[i]) == 0)
				{
					varStack.Put(var[i]);
					post.erase(0, variable[i].length());
					i++;
					break;
				}
				else
					break;
			}

			if (post[0] == '*')
			{
				double temp = varStack.Get();
				tempResult = varStack.Get() * temp;
				varStack.Put(tempResult);
				post.erase(0, 1);
			}

			if (post[0] == '/')
			{
				double temp = varStack.Get();
				tempResult = varStack.Get() / temp;
				varStack.Put(tempResult);
				post.erase(0, 1);
			}

			if (post[0] == '+')
			{
				double temp = varStack.Get();
				tempResult = varStack.Get() + temp;
				varStack.Put(tempResult);
				post.erase(0, 1);
			}

			if (post[0] == '-')
			{
				double temp = varStack.Get();
				tempResult = varStack.Get() - temp;
				varStack.Put(tempResult);
				post.erase(0, 1);
			}
		}
		return result = varStack.Get();
	}
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	string* GetArrVar() { return variable; }

};

#endif