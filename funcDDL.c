// Funções usadas no programa "DiasDaLiturgia".
//

#include "astrocalendar.h"

int epifania(int primeiroDia)	// Retorna o dia da Solenidade da Epifania do Senhor (entre 2 e 8 de janeiro).
{
	int dia2;

	dia2 = (primeiroDia + 1) % 7;	// Dia da semana correspondente a 2 de janeiro (0 - Dom, 1 - Seg etc)

	if (dia2 == 0)
		return 2;
	else
		return 9 - dia2;			// Domingo que se segue ao dia 2 de janeiro
}

int batismo(int epifania)		// Retorna o dia da Festa do Batismo do Senhor.
{
	if (epifania == 7 || epifania == 8)
		return epifania + 1;
	else
		return epifania + 7;
}

int advento(long ano, int primeiroDia)		// Retorna o número do dia do 1º Domingo do Advento.
{
	int anoBissexto, dias, natal;

	anoBissexto = is_leap_year(ano);

	natal = primeiroDia;				// Determina o dia da semana correspondente ao Natal.

	if (!anoBissexto)
		natal++;
	else
		natal += 2;

	natal = natal % 7;

	dias = 21;							// Tempo mínimo do Advento

	if (natal == 0)						// Acrescenta o tempo entre o 4º Domingo e o Natal.
		dias += 7;
	else
		dias += natal;

	if (anoBissexto)					// Correção para anos bissextos
		dias--;

	return 359 - dias;					// Subtrai o Tempo do Advento do dia correspondente ao Natal (num ano normal).
}

int pausa_TC(int batismo, int cinzas)		// Retorna a semana do Tempo Comum em que se inicia a Quaresma.
{
	int semana;

	semana = (cinzas - batismo) / 7 + 1;

	return semana;
}

int retorno_TC(int pentecostes, int advento)	// Retorna a semana do Tempo Comum em que ele é retomado.
{
	int semanas;

	semanas = (advento - pentecostes) / 7;

	return 35 - semanas;
}

void letra_dominical(int primeiroDia, long ano, char str[6])	// Monta uma string com a letra ou as letras dominicais
{																// de um dado ano.
	int anoBissexto;
	char letra;

	anoBissexto = is_leap_year(ano);

	if (primeiroDia == 0)						// Determina a letra dominical.
		letra = 'A';
	else
		letra = 'h' - (char) primeiroDia;

	if (!anoBissexto)							// Monta a string.
	{
		str[0] = letra;

		str[1] = '\0';
	}
	else											// Caso em que há duas letras dominicais (ano bissexto).
	{
		str[0] = letra;

		str[1] = ',';

		str[2] = ' ';

		if (letra == 'A')
			str[3] = 'g';

		else if (letra == 'b')
			str[3] = 'A';

		else
			str[3] = str[0] - 1;

		str[4] = '\0';
	}
}

void ciclo_dominical(long ano, char str[6])		// Monta uma string com o ciclo dominical de um dado ano.
{
	int r;

	r = ano % 3;

	switch (r)
	{
		case 0:
		{
			str[0] = 'C';

			str[4] = 'A';

			break;
		}
		case 1:
		{
			str[0] = 'A';

			str[4] = 'B';

			break;
		}
		case 2:
		{
			str[0] = 'B';

			str[4] = 'C';

			break;
		}
	}

	str[1] = str[3] = ' ';

	str[2] = '-';

	str[5] = '\0';
}
