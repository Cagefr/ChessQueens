class Stack{
	private:
		int count;
		StackNode *top;
	public:

		Stack();
		~Stack(){deleteAllStack();};
		void push(StackNode *node);
		StackNode *pop();
		void traverseStack();
		void deleteAllStack();
		bool isEmptyStack();
		int getStackSize();
		StackNode *stackTop();
};

Stack::Stack()
{
	count = 0;
	top   = nullptr;
}

StackNode *Stack::stackTop()
{
	return top;
}

int Stack::getStackSize()
{
	return count;
}

bool Stack::isEmptyStack()
{
	return top == nullptr;
}

void Stack::push(StackNode *node)
{

	cout << "\n\t\t\tInserting New Node into Stack ....";

	//Inserting into empty stack:
	if(top == nullptr){
		top = node;

	}
	else{	//Inserting into non-empty stack:
		node->setNext(top);
		top = node;	
	}

	count += 1;

	cout << "\n\t\t\tNumber of Items in Stack: " << count <<endl;

	return;

}

void Stack::deleteAllStack()
{
	StackNode *node;

	cout << "\n\n\t\t\tDeleting All Items in Stack ....";

	while(count > 0){
		
		node = top;
		top = node->getNext();
		cout <<"\n\t\t\tDeleting Node: \n";
		node->printInfo();

		delete node;
		count--;

		cout << "\n\t\t\tNumber of Remaining Items is: " << count << "\n\n";
	}

	cout << "\n\n";

	return;

}

StackNode *Stack::pop()
{
	StackNode *node;
	StackNode *prev;

	if(count > 0){
		cout << "\n\t\t\tPopping Node ...\n";
		
		node = top;
		top  = node->getNext();

		count--;

		cout << "\n\t\t\tNumber of Remaining Items is: " << count << "\n\n";
	}
	else{
		cout << "\n\t\t\tStack is Empty..." <<endl;	
		node = nullptr;
	}

	return node;
}

void Stack::traverseStack()
{
        StackNode *node;

        cout << "\n\n\t\t\tTraversing Stack ....";

        node = top;
        while(node != nullptr){

                node->printInfo();
                node = node->getNext();
        }

        cout << "\n\n";

        return;
}


Stack *createStack()
{
	Stack *stack;

	stack = new Stack();
	
	return stack;
}

void destroyStack(Stack *stack)
{
	if(stack != nullptr){

		if(stack->getStackSize() >0){
			cout << "\n\n\t\t\tFailure: Attempting to delete a non-empty stack\n\n";
		}
		else{
			delete stack;
			stack = nullptr;
			cout << "\n\n\t\t\tStack Successfully Deleted\n\n";
		}
	}
	
	return;	
}
