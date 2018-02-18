Node * copyList(Node *head)
{
    Node* cur=head;
    Node* res;
    Node* t;
    Node* temp;
    
    while(cur)
    {
        t=new Node();
        t->data=cur->data;
        t->arb=NULL;
        t->next=cur->next;
        temp=cur->next;
        cur->next=t;
        cur=temp;
    }
    
    
    res=head->next;
    Node* e=res;
    cur=head;
    
    while(cur!=NULL)
    {
        if (cur->arb!=NULL)
            cur->next->arb=cur->arb->next;
        cur=cur->next->next;
    }
    cur=head;
    while (e->next!=NULL)
    {
        cur->next=e->next;
        cur=cur->next;
        e->next=cur->next;
        e=e->next;

    }
    
    cur->next=NULL;
    return res;
    
    
    
    
}