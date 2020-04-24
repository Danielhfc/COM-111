//MENSAGENS COM ACENTO
// Uso do tipo wchar_t
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <math.h>
#include <locale.h>
int main()
{
// declarando ponteiro para arquivo
FILE *fp;
// declarando as variáveis
int qdemsgs, tammsg, c, i, j, k, lq;
float raiz;
wchar_t pmo[100];
wchar_t pmd[100];
setlocale(LC_ALL,"");
/* abre arquivo para leitura */
fp = fopen("mensagens_CA.txt","rt");
if (fp==NULL) {
printf("Não foi possivel abrir arquivo.\n");
exit(1);
}
/* Le do arquivo a quantidade de mensagens */
fwscanf(fp,L"%d",&qdemsgs);
i=0;
while (i < qdemsgs){
fwscanf(fp,L"%d", &tammsg);
fwscanf(fp,L" %[^\n]", pmo);
raiz = sqrt(tammsg);
lq = (int)raiz;
c = -1;
for(j=0; j < lq; j++){
for(k = j; k < tammsg; k = k + lq){
c++;
wmemcpy(pmd+c, pmo+k, 1 );
}
}
wmemcpy(pmd + c + 1, L"\0", 1);
printf("\nOriginal: \n ");
printf(" >> tm: %d \n >> lq: %d \n >> msg: %ls", tammsg, lq, pmo);
printf("\nDescripto: %ls\n\n", pmd);
i++;
} // fim while
return 0;
}

