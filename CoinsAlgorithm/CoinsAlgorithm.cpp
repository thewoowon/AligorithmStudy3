
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<long>> min_calc(long long value, vector<long> coins) {
	long long total = 0;
	vector<vector<long>> cnt_list;
	sort(coins.begin(), coins.end());
	reverse(coins.begin(), coins.end()); // 역순으로 바꾼다

	for (int i = 0; i < coins.size(); i++) // 입력 받은 코인들의 개수 만큼 반복문 실행
	{
		vector<long> temp;
		total = value / coins[i]; // 입력받은 값을 나눈 몫을 반환한다.
		temp.push_back(coins[i]); // 해당 코인의 값
		temp.push_back(total); // 해당 코인의 사용 개수
		cnt_list.push_back(temp); // 해당 벡터를 넣어주고
		value -= total * coins[i]; // 해당 나머지 금액으로 재할당
	}

	return  cnt_list;
}

int main()
{
	vector<vector<long>> temp = min_calc(11234567899, { 500,300,40,20,1 });

	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i][0] << " ," << temp[i][1] << endl;
	}
	return 0;
}
