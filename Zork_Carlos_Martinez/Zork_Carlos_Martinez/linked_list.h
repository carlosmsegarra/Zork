#ifndef __VECTOR__H_
#define __VECTOR__H_


template <class T>
class LinkedList{
public:
	struct node{
	class LinkedList<T>;
	public:

		 T data;

		 const node* next() const{
			return nxt;
		}

	private:

		node* nxt = nullptr;

		node(const T& data) :data(data){}

	};

private:
	node* start = nullptr;

public:

	void clear(){
		node* current;
		node* next_;

		for (current = start; current != nullptr; current = next_){
			next_ = current->next();
			delete current;
			current = nullptr;
		}
		
		start = nullptr;
	}
	
	node* last_element(){

		node* current = start;
		node* next_ = nullptr;
		
		while (current != nullptr){
			next_ = current;
			current = current->next();
		}

		return next_;
	}

	node* push_back(const T& data){
		node* new_node;
		node* last;

		new_node = new node[data];
	}


};



#endif 