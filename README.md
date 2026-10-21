# C 语言入门教学程序

一个可以直接运行的 C 语言互动教程。10 节课，从 `Hello, World!` 讲到指针和结构体，
每课都是「讲解 + 当场打印的真实输出」，可以边看边改边编译。

## 目录结构

```
.
├── c_tutorial.c    教学程序源码（全部内容都在这一个文件里）
├── build.bat       Windows 一键编译脚本
├── Makefile        make 编译
├── README.md       本文件
└── .tools/         本地工具链（w64devkit，已 gitignore，不会提交）
```

## 编译与运行

### Windows（最简单）

双击 `build.bat`，或在该目录打开命令行：

```bat
build.bat
c_tutorial.exe
```

`build.bat` 会优先用 PATH 里的 `gcc`；找不到时自动回退到 `.tools\w64devkit\bin\gcc.exe`。

### 用 gcc 手动编译

```bash
gcc -std=c11 -Wall -Wextra -O2 -o c_tutorial.exe c_tutorial.c
./c_tutorial.exe
```

### 用 MSVC

```bat
cl /W4 /utf-8 c_tutorial.c
```

> 源码以 UTF-8 保存。程序启动时会调用 `SetConsoleOutputCP(65001)` 把 Windows 控制台
> 切到 UTF-8，所以中文能正常显示。如果你用 Dev-C++ 这类老 IDE 看到乱码，改用上面的
> gcc/MSVC 命令编译即可。

## 课程列表

| 编号 | 课程 | 主要知识点 |
| --- | --- | --- |
| 1 | 你好，C 语言 | `printf`、转义字符、注释、程序结构 |
| 2 | 变量与数据类型 | `int` / `double` / `float` / `char`、格式符、`sizeof` |
| 3 | 输入与运算符 | 读入数字、四则运算、取余、类型转换、自增 |
| 4 | 条件分支 | `if` / `else if` / `else`、`switch` |
| 5 | 循环 | `for` / `while` / `do-while`、`break` / `continue`、嵌套 |
| 6 | 数组与字符串 | 数组遍历、冒泡排序、`\0`、`strlen` / `strcpy` / `strcat` |
| 7 | 函数 | 定义与调用、参数、返回值、递归 |
| 8 | 指针入门 | 取地址 `&`、解引用 `*`、指针与数组、用指针交换变量 |
| 9 | 结构体 | `struct` / `typedef`、结构体数组、`->` |
| 10 | 综合练习 | 猜数字游戏，综合运用前面所有内容 |

## 怎么用这份教程

1. **先跑一遍**：依次选 1 到 10，看每课输出什么。
2. **再改一遍**：打开 `c_tutorial.c`，找到对应函数（`lesson01` 到 `lesson10`），
   把数字、字符串改掉，重新编译看变化。
3. **最后写一遍**：合上教程，自己从空白文件重写第 10 课。

每课末尾都有「易错点」或「试一试」，建议至少动手改一处。

## 环境说明

本仓库的 `.tools/` 里放了一份 [w64devkit](https://github.com/skeeto/w64devkit)
（gcc 16.2.0 + make + gdb），仅本机使用，不会提交到仓库。
换一台机器时，装好 MinGW-w64 或直接用 MSVC 即可，代码本身不依赖任何第三方库。

## 许可

代码可自由使用、修改、分发，用于学习或教学均可。
