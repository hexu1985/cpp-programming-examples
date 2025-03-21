
int a = 0;

void func1()
{
    int* p = &a;
    *p = 1;
}

void func2()
{
    *(int*) &a = 1;
}
