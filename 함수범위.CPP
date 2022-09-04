void f()
{
    {   
        goto label; // label in scope even though declared later
label:;
    }
    goto label;     // label ignores block scope
}

void g()
{
    goto label;     // error: label not in scope in g()
}