class A {
public:
    int x;
} a;

void func_c1()
{
    a.x = 1;
}

void func_c2()
{
    ((A*)&a)->x = 1;
}
