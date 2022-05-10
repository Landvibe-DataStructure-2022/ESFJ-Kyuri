#include <iostream>
#include <vector>
using namespace std;

class heap {
public:
	heap() {
		arr.push_back(0);
	}
	int size() {
		return arr.size() - 1;
	}
	bool empty() {
		return (arr.size() == 1);
	}
	void insert(int e) {
		arr.push_back(e);
		upHeap(size());
	}
	int min() {
		if (empty()) return -1;

		return arr[1];
	}
	void removeMin() {
		if (empty())
			cout << -1 << endl;
		else {
			cout << min() << endl;
			swap(1, size());
			arr.pop_back();
			downHeap(1);
		}
	}

	void print() {
		if (empty()) cout << -1 << endl;
		else {
			for (int i = 0; i < size(); i++) {
				cout << arr[i + 1] << " ";
			}
			cout << endl;
		}
	}

private:
	vector<int> arr;

	void swap(int idx1, int idx2) {
		arr[0] = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = arr[0];
	}
	void upHeap(int idx) {
		if (empty()) return;

		int parent = idx / 2;
		if (arr[parent] > arr[idx]) {
			swap(parent, idx);
			upHeap(parent);
		}

	}
	void downHeap(int idx) {
		int left = 2 * idx;
		int right = 2 * idx + 1;
		int child;

		if (left > size()) {
			return;
		}
		else if (left == size()) {
			child = left;
		}
		else {
			if (arr[left] >= arr[right]) child = right;
			else child = left;
		}

		if (arr[child] < arr[idx]) {
			swap(child, idx);
			downHeap(child);
		}
	}

};

int main() {
	int T, i;
	string cmd;
	heap pq;

	cin >> T;
	while (T--) {
		cin >> cmd;
		if (cmd == "insert") {
			cin >> i;
			pq.insert(i);
		}
		else if (cmd == "size") {
			cout << pq.size() << endl;
		}
		else if (cmd == "isEmpty") {
			cout << pq.empty() << endl;
		}
		else if (cmd == "pop") {
			pq.removeMin();
		}
		else if (cmd == "top") {
			cout << pq.min() << endl;
		}
		else if (cmd == "print") {
			pq.print();
		}
	}
}