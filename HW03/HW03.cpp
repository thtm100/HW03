#include <iostream>
using namespace std;

#include "simplevector.h"
#include <algorithm>

int main() {
	// 생성자 테스트
	SimpleVector<int> vec(5); // 여기서 템플릿 타입을 지정해줘야 한다!
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	vec.getData();

	// push_back 테스트
	cout << "===원소 추가===" << endl;
	vec.push_back(55);
	vec.push_back(33);
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	vec.getData();

	// pop_back 테스트
	cout << "===원소 제거===" << endl;
	vec.pop_back();
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	vec.getData();


	// pop_back 한뒤 다시 push_back 테스트
	cout << "===원소 제거 후 다시 추가하면?===" << endl;
	vec.push_back(2);
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	vec.getData();


	// 도전 기능 테스트
	vec.push_back(0);
	vec.push_back(0);
	vec.push_back(0);
	vec.getData(); // 원소 5개 full

	// sortData 정렬 테스트
	vec.sortData();
	vec.getData(); 

	// full인 상태에서 push_back + resize 테스트
	vec.push_back(117);
	vec.getData();
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;

	return 0;
}