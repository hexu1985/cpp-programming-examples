void func1()
{
    int a = 1;
    int* p = &a;
    *p = 2;
}

void func2()
{
    int a = 1;
    int& r = a;
    r = 2;
}
