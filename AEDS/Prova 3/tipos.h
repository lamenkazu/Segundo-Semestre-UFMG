#pragma once

#ifndef __TIPOS_h__
#define __TIPOS_h__

/* Inclusões */

/* Constantes */

// Código de erro indicando que tudo correu conforme o esperado
#define SUCESSO 0

// Valor Verdadeiro para o tipo booleano
#define VERDADEIRO (1==1)
// Valor Falso para o tipo booleano
#define FALSO      (!VERDADEIRO)


#define TAMANHO_TEXTO (20 + 1)
#define NUMERO_TEXTOS (100)

/* Tipos */

/// <summary>
/// Tipo para valores booleanos.
/// </summary>
typedef unsigned char bool_t;

#endif // __TIPOS_h__