/*
 * File:   listaEncadeada.h
 * Author:
 *
 * Created
 */

#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

  typedef struct no Tipono;
  typedef struct lista TipoLista;

  TipoLista *LCria();//F01
  void LInsereInicio(TipoLista *le, int valor);//F02
  void LInsereFinal(TipoLista *le, int valor);//F03
  void LInsereOrdenado(TipoLista *le, int valor);//F04
  int  LConsultaElemento(TipoLista *le, int valor);//F05
  void LRemoveElemento(TipoLista *le, int valor);//F06
  void LRemoveElemento_rec(TipoLista *le, int valor);//F07
  void FLVazia(TipoLista *le);//F08
  void FLVazia_rec(TipoLista *le);//F09
  int  LVazia(TipoLista *le);//F10
  void LImprime(TipoLista *le);//F11
  void LImprime_rec(TipoLista *le);//F12
  int  LTamanho(TipoLista *le);//F13
  int  LSoma(Tipono *no);//F14
  Tipono *LRetornaInicio(TipoLista *le);//F15
  void NoDisplay(Tipono *no);//F16

#endif /* LISTAENCADEADA_H */

