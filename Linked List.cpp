#include<iostream>
using namespace std;
class Node{
	int data;
	Node* link;
	public:
		Node(int data){
			this->data=data;
			this->link=NULL;
		}
		int get_data(){
			return data;
		}
		void set_link(Node* link){
			this->link=link;
		}
		Node* get_link(){
			return link;
		}
		void set_data(int data){
			this->data=data;
		}
};
class LinkedList{
	Node* head;
	public:
	LinkedList(){
		head=NULL;
	}
	void createLL(){
		string option;
		int x;
		Node* current;
		current=head;
		do{
			cout<<"Enter the value:";
			cin>>x;
			Node* node=new Node(x);
			if(head==NULL){
				head=node;
				current=head;
			}
			else{
				current->set_link(node);
				current=node;
			}
			cout<<"Do you want to enter numbers(Yes/No):";
			cin>>option;
		}
		while(option=="Yes");
	}
	void display(){
		Node* t=head;
		while(t!=NULL){
			cout<<t->get_data()<<"  ";
			t=t->get_link();
		}
		cout<<endl;
	}
	void insert_at_front(int key){
		Node* node=new Node(key);
		node->set_data(key);
		node->set_link(head);
		head=node;	
	}
	void insert_at_end(int key){
		Node* node=new Node(key);
		node->set_data(key);
		Node* p=head;
		while (p->get_link()!=NULL){
			p=p->get_link();
		}
		p->set_link(node);
	}
	void insert_after_key(int key,int item){
		Node* p=head;
		while(p->get_link()!=NULL && p->get_data()!=key){
			p=p->get_link();
		}
		Node* q=p->get_link();
		Node* node=new Node(item);
		node->set_data(item);
		node->set_link(q);
		p->set_link(node);
	}
	void insert_before_key(int key,int item){
		Node* p=head;
		Node* q=p->get_link();
		while (q->get_data()!=key && q->get_link()!=NULL){
			p=q;
			q=q->get_link();
		}
		Node* node=new Node(item);
		node->set_link(q);
		p->set_link(node);
		
	}
	void delete_from_front(){
		Node* temp=head;
		head=head->get_link();
		delete(temp);
	}
	void delete_from_end(){
		Node* p=head;
		Node* q=p->get_link();
		while(q->get_link()!=NULL){
			p=q;
			q=q->get_link();
		}
		p->set_link(NULL);
		delete(q);
	}
	void delete_key(int key){
		Node* p=head;
		Node* q=p->get_link();
		while(q->get_data()!=key){
			p=q;
			q=q->get_link();
		}
		p->set_link(q->get_link());
		delete(q);
	}
	void concatenation(LinkedList & l){
		Node*p=head;
		Node* q=l.head;
		while(p->get_link()!=NULL){
			p=p->get_link();
		}
		p->set_link(q);
	}
	void searching(int key){
		Node* p=head;
		Node *q=p->get_link();
		while(p->get_link()!=NULL && p->get_data()!=key){
			p=q;
			q=q->get_link();
		}
		if(p->get_link()==NULL){
			cout<<"Element not found \n";
		}
		else{
			cout<<"Element found \n";
		}
		
	}
	void reverse(){
		Node*q=head;
		Node*p =NULL;
		Node*r=NULL;
		while(q!=NULL){
			r=q->get_link();
			q->set_link(p);
			p=q;
			q=r;
		}
		head=p;
	}
	void reverse_traversal(Node * node){
		if(node==NULL){
			return;
		}
		reverse_traversal(node->get_link());
		cout<<node->get_data()<<" ";
		}
	void reverse_traversal(){
		reverse_traversal(head);
	}
	void sort(){
		Node* p=head;
		while(p!=NULL){
			Node* q=p->get_link();
			while(q!=NULL){
				if(p->get_data()>q->get_data()){
					int temp=p->get_data();
					p->set_data(q->get_data());
					q->set_data(temp);
				}
				q=q->get_link();
			}
			p=p->get_link();
		}
	}
	

		
};	
int main(){
	LinkedList l;
	l.createLL();
	l.display();
	int key;
	cout<<"Enter the data to be inserted at front:";
	cin>>key;
	l.insert_at_front(key);
	l.display();
	int key2;
	cout<<"Enter the data to be inserted at end:";
	cin>>key2;
	l.insert_at_end(key2);
	l.display();
	int key3,item1;
	cout<<"Enter the data after to insert:";
	cin>>key3;
	cout<<"Enter the data to be inserted after data "<<key3<<":";
	cin>>item1;
	l.insert_after_key(key3,item1);
	l.display();
	int key4,item2;
	cout<<"Enter the data before to insert:";
	cin>>key4;
	cout<<"Enter the data to be inserted before data "<<key4<<":";
	cin>>item2;
	l.insert_before_key(key4,item2);
	l.display();
	cout<<"After delete at front:\n";
	l.delete_from_front();
	l.display();
	cout<<"After delete at end:\n";
	l.delete_from_end();
	l.display();
	int key5;
	cout<<"Enter the key to delete:";
	cin>>key5;
	l.delete_key(key5);
	l.display();
	LinkedList l2;
	l2.createLL();
	l.concatenation(l2);
	cout<<"After concatenation:\n";
	l.display();
	int key6;
	cout<<"Enter the data to search:";
	cin>>key6;
	l.searching(key6);
	cout<<"After reverse traversal:\n";
	l.reverse_traversal();
	cout<<endl;
	cout<<"After reverse:\n";
	l.reverse();
	l.display();
	cout<<"After sorting:\n";
	l.sort();
	l.display();
	return 0;
}

