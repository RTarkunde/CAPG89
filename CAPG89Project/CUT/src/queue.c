


int enqueue ( employee** head, employee* queue)
{
	return prepend ( head, queue);
}

employee*  dequeue ( employee** head, employee* queue)
{
	// Traverse to the end of list.
    // Return last node and mark secondlast next Node pointer to NULL 
	//return deleteFirstNode (head);
}

int isFull(employee** head)
{
	return False;
}

int isEmpty (employee** head );
{
	if (head != NULL && *head == NULL)
		return True;
	else
		return False;
}

