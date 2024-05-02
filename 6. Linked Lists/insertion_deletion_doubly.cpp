#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2LL(vector<int>& arr){
    Node*head = new Node(arr[0]);
    Node*prev = head;

    for(int i=1; i<arr.size(); i++){
        Node*temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}


void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

Node* deletehead(Node*head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }

    Node*prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;

    return head;
}

Node* deletetail(Node*head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node*tail = head;
    while(tail->next!=NULL){
        tail = tail->next;

    }
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node* removeKthelement(Node*head, int k){
    if(head==NULL){
        return NULL;
    }
    int cnt =0;
    Node* kNode = head;

    while(kNode!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        kNode= kNode->next;
    }

    Node*prev = kNode->back;
    Node*front = kNode->next;

    if(prev == NULL && front == NULL){ //single element
        return NULL;
    } 

    else if(prev== NULL){   // standing at head of linked list
        return deletehead(head);
    }
    else if(front==NULL){   // standing at tail of linked list
        return deletetail(head);
    }
    prev->next = front;
    front->back = prev;

    kNode->next = nullptr;
    kNode->back = nullptr;
    delete kNode;
    return head;
}


void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front= temp->next;

    if(front==NULL){
        prev->next = NULL;
        temp->back = nullptr;      
        delete temp;
        return;
    }

    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
}

Node* insertbeforehead(Node*head, int val){
    Node* newhead = new Node(val, head, nullptr);
    head->back = newhead;

    return newhead;
}

Node* insertbeforetail(Node*head, int val){

    if(head->next == nullptr){
        return insertbeforehead(head, val);
    }

    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    Node*prev = tail->back;
    Node* newNode= new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

Node*insertbeforeKthElement(Node* head, int k, int val){
    if(k==1){
        return insertbeforehead(head,val);
    }
    Node*temp = head;
    int cnt =0;

    while(temp){
        cnt++;
        if(cnt==k){
            break;
        }
        temp = temp->next;
    }
    Node*prev = temp->back;
    Node* newNode= new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
    
}
void insertbeforenode(Node*node, int val){
    Node*prev = node->back;
    Node* newNode= new Node(val, node, prev);

    prev->next = newNode;
    node->back = newNode;
    
}
int main(){
    vector<int>arr = {23,45,223,24};

    Node* head = convertArr2LL(arr);
    head = deletetail(head);
    print(head);

}
