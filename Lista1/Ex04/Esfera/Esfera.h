//Arquivo Esfera.h
typedef struct esfera esfera;

//cria uma nova esfera
esfera *esfera_cria(float raio);

//libera uma esfera
void esfera_libera(esfera *r);

//Acessa o valor "raio" de esfera
float esfera_acessa(esfera *r);

//atribui o valor raio de uma esfera
void esfera_atribui(esfera *r, float raio);

//calcula a area total da esfera
float esfera_area(esfera *r);

//calcula o volume de uma esfera
float esfera_volume(esfera *r);

