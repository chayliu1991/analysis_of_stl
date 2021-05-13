#pragma once

namespace stl
{
    template <typename Item>
    class ListIterator
    {
    public:
        ListIterator(Item *p = nullptr) : ptr_(p) {}

        Item &operator*() const { return *ptr_; }
        Item *operator->() const { return ptr_; }

        //@ pre-inclement
        ListIterator &operator++()
        {
            ptr_ = ptr_->next();
            return *this;
        }

        //@ post-inclement
        ListIterator operator++(int)
        {
            ListIterator ret = ptr_;
            ptr_ = ptr_->next();
            return ret;
        }

        bool operator==(const ListIterator &rhs) const
        {
            return ptr_ == rhs.ptr_;
        }

        bool operator!=(const ListIterator &rhs) const
        {
            return ptr_ != rhs.ptr_;
        }

    private:
        Item *ptr_;
    };
}