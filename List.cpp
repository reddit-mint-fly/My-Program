

List* insert(List* head,int pos,int value){
    for (int i = 1; i < pos; i++) {
        head=head->next;
    }
    List* node=(List*)malloc(sizeof(List));
    node->value=value;
    head->next=node->next;
    node->next=head;
    return head;
}


List* delete(List* head,int value){
    List*p,*prev;
    p=head->next;
    while(p->value != value){
        prev=p;
        p=p->next;
    }
    p->next=prev->next;
    free(p);
    return head;
}
