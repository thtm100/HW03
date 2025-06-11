#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_

#include <algorithm> // sortData()
using namespace std;
template <typename T> // 템플릿 선언
class SimpleVector {
private:
	T* data; // T 타입의 동적 배열을 가리키는 포인터
	int currentSize;
	int currentCapacity;

	// 필수기능 단계에서는 불필요
	
	void resize(int newCapacity) {
		if (newCapacity > currentCapacity) {
			T* tempData = data;
			data = new T[newCapacity];
			for (int i = 0; i < currentSize; ++i) {
				data[i] = tempData[i];
			}
			currentCapacity = newCapacity;
			delete[] tempData;
		}
		else {
			cout << "현재 배열 크기보다 작아 재할당 불가" << endl;
		}
	}
	

public:
	SimpleVector(int capacity = 10) {
		this->currentSize = 0;
		this->currentCapacity = capacity;
		data = new T[capacity];
	}

	// 복사 생성자
	// 대입연산에서 자동으로 해주지만 "얕은 복사"
	// "깊은 복사"를 위한 명시
	SimpleVector(const SimpleVector& other) :
		currentSize(other.currentSize), currentCapacity(other.currentCapacity)
	{
		data = new T[other.currentCapacity];
		for (int i = 0; i < other.currentSize; ++i) {
			data[i] = other.data[i];
		}
	}

	void push_back(const T& value) {
		if (currentSize >= currentCapacity) {
			resize(currentCapacity + 5);
		}
		else {
			data[currentSize] = value;
			currentSize++;
		}
		
	}

	void pop_back() {
		if (currentSize != 0) {
			currentSize--;
		}
		else {
			cout << "제거할 원소 없음." << endl;
		}
	}

	int size() {
		return currentSize; // 이걸로만 논리적으로 늘고줄어듬
	}

	int capacity() {
		return currentCapacity; // 이 capacity는 사실 일단 고정
	}

	void sortData() {
		std::sort(data, data + currentSize); // data 가 주소
	}

	// 배열 확인용
	void getData() {
		for (int i = 0; i < currentCapacity; ++i) {
			cout << data[i] << " ";
		}
		cout << endl;
	}

	~SimpleVector() {
		delete[] data;
	}
};

#endif

