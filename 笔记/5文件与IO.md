# 文件与IO

## 1. 准备(ctags 安装)
1. sudo apt-get install exbuerance-ctags
2. 执行以下代码

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

3. 检查ctags的安装: `vi -t FILE`

## 2. 标准IO(C库函数)
### 规则
1. 标准IO使用文件流来定位文件
2. 操作文件后记得对文件进行重新定位
3. 三个标准流流 `FILE *stream`
	- `stdout`
	- `stderr`
	- `stdin`
4. **标准IO有缓存**
	1. 行缓存 (缓存空间为 1024)
	2. 全缓存 (缓存空间为 4096)
	3. 无缓存
### 2.1 fprintf函数簇
1. `fprintf(FILE *stream, const char *format, ...)`
2. `sprintf(char *str, const char *format, ...)`
	- 将指定的字符串给指定流
	- 以上两者如果成功执行, 返回成功读到的字符总数, 否则返回一个负数
### 2.2 打开关闭文件函数
1. `fopen()`
	1. "r" "r+": 文件必须存在
	2. "w": 文件存在会覆盖写入
	3. "a"(append): 追加写入
2. `fclose()`
	- 关闭成功返回0, 否则返回EOF(-1)
### 2.3 读写文件操作
#### 2.3.1 按字符读写
1. `fgetc(FILE *stream)`
	- 从流中读取单个字符
	- 返回值: 为读到的字符
2. `fputc(int char, FILE *stream)`
	- 将指定的字符写入流中
	- 返回值: 成功返回被写入的字符, 否则返回EOF
#### 2.3.2 按行读写
1. `char * fgets(char *s, int size, FILE *stream)`
	- 从流中读取 **size-1** 个字符存入字符数组 s 中
	- 返回值: 成功返回字符串, 失败或读到文件尾端时返回NULL
2. `int fputs(const char *s, FILE *stream)`
	- 把指定字符串输入到流中
	- 返回值: 成功返回非负数, 失败返回EOF
#### 2.3.3 按对象读写
1. 规则: 需要有个结构体
2. `fread`
3. `fwrite`
#### 2.3.4 文件定位
1. `fseek`
2. `ftell`
	- 直接定位到文件尾部
3. `rewind`
	- (倒带): 直接定位到文件头部
#### 2.3.5 错误处理
1. `void *perror(const char *str)`
	- 对置errno的函数输出错误内容
2. `strerror(int errnum)`
3. `fprintf(stderr, "<错误内容>")`
	- 对不置errno的函数可以使用该打印错误的方式

## 3. 文件IO(系统调用)
### 规则
1. 文件IO使用fd(file description)对文件进行定位
2. 与标准IO一样, 对文件进行操作后需要对文件进行重新定位
### 3.2 打开关闭文件函数
1. `int open(pathname, flags)`
2. `int open(pathname, flags, mode)`
	1. @pathname: 可以是文件名也可以是路径名
	2. @flags: O_CREAT: 没有就创建, O_TRUNC: 截断
	3. @mode: 权限(实际权限为 mode & ~umask) 0666
3.  `close`
### 3.3 读写文件操作
1. `ssize_t read(int fd, void *buf, size_t count)`
2. `ssize_t write(int fd, const void *buf, size_t count)`
### 3.4 目录操作
#### 3.4.1 打开关闭目录
1. `DIR * opendir(const char *name)`
2. `int closedir(DIR *dirp)`
#### 3.4.2 读目录
- `struct dirent * readdir(DIR *dirp)`
	1. 返回值: 返回目录中一个文件的 struct dirent 结构的首地址, 读到结尾返回NULL
	2. struct dirent

			struct dirent
			{
				into_t d_ino;		// 目录文件的 inode 号, ls -i 查询
				off_t d_off;		// 在目录文件中的偏移
				unsigned short d_reclen;// 目录文件名长
				unsigned char d_type;// 文件类型
				char d_name[256];// 目录文件的名字, 最长 255 字符
			}

	3. d_type 取值类型

				DT_BLK	this is a block device
				DT_CHR	this is a character device
				DT_DIR	this is a directory
				DT_FIFO	this is a named pipe
				DT_LNK	this is a symbolic link
				DT_REG	this is a regular file
				DT_SOCK	this is a UNIX domain socket

### 3.4 定位文件
- `long lseek(int fd, off_t offset, int whence)` [参考标准IO](#234-文件定位)