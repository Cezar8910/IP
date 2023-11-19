#include <stdio.h>

int main(){

    int sold, tanq, avio, lan;
    int soldI, tanqI, avioI, lanI;
    int soldRi, tanqRi, avioRi, lanRi;

    scanf("%d %d %d %d", &sold, &tanq, &avio, &lan);
    scanf("%d %d %d %d", &soldI, &tanqI, &avioI, &lanI);
    scanf("%d %d %d %d", &soldRi, &tanqRi, &avioRi, &lanRi);

    if ((sold + tanq + avio + lan) > (soldI + tanqI + avioI + lanI + soldRi + tanqRi + avioRi + lanRi)*1.5){
        printf("Avancar");
    } else if ((soldI + tanqI + avioI + lanI + soldRi + tanqRi + avioRi + lanRi) > (sold + tanq + avio + lan)) {
        printf("Recuar");
    } else {
        printf("Permanecer");
    }

    return 0;
}