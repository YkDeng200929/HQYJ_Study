# �ļ���IO

## 1. ׼��(ctags ��װ)
1. sudo apt-get install exbuerance-ctags
2. ִ�����´���

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

3. ���ctags�İ�װ: `vi -t FILE`

## 2. ��׼IO(C�⺯��)
### ����
1. ��׼IOʹ���ļ�������λ�ļ�
2. �����ļ���ǵö��ļ��������¶�λ
3. ������׼���� `FILE *stream`
	- `stdout`
	- `stderr`
	- `stdin`
4. **��׼IO�л���**
	1. �л��� (����ռ�Ϊ 1024)
	2. ȫ���� (����ռ�Ϊ 4096)
	3. �޻���
### 2.1 fprintf������
1. `fprintf(FILE *stream, const char *format, ...)`
2. `sprintf(char *str, const char *format, ...)`
	- ��ָ�����ַ�����ָ����
	- ������������ɹ�ִ��, ���سɹ��������ַ�����, ���򷵻�һ������
### 2.2 �򿪹ر��ļ�����
1. `fopen()`
	1. "r" "r+": �ļ��������
	2. "w": �ļ����ڻḲ��д��
	3. "a"(append): ׷��д��
2. `fclose()`
	- �رճɹ�����0, ���򷵻�EOF(-1)
### 2.3 ��д�ļ�����
#### 2.3.1 ���ַ���д
1. `fgetc(FILE *stream)`
	- �����ж�ȡ�����ַ�
	- ����ֵ: Ϊ�������ַ�
2. `fputc(int char, FILE *stream)`
	- ��ָ�����ַ�д������
	- ����ֵ: �ɹ����ر�д����ַ�, ���򷵻�EOF
#### 2.3.2 ���ж�д
1. `char * fgets(char *s, int size, FILE *stream)`
	- �����ж�ȡ **size-1** ���ַ������ַ����� s ��
	- ����ֵ: �ɹ������ַ���, ʧ�ܻ�����ļ�β��ʱ����NULL
2. `int fputs(const char *s, FILE *stream)`
	- ��ָ���ַ������뵽����
	- ����ֵ: �ɹ����طǸ���, ʧ�ܷ���EOF
#### 2.3.3 �������д
1. ����: ��Ҫ�и��ṹ��
2. `fread`
3. `fwrite`
#### 2.3.4 �ļ���λ
1. `fseek`
2. `ftell`
	- ֱ�Ӷ�λ���ļ�β��
3. `rewind`
	- (����): ֱ�Ӷ�λ���ļ�ͷ��
#### 2.3.5 ������
1. `void *perror(const char *str)`
	- ����errno�ĺ��������������
2. `strerror(int errnum)`
3. `fprintf(stderr, "<��������>")`
	- �Բ���errno�ĺ�������ʹ�øô�ӡ����ķ�ʽ

## 3. �ļ�IO(ϵͳ����)
### ����
1. �ļ�IOʹ��fd(file description)���ļ����ж�λ
2. ���׼IOһ��, ���ļ����в�������Ҫ���ļ��������¶�λ
### 3.2 �򿪹ر��ļ�����
1. `int open(pathname, flags)`
2. `int open(pathname, flags, mode)`
	1. pathname: �������ļ���Ҳ������·����
	2. flags: O_CREAT: û�оʹ���, O_TRUNC: �ض�
	3. mode: Ȩ��(ʵ��Ȩ��Ϊ mode & ~umask) 0666
3.  `close`
### 3.3 ��д�ļ�����
1. `read`
2. `write`
### 3.4 ��λ�ļ