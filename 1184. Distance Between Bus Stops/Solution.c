#include <math.h>

int distanceBetweenBusStops(int *distance, int distanceSize, int start, int destination)
{
    int d1 = 0, d2 = 0;
    for (int i = start; i != destination; i = (i + 1) % distanceSize)
        d1 += distance[i];
    for (int i = destination; i != start; i = (i + 1) % distanceSize)
        d2 += distance[i];
    return fmin(d1, d2);
}
