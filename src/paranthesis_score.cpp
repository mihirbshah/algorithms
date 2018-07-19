/*
 * paranthesis_score.cpp
 *
 *  Created on: Jul 17, 2018
 *      Author: mihir
 *
 *  https://leetcode.com/problems/score-of-parentheses/description/
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;
using pstack = stack<int>;

void disp_stack(const pstack& stk)
{
	pstack st = stk;
	cout << "stack: [" << stk.size() << "]: ";
	while (!st.empty())
	{
		int t = st.top();
		cout << t << ", ";
		st.pop();
	}
}

int check_n_apply_addition(pstack& stk, int v)
{
	if (!stk.empty() && stk.top() == '+')
	{
		stk.pop();
		v += stk.top();
		stk.pop();
	}
	return v;
}

int check_n_apply_multiplication(pstack& stk, int v)
{
	if (!stk.empty() && stk.top() == '(')
	{
		stk.pop();
		v = 2 * v;
	}
	return v;
}

int paranthesis_score(const string& s)
{
	pstack stk;
	int v = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		const char& tok = s[i];

		// If we get '(', we just push it. It will be later used when we encounter its matching
		// ')' to decide how to evaluate it
		if (tok == '(')
			stk.push(tok);
		// If we get ')', there are 2 main cases we need to consider -
		else if (tok == ')')
		{
			int t = stk.top();
			// case 1: If stack top = '(', that means we have a () pair which evaluates to 1.
			// There could have been another such pair right before it as - ()().
			// In this case, the stack would look like - (, +, 1 indicating that after matching
			// '(', we need to further add the result with left operand of + on stack. Thus, we
			// 'consume' any addition operations we find here.
			if (t == '(')
			{
				stk.pop();
				v = 1;
				v = check_n_apply_addition(stk, v);
				stk.push(v);
			}
			// case 2: If stack top is a number, then it can occur in 2 contexts -
			//   a. (number): In which case we need to do 2 * number i.e consume multiplication
			//   b. () + number: Which boils down to number1 + number2 i.e. consume addition
			else if (t != '(' && t != '+')
			{
				v = t;
				stk.pop();
				v = check_n_apply_multiplication(stk, v);
				v = check_n_apply_addition(stk, v);
				stk.push(v);
			}

			// If we find a '(' immediately after current ')' token, then it means its a ()(...) pair.
			// In this case, we need to push a + to perform () + (...) at a later stage when (...) gets
			// evaluated
			if (i < s.size() && s[i+1] == '(')
				stk.push('+');
		}
	}

	return stk.top();
}

/*
int main()
{
	for (auto s : {"()", "(())", "()()", "((()))", "((())(()))", "(()())", "()(())", "()()(())"})
		cout << "paranthesis score for [" << s << "]: " << paranthesis_score(s) << "\n";
}
*/
