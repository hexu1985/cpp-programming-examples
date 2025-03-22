void func3(int* p)
{
    *p = 2;
}

void func4(int& r)
{
    r = 2;
}

void call()
{
    int a = 1;

    func3(&a);

    func4(a);
}
