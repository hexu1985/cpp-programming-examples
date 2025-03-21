int func3(int x)
{
    if (x > 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int func4(int x)
{
    if (x <= 1)
    {
        goto l9;
    }
    return 1;
l9:
    return 0;
}
