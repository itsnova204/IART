#include <stdio.h>
#include <stdbool.h>

void print_board(int arr[11][11])
{
    //int k == 4;
    int i, j;
    for (i = 0; i < 11; i++){

      for (j = 0; j < 11; j++){
        if (arr[i][j] == -1)
        {
            printf("  ");
            continue;
        }

        printf("[%d]", arr[i][j]);
      }
    
    printf("\n");
    }
}

bool check_block(int arr[9][9], int piece_x, int piece_y){
    int current_color = arr[piece_x][piece_y];
    int enemy_color = current_color == 1 ? 2 : 1;

    if (piece_y<5)
    {
        /* code */
    }

    if (piece_y==5)
    {
        /* code */
    }

    if (piece_y>5)
    {
        /* code */
    }


    
    
}


/*
    [1][0][0][0][2][-1][-1][-1][-1]
   [1][0][0][0][0][2][-1][-1][-1]
  [1][0][0][0][0][0][2][-1][-1]
 [1][0][0][0][0][0][0][2][-1]
[1][0][0][0][0][0][0][0][2]
 [1][0][0][0][0][0][0][2][-1]
  [1][0][0][0][0][0][2][-1][-1]
   [1][0][0][0][0][2][-1][-1][-1]
    [1][0][0][0][2][-1][-1][-1][-1]
*/

int main() {
    int board[11][11]={{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                       {-1,1,0,0,0,2,-1,-1,-1,-1,-1},
                       {-1,1,0,0,0,0,2,-1,-1,-1,-1},
                       {-1,1,0,0,0,0,0,2,-1,-1,-1},
                       {-1,1,0,0,0,0,0,0,2,-1,-1},
                       {-1,1,0,0,0,0,0,0,0,2,-1},
                       {-1,1,0,0,0,0,0,0,2,-1,-1},
                       {-1,1,0,0,0,0,0,2,-1,-1,-1},
                       {-1,1,0,0,0,0,2,-1,-1,-1,-1},
                       {-1,1,0,0,0,2,-1,-1,-1,-1,-1},
                       {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};
    print_board(board);
    return 0;
}