
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<string> solution2(vector<string> record) {
    map<string, string> m;
    vector<string> split;
    vector<vector<string>> splitData;
    vector<string> answer;
    for (size_t i = 0; i < record.size(); i++)
    {
        string temp = record[i];
        size_t previous = 0, current;
        current = temp.find(' ');
        split.clear();
        while (current != string::npos)
        {
            string substring = temp.substr(previous, current - previous);
            split.push_back(substring);
            previous = current + 1;
            current = temp.find(' ', previous);

            if (current == string::npos)
            {
                string substring2 = temp.substr(previous, temp.size() - previous);
                split.push_back(substring2);
            }
        }
        if (split[0] != "Leave")
        {
            m[split[1]] = split[2];
        }
        splitData.push_back(split);

    }
    for (size_t i = 0; i < splitData.size(); i++)
    {
        if (splitData[i][0] == "Enter")
        {
            answer.push_back(m[splitData[i][1]] + "님이 들어왔습니다.");
        }
        else if (splitData[i][0] == "Leave") {
            answer.push_back(m[splitData[i][1]] + "님이 나갔습니다.");
        }
        else // 변경했을 때
        {
            continue;
        }
    }

    return answer;
}

vector<string> solution(vector<string> record) {

    //일단 중요한 것은 들어 올때, 변경했을 때이다
    vector<string> answer;
    vector<vector<string>> splitData;
    vector<string> split;
    vector<vector <string>> changeVector;

    for (size_t i = 0; i < record.size(); i++)
    {
        string temp = record[i];
        size_t previous = 0, current;
        current = temp.find(' ');
        split.clear();
        while (current != string::npos)
        {
            string substring = temp.substr(previous, current - previous);
            split.push_back(substring);
            previous = current + 1;
            current = temp.find(' ', previous);

            if (current == string::npos)
            {
                string substring2 = temp.substr(previous, temp.size() - previous);
                split.push_back(substring2);
            }
        }
        if (split[0] == "Change" || split[0] == "Enter")
        {
            changeVector.push_back(split); // -> 일단 들어왔을 때, 바꾸었을때 저장
        }
        else // 떠났을 때
        {
            for (size_t i = 0; i < splitData.size(); i++)
            {
                if (splitData[i][1] == split[1])
                {
                    //일치하면
                    split.push_back(splitData[i][2]);
                    break;
                }
            }
        }
        splitData.push_back(split);
    } // 분리해서 로 입력해 놓은 상태 Generic은 벡터

    // Change
    // Enter
    // Exit 
    // senario 1. 가장 먼저 전역으로 탐색하면서 change를 확인한다. -> change

    for (size_t i = 0; i < changeVector.size(); i++)
    {
        for (size_t j = 0; j < splitData.size(); j++)
        {
            if (splitData[j][1] == changeVector[i][1])
            {
                 // 아이디가 일치하면
                splitData[j][2] = changeVector[i][2];
            }
        }
    }

    for (size_t i = 0; i < splitData.size(); i++)
    {
        if (splitData[i][0] == "Enter")
        {
            answer.push_back(splitData[i][2] + "님이 들어왔습니다.");
        }
        else if (splitData[i][0] == "Leave") {
            answer.push_back(splitData[i][2] + "님이 나갔습니다.");
        }
        else // 변경했을 때
        {
            continue;
        }
    }
    return answer;
}

int main()
{

    vector<string> v = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };

    vector<string> answer = solution2(v);
    for (size_t i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
}


