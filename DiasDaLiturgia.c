// Este programa calcula datas e informações relevantes do calendário litúrgico da Igreja Católica Apostólica Romana
// para serem usadas na organização do Ofício Divino, também chamado de Liturgia das Horas.
//

#include <stdio.h>
#include "astrocalendar.h"
#include "funcDDL.h"

int main()
{
    int adv, bat, cinz, epif, pasc, pent, primeiroDia;
    long ano;
    char string[6];

    Date *data;

    printf("\n\n********************************* ");

    printf("INFORMA%c%cES E DATAS IMPORTANTES DA LITURGIA", 128, 229);

    printf(" *********************************\n\n");

    do
    {
        printf("Informe o ano civil: ");

        scanf(" %li", &ano);

        if (ano < 1971)
            printf("\n***O ano deve ser posterior a 1970.***\n\n");

    } while (ano < 1971);           // Pois o novo calendário litúrgico foi implementado por volta dessa época.

    primeiroDia = gregorian_first_day_of_year(ano);         // Dia da semana do primeiro dia do ano

    printf("\n+------------------------------------------------+ ");

    printf("%li +------------------------------------------------+", ano);

    ciclo_dominical(ano, string);

    printf("\n\n\nCiclo dominical:  %s", string);

    letra_dominical(primeiroDia, ano, string);

    printf("\t\t\t\t\tLetra dominical:  %s", string);

    epif = epifania(primeiroDia);

    data = date_of_day_number(epif, ano);

    printf("\n\nEpifania do Senhor:");

    print_date(data);

    free_date(data);

    bat = batismo(epif);

    data = date_of_day_number(bat, ano);

    printf("\t\t\t\tBatismo do Senhor:");

    print_date(data);

    free_date(data);

    pasc = day_number( catholic_easter_date(ano) );

    cinz = pasc - 46;                                       // Período da Quaresma

    data = date_of_day_number(cinz, ano);

    printf("\n\nQuarta-feira de Cinzas:");

    print_date(data);

    free_date(data);

    printf("\t\t\tPausa no Tempo Comum: %d%c semana", pausa_TC(bat, cinz), 166);

    data = date_of_day_number(pasc, ano);

    printf("\n\nP%cscoa:", 160);

    print_date(data);

    free_date(data);

    pent = pasc + 49;                                       // Tempo Pascal

    data = date_of_day_number(pent, ano);

    printf("\t\t\t\t\tPentecostes:");

    print_date(data);

    free_date(data);

    adv = advento(ano, primeiroDia);

    printf("\n\nRetorno do Tempo Comum: %d%c semana", retorno_TC(pent, adv), 166);

    data = date_of_day_number(pasc + 60, ano);

    printf("\t\t\tCorpus Christi:");

    print_date(data);

    free_date(data);

    data = date_of_day_number(pasc + 68, ano);

    printf("\n\nSagrado Cora%c%co de Jesus:", 135, 198);

    print_date(data);

    free_date(data);

    data = date_of_day_number(adv, ano);

    printf("\t\t\t1%c Domingo do Advento:", 167);

    print_date(data);

    free_date(data);

    printf("\n\n+--------------------------------------------------");

    printf("------------------------------------------------------+\n\n");

    return 0;
}
