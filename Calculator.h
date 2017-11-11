#pragma once
#include"Stack.h"
#include<iostream>
#include<string.h>
using namespace std;
class TCalculator
{
private:
	string infix, postfix;
	int priority(char ch)
	{
		if ((ch == '-') || (ch == '+'))
			return 1;
		if ((ch == '*') || (ch == '/'))
			return 2;
		if ((ch == '(') || (ch == ')'))
			return 0;
		if ((ch == '^'))
			return 3;
	}
	TStack<char> Stc;
public:
	void to_postfix()
	{
		postfix = "";
		Stc.ClearStack();
		string tmp = "(" + infix + ")";
		for (int i = 0; tmp.size(); i++)
		{
			if ((tmp[i] >= '0') && (tmp[i] <= '9') || (tmp[i] == '.'))
				postfix += tmp[i];
			if (tmp[i] == '(')
				Stc.Push(tmp[i]);
			if (tmp[i] == ')')
			{
				while (Stc.Top() != '(')
					postfix += Stc.Pop();
				Stc.Pop();
			}
			else if ((tmp[i] == '-') || (tmp[i] == '+') || (tmp[i] == '/') || (tmp[i] == '*') || (tmp[i] == '^'))
			{
				postfix += " ";
				if (priority(Stc.Top()) < priority(tmp[i]))
					Stc.Push(tmp[i]);
				else
				{
					while (priority(Stc.Top()) >= priority(tmp[i]))
						postfix += Stc.Pop();
					Stc.Push(tmp[i]);
				}
			}
		}
	}
};
