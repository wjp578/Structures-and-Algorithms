#include "string_Ope.h"
#include <string.h>

//��ʼ��
void Initiate(Dstring *str)
{
    str->len = 0;
    str->max_len = 0;
    str->String = NULL;
}


//�ַ�����ֵ
void Assign_Operate(Dstring *str, const char *src)
{
    int len = strlen(src);
    if (len <= str->max_len && str->max_len != 0 && str->String != NULL)
    {
        memcpy(str->String, src, len);
        str->len = len;
        //test
//        printf("len <= str->max_len && str->max_len != 0 && str->String != NULL\n");
        return;
    }

    if (len == 0 && str->String == NULL)
    {
        str->String = (char*)malloc(1);
        str->len = 0;
        str->max_len = 1;
//        printf("len == 0 && str->String == NULL\n");
        return;
    }

    //����״̬
    //1��StringԭΪ��ָ��---realloc()�����¿ռ䲢��ֵ��String
    //2��String��Ϊ�գ�realloc()�󷵻�ֵΪԭ��ַ---����String
    //3��String��Ϊ�գ�realloc()�󷵻�ֵΪ�µ�ַ---realloc�ͷ��Ͽռ䣬������ָ�븳��String
    char *new_ptr = (char*)realloc(str->String, len);
    str->String = new_ptr;
    memcpy(str->String, src, len);
    str->len = len;
    str->max_len = len;
//    printf("Other situations\n");
}


//��posλ�ú��ַ�����offset(�Ӵ�����)��λ��
void String_Offset(Dstring *str, int pos, int offset)
{
    int len = str->len, i = 0;
    //���ַ������⡰+1������---�����û����ԣ��ַ���1��ʼ,��Ӧ�ں�0λ��
    //������Ϊ0�����ں�Ϊ-1������Խ��
    if (len == 0)
        len++;
    int count = len - pos + 1; //pos�󣨰���pos��Ԫ�ظ���|��Ҫ�ƶ���Ԫ�ظ���
    for (i = 0; i < count; i++)
    {
        str->String[len - 1 + offset] = str->String[len - 1];
        len--;
    }
}


//�����Ӵ�
//��posλ�ò����Ӵ�
int Insert(Dstring *str, const Dstring *sub_str, int pos)
{
    //posΪ�û�����λ�ã���1��ʼ
    //λ�÷Ƿ����������
    //���ַ���  ��Ϊ  ���ַ���ʱ��λ�ô��ڳ��ȣ�λ�÷Ƿ�
    //���ַ���   Ϊ   ���ַ���ʱ��λ�ô���1��λ�÷Ƿ�
    if ((pos > str->len && str->len != 0) || (str->len == 0 && pos > 1))
    {
        printf("Illegal position");
        return 0;
    }

    if ((str->len + sub_str->len) <= str->max_len)
    {
        String_Offset(str, pos, sub_str->len);
        memcpy(str->String + pos - 1, sub_str->String, sub_str->len);
        str->len = str->len + sub_str->len;
        printf("(str->len + sub_str->len) <= str->max_len\n");
        return 1;
    }

    char *new_ptr = (char*)realloc(str->String, str->len + sub_str->len);
    str->String = new_ptr;
    //��ƫ���ڸı���ֵ��len��max_len��
    String_Offset(str, pos, sub_str->len);
    str->max_len = str->len + sub_str->len;
    str->len = str->len + sub_str->len;
    memcpy(str->String + pos - 1, sub_str->String, sub_str->len);
    printf("Other situations\n");
    return 1;
}


//��ӡstring
void print(const Dstring *str)
{
    if (str->String == NULL)
    {
        printf("please assign!!\n");
        return;
    }

    int i;
    for (i = 0; i < str->len; i++)
        printf("%c", str->String[i]);
    printf("\tlength=%d\tmaxlength=%d\n\n", str->len, str->max_len);
}


//����
void destory(Dstring *str)
{
    free(str->String);
    str = NULL;
}
