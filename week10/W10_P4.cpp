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
		if (empty()) return;

		swap(1, size());
		arr.pop_back();
		downHeap(1);
	}

	void mix(int p) {
		int cnt = 0;
		bool isPossible = false;

		while (true) {
			if (min() >= p) {
				isPossible = true;
				break;
			}
			if (size() == 1) {
				break;
			}

			int k1 = min();
			removeMin();
			int k2 = min();
			removeMin();

			insert((k1 + k2) / 2);
			cnt++;
		}

		if (isPossible) {
			cout << "True" << endl;
			this->print();
		}
		else {
			cout << "False" << endl;
		}
	}

	void print() {
		if (empty()) return;
		else {
			for (int i = 0; i < size(); i++) {
				cout << arr[i + 1] << " ";
			}
		}
		cout << endl;
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
			if (arr[left] <= arr[right]) child = left;
			else child = right;
		}

		if (arr[child] < arr[idx]) {
			swap(child, idx);
			downHeap(child);
		}
	}
};

int main() {
	int t, k, n, p;
	cin >> t;
	while (t--) {
		heap* pq = new heap;

		cin >> n >> p;
		while (n--) {
			cin >> k;
			pq->insert(k);
		}
		pq->mix(p);

		delete pq;
	}
}