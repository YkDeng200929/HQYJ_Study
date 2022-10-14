void count_data2(int *nu, int *ch, int *sm)
{
    int i;
    char buf[1024]={0};
    printf("输入：\n");
    scanf("%s", buf);
    for (i=0; i<sizeof(buf)/sizeof(buf[0]); i++)
    {        
        for (int j=0; j<10; j++)
        {
            if ((int)buf[i] == j)
                (*nu)++;
        }
        for (int a=0; a<10; a++)
        {
            if (buf[a] == 'a'+a)
                (*ch)++;
        }
        if ((buf[i]) != 0 && (buf[i+1] != 0))
            (*sm)++;
    }
}

int main()