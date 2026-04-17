#include <cstring>
#include <cstdio>
#include "romanos.hpp"

int main() {
    // Testes simples para verificação com Valgrind
    const char* testes[] = {
        "I", "V", "X", "L", "C", "D", "M",
        "II", "III", "IV", "VI", "VII", "VIII", "IX",
        "XIV", "XLIX", "MCMXCIV", "MMXXVI", "MMMCMXCIX",
        "", "G", "IIII", "VV", "IL"
    };
    
    int num_testes = sizeof(testes) / sizeof(testes[0]);
    
    printf("Executando testes Valgrind:\n");
    for (int i = 0; i < num_testes; i++) {
        int resultado = romanos_para_decimal(testes[i]);
        printf("  romanos_para_decimal(\"%s\") = %d\n", testes[i], resultado);
    }
    
    printf("\nTodos os testes executados.\n");
    return 0;
}
