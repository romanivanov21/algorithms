#ifndef _LIST_IMPL_H_
#define _LIST_IMPL_H_

namespace struct_data
{
    template <class T>
    list<T>::list() : head_(nullptr), tail_(nullptr) { }

    template <class T>
    list<T>::~list()
    {
        while(tail_ != head_)
        {
            node *temp = head_;
            head_->previus_= head_;
            head_->next_ = nullptr;
            delete temp;
        }
    }

    template <class T>
    void list<T>::push_back(T value)
    {
        node *item = new node();
        item->value_ = value;
        if( (tail_ == head_) && (tail_ == nullptr) && (head_ == nullptr) )
        {
            tail_ = head_ = item;
        }
        else
        {
            node *temp = head_;
            head_ = item;
            head_->previus_ = temp;
            head_->next_ = nullptr;
        }
    }
    template <class T>
    void list<T>::push_front(T value)
    {
        node *item = new node();
        item->value_ = value;
        if( (tail_ == head_) && (tail_== nullptr) && (head_ == nullptr) )
        {
            tail_ = head_ = item;
            tail_->next_ = NULL;
            head_->next_ = NULL;
        }
        else
        {
            node *temp = tail_;
            tail_ = item;
            temp->next_ = item;
            temp->previus_ = NULL;
        }
    }

    template <class T>
    void list<T>::print_list() const
    {
        for(node *temp = tail_; tail_ != head_; temp = temp->next_)
        {
            std::cout<<temp->value_<<std::endl;
        }
    }
}
#endif //_LIST_IMPL_H_