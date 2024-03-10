#include<iostream>
#include<ostream>
using namespace std;
template<class T>
class Node{
	T data;
	Node* link;
	public:
		Node(T);
		T get_data();
		void set_link(Node* link);
		Node* get_link();
		void set_data(T);
};
template<class T>
class LinkedList{
	Node<T>* head;
	public:
		void createLL();
		void display();
		void insert_at_front(T);
		void insert_at_end(T);
		void insert_after_key(T ,T );
		void insert_before_key(T ,T );
		void delete_from_front();
		void delete_from_end();
		void delete_key(T);
		void concatenation(LinkedList & l);
		void searching(T);
		void reverse();
		void reverse_traversal(Node<T>* node);
		void reverse_traversal();
		void sorting();
		template<class U>
		friend ostream & operator <<(ostream &,LinkedList<U>);
};
