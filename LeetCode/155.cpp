#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
class MinStack
{
public:
    struct Element
    {
        int val;
        int minnum; // 当前栈中最小值
    } element;
    int len = 0;
    vector<struct Element> v;
    MinStack()
    {
        v.clear();
    }

    void push(int val)
    {
        element.val = val;
        if (len == 0)
        {
            element.minnum = val;
        }
        else
        {
            element.minnum = min(v.back().minnum, val);
        }
        len++;
        v.push_back(element);
    }

    void pop()
    {

        v.pop_back();
        len--;
    }

    int top()
    {
        return v.back().val;
    }

    int getMin()
    {
        return v.back().minnum;
    }
    void print()
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << "val: " << v[i].val << " | minnum: " << v[i].minnum << endl;
        }
    }
};

int main()
{
    MinStack *minStack = new MinStack();
    string x;
    cin >> x;
    while (x != "-1")
    {
        if (x == "push")
        {
            int num;
            cin >> num;
            minStack->push(num);
        }
        else if (x == "pop")
        {
            minStack->pop();
        }
        else if (x == "t")
        {
            cout << "top: " << minStack->top() << endl;
        }
        else if (x == "g")
        {
            cout << "min: " << minStack->getMin() << endl;
        }
        else if (x == "p")
        {
            minStack->print();
        }
        cin >> x;
    }
    return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */