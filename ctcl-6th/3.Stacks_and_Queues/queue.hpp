

// Node* next が Stack とは逆になっていることに注意
// Stack: top -> ... -> nullptr
// Queue: last <- .. <- first
template <typename T>
class Queue
{
    private:
        struct Node
        {
            T data;
            Node* next;
            Node( T d ): data(d), next(nullptr) {}
        };
        Node* first;  // 最初に入れたやつ
        Node* last;   // 最後に入れたやつ
        size_t queueSize;

    public:
        Queue():first(nullptr), last(nullptr), queueSize(0) {}
        ~Queue() { while( !isEmpty() ) remove();  }

        void add( T d );
        T remove();
        T& peek();
        bool isEmpty() { return !first; }
        size_t size() { return queueSize; }
        class QueueIsEmptyExcemption {};
};

template <typename T>
void Queue<T>::add( T d )
{
    auto n = new Node(d);
    if( isEmpty() ) first = n;
    else last->next = n;
    last = n;
    ++queueSize;
}

template <typename T>
T Queue<T>::remove()
{
    if( isEmpty() ) throw QueueIsEmptyExcemption();
    T value = first->data;
    auto n = first;
    first = n->next;
    if( !first ) last = nullptr;
    delete n;
    --queueSize;
    return value;
}

template <typename T>
T& Queue<T>::peek()
{
    if( isEmpty() ) throw QueueIsEmptyExcemption();
    return first->data;
}
