// finding whether list is cycle or not
Node* floydCycleAlgo(Node* head){
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast -> next != NULL && slow != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(fast == slow)
            return slow;
    }
    return NULL;
}

// if cycle then finding the starting of Node loop
Node* getStartingNode(Node* head){
    if(head == NULL)
        return NULL;

    Node* intersection = floydCycleAlgo(head);
    if(intersection == NULL)
        return NULL;

    Node* slow = head;

    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow;
}

// if cycle then after finding starting of node, removing loop
Node *removeLoop(Node *head)
{
    if(head == NULL)
        return NULL;

    Node* startNode = getStartingNode(head);
    if(startNode == NULL)
        return head;
        
    Node* temp = startNode;

    while(temp -> next != startNode){
        temp = temp -> next;
    }
    temp -> next = NULL;

    return head;
}
