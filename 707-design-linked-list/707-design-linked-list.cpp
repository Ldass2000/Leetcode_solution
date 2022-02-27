
class  LinkedList
{
    public:
    int val;
    LinkedList* next;
};

class MyLinkedList {
public:
   
    MyLinkedList() {
        head=NULL;
        size=0;
    }
    
    int get(int index) {
        int ans=-1;
        LinkedList* curr=head;
        int i=0;
        while(curr!=NULL)
        {
          if(i==index)
          {
            ans=curr->val;
            break;
          }
          i++;
          curr=curr->next;
        }
        return ans;
    }
    
    void addAtHead(int val) {
        
        LinkedList* node=new LinkedList();
        node->val=val;
        node->next=head;
        head=node;
        size++;
    }
    
    void addAtTail(int val) {
         if(head==NULL)
            addAtHead(val);
        else
        {
            LinkedList* curr=head;

            while(curr->next!=NULL)
            {
                curr=curr->next;
            }
            LinkedList* node=new LinkedList();
            node->val=val;
            node->next=NULL;
            curr->next=node;
            size++;
        }
    }
    
    void addAtIndex(int index, int val) {
         if(index==0)
        {
            addAtHead(val);
        }
        else
        {
            LinkedList* curr=head;
            LinkedList* prev=NULL;
            int i=0;
            while(curr!=NULL)
            {
                if(i==index)
                {
                    LinkedList* node=new LinkedList();
                    node->val=val;
                    node->next=curr;
                    prev->next=node;
                    break;
                }
                i++;
                prev=curr;
                curr=curr->next;
                size++;
            }
            
            if(curr==NULL && i==index)
            {
                addAtTail(val);
            }
        }
    }
    
    void deleteAtIndex(int index) {
        LinkedList* curr=head;
        LinkedList* prev=NULL;
        int i=0;
        if(index==0)
        {
            head=curr->next;
            delete curr;
            size--;
        }
        else
        {
            while(curr!=NULL)
            {
                if(i==index)
                {
                    LinkedList* temp=curr;
                    prev->next=curr->next;
                    delete temp;
                    size--;
                    break;
                }
                i++;
                prev=curr;
                curr=curr->next;
            }
        }
    }
    int size;
    LinkedList* head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */