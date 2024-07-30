#ifndef _H_LINKED_LIST
#define _H_LINKED_LIST


template <typename T>
class LinkedList
{
    private:
        struct ListNode
        {
            T data;
            ListNode* next;
            ListNode( T d ): data(d), next(nullptr) {}
        };
        ListNode* head;

    public:
        LinkedList(): head(nullptr) {}

        void appendNode( T d );
};

template <typename T>
void LinkedList<T>::appendNode( T d )
{
    ListNode* n = new ListNode( d );
    ListNode* curr = head;

    if( !head ) head = n;
    else{
        while( curr->next ) curr = curr->next;
        curr->next = n;
    }
}




#endif