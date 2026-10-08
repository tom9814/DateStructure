#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef int elemtype;
// 栈的链表结构体定义
typedef struct stack
{
    elemtype data;
    struct stack *next;
} Stack;

// 字符类型的枚举定义(EOS代表的是字符串最后的\0)
typedef enum
{
    LEFT_PARE,
    RIGHT_PARE,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    EOS,
    NUM
} contentType;

//char expr[] = "82/2+56*-";
char expr[] = "x/(i-j)*y";

// 栈的初始化
Stack *initStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = 0;
    s->next = NULL;
    return s;
}

// 压栈
int push(Stack *s, elemtype e)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1;
}

// 出栈
int pop(Stack *s, elemtype *e)
{
    if (s->next == NULL)
    {
        printf("空栈\n");
        return 0;
    }
    Stack *p = s->next;
    *e = p->data;
    s->next = p->next;
    free(p);
    return 1;
}

// 获取栈顶元素
int getTop(Stack *s, elemtype *e)
{
    if (s->next == NULL)
    {
        printf("空栈\n");
        return 0;
    }
    *e = s->next->data;
    return 1;
}

// 判断字符串中的每个字符的类型函数
contentType getToken(char *symbol, int *index)
{
    *symbol = expr[*index];
    *index = *index + 1;
    switch (*symbol)
    {
    case '(':
        return LEFT_PARE;
    case ')':
        return RIGHT_PARE;
    case '+':
        return ADD;
    case '-':
        return SUB;
    case '*':
        return MUL;
    case '/':
        return DIV;
    case '%':
        return MOD;
    case '\0':
        return EOS;
    default:
        return NUM;
    }
}

// 后缀表达式求值的函数
int eval(Stack *s)
{
    // 符号
    char symbol;
    // 操作数1，操作数2
    int op1, op2;
    // 字符串下标
    int index = 0;
    // 字符类型
    contentType token;
    token = getToken(&symbol, &index);
    elemtype result;
    while (token != EOS)
    {
        // 如果是数字则将其压栈
        if (token == NUM)
        {
            // symbol存的是char,其 - '0'可得数字
            push(s, symbol - '0');
        }
        // 是符号的情况
        else
        {
            // 先出栈2次并放到操作数中
            pop(s, &op2);
            pop(s, &op1);
            // 不同符号对应不同操作，并将计算后的数压栈
            switch (token)
            {
            case ADD:
                push(s, op1 + op2);
                break;
            case SUB:
                push(s, op1 - op2);
                break;
            case MUL:
                push(s, op1 * op2);
                break;
            case DIV:
                push(s, op1 / op2);
                break;
            case MOD:
                push(s, op1 % op2);
                break;
            default:
                break;
            }
        }
        token = getToken(&symbol, &index);
    }
    pop(s, &result);
    printf("%d\n", result);
    return 1;
}

//输出token的函数
int print_token(contentType token)
{
    switch(token)
    {
        case ADD:
            printf("+");
            break;
        case SUB:
            printf("-");
            break;
        case MUL:
            printf("*");
            break;
        case DIV:
            printf("/");
            break;
        case MOD:
            printf("%");
            break;
    }
    return 1;
}

//中缀表达式转后缀表达式的函数
void postfix(Stack *s)
{
    //运算符在栈内以及栈外的优先度
    int in_stack[] = {0, 19, 12, 12, 13, 13, 13, 0};
    int out_stack[] = {20, 19, 12, 12, 13, 13, 13, 0};
    contentType token;
    int index = 0;
    push(s, EOS);
    char symbol;
    elemtype e;
    token = getToken(&symbol, &index);
    while (token != EOS)
    {
        //数字直接输出
        if (token == NUM)
        {
            printf("%c",symbol);
        }
        //如果读取到右括号,输出栈的元素，直到读取到左括号结束
        else if(token == RIGHT_PARE)
        {
            while (s->next->data != LEFT_PARE)
            {
                pop(s, &e);
                print_token(e);
            }
            //弹出左括号运算符
            pop(s,&e);   
        }
        else
        {   
            //栈顶运算符优先级>=所读取运算符优先级时
            while(in_stack[s->next->data] >= out_stack[token])
            {
                //弹出栈顶运算符并且输出
                pop(s, &e);
                print_token(e);
            }
            push(s,token);
        }
        token = getToken(&symbol, &index);
    }
    //当读取到EOS时，将栈内的运算符全部输出
    while (s->next->data != EOS)
    {
        pop(s,&e);
        print_token(e);
    }
}    

int main()
{
    //后缀表达式计算值的测试
    // Stack *s = initStack();
    // eval(s);

    //中缀表达式转后缀表达式的测试
    Stack *s = initStack();
    printf("%s\n",expr);
    postfix(s);

    system("pause");
    return 0;
}