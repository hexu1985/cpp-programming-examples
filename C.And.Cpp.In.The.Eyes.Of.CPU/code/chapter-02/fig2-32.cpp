
void func1(int a[2])
{
    a[0] = 1;
    a[1] = 2;
}

void func2(int* a)
{
    *a = 1;
    *(a + 1) = 2;
}
