#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
#include <unordered_map>

using namespace std;


class MinStack {
public:
	int min = INT_MAX;
	stack<int> minStack;
	stack<int> base;
	MinStack() {
	}

	void push(int val) {
		if (val < min)
		{
			min = val;
		}
		base.push(val);
		minStack.push(min);
	}

	void pop() {
		base.pop();
		minStack.pop();
		if (!minStack.empty())
		{
			min = minStack.top();
		}
		else
		{
			min = INT_MAX;
		}
	}

	int top() {
		return base.top();
	}

	int getMin() {
		return min;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */