# include <stdio.h>

typedef enum {
    SEASON_SPRING,
    SEASON_SUMMER,
    SEASON_AUTUMN,
    SEASON_WINTER
} Season;

void describe_season(Season s);

int main(void) {
    int i;
    for (i = 0; i < 4; i++) {
        describe_season(i);
    }
    return 0;
}

void describe_season(Season s) {
    switch (s) {
        case 0:
            printf("Spring (0): Flowers bloom and temperatures rise. Rain is frequent.\n");
            break;
        case 1:
            printf("Summer (1): Hot and sunny days with long daylight hours. Heat is strong.\n");
            break;
        case 2:
            printf("Autumn (2): Weather starts to cool down. Leaves begin to redden.\n");
            break;
        case 3:
            printf("Winter (3): Freezing temperatures welcome holiday cheer. Fountains freeze over.\n");
            break;
        default:
            printf("Unexpected input.\n");       
    }
}