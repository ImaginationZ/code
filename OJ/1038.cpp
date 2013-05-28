#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct node{
	long long num;
	node *next;
};

int main() {
	long long m;
	cin >> m;
	node *head = new node;
	node *p = head;
	node *tmp;
	head->num = 1;
	for (long long i=1;i<m;++i){
		tmp = p;
		p->next = new node;
		p = p->next;
		p->num = i+1;
	}
	p->next  = head;
	while (m>1){
		long long kn;
		cin >> kn;
		--kn;
		kn %= m;
		++kn;
		for (long long i=0;i<kn;++i){
			tmp = p;
			p = p->next;
		}
		tmp->next = p->next;
		delete p;
		p = tmp;
		--m;
	}
	cout << p->num;

    return 0;
}
