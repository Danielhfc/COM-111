/*ARVOREBIN _H */
#ifndef ARVOREBINARIA _H
#define ARVOREBINARIA _H

typedef struct NO* ArvBin;
ArvBin * ArvBinCriar(); //F01
int ArvBin Liberar(ArvBin *raiz); //F02
int ArvBinVazia(ArvBin *raiz); //F03
int ArvBinAltura(ArvBin *raiz); //F04
int ArvBinTotalNO (ArvBin *raiz); //F05
int ArvBinPreOrdem (ArvBin *raiz); //F06
int ArvBinEmOrdem (ArvBin *raiz); //F07
int ArvBinPosOrdem (ArvBin *raiz); //F08
int ArvBinInsere (ArvBin *raiz, int valor); //F09
int ArvBin Remove (ArvBin *raiz, int valor); //F10
int ArvBinConsulta (ArvBin *raiz, int valor); //F11
#endif /* ARVOREBIN _H */
