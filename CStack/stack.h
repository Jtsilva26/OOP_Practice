#include <string>

template <typename t>
class Stack
{
public:
    Stack();
    Stack(const Stack &);
    ~Stack();
    Stack &operator=(const Stack &);
    int size();
    void push(t);
    t pop();

private:
    static const int chunk_size;
    unsigned maximum_size;
    int current_size;
    t *base;
};

template <typename t>
const int Stack<t>::chunk_size = 10;

template <typename t>
Stack<t>::Stack()
    : current_size(-1), maximum_size(chunk_size), base(new t[chunk_size])
{
}
template <typename t>
Stack<t>::Stack(const Stack &s)
    : maximum_size(s.maximum_size), base(new t[s.maximum_size])
{
    if (s.current_size > -1)
    {
        for (current_size = 0; current_size <= s.current_size; current_size++)
            base[current_size] = s.base[current_size];
        current_size--;
    }
}
template <typename t>
Stack<t>::~Stack()
{
    delete[] base;
}
template <typename t>
Stack<t> &Stack<t>::operator=(const Stack &s)
{
    delete[] base;
    maximum_size = s.maximum_size;
    base = new t[maximum_size];
    current_size = s.current_size;
    if (current_size > -1)
    {
        for (int x = 0; x <= current_size; x++)
            base[x] = s.base[x];
    }
    return *this;
}

template <typename t>
void Stack<t>::push(t element)
{
    t p;
    current_size++;
    if (current_size == maximum_size - 1)
    {
        maximum_size += chunk_size;
        t *new_buffer = new t[maximum_size];
        for (int x = 0; x < current_size; x++)
            new_buffer[x] = base[x];
        delete[] base;
        base = new_buffer;
    }
    base[current_size] = element;
}
template <typename t>
t Stack<t>::pop()
{
    if (current_size < 0)
        throw "Nothing to pop!";
    return base[current_size--];
}
template <typename t>
int Stack<t>::size()
{
    return current_size + 1;
}