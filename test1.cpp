func(node *head){

    node *temp = head;
    
    vector<int> arr;

    while(temp){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int start = 0;
    int n = arr.size();
    int end = n - 1;

    vector<int> ans;

    int count = 0;

    while(count < n){
        ans.push_back(arr[end]);
        end--;
        count++;
        if(count < arr.size()){
            ans.push_back(arr[start]);
            count++;
            start++;
        }
    }

    node *headptr = head;

    for(int i = 0; i < n; i++){
        headptr -> data = ans[i];
        headptr = headptr -> next;
    }

    return head;
}

// 

void arrange(struct Node* head) 
{ 
    struct Node* temp = head; 
    deque<int> d; // defining a deque 
  
    // push all the elements of linked list in to deque 
    while (temp != NULL) { 
        d.push_back(temp->data); 
        temp = temp->next; 
    } 
  
    // Alternatively push the first and last elements 
    // from deque to back to the linked list and pop 
    int i = 0; 
    temp = head; 
    while (!d.empty()) { 
        if (i % 2 == 0) { 
            temp->data = d.front(); 
            d.pop_front(); 
        } 
        else { 
            temp->data = d.back();  
            d.pop_back();  
        } 
        i++; 
        temp = temp->next; // increase temp 
    } 
} 
  