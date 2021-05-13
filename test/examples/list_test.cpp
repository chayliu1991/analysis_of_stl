#include "../List.h"
#include "../ListIterator.h"

using namespace stl;

template <class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T &value)
{
    while (first != last && *first != value)
        ++first;
    return first;
}

template <typename T>
bool operator!=(const ListItem<T> &item, T n)
{
    return item.value() != n;
}

int main()
{
    List<int> mylist;

    for (int i = 0; i < 5; ++i)
    {
        mylist.insert_front(i);
        mylist.insert_end(i + 2);
    }

    std::cout << "list size:" << mylist.size() << std::endl;
    mylist.display();

    ListIterator<ListItem<int>> begin(mylist.front());
    ListIterator<ListItem<int>> end;
    ListIterator<ListItem<int>> iter;
    iter = find(begin, end, 3);
    if (iter == end)
        std::cout << "not found" << std::endl;
    else
        std::cout << "found: " << iter->value() << std::endl;

    iter = find(begin, end, 7);
    if (iter == end)
        std::cout << "not found" << std::endl;
    else
        std::cout << "found: " << iter->value() << std::endl;
}