#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution2(string s)
{
    int answer = 0;

    for (size_t i = 1 ; i <= s.size(); i++) // 사이즈만큼
    {
        string clone = s;
        vector<string> v;
        for (size_t j = 0; j < s.size(); j++) // 처음 자르는 것은 문제가 없음
        {
            if (s.size()-(i*j) > i) 
            {
                v.push_back(clone.substr(j * i, i)); // 클론으로부터 추출
            }
            else // 남은 길이가 작다면
            {
                v.push_back(clone.substr(j * i, s.size() - (i * j))); // 클론으로부터 추출
                break;
            }
        }

        int dupleCount = 1;
        string pre;
        string now;
        string complete;
        bool sw = true;

        for (size_t k = 0; k < v.size(); k++) // 같은 친구가 들어오면
        {
            if (v.size()== 1)
            {
                complete = v[0];
                break;
            }
            if (v[0].size() == v[1].size()) // 길이가 다르면 의미가 없음
            {
                if (k==0)
                {
                    pre = v[k];
                    now = v[k];
                }
                else
                {
                    now = v[k];
                    if (pre == now)
                    {
                        dupleCount++;
                    }
                    else
                    {
                        if (dupleCount == 1)
                        {
                            complete += pre;
                        }
                        else
                        {
                            complete += to_string(dupleCount) + pre;
                        }
                        dupleCount = 1;
                    }
                }
                pre = now;

                if (k == v.size() -1)
                {
                    if (dupleCount == 1)
                    {
                        complete += pre;
                    }
                    else
                    {
                        complete += to_string(dupleCount) + pre;
                    }
                }
            }
            else
            {
                sw = false;
                break;
            }
        }

        if (!sw)
        {
            continue;
        }

        if (answer == 0)
        {
            answer = complete.size();
        }
        else
        {
            if (answer > complete.size())
            {
                answer = complete.size();
            }
        }

    }

    return answer;
}



int solution(string s) {
    int answer = 0;

    for (size_t i = 1; i <= s.size(); i++)
    {
        string zip = "";
        string pre = "";
        string now = "";
        int count = 0;
        int dupleCount = 1;
        int leftSize = s.size();
        while (true)
        {
            
            if (leftSize < i)
            {
                if (leftSize == 0) // 길이 1일 때 같을 수도 있기 때문
                {
                    if (dupleCount == 1)
                    {
                        zip = zip + pre; // 이전것으로 채워 준다
                    }
                    else
                    {
                        zip = zip + to_string(dupleCount) + pre; // 이전것으로 채워 준다
                    }
                    dupleCount = 1;
                    break;
                }
                else // 길이  2 이상일 때 길이 다르면 무조건 다르다
                {
                    zip = zip + pre + s.substr(count * i, leftSize); // 이전것으로 채워 준다

                    break;
                }
            }

            if (count == 0)
            {
                pre = s.substr(count * i, i); // i만큼 추출
                now = s.substr(count * i, i); // i만큼 추출
            }
            else
            {
                now = s.substr(count * i, i); // i만큼 추출

                if (pre == now) // 이전과 같다면
                {
                    dupleCount++;
                }
                else
                {
                    if (dupleCount ==1)
                    {
                        zip = zip  + pre; // 이전것으로 채워 준다
                    }
                    else
                    {
                        zip = zip + to_string(dupleCount) + pre; // 이전것으로 채워 준다
                    }
                    dupleCount = 1;
                }
            }
            leftSize -= i;
            pre = now;
            count++;
        }

        if (answer == 0)
        {
            answer = zip.size();
        }
        else
        {
            if (answer > zip.size())
            {
                answer = zip.size();
            }
        }
    }

    return answer;
}


int main()
{
    cout << solution2("xababcdcdababcdcd") << endl;
    //입력받은 스트링의 자기 길이까지 비교한다.
    //cout<< solution("aaabbzxczxczxczxcasdqwe") << endl;
}

