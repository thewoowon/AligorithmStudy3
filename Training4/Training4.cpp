

#include <iostream>
#include <forward_list>
#include <vector>

using namespace std;


int main()
{
	vector<string> vec = { "Lewis Hamilton" ,"Lewis  Hamilton", "Nico Roseberg",
							"Sebastian Vettel", "Lewis Hamilton","Sebatstian Vettel",
							"Sebastian Vettel", "Sebastian Vettel", "Fernando Alonso"};

	auto it = vec.begin(); // 벡터 첫번째 인덱스의 참조값을 가져온다.
	cout << "가장 최근 우승자 : " << *it << endl; // 

	it += 8; // 총 9개의 원소가 들어 있기 때문에 -> +8은 9번째 원소의 참조를 리턴한다.
	cout << "8년 전 우승자 : " << *it << endl; // 내림차순으로 정리한 배열이라서 8년전의 우승자가 가장 뒤에 있다.

	advance(it, -3);// 8년 전의 시점에서 advance함수는 첫번째 인수로 참조를 받고, 두번째는 offset을 입력받는다 -> advacnce는 참조를 이동시킨다. 
	cout << "그후 3년 뒤 우승자 : " << *it << endl; // 8년 전의 시점에서 3년 뒤 우승자가 출력된다.

	forward_list<string> fwd(vec.begin(), vec.end()); // 연결리스트 생성 및 초기화

	auto it1 = fwd.begin(); // 첫번째 참조자를 입력받는다.
	cout << "가장 최근 우승자 : " << *it1 << endl; // 처음

	advance(it1, 5);
	cout << "5년 전 우승자 : " << *it1 << endl;
}

