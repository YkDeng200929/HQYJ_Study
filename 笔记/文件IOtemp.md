

## ���ļ�

### `ssize_t read(int fd, void *buf, size_t count)`<br>˵��: �� fd �ж�ȡ count ���ַ����ݵ� buf������(��Ϊϵͳ�����޻������ĸ���, �������buf�ַ��������������)<br>����ֵ: �������ַ�����

## д�ļ�

### `ssize_t write(int fd, const void *buf, size_t count`<br>˵��: �� buf �е� count ���ַ�д�뵽 fd(�ļ���ʶ��)��

## ��λ�ļ�

### `long lseek(int fd, off_t offset, int whence)`

### ͷ�ļ�����

- "sys/types.h"
- "unistd.h"

## ��Ŀ¼
### ��Ŀ¼
- `DIR * opendir(const char *name)`
### �ر�Ŀ¼
- `int closedir(DIR *dirp)`
### ��Ŀ¼
- `struct dirent * readdir(DIR *dirp)`<br>����ֵ�� ����Ŀ¼��һ���ļ��� struct dirent �ṹ���׵�ַ, ������β���� NULL, errno����, ������ NULL, ���� errno
- 
```
struct dirent
{
	ino_t d_ino; // Ŀ¼�ļ� inode ��, ls -i ��ѯ
	off_t d_off; // ��Ŀ¼�ļ��е�ƫ��
	unsigned short d_reclen; // Ŀ¼�ļ�����
	unsigned char d_type; // �ļ����� bcd-lps
	char d_name[256]; // Ŀ¼�ļ�������, � 255�ַ�
}
```
- d_type ȡֵ����
```
	DT_BLK	this is a block device
	DT_CHR	this is a character device
	DT_DIR	this is a directory
	DT_FIFO	this is a named pipe
	DT_LNK	this is a symbolic link
	DT_REG	this is a regular file
	DT_SOCK	this is a UNIX domain socket
```
