#include <iostream>
#include <vector>
using namespace std;

struct compare {
	bool operator()(const int& e1, const int& e2) const {
		return e1 < e2;
	}
};

class unsortedSeqPQ {
public:
	int size() {
		return seq.size();
	};
	bool empty() {
		return (seq.size() == 0);
	}
	void insert(int e) {
		seq.push_back(e);
	}
	int min() {
		if (empty()) return -1;

		compare C;
		int minVal = seq[0];

		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], minVal)) {
				minVal = seq[i];
			}
		}

		return minVal;
	}

	void removeMin() {
		if (empty()) return;

		compare C;
		int minIdx = 0;

		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], seq[minIdx])) {
				minIdx = i;
			}
		}
		cout << seq[minIdx] << " ";
		
		seq.erase(seq.begin() + minIdx);
	}

private:
	vector<int> seq;
};

int main() {
	int t, N, n;
	cin >> t;

	while (t--) {
		unsortedSeqPQ* pq = new unsortedSeqPQ;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> n;
			pq->insert(n);
		}
		
		for (int i = 0; i < N; i++) {
			pq->removeMin();
		}
		cout << endl;

		delete pq;
	}
}