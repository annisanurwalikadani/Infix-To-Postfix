#include<iostream>
using namaspace std;
struct stack{
	char stack2[200000];
	int top;
};

//class yang berisi fungsi-fungsi yang akan digunakan (push,pop,dll)
class convert{
private:
	stack consist;

public:
	void init(){
		consist.top = -1;
	}

	void push(char input){
			consist.top++;
			consist.stack2[consist.top] = input;
	}

	void pop(){
		consist.top--;
	}

	char Top(){
		return consist.stack2[consist.top];
	}

	bool isEmpty(){
		if(consist.top <= -1)
			return true;
		else
			return false;
	}
}; convert SC;
