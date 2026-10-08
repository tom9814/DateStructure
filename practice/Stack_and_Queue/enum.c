#include <stdio.h>
#include <windows.h>
//枚举数据类型的定义
// typedef enum
// {
//     mod, tue, wed, thu, fri, sat, sun
// }weekday;

typedef enum
{
    mod = 1, tue, wed, thu, fri, sat, sun
}weekday;

int main()
{
    weekday a = mod;
    weekday b = wed;
    printf("%d\n",a);
    printf("%d\n",b);

    system("pause");
    return 0;
}