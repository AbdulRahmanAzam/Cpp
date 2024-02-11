// it will put that value in a sorted way
void sortedInsert(stack<int> &s, int num){
	if(s.empty() || (s.top() < num)){
		s.push(num);
		return;
	}

	int top = s.top();
	s.pop();

	sortedInsert(s, num);

	s.push(top);
}

// it will send all the values one by one from down to up
// not from top (from down to top)
void sortStack(stack<int> &stack)
{
	if(stack.empty())
		return;

	int num = stack.top();
	stack.pop();

	sortStack(stack);
	
	sortedInsert(stack, num);
}
