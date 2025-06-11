#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_

#include <algorithm> // sortData()
using namespace std;
template <typename T> // ���ø� ����
class SimpleVector {
private:
	T* data; // T Ÿ���� ���� �迭�� ����Ű�� ������
	int currentSize;
	int currentCapacity;

	// �ʼ���� �ܰ迡���� ���ʿ�
	
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
			cout << "���� �迭 ũ�⺸�� �۾� ���Ҵ� �Ұ�" << endl;
		}
	}
	

public:
	SimpleVector(int capacity = 10) {
		this->currentSize = 0;
		this->currentCapacity = capacity;
		data = new T[capacity];
	}

	// ���� ������
	// ���Կ��꿡�� �ڵ����� �������� "���� ����"
	// "���� ����"�� ���� ���
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
			cout << "������ ���� ����." << endl;
		}
	}

	int size() {
		return currentSize; // �̰ɷθ� �������� �ð��پ��
	}

	int capacity() {
		return currentCapacity; // �� capacity�� ��� �ϴ� ����
	}

	void sortData() {
		std::sort(data, data + currentSize); // data �� �ּ�
	}

	// �迭 Ȯ�ο�
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

