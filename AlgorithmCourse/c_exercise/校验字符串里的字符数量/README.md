# 使用说明

## 文件介绍
- wc.cpp 代码文件
- test 测试文件

## 命令使用
- 进入test目录下，打开命令行，使用命令`wc.exe [parameter] [file_name]`
    + parameter：命令类型
        + -c : 统计文件字符数
        + -w : 统计文件词数
        + -l : 统计文件行数
    + file_name：文件名
+ 示例：
```
    wc.exe -c file.c    //返回文件 file.c 的字符数
    wc.exe -w file.c    //返回文件 file.c 的词的数目  
    wc.exe -l file.c    //返回文件 file.c 的行数
```