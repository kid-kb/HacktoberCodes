nt countPairs(struct Node* head1, struct Node* head2, int x) 
{
    int count = 0;
    unordered_set<int> us;
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    while(temp1 != NULL){
    us.insert(temp1->data);
    temp1 = temp1->next;
    }
    while(temp2 != NULL){
    if(us.find(x - temp2->data) != us.end()){
    count++;
    }
    temp2 = temp2->next;
    }
    return count;
    // Code here
}
