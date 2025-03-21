
int a = 0;

void func_2()
{
    *(int*) &a = 1;
}

void func_3()
{
    a = 1;
}
