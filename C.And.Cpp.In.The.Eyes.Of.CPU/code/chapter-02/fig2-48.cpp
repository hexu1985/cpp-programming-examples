class A {
public:
    int x;
    A& operator++()
    {
        x++;
        return *this;
    }

    A operator++(int)
    {
        A tmp = *this;
        ++*this;
        return tmp;
    }
} i;

int main()
{
    i++;
    ++i;
}