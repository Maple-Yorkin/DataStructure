#include <iostream>
#include <vector>
using namespace std;

class BrowserHistory
{
public:
    struct HistoryStack
    {
        string s[5010];
        string *pos;
        int length;
    } historyStack;
    BrowserHistory(string homepage)
    {
        historyStack.pos = historyStack.s;
        *historyStack.pos = homepage;
        historyStack.length = 1;
    }

    void visit(string url)
    {
        int length = historyStack.length;
        for (string *i = historyStack.pos + 1; i <= historyStack.s + length - 1; ++i)
        {
            i->clear();
            historyStack.length--;
        }
        historyStack.pos++;
        *historyStack.pos = url;
        historyStack.length++;
    }

    string back(int steps)
    {
        if (steps <= historyStack.pos - historyStack.s)
        {
            historyStack.pos -= steps;
        }
        else
        {
            historyStack.pos = historyStack.s;
        }
        return *historyStack.pos;
    }

    string forward(int steps)
    {
        if (steps <= (historyStack.s + historyStack.length - 1) - historyStack.pos)
        {
            historyStack.pos += steps;
        }
        else
        {
            historyStack.pos = historyStack.s + historyStack.length - 1;
        }
        return *historyStack.pos;
    }

    void print()
    {
        cout << "此时的长度：" << historyStack.length << endl;
        cout << "此时的页面：" << *historyStack.pos << endl;
        cout << "栈底--------------------------" << endl;
        for (auto i = historyStack.s; i < historyStack.s + historyStack.length; i++)
        {
            cout << *i << endl;
        }
        cout << "栈顶--------------------------" << endl;
    }
};

int main()
{
    string str;
    cin >> str;
    BrowserHistory *browserHistory = new BrowserHistory(str);
    string x;
    cin >> x;
    while (x != "-1")
    {
        if (x == "v")
        {
            string url;
            cin >> url;
            browserHistory->visit(url);
        }
        else if (x == "b")
        {
            int steps;
            cin >> steps;
            browserHistory->back(steps);
        }
        else if (x == "f")
        {
            int steps;
            cin >> steps;
            browserHistory->forward(steps);
        }
        else if (x == "p")
        {
            browserHistory->print();
        }
        cin >> x;
    }
    return 0;
}