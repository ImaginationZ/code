#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class list{
	public:
	struct node{
		long element;
		node *next;
	}head;
	list(){
		head.next = NULL;
	}
	void add(long number){
		node *index = &head;
		while(index->next!=NULL){
			index=index->next;
		}
		index->next = new node;
		index = index->next;
		index->element = number;
		index->next =NULL;
	}
	int search(long number){
		node *index = head.next;
		node *before = &head;
		int times = 0;
		while(index!=NULL){
			++times;
			if (index->element == number){
				before->next = index->next;
				index->next = head.next;
				head.next = index;
				return times;
			}
			before = index;
			index = index->next;
		}
		return times;
	}

	void read(){
		node *index = head.next;
		while(index!=NULL){
			cout << index->element << ' ';
			index=index->next;
		}
	}


};

int main(){
	int n,m;
	long times=0;
	cin >> n;
	list list0;
	for (int i=0;i<n;++i){
	long num;
	cin >> num;
	list0.add(num);
	}
	cin >> m;
	for (int i=0;i<m;++i){
		long num;
		cin >> num;
		times += list0.search(num);
		//list0.read();
	}
	cout << times;


    return 0;
}
