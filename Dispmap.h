#ifndef DISPMAP_H_INCLUDED
#define DISPMAP_H_INCLUDED

void MarkRestaurant(char grid[36][36]);
void UnmarkRestaurant(char grid[36][36]);
void DispMap(char grid[36][36], int GRID_SIZE);
int NotOnRestaurant(int x, int y);
int NotOnRoad(int x,int y);
route CalcRoute(int source_x, int source_y, int dest_x, int dest_y);
void PlotPathX(int source_x,int source_y,int dest_x,char grid[36][36]);
void PlotPathY(int source_x,int source_y,int dest_y,char grid[36][36]);
void DispRoute(int source_x,int source_y,int dest_x,int dest_y,route path,char grid[36][36]);


#endif // DISPMAP_H_INCLUDED
