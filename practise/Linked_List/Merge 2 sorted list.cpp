Node<int>* solve(Node<int>* first, Node<int>* second){
    // if there is only one member in the list
    if(first -> next == NULL){
        first -> next = second;
        return first;
    }

    // pointers to the first and second list
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1 -> next;

    Node<int>* curr2 = second;
    Node<int>* next2 = curr2 -> next;

    // loop till there curr (not next)
    while(curr1 != NULL && curr2 != NULL){

        if((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)){
            // add nodes between the first list
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            //update pointers
            curr1 = curr1 -> next; // or = curr2
            curr2 = next2;
        }else{
            curr1 = curr1 -> next; // or = next1
            next1 = next1 -> next;

            if(next1 == NULL){
                curr1 -> next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    //checking is either is NULL
    if(first == NULL)
        return second;

    if(second == NULL)
        return first;

    // send whoever is big firstly
    if(first -> data <= second -> data)
        return solve(first, second);
    else
        return solve(second, first);
}
