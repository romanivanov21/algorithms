#ifndef _FORWARD_LIST_H_
#define _FORWARD_LIST_H_

template <class T>
class forward_list
{
public:
    forward_list() : head_( nullptr ), tail_( nullptr ) { }
    ~forward_list()
    {
        while( head_ != nullptr )
        {
            node *item = head_;
            head_ = head_->next_;
            delete item;
        }
    }
    void push_back( T data )
    {
        auto *item = new node();
        item->next_ = nullptr;
        item->data_ = data;
        if( ( head_ == nullptr ) && ( tail_ == nullptr ) )
        {
            head_ = tail_ = item;
        }
        else
        {
            tail_->next_= item;
            tail_ = item;
        }
    }
    void push_front( T data )
    {
        auto *item = new node();
        item->data_ = data;
        item->next_ = nullptr;
        if( ( head_ == nullptr) && ( tail_ == nullptr ) )
        {
            head_ = tail_ = item;
        }
        else
        {
            node *temp = head_;
            head_ = item;
            head_->next_ = temp;
        }
    }
    void pop_front()
    {
        node *temp = head_;
        head_ = head_->next_;
        delete temp;
    }

    forward_list( const forward_list& other )
    {
        head_ = tail_ = nullptr;
        node *it = other.head_;
        while( it != nullptr )
        {
            push_back( it->data_ );
            it = it->next_;
        }
    }

    forward_list& operator=( const forward_list& other )
    {
        node *it = head_;
        node *it_other = other.head_;
        while( it_other != nullptr )
        {
            if( it != nullptr )
            {
                it->data_ = it_other->data_;
                it = it->next_;
            }
            else
            {
                push_back( it_other->data_ );
            }
            it_other = it_other->next_;
        }
    }

private:
    struct node
    {
        node() : data_( 0 ), next_( nullptr ) { }
        T data_;
        node* next_;
    };
    node* head_; // указатель на начало списка
    node* tail_; // указатель на конец списка ( нужен для быстрого добавление элемента в конец )
};

#endif //_FORWARD_LIST_H_