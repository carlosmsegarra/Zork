#ifndef __STRING__
#define __STRING__

typedef unsigned int uint;

//http://stackoverflow.com/questions/2843421/custom-string-class-c

class my_string{
	char* str;
	uint size;
	void alloc(uint length){
		str = new char[length + 1];
	}
public:
	my_string(){
		alloc(1);
		str = '\0';
	};

	my_string(const char* text){
		
		uint length = strlen(text);
		alloc(length);
		strcpy_s(str, length + 1, text);
	}

	~my_string(){
		delete[] str;
		str = nullptr;
	};

	uint length() const{ //this method cannot change anything inside the class
		return strlen(str);
	}

	const char* c_str() const { return str; }

	bool operator==(const my_string& s2){
		return strcmp(str, s2.c_str()) == 0;
	}

	bool operator!=(const my_string& s2){
		return strcmp(str, s2.c_str()) != 0;
	}

	const my_string& operator=(const my_string& s2){
		delete[] str;

		size = strlen(s2.c_str()) + 1;
		str = new char[size];

		strcpy_s(str, size, s2.str);
		
		return str;
	}

	/*
	if (strcmp(str, s2.c_str()) == 0){
		return true;
	}
	else{
		return false;
	}
	*/

};


#endif