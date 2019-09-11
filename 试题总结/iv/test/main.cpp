#include <iostream>
#include <memory.h>
#include <unistd.h>


using namespace std;


void intel()
{
    int num = 76421;
    int swp = 3;
    int decbit[10];
    memset(decbit, -1, sizeof(decbit));

    //获取每一位
    for (int i=0; num; ++i) {
        decbit[i] = num%10;
        num/=10;
    }

    //将数组逆序
    int pos=0;
    for (;decbit[pos] != -1; ++pos);
    pos--;
    for (int i = 0, j = pos; i < j; i++, j--)
    {
        int tmp = decbit[i];
        decbit[i] = decbit[j];
        decbit[j] = tmp;
    }

    //交换
    //外循环交换次数
    for (int i = 0; i < swp; ++i) {
        int min_index = i;
        //内循环找到最小值下标
        for (int j = i+1; decbit[j] != -1; ++j) {
            if (decbit[j] < decbit[min_index])
                min_index = j;
        }
        int tmp = decbit[i];
        decbit[i] = decbit[min_index];
        decbit[min_index] = tmp;
    }

    for (size_t i = 0; decbit[i] != -1; i++)
        cout << decbit[i];
}


void autel1()
{
    int val, ans = 0;
    cin >> val;
    int cnt = 0;
    for (int i=1; i < val; ++i) {
        if (val%i == 0 && i%2 == 1)
            ans+=i;
    }
    
    cout << ans << endl;
}


int *merge(int *a, int *b, int *c, int la, int lb)
{
    if (la == 0) {
        while (lb--)
            *c = b[lb];
    }
    if (lb == 0) {
        while (la--)
            *c = a[la];
    }

    if (*a < *b) {
        *c = *a;
        merge(a+1, b, c+1, la-1, lb);
    } else {
        *c = *b;
        merge(a, b+1, c+1, la, lb-1);
    }
}

void autel2()
{
    int arra[10];
    int arrb[10];
    int arrc[20];
    int lena = 0;
    int lenb = 0;
    
    for (int i = 0; i < 10; ++i) {
        if ('\n' == getchar()) 
            break;
        cin >> arra[i];
        lena++;
    }

    for (int i = 0; i < 10; ++i) {
        if ('\n' == getchar()) 
            break;
        cin >> arrb[i];
        lenb++;
    }

    merge(arra, arrb, arrc, lena, lenb);

    for (int i = 0; i < lena+lenb; ++i) {
        cout << arrc[i];
        if (i != lena+lenb-1)
            cout << ',';
    }
}


int main()
{
    
}