#ifndef __VECTOR__H_
#define __VECTOR__H_

typedef unsigned int uint;

#define DYNARRAY_BLOCK_SIZE 16

template <class T> 
class DynArray {
private:
	T* buffer;
	uint capacity;
	uint num_elements;

	T* alloc(uint size)
	{
		uint mem_size = DYNARRAY_BLOCK_SIZE*(size / DYNARRAY_BLOCK_SIZE + 1);
		T* new_buffer = new T[mem_size];

		return new_buffer;
	}

public:
	DynArray(): 
		capacity(DYNARRAY_BLOCK_SIZE),
		num_elements(0)
	{
		buffer = new T[DYNARRAY_BLOCK_SIZE];
	}

	DynArray(uint _num_elements){

		uint mem_size = DYNARRAY_BLOCK_SIZE*(_num_elements / DYNARRAY_BLOCK_SIZE + 1);

		buffer = new T[mem_size];
		capacity = mem_size;
		num_elements = 0;
	}

	
	~DynArray(){
		if (buffer != nullptr){
			delete[] buffer;
			buffer = nullptr;
		}
	}

	//copy constructor

	DynArray(const DynArray& D){
		capacity = D.capacity;
		num_elements = D.num_elements;
		buffer = new T[capacity];

		for (int i = 0; i < num_elements; i++){
			buffer[i] = D.buffer[i];
		}
	}

	uint size()const{
		return num_elements;
	}

	void push_back(const T& item){
		T* tmp = buffer;
		buffer = alloc(num_elements + 1);
		for (int i = 0; i < num_elements; ++i)
			buffer[i] = tmp[i];
		buffer[num_elements] = item;
		num_elements++;
		delete[] tmp;
	}

	void push_front(const T& item){
		T* tmp = buffer;
		buffer[0] = item;
		buffer = alloc(num_elements + 1);
		for (int i = 1; i <= num_elements; ++i)
			buffer[i] = tmp[i];
		
		num_elements++;
		delete[] tmp;
	}

	bool pop_back(T& item){

		if (num_elements > 0){
			--num_elements;
			item = buffer[num_elements];
			return true;
		}

		return false;
	}

	operator[](uint index){
		assert(index < num_elements);


	}
	
	
};

#endif