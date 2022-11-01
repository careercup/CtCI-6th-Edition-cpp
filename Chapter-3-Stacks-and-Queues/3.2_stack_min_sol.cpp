/*
 * Cracking the coding interview edition 6
 * Problem 3-2 : Return the min from a stack.
 */
#include<iostream>
#include<stack>
#include<utility>
#include<climits>

using namespace std;

//stack stores the pairs
//pair.first stores the value
//pair.second stores the current min element found in the stack
class minStack{
private:
	stack<pair<int,int>> s1;

public:
	//adds a pair to the top of the stack
	void push(int x){
		int currMin=x;
		if(!isEmpty())
		{
		    //check if current element can be minimum of all elements 
			if(currMin > top().second)
			{
			    currMin=top().second;
			}
		}
		s1.push({x,currMin});
	}

	//pops the stack top pair
	void pop(){
		if(isEmpty()){
			cout<<"Cannot be popped"<<endl;
			return ;
		}
		s1.pop();
	}
	
	//returns the current min element in the stack
	int min(){
		if(isEmpty()){
			cout<<"Stack is empty "<<endl;
			return INT_MAX;   //Maximum value for an object of type int (climits is used)
		}
		return s1.top().second;
	}
	
	//returns true if stack is empty else false
	bool isEmpty(){
		return s1.empty();
	}

	//returns the stack top pair
	pair<int,int> top(){
		if(isEmpty()){
			return {INT_MAX,INT_MAX};
		}
		return s1.top();
	}
};

int main(){
	minStack myStack;
	pair<int,int> stk;
	int arr[] = {6, 3, 5, 2, 2, 9, 2, 8, 1, 1};
	for(int i=0; i<10; i++){
		myStack.push(arr[i]);
		cout<<"push in the element "<<arr[i]<<", the current min is "<<myStack.min()<<'\n';
	}
	for(int i=0; i<10; i++){
        stk = myStack.top();
		myStack.pop();
		cout<<"pop out the element "<<stk.first<<" from the stack and the current min is "<<myStack.top().second<<'\n';
	}
	return 0;
}