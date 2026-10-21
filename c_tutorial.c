/**
 * c_tutorial.c —— C 语言入门互动教学程序
 * ------------------------------------------------------------------
 * 用法：
 *   编译后运行，按菜单选择课程。每课都是「讲解 + 可运行示例」。
 *
 * 编译（gcc / MinGW）：
 *   gcc -std=c11 -Wall -Wextra -O2 -o c_tutorial.exe c_tutorial.c
 *
 * 编译（MSVC）：
 *   cl /W4 /utf-8 c_tutorial.c
 *
 * 说明：
 *   - 源码以 UTF-8 保存，Windows 下程序启动时会把控制台切到 UTF-8。
 *   - 每课用 \n 分隔，按回车继续。
 * ------------------------------------------------------------------
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define LINE_MAX_LEN 256

/* ================= 基础工具函数 ================= */

/* 把 Windows 控制台切换到 UTF-8，避免中文乱码 */
static void setup_console(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
}

/* 打印一条分隔线 */
static void print_rule(void)
{
    int i;
    for (i = 0; i < 60; ++i) {
        putchar('=');
    }
    putchar('\n');
}

/* 打印课程标题 */
static void print_title(const char *title)
{
    printf("\n");
    print_rule();
    printf("  %s\n", title);
    print_rule();
}

/* 打印一个小节标题 */
static void print_section(const char *text)
{
    printf("\n【%s】\n", text);
}

/* 暂停，等用户按回车 */
static void pause_console(void)
{
    char line[LINE_MAX_LEN];
    printf("\n按回车键继续...");
    fflush(stdout);
    (void)fgets(line, sizeof line, stdin);
}

/* 读取一行并解析为整数；成功返回 1，失败返回 0 */
static int read_int(const char *prompt, int *value)
{
    char line[LINE_MAX_LEN];
    char *end;
    long v;

    printf("%s", prompt);
    fflush(stdout);

    if (fgets(line, sizeof line, stdin) == NULL) {
        return 0;
    }

    v = strtol(line, &end, 10);
    if (end == line) {
        return 0;
    }

    *value = (int)v;
    return 1;
}

/* 读取一行并解析为浮点数；成功返回 1，失败返回 0 */
static int read_double(const char *prompt, double *value)
{
    char line[LINE_MAX_LEN];
    char *end;
    double v;

    printf("%s", prompt);
    fflush(stdout);

    if (fgets(line, sizeof line, stdin) == NULL) {
        return 0;
    }

    v = strtod(line, &end);
    if (end == line) {
        return 0;
    }

    *value = v;
    return 1;
}

/* ================= 第 1 课：输出 ================= */

static void lesson01(void)
{
    print_title("第 1 课  你好，C 语言");

    print_section("一份最小的 C 程序");
    printf("  #include <stdio.h>      <- 引入「标准输入输出」库\n");
    printf("  int main(void) {        <- 程序从这里开始执行\n");
    printf("      printf(\"Hello!\\n\");  <- 向屏幕输出一行字\n");
    printf("      return 0;           <- 0 表示「正常结束」\n");
    printf("  }\n");

    print_section("实际运行效果");
    printf("  Hello, World!\n");
    printf("  我正在学习 C 语言。\n");

    print_section("转义字符");
    printf("  \\n   换行\n");
    printf("  \\t   制表符（对齐用）\n");
    printf("  \\\\   输出一个反斜杠\n");
    printf("  \\\"   输出一个双引号\n");
    printf("  示例：\t甲\t乙\t丙\n");

    print_section("注释");
    printf("  // 这是单行注释\n");
    printf("  /* 这是\n     多行注释 */\n");
    printf("  注释不会被执行，是写给人看的。\n");

    print_section("试一试");
    printf("  把上面的 printf 改成输出你的名字，然后重新编译。\n");

    pause_console();
}

/* ================= 第 2 课：变量与类型 ================= */

