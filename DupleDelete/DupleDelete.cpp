#include <iostream>
#include<string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = -1;
    string temp = s;
    vector<char> v;
    int index = 0;

    while (true)
    {

        if (index ==0)
        {
            v.push_back(temp[index]);
        }
        else
        {
            if (v.size() == 0)
            {
                v.push_back(temp[index]);
            }
            else
            {
                if (v.back() == temp[index]) // 가장 뒤와 비교해서 같으면
                {
                    v.pop_back();
                }
                else
                {
                    v.push_back(temp[index]);
                }
            }
        }

        if (index == temp.size() - 1)
        {
            break;
        }
        index++;
    }

    if (v.size() ==0)
    {
        answer = 1;
    }
    else
    {
        answer = 0;
    }

    return answer;
}


int main()
{
    int answer = solution("cdcd");
    std::cout << answer;
}