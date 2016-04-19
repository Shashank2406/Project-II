#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print(char *a, int i, int n) {
    int j;
    if(i == n) {
        printf("%s,", a);
    } else {
        for(j = i; j <= n; j++) {
            swap(a + i, a + j);
            print(a, i + 1, n);
            swap(a + i, a + j);
        }
    }
}

int main(void) {
    FILE *fp;
    int i,d=80,temp,j;
    char a[100][d],b[100];
    i=0;
    fp = fopen("one.txt", "r");
    while (feof(fp) == 0)
    {
     i++;
     fgets(a[i],d,fp);
    }
    temp=i;
    j=1;
    do{
        strcpy(b,a[j]);
        for(i=0;i<5;i++)
        {
            if(b[i]=='\n')
            {
            b[i]='\0';
            }
        }
        print(b, 0, strlen(b) - 1);
        printf("\n");
        j=j+1;
    }while(j<=temp);
    fclose(fp);
    return 0;
}
