#include <wchar.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

int main ()
{
    int qtdmsg,tammsg,c,i,j,k, intraiz;
    float raiz;
    wchar_t dcod[100],cod[100];
    FILE *fp;

setlocale(LC_ALL,"");

    fp = fopen("mensagens_CA.txt","rt");
        if (fp==NULL) {
            printf("Não foi possivel abrir arquivo.\n");
                exit(1);
        }
fwscanf(fp,L"%d",&qtdmsg);
for(i = 0; i< qtdmsg; i++){
        fwscanf(fp,L"%d",&tammsg);
        fwscanf(fp,L" %[^\n]", cod);
        raiz = sqrt(tammsg);
        intraiz = (int)raiz;
        c=0;
    for(j = 0; j < intraiz; j++){
        for(k = j; k < tammsg;k = k+intraiz){
            wmemcpy(dcod+c , cod+k ,1);
            c++;
        }
    }
    wmemcpy(dcod+c,L"\0",1);
    printf("Mensagem: \n");
    printf("Tamanho da mensagem: %d \nRaiz: %d \nMensagem codificada: %ls ",tammsg,intraiz,cod);
    printf("\nMensagem decodificada: %ls \n\n\n",dcod);
}
fclose(fp);
}
