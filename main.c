#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void restdeck(char *deck[52])
{
    deck[0] = "maca A  ";
    deck[1] = "maca 2  ";
    deck[2] = "maca 3  ";
    deck[3] = "maca 4  ";
    deck[4] = "maca 5  ";
    deck[5] = "maca 6  ";
    deck[6] = "maca 7  ";
    deck[7] = "maca 8  ";
    deck[8] = "maca 9  ";
    deck[9] = "maca 10 ";
    deck[10] = "maca J  ";
    deck[11] = "maca Q  ";
    deck[12] = "maca K  ";

    deck[13] = "karo A  ";
    deck[14] = "karo 2  ";
    deck[15] = "karo 3  ";
    deck[16] = "karo 4  ";
    deck[17] = "karo 5  ";
    deck[18] = "karo 6  ";
    deck[19] = "karo 7  ";
    deck[20] = "karo 8  ";
    deck[21] = "karo 9  ";
    deck[22] = "karo 10 ";
    deck[23] = "karo J  ";
    deck[24] = "karo Q  ";
    deck[25] = "karo K  ";

    deck[26] = "kupa A  ";
    deck[27] = "kupa 2  ";
    deck[28] = "kupa 3  ";
    deck[29] = "kupa 4  ";
    deck[30] = "kupa 5  ";
    deck[31] = "kupa 6  ";
    deck[32] = "kupa 7  ";
    deck[33] = "kupa 8  ";
    deck[34] = "kupa 9  ";
    deck[35] = "kupa 10 ";
    deck[36] = "kupa J  ";
    deck[37] = "kupa Q  ";
    deck[38] = "kupa K  ";

    deck[39] = "sinek A ";
    deck[40] = "sinek 2 ";
    deck[41] = "sinek 3 ";
    deck[42] = "sinek 4 ";
    deck[43] = "sinek 5 ";
    deck[44] = "sinek 6 ";
    deck[45] = "sinek 7 ";
    deck[46] = "sinek 8 ";
    deck[47] = "sinek 9 ";
    deck[48] = "sinek 10";
    deck[49] = "sinek J ";
    deck[50] = "sinek Q ";
    deck[51] = "sinek K ";


}


void showdeck(char *deck[52])
{
    for (int j=0; j<13; j++)
    {
        Sleep(100);
        printf("%s    %s    %s    %s\n", deck[j], deck[j+13], deck[j+26], deck[j+39]);

    }
}


void mixdeck(char *deck[52])
{
    int rander[52];
    char *deck2[52];


    int a;
    srand(time(NULL));

    for (int i=0; i<52; i++)
    {

        a = rand()%52;

        rander[i] = a;

        if(i>0)
        {
            for (int j=1; j<51; j++)
            {
                if(rander[i] == rander[i-j])
                    i--;
            }
        }

    }

    for (int i=0; i<52; i++)
        deck2[i] = deck[rander[i]];

    for (int i=0; i<52; i++)
        deck[i] = deck2[i];
}




int main()
{

    char *deste[52];

    printf("STARTING DECK\n\n");
    restdeck(deste);

    showdeck(deste);

    printf("\n\n");

    printf("SHUFFLE 1\n\n");
    mixdeck(deste);

    showdeck(deste);

    printf("\n\n");

    printf("SHUFFLE 2\n\n");
    mixdeck(deste);

    showdeck(deste);

    printf("\n\n");

    printf("RESET DECK\n\n");
    restdeck(deste);

    showdeck(deste);


    return 0;
}
