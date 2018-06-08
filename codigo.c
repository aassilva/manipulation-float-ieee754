#include<stdio.h>

#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))
#define getsig(x) ((x)>>31 & 1)
#define getexp(x) ((x)>>23 & 0xff)
#define getfrac(x) ((x) & 0x7fffff)

typedef union {
 float f;
 unsigned int i;
} U;


float float2(float f) {
    U u;
    u.f = f;
    unsigned int sinal = getsig(u.i);
    unsigned int expresao = getexp(u.i);
    unsigned int fracao = getfrac(u.i);
    expresao += 1;
    u.i = makefloat(sinal,expresao,fracao);
}

int main() {
    float numero;
    printf("Digite um número flutuante:\n");
    scanf("%f", &numero);
    float2(numero);
    printf("%f\n", u.f);
    return 0;

}
