#include <vector>

using namespace std;
//[[1, 1, 1, 0], [1, 2, 2, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 3], [0, 0, 0, 3]]
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {

    vector<vector<int>> pictureCopy(m, vector<int>(n, 0)); // 똑같은 크기의 캔버스 생성
    vector<bool> boolV1(n,false); // 내부를 false로 모두 초기화 // 레이어 조사
    vector<bool> boolV2(n,false); // 내부를 false로 모두 초기화 // 레이어 조사
    vector<int> remember;

    int now = -1; // 
    int pre = -1;


    while (true)
    {
        for (int i = 0; i < m; i++) // 행만큼 조사
        {
            for (int j = 0; j < n; j++) // 내부의 원소 조사
            {
                if (picture[i][j] == 0)
                {
                    pictureCopy[i][j] == -1; // -1을 할당함 필요없다는 뜻임
                }
                else
                {
                    now = picture[i][j];
                }

                if (pre != -1) // 이전 값이 -1라면 
                {
                    
                }
                else
                {
                    
                }
                // 연결되어 있는 것이면 boolV1에 true 삽입;
                picture[i][j]; //

            }
        }
    }

    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}


int main()
{
    return 0;
}