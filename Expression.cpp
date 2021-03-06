#include<iostream>
using namespace std;
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

//mengubah infix ke postfix
string intopost(string input){
	opstack.init();
	int i=0;
	string postfix = "";
	while(input[i] != '\0'){
		if(isOperand(input[i])){
			postfix += input[i];
		}
		if(input[i] == '('){
			opstack.push(input[i]);
		}
		if(input[i] == ')'){
			while(!opstack.isEmpty() && opstack.Top() != '('){
				postfix = postfix + " " + opstack.Top(); opstack.pop();
			}
			opstack.pop();
		}
		if(isOperator(input[i])){
			if(opstack.isEmpty() || opstack.Top() == '('){
				opstack.push(input[i]);
			}else{
				while(!opstack.isEmpty() && opstack.Top() != '(' && more(input[i], opstack.Top())){
					postfix = postfix + " " + opstack.Top(); opstack.pop();
				}
				opstack.push(input[i]);
			}
		}
		if(isOperator(input[i]))
			postfix += " "; 
		i++;
	}
	while(!opstack.isEmpty()){
		postfix = postfix + " " + opstack.Top(); opstack.pop();
	}
	return postfix;
}

//fungsi utama
int main(){

	string infix;
	cout<<"\t\t====================================================="<<endl;
	cout<<"\t\tNama : 1. Annisa Nurwalikadani\t (1817051037)"<<endl;
	cout<<"\t\t       2. Syela Septania\t (1817051058)"<<endl;
	cout<<"\t\t       3. Suci Hikmawati\t (1817051033)"<<endl;
	cout<<"\t\t       4. Rika Ningtias Azhari\t (1817051073)"<<endl;
	cout<<"\t\t====================================================="<<endl<<endl;
	cout<<"\t\t		    INFIX ke POSTFIX"<<endl<<endl;
	cout <<"\t\tMasukkan operasi matematika dalam bentuk infix : ";
	getline(cin,infix);
	string postfix = intopost(infix);
	cout << "\n\t\tInfix    = " << infix;
	cout << "\n\t\tPostfix  = " << postfix;


	cin.get();
	return 0;
}
