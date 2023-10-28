#include <stdio.h>
#include <stdlib.h>

// tamanho da memória
#define MEMSIZE 10000

int M[MEMSIZE] = {0}; // representa a memória do HIPO.

void loadM(char *imgFileName) {
  FILE *fp;
  fp = fopen(imgFileName, "rt");
  int i = 0;
  printf("Efetuando a leitura do conteúdo\n");
  while (!feof(fp)) {
    printf("Lendo linha %d ", i);
    fscanf(fp, "%d\n", &(M[i]));
    printf("conteúdo: %d \n", M[i]);
    ++i;
  }
  fclose(fp);
}

void dumpM() {
  for (int i = 0; i < MEMSIZE; i++) {
    printf("(%d,%d)\t", i, M[i]);
  }
}

int acumulador = 0;
int apontador_instrucao = 0;

void executa() {
  printf("\nExecução: \n");
  while (apontador_instrucao < MEMSIZE) {

    int instrucao = M[apontador_instrucao]; // variável auxiliar
    int codigo_instrucao =
        instrucao / 100; // código que define qual instrução será realizada
    int codigo_memoria = instrucao % 100; // memória que está sendo modificada

    if (codigo_instrucao == 70)
      break;

    switch (codigo_instrucao) {
    case 11: { // copia o conteudo do codigo_memoria no acumulador
      acumulador = M[codigo_memoria];
    } break;

    case 12: { // Copie o conteúdo do acumulador no codigo_memoria
      M[codigo_memoria] = acumulador;
    } break;

    case 21: { // Conteúdo do acumulador + codigo_memoria -> acumulador.
      acumulador += M[codigo_memoria];
    } break;

    case 22: { // Conteúdo do acumulador - codigo_memoria -> acumulador.
      acumulador -= M[codigo_memoria];
    } break;

    case 23: { // Conteúdo do acumulador * codigo_memoria -> acumulador.
      acumulador *= M[codigo_memoria];
    } break;

    case 24: { // Conteúdo do acumulador / codigo_memoria -> acumulador.
      acumulador /= M[codigo_memoria];
    } break;

    case 25: { // Acumulador recebe o resto da divisão
      acumulador %= M[codigo_memoria];
    } break;

    case 31: { // Recebe um número
      printf("Digite um número: ");
      scanf(" %i", &M[codigo_memoria]);
    } break;

    case 41: { // Imprime o conteúdo
      printf("%i\n", M[codigo_memoria]);
    } break;

    case 50: { // Não realiza operação
    } break;

    case 51: { // Desvie a execução para o endereço
      apontador_instrucao = codigo_memoria - 1;
    } break;

    case 52: { // Desvie a execução para o endereço se o conteúdo do for maior
               // que zero
      if (acumulador > 0)
        apontador_instrucao = codigo_memoria - 1;
    } break;

    case 53: { // Desvie a execução para o endereço se o conteúdo do for maior
               // ou igual a zero
      if (acumulador >= 0)
        apontador_instrucao = codigo_memoria - 1;
    } break;

    case 54: { // Desvie a execução para o endereço se o conteúdo do acumulador
               // for menor que zero
      if (acumulador < 0)
        apontador_instrucao = codigo_memoria - 1;
    } break;

    case 55: { // Desvie a execução para o endereço se o conteúdo do acumulador
               // for menor ou igual a 0
      if (acumulador <= 0)
        apontador_instrucao = codigo_memoria - 1;
    } break;

    case 56: { // Desvie a execução para o endereço se o conteúdo do acumulador
               // for diferente de 0
      if (acumulador != 0)
        apontador_instrucao = codigo_memoria - 1;
    } break;

    case 57: { // Desvie a execução para o endereço se o conteúdo do acumulador
               // for igual a 0
      if (acumulador == 0)
        apontador_instrucao = codigo_memoria - 1;
    } break;

    case 61: { // Desloca os dígitos p/ esquerda e despreza dígito mais
               // significativo
      if (acumulador < 10 && acumulador > -10) {
        acumulador = 0;
        break;
      }

      int result = 1;

      for (int divisor = 10; acumulador / divisor; divisor *= 10) {
        result = acumulador % divisor;
      }

      acumulador = 10 * result;
    } break;

    case 62: { // Desloca os dígitos p/ direita e despreza dígito menos
               // significativo
      acumulador /= 10;
    } break;

    default: // ERRO
      printf("Instrução inválida: %d\n", instrucao);
    }
    apontador_instrucao++;
  }
}

int main(int argc, char *argv[]) {
  printf("Iniciando...");
  if (argc > 1) {
    loadM(argv[1]);
    dumpM();
    executa();
    return 0;
  }
  printf("Erro na execução, faltou especificar o arquivo .txt\n");
  return -1;
}
