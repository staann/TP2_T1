#include "romanos.hpp"
#include <cstring>
#include <cctype>

// Retorna o valor decimal de um algarismo romano valido
// Retorna -1 se o algarismo for invalido
static int valor_algarismo(char algarismo) {
  switch (algarismo) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
    default:
      return -1;
  }
}

// Verifica se um algarismo pode ser repetido
// V, L, D nao podem ser repetidos
static bool pode_repetir(char algarismo) {
  return algarismo == 'I' || algarismo == 'X' || algarismo == 'C' ||
         algarismo == 'M';
}

// Verifica se a subtracao eh valida
// I pode estar antes de V e X
// X pode estar antes de L e C
// C pode estar antes de D e M
static bool subtracao_valida(char menor, char maior) {
  if (menor == 'I') {
    return maior == 'V' || maior == 'X';
  }
  if (menor == 'X') {
    return maior == 'L' || maior == 'C';
  }
  if (menor == 'C') {
    return maior == 'D' || maior == 'M';
  }
  return false;
}

// Valida se a entrada eh uma string valida nao vazia
static bool entrada_valida(char const * num_romano) {
  return num_romano != nullptr && num_romano[0] != '\0';
}

// Valida se o resultado nao excede 3000
static bool resultado_valido(int resultado) {
  return resultado >= 0 && resultado <= 3000;
}

int romanos_para_decimal(char const * num_romano) {
  // String vazia eh invalida
  if (!entrada_valida(num_romano)) {
    return -1;
  }

  int comprimento = std::strlen(num_romano);
  int resultado = 0;
  int i = 0;

  while (i < comprimento) {
    int valor_atual = valor_algarismo(num_romano[i]);

    // Algarismo invalido
    if (valor_atual == -1) {
      return -1;
    }

    // Proximo algarismo
    if (i + 1 < comprimento) {
      int proximo_valor = valor_algarismo(num_romano[i + 1]);

      if (proximo_valor == -1) {
        return -1;
      }

      // Se o proximo eh maior, eh subtracao
      if (proximo_valor > valor_atual) {
        // Verifica se a subtracao eh valida
        if (!subtracao_valida(num_romano[i], num_romano[i + 1])) {
          return -1;
        }

        // Verifica se ha outro algarismo apos e se eh valido
        if (i + 2 < comprimento) {
          int proximo_proximo = valor_algarismo(num_romano[i + 2]);
          if (proximo_proximo == -1) {
            return -1;
          }
          // Apos uma subtracao, o proximo deve ser menor ou igual
          if (proximo_proximo >= proximo_valor) {
            return -1;
          }
        }

        resultado += proximo_valor - valor_atual;
        i += 2;
        continue;
      }
    }

    // Verifica repeticao invalida
    if (i + 1 < comprimento && num_romano[i] == num_romano[i + 1]) {
      if (!pode_repetir(num_romano[i])) {
        return -1;
      }

      // Conta quantas vezes se repete
      int contador = 1;
      while (i + contador < comprimento &&
             num_romano[i + contador] == num_romano[i]) {
        contador++;
      }

      // I, X, C, M podem repetir no maximo 3 vezes
      if (contador > 3) {
        return -1;
      }

      resultado += valor_atual * contador;
      i += contador;
    } else {
      resultado += valor_atual;
      i++;
    }
  }

  // Verifica se o resultado nao excede 3000
  if (!resultado_valido(resultado)) {
    return -1;
  }

  return resultado;
}
