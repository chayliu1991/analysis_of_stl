#pragma once

#include <iostream>

namespace stl
{
    template <typename T>
    class ListItem
    {
    public:
        ListItem() : value_(nullptr), next_(nullptr) {}
        ListItem(const T &value) : value_(value), next_(nullptr) {}
        T value() const { return value_; }
        ListItem *next() { return next_; }
        void set_next(ListItem *next)
        {
            next_ = next;
        }

    private:
        T value_;
        ListItem *next_;
    };

    template <typename T>
    class List
    {
    public:
        List();
        void insert_front(const T &value);
        void insert_end(const T &value);
        void display(std::ostream &os = std::cout) const;
        long size() const { return size_; }

        ListItem<T> *front()
        {
            return front_;
        }

    private:
        ListItem<T> *end_;
        ListItem<T> *front_;
        long size_;
    };

    template <typename T>
    List<T>::List() : end_(nullptr), front_(nullptr), size_(0) {}

    template <typename T>
    void List<T>::insert_front(const T &value)
    {
        ListItem<T> *temp = new ListItem<T>(value);
        temp->set_next(front_);
        front_ = temp;
        ++size_;
    }

    template <typename T>
    void List<T>::insert_end(const T &value)
    {
        ListItem<T> *temp = new ListItem<T>(value);
        ListItem<T> *curr = front_;
        while (curr->next() != end_)
            curr = curr->next();
        curr->set_next(temp);
        end_ = temp->next();
        ++size_;
    }

    template <typename T>
    void List<T>::display(std::ostream &os) const
    {
        ListItem<T> *curr = front_;
        while (curr != end_)
        {
            os << curr->value() << ",";
            curr = curr->next();
        }
        os << "\n";
    }
}