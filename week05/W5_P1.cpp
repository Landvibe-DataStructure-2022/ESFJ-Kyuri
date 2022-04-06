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

	void erase(node* pos) {
		pos->next->prev = pos->prev;
		pos->prev->next = pos->next;
		delete pos;
		n--;
	}
	
	void print() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}

		for (node* p = begin(); p != end(); p = p->next) {
			cout << p->data << " ";
		}
		cout << endl;
	}

	void find(int e) {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}

		bool isFound = false;
		node* p = begin();
		for (int i = 0; i < n; i++) {
			if (p->data == e) {
				cout << i << " ";
				isFound = true;
			}
			p = p->next;
		}

		if (!isFound)
			cout << -1 << endl;
		else
			cout << endl;
	}
};

int main() {
	nodeList list;
	node* p = list.begin();

	int m;
	cin >> m;
	while (m--) {
		string cmd;
		cin >> cmd;

		if (cmd == "begin") {
			p = list.begin();
		}
		else if (cmd == "end") {
			p = list.end();
		}
		else if (cmd == "insert") {
			if (p != list.begin()->prev) {
				int e;
				cin >> e;
				list.insert(p, e);
			}
		}
		else if (cmd == "erase") {
			if (p != list.begin()->prev || p != list.end()) {
				list.erase(p);
				p = list.begin();
			}
		}
		else if (cmd == "++") {
			if (p != list.end())
				p = p->next;
		}
		else if (cmd == "--") {
			if(p != list.begin()->prev)
				p = p->prev;
		}
		else if (cmd == "print") {
			list.print();
		}
		else if (cmd == "find") {
			int e;
			cin >> e;
			list.find(e);
		}
	}
}