// Funções usadas no programa "DiasDaLiturgia".
// A biblioteca 'astrocalendar.h' é necessária.
//

// Retorna o dia da Solenidade da Epifania do Senhor (entre 2 e 8 de janeiro).
//
int epifania(int primeiroDia);

// Retorna o dia da Festa do Batismo do Senhor.
//
int batismo(int epifania);

// Retorna o número do dia do 1º Domingo do Advento.
//
int advento(long ano, int primeiroDia);

// Retorna a semana do Tempo Comum em que se inicia a Quaresma.
//
int pausa_TC(int batismo, int cinzas);

// Retorna a semana do Tempo Comum em que ele é retomado.
//
int retorno_TC(int pentecostes, int advento);

// Monta uma string com a letra ou as letras dominicais de um dado ano.
//
void letra_dominical(int primeiroDia, long ano, char str[6]);

// Monta uma string com o ciclo dominical de um dado ano.
//
void ciclo_dominical(long ano, char str[6]);