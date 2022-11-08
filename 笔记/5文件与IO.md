# 标准IO(文件读写)

## ctags安装

- sudo apt-get install exuberance-ctags
- 执行以下脚本

```
#! /bin/bash

#Mon Aug 26 15:13:48 CST 2013
#designed by tim

TAGS="set tags+=/usr/include/tags"
MAP="map <F9> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<CR>"
JUMP="nmap <c-]> g<c-]>"

for var in "$MAP" "$TAGS" "$JUMP"
do
    ret=`grep "$var" ~/.vimrc | wc -l`
    if [ $ret -eq 0 ]
    then
        echo "$var" >> ~/.vimrc
    fi
done

ls -lh /usr/include/tags 2> /dev/null
if [ $? -ne 0 ]
then
    cd /usr/include/
    sudo ctags -R --c++-kinds=+p --fields=+iaS --extra=+q . 2> /dev/null
fi

```

- 查看是否安装: `vi -t FILE`

## `FILE *stream`

- stdout: 标准输出流
- stderr: 标准错误流
- stdin: 标准输入流

## 标准输出函数(printf函数类)

### `int fprintf(FILE *stream, const char *format, ...)`<br>说明: 发送格式化输出到流中 <br>返回值: 成功过返回写入的字符总数, 否则返回一个负数

```
char buf[] = "hello";
fprintf(stdout, "%s", buf);
```

### `int sprintf(char *str, const char *formatm, ...)`<br>说明: 发送格式化输出到 str 指向的字符串 <br>返回值: 成功返回写入的字符总数, 否则返回一个负数

```
int a = 123;
char buf[1024] = {0};
sprintf(buf, "%d", a);  将 buf 中的内容格式化, 然后将 a 赋值给 buf
```

## 标准IO中的缓存区

- | IO模型 | 标准IO             | 文件IO   |
  | ------ | ------------------ | -------- |
  | 层次   | 库函数             | 系统调用 |
  | 缓存   | 有缓存             | 无缓存   |
  | 打开   | fopen              | open     |
  | 读     | fgetc/fgets/fread  | read     |
  | 写     | fputc/fputs/fwrite | write    |
  | 定位   | fseek/ftell        | lseek    |
  | 关闭   | fclose             | close    |

### 行缓存

- 缓存空间 1024, 1025时刷新
- 输出字符串时会先将字符串存入输出缓存区然后输出
- fflush(FILE *stream): 刷新流 stream 的输出缓冲区
- putchar('\n'): 可用于刷新行缓存, 不过**只限行缓存**

### 全缓存

- 缓存空间 4096, 4097时刷新缓存区

### 无缓存

- 标准出错无缓存

## 文件操作函数

### `FILE * fopen(const char *[filename][filepath], const char *mode)`<br>说明: 以指定模式打开文件, filename 可以是文件路径 <br>返回值:成功读取返回 FILE 指针, 否则返回NULL**可以使用 errno 来标识错误**

#### 参数:

- "r": 打开一个用于读取的文件**该文件必须存在**
- "r+": 打开一个用于更新的文件, **该文件可以读取也可以写入, 但必须存在**
- "w": 创建一个用于***只写***的空文件, 若存在同名文件, 则会覆盖
- "w+": 创建一个用于***读写***的空文件
- "a": 打开一个用于读取和追加的文件

### `int fclose(FILE *stream)`<br>说明: 关闭文件流 <br>成功关闭返回0, 否则返回 EOF(-1)

## 按字符读写函数
### `int fgetc(FILE *stream)`<br>说明: 读取文件流中的**字符**读取后把尾值标识符往前移动 <br>返回值: 以无符号 char 强制转换为 int 的形式**返回读取的字符**, 如果到达文件末尾或发生读错误时返回 EOF

### `int fputc(int char, FILE *stream)`<br>说明: 将指定的字符写入指定的文件流中 <br>返回值: 如果没发生错误, 则返回被写入的字符, 否则返回 EOF

### 利用以上两个函数实现文件复制

```
void copy(FILE *org, FILE *dest);

int main(void)
{
	hello.txt --内容--> welcom to wuhan
	FILE *org, *dest;
	org = fopen("hello.txt", "r");
	dest = fopen("copy.txt", "w");
	copy(org, dest);
	fclose(org);
	fclose(dest);

	return 0;
}
void copy(FILE *org, FILE *dest)
{
	int val = 0;
	while (1)
	{
		val = fgetc(org);
		if (val == EOF)
		break;
		fputc(val, dest)
	}
}

```

## 错误处理函数

### `void perror(const char *str)`<br>说明: 把 str 放在标准错误 stderr 前面

```
FILE *fp;
fp fopen("hello.txt", "r");
if (fp == NULL)
{
	perror("hello");
}

--> hello: No Such File
```

### `char *strerror(int errnum)`<br>说明: 从函数内部数组中搜索错误号, 并返回一个指向错误消息的指针 `<br>`函数调用: string.h <br>返回值: 该函数返回一个指向错误字符串的指针, 该错误字符串描述了错误 errnum (errno.h)

```
fprintf(fp, "%s\n", strerror(errno));
```

## 按行读写函数

### `char * fgets(char *s, int size, FILE *stream)<br>`说明: 从指定流中读取 **size-1 个字符**存入 s 中(**遇到'\n'结束, '\n'也会存入 s, 会在 s的末尾添加 '\0'**)`<br>`返回值: 成功返回字符串, 若读取失败或到达文件尾端返回NULL

### `int fputs(const char *s, FILE *stream)<br>`说明: 把字符串输入到指定文件流中, 遇到'\0'时结束`<br>`返回值: **成功返回非负数, 失败返回 EOF**

## 按对象进行读写

### 读

#### `size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)`

#### 说明: 从给定流 stream 读取数据到 ptr 所指向的数组中

#### 参数说明:

- ptr: 要被写入的数组
- size: 要读取的每个元素的大小, 以字节为单位
- nmemb: 元素个数
- 返回值: 成功读取返回成功写入的对象个数, 失败或者读取到文件的末尾返回0

### 写

#### `size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)`

#### 说明: 把 ptr 指向的数组写入到文件流中

# 标准IO(文件定位)

## `int fseek(FILE *stream, log offset, int whence)`

## `long ftell(FILE *stream)`

# 文件IO(操作函数)

## 打开文件

### `int open(const char *pathname, int flags) or int open(const char *pathname, int flags, mode_t mode)`
### flags参数
- O_WRONLY: 只写
- O_RDONLY: 只读
- O_RDWR: 读写
- O_CREAT: 没有就创造
- O_TRUNC: 截断
- 以|来隔开每个flags
### mode说明
- 给文件以权限: 例如：0666
- 实际权限是 mode & ~umask的数值

## 关闭文件

### `int close(int fd)`

## 读文件

### `ssize_t read(int fd, void *buf, size_t count)`<br>说明: 从 fd 中读取 count 个字符传递到 buf缓冲中(因为系统调用无缓冲区的概念, 所以这个buf字符数组替代缓冲区)<br>返回值: 读到的字符数量

## 写文件

### `ssize_t write(int fd, const void *buf, size_t count`<br>说明: 将 buf 中的 count 个字符写入到 fd(文件标识符)中

## 定位文件

### `long lseek(int fd, off_t offset, int whence)`

### 头文件调用

- "sys/types.h"
- "unistd.h"

## 打开目录
### 打开目录
- `DIR * opendir(const char *name)`
### 关闭目录
- `int closedir(DIR *dirp)`
### 读目录
- `struct dirent * readdir(DIR *dirp)`