static void lesson02(void)
{
    int age = 20;            /* 整数 */
    double height = 1.75;    /* 小数（双精度） */
    float weight = 62.5f;    /* 小数（单精度，注意 f 后缀） */
    char grade = 'A';        /* 单个字符 */
    const char *name = "小明"; /* 字符串：字符数组的指针 */

    print_title("第 2 课  变量与数据类型");

    print_section("常见类型");
    printf("  int     整数          例如 20, -5, 1000\n");
    printf("  double  小数（双精度） 例如 1.75, 3.14159\n");
    printf("  float   小数（单精度） 例如 62.5f\n");
    printf("  char    单个字符      例如 'A', '7'\n");
    printf("  字符串用 char 数组或 const char * 表示\n");

    print_section("声明与赋值");
    printf("  类型 变量名 = 初始值;\n");
    printf("  int age = 20;\n");
    printf("  age = 21;        <- 变量可以改\n");
    printf("  const 修饰的变量不能改（常量）\n");

    print_section("用 printf 打印它们");
    printf("  age    = %d\n", age);
    printf("  height = %.2f 米\n", height);
    printf("  weight = %.1f 公斤\n", weight);
    printf("  grade  = %c\n", grade);
    printf("  name   = %s\n", name);

    print_section("常用格式符");
    printf("  %%d  整数\n");
    printf("  %%f  小数（%%.2f 表示保留 2 位）\n");
    printf("  %%c  字符\n");
    printf("  %%s  字符串\n");
    printf("  %%%%  输出百分号本身\n");

    print_section("各类型占多少字节");
    printf("  sizeof(int)    = %d\n", (int)sizeof(int));
    printf("  sizeof(double) = %d\n", (int)sizeof(double));
    printf("  sizeof(float)  = %d\n", (int)sizeof(float));
    printf("  sizeof(char)   = %d\n", (int)sizeof(char));

    pause_console();
}

/* ================= 第 3 课：输入与运算 ================= */

static void lesson03(void)
{
    int a = 0, b = 0;
    int ok_a, ok_b;

    print_title("第 3 课  输入与运算符");

    print_section("读取用户输入");
    printf("  用 fgets 读一整行，再转成数字，比 scanf 更安全。\n");

    ok_a = read_int("  请输入第一个整数: ", &a);
    ok_b = read_int("  请输入第二个整数: ", &b);

    if (!ok_a || !ok_b) {
        printf("  输入无效，本课改用默认值 7 和 2。\n");
        a = 7;
        b = 2;
    }

    print_section("四则运算");
    printf("  %d + %d = %d\n", a, b, a + b);
    printf("  %d - %d = %d\n", a, b, a - b);
    printf("  %d * %d = %d\n", a, b, a * b);

    if (b != 0) {
        printf("  %d / %d = %d   (整数除法，会丢掉小数)\n", a, b, a / b);
        printf("  %d %% %d = %d   (取余数)\n", a, b, a % b);
        printf("  (double)%d / %d = %.2f   (强制转换后才是精确的)\n",
               a, b, (double)a / (double)b);
    } else {
        printf("  第二个数是 0，不能做除法。\n");
    }

    print_section("自增与自减");
    {
        int n = 5;
        printf("  n = %d\n", n);
        printf("  n++ 之后: n = %d\n", n++);
        printf("  现在 n = %d\n", n);
        printf("  ++n 之后: n = %d\n", ++n);
    }

    print_section("小数运算");
    {
        double radius = 0.0;
        if (read_double("  请输入一个圆的半径（如 2.5）: ", &radius) && radius > 0.0) {
            printf("  周长 = %.2f\n", 2.0 * 3.1415926 * radius);
            printf("  面积 = %.2f\n", 3.1415926 * radius * radius);
        } else {
            printf("  输入无效或半径不为正，跳过这段演示。\n");
        }
    }

    print_section("易错点");
    printf("  5 / 2   = %d   （两个整数相除，结果还是整数）\n", 5 / 2);
    printf("  5 / 2.0 = %.1f （有一个是小数，结果才是小数）\n", 5 / 2.0);

    pause_console();
}

/* ================= 第 4 课：分支 ================= */

