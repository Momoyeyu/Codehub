## 例

#### 一. 直接用malloc申请一个int类型二维数组

```c
a = (int**)malloc(sizeof(int*) * n); // 建立长度为n的动态指针数组
for (int i = 0; i < n; i++)
    a[i] = (int*)malloc(sizeof(int) * m); // 建立长度为m的一维整型数组
```

#### 二. 通过函数用malloc申请一个char类型二维数组

```c
char** create1(int n)
{
    char** p = (char**)malloc(sizeof(char*) * n); // 先申请一个指针数组
    return p;
}

void create2(char** strPtr, int n)
{
    for (int i = 0; i < n; i++) {
        strPtr[i] = (char*)malloc(sizeof(char) * (n)); // 指针数组指向一个数组
    }
}
```
