# HIPO - Simulador de OPCODE

HIPO é um simulador de operações de código de máquina baseado em linguagem assembly. Ele permite a execução de programas escritos em uma linguagem de montagem simplificada, que é convertida em operações de código de máquina. O simulador HIPO é uma ferramenta educacional que pode ser usada para entender os princípios de execução de programas em nível de máquina.

## Descrição

O HIPO é um simulador de máquina hipotética que executa programas representados por códigos de operação (opcode) e dados em memória. Ele possui um acumulador e uma memória de 10.000 células, onde as operações são executadas. O acumulador é uma variável que armazena temporariamente resultados intermediários de cálculos.

O HIPO suporta as seguintes instruções:

- **11**: Carrega o valor de uma célula de memória para o acumulador.
- **12**: Armazena o valor do acumulador em uma célula de memória.
- **21**: Adiciona o valor de uma célula de memória ao acumulador.
- **22**: Subtrai o valor de uma célula de memória do acumulador.
- **23**: Multiplica o valor do acumulador pelo valor de uma célula de memória.
- **24**: Divide o valor do acumulador pelo valor de uma célula de memória.
- **25**: Calcula o resto da divisão do acumulador pelo valor de uma célula de memória.
- **31**: Lê um valor da entrada padrão e armazena na memória.
- **41**: Imprime o valor de uma célula de memória.
- **50**: Nenhuma operação.
- **51**: Desvia a execução para um endereço especificado.
- **52**: Desvia a execução se o valor do acumulador for maior que zero.
- **53**: Desvia a execução se o valor do acumulador for maior ou igual a zero.
- **54**: Desvia a execução se o valor do acumulador for menor que zero.
- **55**: Desvia a execução se o valor do acumulador for menor ou igual a zero.
- **56**: Desvia a execução se o valor do acumulador for diferente de zero.
- **57**: Desvia a execução se o valor do acumulador for igual a zero.
- **61**: Desloca os dígitos do acumulador para a esquerda.
- **62**: Desloca os dígitos do acumulador para a direita.

O simulador HIPO é uma ferramenta valiosa para aprender sobre o funcionamento interno de uma máquina de computação, incluindo a execução de código de máquina e a manipulação da memória.

## Como Utilizar

Para utilizar o simulador HIPO, siga os seguintes passos:

1. Crie um arquivo de texto contendo o código-fonte em linguagem assembly HIPO. Cada instrução deve ser escrita em uma linha separada.

2. Execute o simulador HIPO, fornecendo o nome do arquivo como argumento da linha de comando. Por exemplo:

   ```sh
   ./hipo_simulador programa.txt