static void lesson04(void)
{
    int score = 0;

    print_title("第 4 课  条件分支 if / switch");

    print_section("if / else if / else");
    printf("  语法：if (条件) { ... } else if (条件) { ... } else { ... }\n");

    if (!read_int("  请输入你的分数（0-100）: ", &score)) {
        printf("  输入无效，按 85 分演示。\n");
        score = 85;
    }

    if (score < 0 || score > 100) {
        printf("  分数不合法。\n");
    } else if (score >= 90) {
        printf("  %d 分 —— 优秀\n", score);
    } else if (score >= 80) {
        printf("  %d 分 —— 良好\n", score);
    } else if (score >= 60) {
        printf("  %d 分 —— 及格\n", score);
    } else {
        printf("  %d 分 —— 不及格\n", score);
    }

    print_section("switch：按整数选择分支");
    {
        int day = 3;
        printf("  今天是星期 %d：", day);
        switch (day) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("工作日\n");
            break;
        case 6:
        case 7:
            printf("休息日\n");
            break;
        default:
            printf("不是合法的星期\n");
            break;
        }
    }

    print_section("易错点");
    printf("  1. 条件里要用 == 比较，不能用 = 赋值\n");
    printf("  2. switch 的每个 case 末尾记得 break，否则会「贯穿」\n");
    printf("  3. 浮点数不要直接用 == 比较，用范围判断\n");

    pause_console();
}

/* ================= 第 5 课：循环 ================= */

static void lesson05(void)
{
    int i, j, sum;

    print_title("第 5 课  循环 for / while / do-while");

    print_section("for：次数已知时最常用");
    sum = 0;
    for (i = 1; i <= 100; ++i) {
        sum += i;
    }
    printf("  1 加到 100 = %d\n", sum);

    print_section("while：条件成立就一直做");
    i = 5;
    printf("  倒数：");
    while (i > 0) {
        printf("%d ", i);
        --i;
    }
    printf("发射！\n");

    print_section("do-while：至少执行一次");
    {
        int n = 0;
        do {
            printf("  第 %d 次循环（至少会执行一次）\n", n + 1);
            ++n;
        } while (n < 0);
    }

    print_section("break 与 continue");
    printf("  break    跳出整个循环\n");
    printf("  continue 跳过本次，进入下一次\n");
    printf("  1 到 20 里第一个能被 7 整除的数：");
    for (i = 1; i <= 20; ++i) {
        if (i % 7 == 0) {
            printf("%d\n", i);
            break;
        }
    }

    print_section("嵌套循环：九九乘法表");
    for (i = 1; i <= 9; ++i) {
        for (j = 1; j <= i; ++j) {
            printf("%d*%d=%-3d", j, i, i * j);
        }
        printf("\n");
    }

    pause_console();
}

/* ================= 第 6 课：数组与字符串 ================= */

static void lesson06(void)
{
    int nums[5] = {5, 3, 9, 1, 7};
    int i, j, tmp, sum, max;
    char greeting[64] = "你好";
    char name[32] = "小明";
    char buffer[128];

    print_title("第 6 课  数组与字符串");

    print_section("数组：一排同类型的格子");
    printf("  int nums[5] = {5, 3, 9, 1, 7};  下标从 0 开始\n");
    printf("  nums = ");
    for (i = 0; i < 5; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    sum = 0;
    max = nums[0];
    for (i = 0; i < 5; ++i) {
        sum += nums[i];
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    printf("  总和 = %d，最大值 = %d\n", sum, max);

    print_section("冒泡排序（从小到大）");
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
            }
        }
    }
    printf("  排序后：");
    for (i = 0; i < 5; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    print_section("字符串其实是「以 \\0 结尾的 char 数组」");
    printf("  greeting = \"%s\"\n", greeting);
    printf("  strlen(greeting) = %zu\n", strlen(greeting));
    printf("  注意：UTF-8 下一个汉字占 3 个字节，所以 2 个汉字是 6 字节。\n");
    printf("        strlen 数的是「字节数」，不是「字数」。\n");

    {
        char word[] = "cat";
        printf("  用纯英文字符串拆开看，就一目了然：");
        for (i = 0; word[i] != '\0'; ++i) {
            printf("[%c]", word[i]);
        }
        printf("  <- 末尾还藏着一个 '\\0'，它不显示，但 strlen 不算它\n");
    }

    print_section("常用字符串函数（需 #include <string.h>）");
    strcpy(buffer, greeting);
    strcat(buffer, "，");
    strcat(buffer, name);
    printf("  strcpy + strcat 拼出来：%s\n", buffer);
    printf("  strlen(\"%s\") = %zu\n", buffer, strlen(buffer));
    printf("  strcmp(\"abc\", \"abd\") = %d （负数表示前者小）\n",
           strcmp("abc", "abd"));

    pause_console();
}

