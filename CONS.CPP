//---------------------------------------------------------------------------
#include <vcl\condefs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma hdrstop
//---------------------------------------------------------------------------
USERES("cons.res");
//---------------------------------------------------------------------------
int index[32] = {NULL};
int karty[64] = {NULL};
int losovane;

int losovani(void) {
	losovane = random(32);
    if (index[losovane] < 2)
    	index[losovane]++;
    else
    	losovane = losovani();

    return(losovane);
}

int main(int argc, char **argv)
{

	for (int poc = 0; poc < 64; poc++) {
    	karty[poc] = losovani();
    	printf("\t%d", karty[poc]);
    }

    for (int cis = 0; cis < 32; cis++)
    	index[cis] = 0;

    for (int pocy = 0; pocy < 64; pocy++) {
    	karty[pocy] = losovani();
    	printf("\t%d", karty[pocy]);
    }
    getchar();
	return 0;
}

//---------------------------------------------------------------------------
