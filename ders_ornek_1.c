#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5;
    int *p = &a;
    printf(" a = %d ", a);
    printf(" p = %d ", p);
    printf(" a adresi =%d ", &a);
    printf(" p 'nin degeri = %d ", &p);
    printf("a 'nın gosterdigi degisken %d", *a);
    printf("a 'nın gosterdigi degisken %d", *p);
    printf("p' nin degeri %d", p);

    return 0;
}

