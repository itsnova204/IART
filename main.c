#include <stdio.h>
#include <stdbool.h>

void print_board(int arr[11][11])
{
    int k;
    int i, j, n;
    n=5;
    k=0;
    for (i = 0; i < 11; i++){

        for (size_t l = 0; l < n && i < 5; l++)
        {
            printf(" ");
        }
        n--;

        if (i>5){        
            for (size_t l = 0; l <= k; l++)
            {
                printf(" ");
            }
        k++;
        }
        
        

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

bool check_block(int arr[11][11], int piece_x, int piece_y){
    int current_color = arr[piece_x][piece_y];
    int enemy_color = current_color == 1 ? 2 : 1;

    if (piece_y<5)
    {
        if (arr[piece_x][piece_y+1] == enemy_color) return true; //topo direito
        if (arr[piece_x-1][piece_y+1] == enemy_color) return true; //topo esquerdo

        if (arr[piece_x+1][piece_y] == enemy_color) return true; //direita
        if (arr[piece_x-1][piece_y] == enemy_color) return true; //esquerdo

        if (arr[piece_x+1][piece_y-1] == enemy_color) return true; //baixo direito
        if (arr[piece_x][piece_y-1] == enemy_color) return true; //baixo esquerdo
    }

    if (piece_y==5)
    {
        if (arr[piece_x][piece_y+1] == enemy_color) return true; //topo direito
        if (arr[piece_x-1][piece_y+1] == enemy_color) return true; //topo esquerdo

        if (arr[piece_x+1][piece_y] == enemy_color) return true; //direita
        if (arr[piece_x-1][piece_y] == enemy_color) return true; //esquerdo

        if (arr[piece_x][piece_y-1] == enemy_color) return true; //baixo direto
        if (arr[piece_x-1][piece_y-1] == enemy_color) return true; //baixo esquerdo
    }

    if (piece_y>5)
    {
        if (arr[piece_x][piece_y+1] == enemy_color) return true; //topo direto
        if (arr[piece_x+1][piece_y+1] == enemy_color) return true; //topo esquerdo

        if (arr[piece_x+1][piece_y] == enemy_color) return true; //direita
        if (arr[piece_x-1][piece_y] == enemy_color) return true; //esquerdo

        if (arr[piece_x][piece_y-1] == enemy_color) return true; //baixo direto
        if (arr[piece_x-1][piece_y-1] == enemy_color) return true; //baixo esquerdo
    }

    return false;
}


/*
    [1][0][0][0][2][-1][-1][-1][-1]
   [1][0][0][0][0][2][-1][-1][-1]
  [1][0][0][0][0][0][2][-1][-1]
 [1][0][0][0][0][0][0][2][-1]
[0][1][0][0][0][0][0][2][0]
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
                       {-1,0,1,0,0,0,0,0,2,0,-1},
                       {-1,1,0,0,0,0,0,0,2,-1,-1},
                       {-1,1,0,0,0,0,0,2,-1,-1,-1},
                       {-1,1,0,0,0,0,2,-1,-1,-1,-1},
                       {-1,1,0,0,0,2,-1,-1,-1,-1,-1},
                       {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};
    print_board(board);
    return 0;
}
