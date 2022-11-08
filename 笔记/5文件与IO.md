# ��׼IO(�ļ���д)

## ctags��װ

- sudo apt-get install exuberance-ctags
- ִ�����½ű�

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

- �鿴�Ƿ�װ: `vi -t FILE`

## `FILE *stream`

- stdout: ��׼�����
- stderr: ��׼������
- stdin: ��׼������

## ��׼�������(printf������)

### `int fprintf(FILE *stream, const char *format, ...)`<br>˵��: ���͸�ʽ����������� <br>����ֵ: �ɹ�������д����ַ�����, ���򷵻�һ������

```
char buf[] = "hello";
fprintf(stdout, "%s", buf);
```

### `int sprintf(char *str, const char *formatm, ...)`<br>˵��: ���͸�ʽ������� str ָ����ַ��� <br>����ֵ: �ɹ�����д����ַ�����, ���򷵻�һ������

```
int a = 123;
char buf[1024] = {0};
sprintf(buf, "%d", a);  �� buf �е����ݸ�ʽ��, Ȼ�� a ��ֵ�� buf
```

## ��׼IO�еĻ�����

- | IOģ�� | ��׼IO             | �ļ�IO   |
  | ------ | ------------------ | -------- |
  | ���   | �⺯��             | ϵͳ���� |
  | ����   | �л���             | �޻���   |
  | ��   | fopen              | open     |
  | ��     | fgetc/fgets/fread  | read     |
  | д     | fputc/fputs/fwrite | write    |
  | ��λ   | fseek/ftell        | lseek    |
  | �ر�   | fclose             | close    |

### �л���

- ����ռ� 1024, 1025ʱˢ��
- ����ַ���ʱ���Ƚ��ַ����������������Ȼ�����
- fflush(FILE *stream): ˢ���� stream �����������
- putchar('\n'): ������ˢ���л���, ����**ֻ���л���**

### ȫ����

- ����ռ� 4096, 4097ʱˢ�»�����

### �޻���

- ��׼�����޻���

## �ļ���������

### `FILE * fopen(const char *[filename][filepath], const char *mode)`<br>˵��: ��ָ��ģʽ���ļ�, filename �������ļ�·�� <br>����ֵ:�ɹ���ȡ���� FILE ָ��, ���򷵻�NULL**����ʹ�� errno ����ʶ����**

#### ����:

- "r": ��һ�����ڶ�ȡ���ļ�**���ļ��������**
- "r+": ��һ�����ڸ��µ��ļ�, **���ļ����Զ�ȡҲ����д��, ���������**
- "w": ����һ������***ֻд***�Ŀ��ļ�, ������ͬ���ļ�, ��Ḳ��
- "w+": ����һ������***��д***�Ŀ��ļ�
- "a": ��һ�����ڶ�ȡ��׷�ӵ��ļ�

### `int fclose(FILE *stream)`<br>˵��: �ر��ļ��� <br>�ɹ��رշ���0, ���򷵻� EOF(-1)

## ���ַ���д����
### `int fgetc(FILE *stream)`<br>˵��: ��ȡ�ļ����е�**�ַ�**��ȡ���βֵ��ʶ����ǰ�ƶ� <br>����ֵ: ���޷��� char ǿ��ת��Ϊ int ����ʽ**���ض�ȡ���ַ�**, ��������ļ�ĩβ����������ʱ���� EOF

### `int fputc(int char, FILE *stream)`<br>˵��: ��ָ�����ַ�д��ָ�����ļ����� <br>����ֵ: ���û��������, �򷵻ر�д����ַ�, ���򷵻� EOF

### ����������������ʵ���ļ�����

```
void copy(FILE *org, FILE *dest);

int main(void)
{
	hello.txt --����--> welcom to wuhan
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

## ��������

### `void perror(const char *str)`<br>˵��: �� str ���ڱ�׼���� stderr ǰ��

```
FILE *fp;
fp fopen("hello.txt", "r");
if (fp == NULL)
{
	perror("hello");
}

--> hello: No Such File
```

### `char *strerror(int errnum)`<br>˵��: �Ӻ����ڲ����������������, ������һ��ָ�������Ϣ��ָ�� `<br>`��������: string.h <br>����ֵ: �ú�������һ��ָ������ַ�����ָ��, �ô����ַ��������˴��� errnum (errno.h)

```
fprintf(fp, "%s\n", strerror(errno));
```

## ���ж�д����

### `char * fgets(char *s, int size, FILE *stream)<br>`˵��: ��ָ�����ж�ȡ **size-1 ���ַ�**���� s ��(**����'\n'����, '\n'Ҳ����� s, ���� s��ĩβ��� '\0'**)`<br>`����ֵ: �ɹ������ַ���, ����ȡʧ�ܻ򵽴��ļ�β�˷���NULL

### `int fputs(const char *s, FILE *stream)<br>`˵��: ���ַ������뵽ָ���ļ�����, ����'\0'ʱ����`<br>`����ֵ: **�ɹ����طǸ���, ʧ�ܷ��� EOF**

## ��������ж�д

### ��

#### `size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)`

#### ˵��: �Ӹ����� stream ��ȡ���ݵ� ptr ��ָ���������

#### ����˵��:

- ptr: Ҫ��д�������
- size: Ҫ��ȡ��ÿ��Ԫ�صĴ�С, ���ֽ�Ϊ��λ
- nmemb: Ԫ�ظ���
- ����ֵ: �ɹ���ȡ���سɹ�д��Ķ������, ʧ�ܻ��߶�ȡ���ļ���ĩβ����0

### д

#### `size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)`

#### ˵��: �� ptr ָ�������д�뵽�ļ�����

# ��׼IO(�ļ���λ)

## `int fseek(FILE *stream, log offset, int whence)`

## `long ftell(FILE *stream)`

# �ļ�IO(��������)

## ���ļ�

### `int open(const char *pathname, int flags) or int open(const char *pathname, int flags, mode_t mode)`
### flags����
- O_WRONLY: ֻд
- O_RDONLY: ֻ��
- O_RDWR: ��д
- O_CREAT: û�оʹ���
- O_TRUNC: �ض�
- ��|������ÿ��flags
### mode˵��
- ���ļ���Ȩ��: ���磺0666
- ʵ��Ȩ���� mode & ~umask����ֵ

## �ر��ļ�

### `int close(int fd)`

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
- `struct dirent * readdir(DIR *dirp)`
