#include <iostream>
using namespace std;

struct node {
	int data;
	node* prev;
	node* next;
};

class nodeList {
private:
	node* header;
	node* trailer;
	int n;

public:
	nodeList() {
		header = new node();
		trailer = new node();
		header->next = trailer;
		trailer->prev = header;
		header->prev = trailer->next = NULL;
		n = 0;
	}

	bool empty() {
		return (n == 0);
	}

	int size() {
		return n;
	}

	node* begin() {
		return header->next;
	}

	node* end() {
		return trailer;
	}

	void insert(node* pos, int e) {
		node* newNode = new node();
		newNode->data = e;
		newNode->next = pos;
		newNode->prev = pos->prev;
		pos->prev->next = newNode;
		pos->prev = newNode;
		n++;
	}

	void print() {
		for (node* p = begin(); p != end(); p = p->next) {
			int a = p->prev->data;
			int b = p->data;
			int c = p->next->data;
			cout << 1 * a + 3 * b + 1 * c << " ";
		}
		cout << endl;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		nodeList* list = new nodeList;
		node* p = list->begin();

		for (int i = 0; i < n; i++) {
			int e;
			cin >> e;
			list->insert(p, e);
		}

		list->print();

		delete list;
		delete p;
	}
}