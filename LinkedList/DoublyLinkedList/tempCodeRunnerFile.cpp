node* reverseDLL2(node* head){
  node* temp=head;
  node* last=NULL;
  while(temp){
    temp->back;
    temp->back=temp->next;
    temp->next=last;
    temp=temp->back;
  }

  return last->back;
}