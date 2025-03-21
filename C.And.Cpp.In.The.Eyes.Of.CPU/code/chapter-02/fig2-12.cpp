void func1()
{
    int i = 0;
    for (; i < 10; i++)
    {

    }
}

void func2()
{
    int i = 0;
    goto l7;
l8:
    i++;
l7:
    if (i < 10)
    {
        goto l8;
    }
}
