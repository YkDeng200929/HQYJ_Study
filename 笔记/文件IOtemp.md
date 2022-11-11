

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
- `struct dirent * readdir(DIR *dirp)`<br>返回值： 返回目录中一个文件的 struct dirent 结构的首地址, 读到结尾返回 NULL, errno不变, 出错返回 NULL, 并置 errno
- 
```
struct dirent
{
	ino_t d_ino; // 目录文件 inode 号, ls -i 查询
	off_t d_off; // 在目录文件中的偏移
	unsigned short d_reclen; // 目录文件名长
	unsigned char d_type; // 文件类型 bcd-lps
	char d_name[256]; // 目录文件的名字, 最长 255字符
}
```
- d_type 取值类型
```
	DT_BLK	this is a block device
	DT_CHR	this is a character device
	DT_DIR	this is a directory
	DT_FIFO	this is a named pipe
	DT_LNK	this is a symbolic link
	DT_REG	this is a regular file
	DT_SOCK	this is a UNIX domain socket
```
