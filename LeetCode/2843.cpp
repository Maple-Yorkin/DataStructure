#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        int count = 0;
        int num1, num2, num3, num4;
        for (int i = low; i <= high; i++)
        {
            int temp = i;
            if ((i >= 1 && i <= 9))
                i = 10;
            else if ((i >= 100 && i <= 999))
                i = 1000;

            else if (temp >= 10 && temp <= 99)
            {
                num1 = temp % 10;
                temp /= 10;
                num2 = temp;
                if (num1 == num2)
                    count++;
            }
            else if (temp >= 1000 && temp <= 9999)
            {
                num1 = temp % 10;
                temp /= 10;
                num2 = temp % 10;
                temp /= 10;
                num3 = temp % 10;
                temp /= 10;
                num4 = temp;
                if (num1 + num2 == num3 + num4)
                    count++;
            }
        }
        return count;
    }
};

int main()
{
}