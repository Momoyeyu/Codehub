## C语言常见的占位符：

| 格式化符号 | 数据类型                           |
| ---------- | ---------------------------------- |
| %d         | 整型(int)                          |
| %ld        | 长整型(long int)                   |
| %lld       | 长长整型(long long)                |
| %hd        | 短整型(short int)                  |
| %u         | 无符号整型(unsigned int)           |
| %hu        | 无符号短整型(unsigned short int)   |
| %lu        | 无符号长整型(unsigned long int)    |
| %llu       | 无符号长长整型(unsigned long long) |
| %f         | 浮点型(float)                      |
| %e/%E      | 以指数形式表示的浮点型             |
| %m.nf      | 可控制输出小数位数                 |
| %c         | 字符型(char)                       |
| %s         | 字符串                             |
| %o         | 以八进制输出                       |
| %x         | 以十六进制输出                     |
| %p         | 变量地址                           |
| %i         | 结构体输出                         |

- double比较特殊，它的输入占位符是%lf，输出只能是%f
- 浮点型也有长短型，可以参考整型

## 其他占位符
| 格式化符号 | 数据类型 | 描述                                                                                                                                        |
| ---------- | -------- | ------------------------------------------------------------------------------------------------------------------------------------------- |
| %ms        | 字符串   | 输出的字符串占m列，如字符串本身长度大于m，则突破限制，将字符串全部输出。若串长小于m，则左补空格。                                           |
| %-ms       | 字符串   | 若串长小于m，则在m列范围内，m前为负，字符串左对齐，右补空格。                                                                               |
| %m.ns      | 字符串   | 输出占m列，但只取字符串中左端n个字符。这n个字符输出在m列的右侧，左补空格。                                                                  |
| %-m.ns     | 字符串   | 若n>m，则自动取n值，即保证n个字符正常输出。                                                                                                 |
| %f         | 浮点数   | 输出浮点型数据（小数点后默认保留6位小数）。                                                                                                 |
| %mf        | 浮点数   | 输出的数据占m列，如对象本身长度大于m，则突破获m的限制，将浮点型对象全部输出。若对象长度小于m，则左补空格。可以理解为m前为正，则对象右对齐。 |
| %-mf       | 浮点数   | 若对象长度小于m，则在m列范围内，m前为负，对象左对齐，右补空格。                                                                             |
| %m.nf      | 浮点数   | 输出占m列，浮点型对象保留n个小数位。                                                                                                        |
| %-m.nf     | 浮点数   | 若对象长度小于m，则在m列范围内，m前为负，对象左对齐，右补空格。                                                                             |

