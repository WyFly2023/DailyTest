/*
20. 有效的括号

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
*/

bool isValid(char* s) 
{
    Stack stack;
    InitStack(&stack);
    while (*s)
    {
        if (*s == '(' || *s == '[' || *s == '{')
        {
            Push(&stack, *s);
            s++;
        }
        else
        {
            if (EmptyStack(&stack))
                return false;
            else
            {
                ElemType tmp = Pop(&stack);
                if (*s == ')' && tmp != '('
                    || *s == ']' && tmp != '['
                    || *s == '}' && tmp != '{')
                    return false;
                else
                    s++;
            }
        }
    }

    bool ret = EmptyStack(&stack);
    return ret;
}