/* ================= 第 7 课：函数 ================= */

/* 两数相加 */
static int add(int x, int y)
{
    return x + y;
}

/* 递归：阶乘 */
static long factorial(int n)
{
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

/* 递归：斐波那契 */
static int fibonacci(int n)
{
    if (n <= 2) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

static void lesson07(void)
{
    int i;

    print_title("第 7 课  函数");

    print_section("定义函数");
    printf("  返回类型 函数名(参数列表) { ... return 值; }\n");
    printf("  int add(int x, int y) { return x + y; }\n");

    print_section("调用函数");
    printf("  add(3, 5)   = %d\n", add(3, 5));
    printf("  add(10, -2) = %d\n", add(10, -2));

    print_section("递归：函数调用自己");
    printf("  5! = %ld\n", factorial(5));
    printf("  10! = %ld\n", factorial(10));

    printf("  斐波那契前 10 项：");
    for (i = 1; i <= 10; ++i) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    printf("  注意：递归要有「终止条件」，否则会无限调用。\n");

    print_section("为什么要把代码拆成函数");
    printf("  1. 一处编写，多处调用，避免重复\n");
    printf("  2. 每个函数只做一件事，容易阅读和调试\n");
    printf("  3. 可以先写 main 里的调用，再补函数实现\n");

    pause_console();
}

/* ================= 第 8 课：指针 ================= */

/* 通过指针交换两个变量的值 */
static void swap_by_pointer(int *px, int *py)
{
    int tmp = *px;
    *px = *py;
    *py = tmp;
}

static void lesson08(void)
{
    int value = 42;
    int *p = &value;
    int arr[5] = {10, 20, 30, 40, 50};
    int i;
    int a = 1, b = 2;

    print_title("第 8 课  指针入门");

    print_section("变量也有「门牌号」");
    printf("  value = %d\n", value);
    printf("  &value = %p   （& 取地址）\n", (void *)&value);
    printf("  p = &value;   p 存的就是这个地址\n");
    printf("  p = %p\n", (void *)p);
    printf("  *p = %d      （* 解引用：按地址取值）\n", *p);

    print_section("通过指针修改变量");
    *p = 100;
    printf("  执行 *p = 100 之后，value = %d\n", value);

    print_section("指针与数组");
    printf("  arr = %p, &arr[0] = %p（是同一个地址）\n",
           (void *)arr, (void *)&arr[0]);
    printf("  用指针遍历：");
    for (i = 0; i < 5; ++i) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    print_section("指针最常见的用途：让函数改到外面的变量");
    printf("  交换前：a = %d, b = %d\n", a, b);
    swap_by_pointer(&a, &b);
    printf("  交换后：a = %d, b = %d\n", a, b);

    print_section("易错点");
    printf("  1. 指针未初始化就解引用 —— 崩溃\n");
    printf("  2. 不要返回局部变量的地址\n");
    printf("  3. 指针类型要匹配：int *p 指向 int\n");

    pause_console();
}

/* ================= 第 9 课：结构体 ================= */

/* 定义一个学生类型 */
typedef struct {
    char name[32];
    int age;
    double score;
} Student;

/* 打印一个学生 */
static void print_student(const Student *s)
{
    printf("  %-8s 年龄 %2d  分数 %.1f\n", s->name, s->age, s->score);
}

static void lesson09(void)
{
    int i;
    int best = 0;
    Student class_list[3];

    print_title("第 9 课  结构体");

    print_section("把相关的数据打包在一起");
    printf("  typedef struct {\n");
    printf("      char name[32];\n");
    printf("      int age;\n");
    printf("      double score;\n");
    printf("  } Student;\n");

    strcpy(class_list[0].name, "小明");
    class_list[0].age = 20;
    class_list[0].score = 88.5;

    strcpy(class_list[1].name, "小红");
    class_list[1].age = 19;
    class_list[1].score = 95.0;

    strcpy(class_list[2].name, "小刚");
    class_list[2].age = 21;
    class_list[2].score = 76.5;

    print_section("结构体数组");
    for (i = 0; i < 3; ++i) {
        print_student(&class_list[i]);
    }

    print_section("找出分数最高的人");
    for (i = 1; i < 3; ++i) {
        if (class_list[i].score > class_list[best].score) {
            best = i;
        }
    }
    printf("  第一名：%s（%.1f 分）\n",
           class_list[best].name, class_list[best].score);

    print_section("两种访问方式");
    printf("  s.name   结构体变量用「.」\n");
    printf("  p->name  结构体指针用「->」\n");

    pause_console();
}

/* ================= 第 10 课：综合练习 ================= */

static void lesson10(void)
{
    int secret, guess = 0, tries = 0;
    int ok;

    print_title("第 10 课  综合练习：猜数字");

    srand((unsigned)time(NULL));
    secret = rand() % 100 + 1;

    printf("  我想好了一个 1 到 100 之间的整数。\n");
    printf("  输入你猜的数字，我会告诉你「大了」还是「小了」。\n");

    while (guess != secret) {
        ok = read_int("  请输入: ", &guess);
        if (!ok) {
            printf("  请输入一个整数（0 表示放弃）。\n");
            {
                char line[LINE_MAX_LEN];
                (void)fgets(line, sizeof line, stdin);
            }
            continue;
        }

        if (guess == 0) {
            printf("  放弃了？答案是 %d。\n", secret);
            pause_console();
            return;
        }

        ++tries;

        if (guess > secret) {
            printf("  大了\n");
        } else if (guess < secret) {
            printf("  小了\n");
        } else {
            printf("  猜对了！你用了 %d 次。\n", tries);
            break;
        }
    }

    print_section("这个程序用到了什么");
    printf("  - 变量与随机数（srand / rand）\n");
    printf("  - while 循环与 break\n");
    printf("  - if / else if 分支\n");
    printf("  - 输入读取与输入校验\n");
    printf("  - 计数器（tries）\n");

    pause_console();
}

/* ================= 主程序：菜单 ================= */

static void print_menu(void)
{
    printf("\n");
    print_rule();
    printf("          C 语言入门教学程序\n");
    print_rule();
    printf("   1. 你好，C 语言        6. 数组与字符串\n");
    printf("   2. 变量与数据类型      7. 函数\n");
    printf("   3. 输入与运算符        8. 指针入门\n");
    printf("   4. 条件分支            9. 结构体\n");
    printf("   5. 循环               10. 综合练习：猜数字\n");
    print_rule();
    printf("   0. 退出\n");
    print_rule();
}

int main(void)
{
    int choice = 0;

    setup_console();

    printf("\n欢迎使用 C 语言入门教学程序！\n");
    printf("每课都有讲解和可以直接运行的示例。\n");

    for (;;) {
        print_menu();

        if (!read_int("请选择课程编号（0 退出）: ", &choice)) {
            printf("输入无效，请重新选择。\n");
            continue;
        }

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1: lesson01(); break;
        case 2: lesson02(); break;
        case 3: lesson03(); break;
        case 4: lesson04(); break;
        case 5: lesson05(); break;
        case 6: lesson06(); break;
        case 7: lesson07(); break;
        case 8: lesson08(); break;
        case 9: lesson09(); break;
        case 10: lesson10(); break;
        default:
            printf("没有第 %d 课，请输入 1-10 或 0。\n", choice);
            break;
        }
    }

    printf("\n再见，祝你学得顺利！\n");
    return 0;
}
