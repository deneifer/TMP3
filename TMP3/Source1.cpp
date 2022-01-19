#include <iostream>
#include <new>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Node {
	string val;
	Node* next;

	Node(string _val) : val(_val), next(nullptr) {}
};

struct list {
	Node* first;
	Node* last;

	list() : first(nullptr), last(nullptr) {}

	bool is_empty() {
		return first == nullptr;
	}

	void push_back(string _val) {
		Node* p = new Node(_val);
		if (is_empty()) {
			first = p;
			last = p;
			return;
		}
		last->next = p;
		last = p;
	}

	Node* find(string _val) {
		Node* p = first;
		while (p && p->val != _val) p = p->next;
		return (p && p->val == _val) ? p : nullptr;
	}

	void remove_first() {
		if (is_empty()) return;
		Node* p = first;
		first = p->next;
		delete p;
	}

	void remove_last() {
		if (is_empty()) return;
		if (first == last) {
			remove_first();
			return;
		}
		Node* p = first;
		while (p->next != last) p = p->next;
		p->next = nullptr;
		delete last;
		last = p;
	}

	void remove(string _val) {
		if (is_empty()) return;
		if (first->val == _val) {
			remove_first();
			return;
		}
		else if (last->val == _val) {
			remove_last();
			return;
		}
		Node* slow = first;
		Node* fast = first->next;
		while (fast && fast->val != _val) {
			fast = fast->next;
			slow = slow->next;
		}
		if (!fast) {
			cout << "not exist" << endl;
			return;
		}
		slow->next = fast->next;
		delete fast;
	}

	void replace(list l, string _val1, string _val2)
	{
		string temp;
		temp = l.find(_val2)->val;
		l.find(_val2)->val = l.find(_val1)->val;
		l.find(_val1)->val = temp;
	}

	Node* operator[] (const int index) {
		if (is_empty()) return nullptr;
		Node* p = first;
		for (int i = 0; i < index; i++) {
			p = p->next;
			if (!p) return nullptr;
		}
		return p;
	}

	void print() {
		if (is_empty()) return;
		Node* p = first;
		while (p) {
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	list l;
	cout << l.is_empty() << endl;
	string s;
	int count = 0;

	cout << "Для добавление элемента в список введите - 1" << endl;
	cout << "Для поиска элемента по его номеру введите - 2" << endl;
	cout << "Для удаления элемента из списка введите - 3" << endl;
	cout << "Чтобы поменять элементы местами введите - 4" << endl;
	cout << "Для отображения списка введите - 5" << endl;
	cout << "Для выхода введите - 0" << endl;

	while (count == 0)
	{

		cin >> s;
		if (s == "1")
		{
			string str;
			cout << endl << "Введите элемент: ";
			cin >> str;
			l.push_back(str);
			cout << endl;
		}
		if (s == "2")
		{
			cout << "Введите номер элемента из списка для его отображения: ";
			int num = 0;
			cin >> num;
			cout << l[num]->val << endl;
			//l.print();
		}
		if (s == "3")
		{
			cout << endl << "Введите значение элемента для его удаления: ";
			string str;
			cin >> str;
			l.remove(str);
			cout << endl;
		}
		if (s == "4")
		{
			cout << endl << "Введите поочередно значения элементов, чтобы поменять их местами в списке: " << endl;
			string st1, st2;
			cin >> st1;
			cin >> st2;
			l.replace(l, st1, st2);
			cout << endl;
		}
		if (s == "5")
		{
			cout << endl << "Весь список: ";
			l.print();
			cout << endl;
		}
		if (s == "0")
		{
			count++;
		}
	}
	/*l.push_back("123");
	l.push_back("8");
	cout << l.is_empty() << endl;
	l.print();

	l.remove("3");
	l.print();
	cout << l.find("8")->val << endl;
	l.replace(l,"123","8");
	l.print();*/

	system("PAUSE");
	return 0;
}