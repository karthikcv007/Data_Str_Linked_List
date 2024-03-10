#include"LinkedList.h"
template<class T>
Node<T>::Node(T data){
	this->data=data;
	this->link=NULL;
}
template<class T>
T Node<T>::get_data(){
	return data;
}
template<class T>
void Node<T>::set_link(Node* link){
	this->link=link;
}
template<class T>
Node<T>* Node<T>::get_link(){
	return link;
}
template<class T>
void Node<T>::set_data(T data){
	this->data=data;
}
template<class T>
void LinkedList<T>::createLL(){
	string option;
	T x;
	Node<T>* current;
	current=head;
	do{
		cout<<"Enter the value:";
		cin>>x;
		Node<T>* node=new Node<T>(x);
		if(head==NULL){
			head=node;
			current=head;
		}
		else{
			current->set_link(node);
			current=node;
		}
		cout<<"Do you want to enter values?(y/n):";
		cin>>option;
	}
	while(option=="y");
}
template<class T>
void LinkedList<T>::display(){
	Node<T>* t=head;
	while(t!=NULL){
		cout<<t->get_data()<<" ";
		t=t->get_link();
	}
	cout<<endl;
}
template<class T>
void LinkedList<T>::insert_at_front(T key){
	Node<T>* node=new Node<T>(key);
	node->set_data(key);
	node->set_link(head);
	head=node;
}
template<class T>
void LinkedList<T>::insert_at_end(T key){
	Node<T> *p=head;
	while(p->get_link()!=NULL){
		p=p->get_link();
	}
	Node<T>* node=new Node<T>(key);
	node->set_data(key);
	p->set_link(node);
}
template<class T>
void LinkedList<T>::insert_after_key(T key,T item){
	Node<T>* p=head;
	while(p->get_link()!=NULL && p->get_data()!=key){
		p=p->get_link();
	}
	if(p->get_link()==NULL){
		cout<<"Key not found"<<endl;
		return;
	}
	Node<T>* q=p->get_link();
	Node<T>* node=new Node<T>(item);
	node->set_data(item);
	node->set_link(q);
	p->set_link(node);
}
template<class T>
void LinkedList<T>::insert_before_key(T key,T item){
	Node<T>* p=head;
	Node<T>* q=p->get_link();
	while(q->get_link()!=NULL && q->get_data()!=key){
		p=q;
		q=q->get_link();
	}
	if(q->get_link()==NULL){
		cout<<"Key not found"<<endl;
		return;
	}
	Node<T>* node=new Node<T>(item);
	node->set_link(q);
	p->set_link(node);
}
template<class T>
void LinkedList<T>::delete_from_front(){
	Node<T>* temp=head;
	head=head->get_link();
	delete(temp);
}
template<class T>
void LinkedList<T>::delete_from_end(){
	Node<T>* p=head;
	Node<T>* q=p->get_link();
	while(q->get_link()!=NULL){
		p=q;
		q=q->get_link();
	}
	p->set_link(NULL);
	delete(q);
}
template<class T>
void LinkedList<T>::delete_key(T key){
	Node<T>*p=head;
	Node<T>* q=p->get_link();
	while(q->get_link()!=NULL && q->get_data()!=key){
		p=q;
		q=q->get_link();
	}
	/*if(p->get_data()==key){
		delete_from_front();
	}*/
	if(q->get_link()==NULL){
		cout<<"Key not present"<<endl;
	}
	p->set_link(q->get_link());
	delete(q);
}
template<class T>
void LinkedList<T>::concatenation(LinkedList & l){
	/*if(head==NULL){
		head=l.head;
		l.head=NULL;
		return;
	}
	Node<T>* p=head;
	while(p->get_link()!=NULL){
		p=p->get_link();
	}
	p->set_link(l.head);*/
	//l.head=NULL;
    Node<T>* p=head;
	Node<T>* q=l.head;
	while(p->get_link()!=NULL){
		p=p->get_link();
	}
	p->set_link(q);
	q=NULL;
	/*Node<T>* p=this->head;
	while(p->get_link()!=NULL){
		p=p->get_link();
	}
	p->set_link(l.head);*/
}
template<class T>
void LinkedList<T>::searching(T key){
	Node<T>* p=head;
	Node<T>* q=p->get_link();
	while(p->get_link()!=NULL && p->get_data()!=key){
		p=q;
		q=q->get_link();
	}
	
	if(p->get_link()==NULL){
		if(p->get_data()==key){
			cout<<"Element found \n";
		}
		else{
			cout<<"Element not found \n";
		}
	}
	else{
		cout<<"Element found \n";
	}
}
template<class T>
void LinkedList<T>::reverse(){
	Node<T>* q=head;
	Node<T>* p=NULL;
	Node<T>* r=NULL;
	while(q!=NULL){
		r=q->get_link();
		q->set_link(p);
		p=q;
		q=r;
	}
	head=p;
}
template<class T>
void LinkedList<T>::reverse_traversal(Node<T>* node){
	if(node==NULL){
		return;
	}
	reverse_traversal(node->get_link());
	cout<<node->get_data()<<" ";
}
template<class T>
void LinkedList<T>::reverse_traversal(){
	reverse_traversal(head);
}
template<class T>
void LinkedList<T>::sorting(){
	Node<T>* p=head;
	while(p!=NULL){
		Node<T>* q=p->get_link();
		while(q!=NULL){
			if(p->get_data()>q->get_data()){
				T temp=p->get_data();
				p->set_data(q->get_data());
				q->set_data(temp);
			}
			q=q->get_link();
		}
		p=p->get_link();
	}
}


