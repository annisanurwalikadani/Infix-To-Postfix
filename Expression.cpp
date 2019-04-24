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
}; convert opstack;

//pernyataan untuk syarat dalam mengubah infix ke postfix
bool isOperand(char input){
	int c = (int)input;
	if(c >= 48 && c <= 57 || c >= 65 && c <= 90 || c >= 97 && c <= 122)
		return true;
	else
		return false;
}

bool isOperator(char input){
	int c = (int)input;
	if(c == 94 || c >= 42 && c <= 43 || c == 45 || c == 47)
		return true;
	else
		return false;
}

//beberapa keadaan tiap operator
int position(char input){
	if(input == '^')
		return 3;
	else if(input == '*' || input == '/')
		return 2;
	else if(input == '+' || input == '-')
		return 1;
	else if(input == '(' || input == ')')
		return 0;
	else
		return -1;
}

//penentuan posisi yang lebih tinggi
bool more(char input1, char input2){
	int c1 = position(input1);
	int c2 = position(input2);

	if(c1 <= c2)
		return true;
	else
		return false;
}
