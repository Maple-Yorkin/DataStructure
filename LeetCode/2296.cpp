#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class TextEditor
{

public:
    stack<char> right;
    string tempstr = "";
    struct Node
    {
        Node *prev;
        char c;
        Node(char ch = '\0', Node *p = nullptr) : c(ch), prev(p) {}
    } *list, head;
    int length;
    char tempc;
    //-------------------------------------------------------------------------
    int addList(char c, Node *prev)
    {
        struct Node *ch = new struct Node(c, prev);
        ch->prev = list;
        list = ch;
        length++;
        return 1;
    }
    int deleteList()
    {
        if (list->prev == nullptr)
        {
            return 0;
        }
        else
        {
            length--;
            Node *temp = list;
            list = list->prev;
            delete temp;
            return 1;
        }
    }
    //-------------------------------------------------------------------------
    Node *tempPointer;
    TextEditor()
    {
        list = &head;
        length = 0;
    }

    void addText(string text)
    {
        for (int i = 0; i < text.size(); i++)
        {
            addList(text[i], nullptr);
        }
    }

    int deleteText(int k)
    {
        int count = 0;
        for (int i = 0; i < k; i++)
        {
            count += deleteList();
        }
        return count;
    }

    string cursorLeft(int k)
    {
        tempstr.clear();
        for (int i = 0; i < k; i++)
        {
            if (list->c == '\0')
                break;
            char c = list->c;
            right.push(c);
            deleteList();
        }
        tempPointer = list;
        for (int i = 0; i < min(10, length); i++)
        {
            tempstr += tempPointer->c;
            tempPointer = tempPointer->prev;
        }
        reverse(tempstr.begin(), tempstr.end());
        return tempstr;
    }

    string cursorRight(int k)
    {
        tempstr.clear();
        for (int i = 0; i < k; i++)
        {
            if (right.empty())
                break;
            tempc = right.top();
            right.pop();
            addList(tempc, nullptr);
        }
        tempPointer = list;
        for (int i = 0; i < min(10, length); i++)
        {
            tempstr += tempPointer->c;
            tempPointer = tempPointer->prev;
        }
        reverse(tempstr.begin(), tempstr.end());
        return tempstr;
    }

    void printLeft()
    {
        tempstr.clear();
        cout << "--------------------" << endl;
        tempPointer = list;
        for (int i = 0; i < length; i++)
        {
            tempstr += tempPointer->c;
            tempPointer = tempPointer->prev;
        }
        reverse(tempstr.begin(), tempstr.end());
        cout << tempstr << endl;
        cout << "--------------------" << endl;
    }
};

int main()
{
    TextEditor *textEditor = new TextEditor();
    string x;
    cin >> x;
    while (x != "-1")
    {
        if (x == "a")
        {
            string text;
            cin >> text;
            textEditor->addText(text);
        }
        else if (x == "d")
        {
            int n;
            cin >> n;
            cout << "删除了：" << textEditor->deleteText(n) << endl;
        }
        else if (x == "cl")
        {
            int k;
            cin >> k;
            cout << textEditor->cursorLeft(k) << endl;
        }
        else if (x == "cr")
        {
            int k;
            cin >> k;
            cout << textEditor->cursorRight(k) << endl;
        }
        else if (x == "p")
        {
            textEditor->printLeft();
        }
        cin >> x;
    }
    return 0;
}