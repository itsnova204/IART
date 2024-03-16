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

bool isneighbour (int arr[11][11], int x1, int y1, int x2, int y2) {
    int movement[2] = {x2 - x1, y2 - y1};

    if (movement[0] < -1 || movement[0] > 1 || movement[1] < -1 || movement[1] > 1) return false;

    if (y1 < 5 && ( (movement[0] == 1 && movement[1] == -1) || (movement[0] == -1 && movement[1] == 1) )) return false;

    else if (y1 == 5 && ( (movement[0] == 1 && movement[1] == -1 ) || (movement[0] == 1 && movement[1] == 1) )) return false;

    else if (y1 > 5 && ( (movement[0] == -1 && movement[1] == -1) || movement[0] == 1 && movement[1] == 1 )) return false;

    return true;
}

bool check_jump(int arr[11][11], int player, int direction, int x, int y) {

    int opp = player == 1 ? 2 : 1;

    printf("x: %i   y: %i\n", x, y);

    if (y < 5) {
        switch (direction) {
            case 0: //up-left
                if (arr[y - 1][x - 1] == player) return check_jump(arr, player, direction, x-1, y-1);
                else if (arr[y - 1][x - 1] == 0 || arr[y - 1][x - 1] == opp) return true;
                else return false;
                break;
            case 1: //up-right
                if (arr[y - 1][x] == player) return check_jump(arr, player, direction, x, y-1);
                else if (arr[y - 1][x] == 0 || arr[y - 1][x] == opp) return true;
                else return false;
                break;
            case 2: //left
                if (arr[y][x - 1] == player) return check_jump(arr, player, direction, x-1, y);
                else if (arr[y][x - 1] == 0 || arr[y][x - 1] == opp) return true;
                else return false;
                break;
            case 3: //right
                if (arr[y][x + 1] == player) return check_jump(arr, player, direction, x+1, y);
                else if (arr[y][x + 1] == 0 || arr[y][x + 1] == opp) return true;
                else return false;
                break;
            case 4: //down-left
                if (arr[y + 1][x] == player) return check_jump(arr, player, direction, x, y+1);
                else if (arr[y + 1][x] == 0 || arr[y + 1][x] == opp) return true;
                else return false;
                break;
            case 5: //down-right
                if (arr[y + 1][x + 1] == player) return check_jump(arr, player, direction, x+1, y+1);
                else if (arr[y + 1][x + 1] == 0 || arr[y + 1][x + 1] == opp) return true;
                else return false;
                break;
        }
    }

    else if (y == 5) {
        switch (direction) {
            case 0: //up-left
                if (arr[y - 1][x - 1] == player) return check_jump(arr, player, direction, x-1, y-1);
                else if (arr[y - 1][x - 1] == 0 || arr[y - 1][x - 1] == opp) return true;
                else return false;
                break;
            case 1: //up-right
                if (arr[y - 1][x] == player) return check_jump(arr, player, direction, x, y-1);
                else if (arr[y - 1][x] == 0 || arr[y - 1][x] == opp) return true;
                else return false;
                break;
            case 2: //left
                if (arr[y][x - 1] == player) return check_jump(arr, player, direction, x-1, y);
                else if (arr[y][x - 1] == 0 || arr[y][x - 1] == opp) return true;
                else return false;
                break;
            case 3: //right
                if (arr[y][x + 1] == player) return check_jump(arr, player, direction, x+1, y);
                else if (arr[y][x + 1] == 0 || arr[y][x + 1] == opp) return true;
                else return false;
                break;
            case 4: //down-left
               // if (arr[y + 1][x - 1] == player) return check_jump(arr, player, direction, y+1, x-1);
                if (arr[y + 1][x - 1] == player) return check_jump(arr, player, direction, x-1, y+1);
                else if (arr[y + 1][x - 1] == 0 || arr[y + 1][x - 1] == opp) return true;
                else return false;
                break;
            case 5: //down-right
                //if (arr[y + 1][x] == player) return check_jump(arr, player, direction, y+1, x);
                if (arr[y + 1][x] == player) return check_jump(arr, player, direction, x, y+1);
                else if (arr[y + 1][x] == 0 || arr[y + 1][x] == opp) return true;
                else return false;
                break;
        }
    }

    else if (y > 5) {
        switch (direction) {
            case 0: //up-left
                if (arr[y - 1][x] == player) return check_jump(arr, player, direction, x, y-1);
                else if (arr[y - 1][x] == 0 || arr[y - 1][x] == opp) return true;
                else return false;
                break;
            case 1: //up-right
                if (arr[y - 1][x + 1] == player) return check_jump(arr, player, direction, x+1, y-1);
                else if (arr[y - 1][x + 1] == 0 || arr[y - 1][x + 1] == opp) return true;
                else return false;
                break;
            case 2: //left
                if (arr[y][x - 1] == player) return check_jump(arr, player, direction, x-1, y);
                else if (arr[y][x - 1] == 0 || arr[y][x - 1] == opp) return true;
                else return false;
                break;
            case 3: //right
                if (arr[y][x + 1] == player) return check_jump(arr, player, direction, x+1, y);
                else if (arr[y][x + 1] == 0 || arr[y][x + 1] == opp) return true;
                else return false;
                break;
            case 4: //down-left
                if (arr[y + 1][x - 1] == player) return check_jump(arr, player, direction, x-1, y+1);
                else if (arr[y + 1][x - 1] == 0 || arr[y + 1][x - 1] == opp) return true;
                else return false;
                break;
            case 5: //down-right
                if (arr[y + 1][x] == player) return check_jump(arr, player, direction, x, y+1);
                else if (arr[y + 1][x] == 0 || arr[y + 1][x] == opp) return true;
                else return false;
                break;
        }
    }
}

bool check_move(int arr[11][11], int xi, int yi, int xf, int yf) {
    // check neighbours, if move is a jump, check the direction of the movement so that the jump is made in one direction only (up-right/up-left/down-right/down-left)
    // maybe fazer x_f - x_i e y_f - y_i para calcular direção ou para checkar se destino é neighbour

    int current_color = arr[yi][xi];
    if (current_color != 1 && current_color != 2) return false;
    int enemy_color = current_color == 1 ? 2 : 1;
    int direction; //0 - ub ; 1 - uf ; 2 - back ; 3 - for ; 4 - db ; 5 - df
    int movement[2] = {xf - xi, yf - yi};

    printf("Movement:\n x: %i\n y: %i\n", movement[0], movement[1]);

    if (!isneighbour(arr, xi, yi, xf, yf)) return false;
    printf("Starting value: %i ; on coords x=%i y=%i\n", arr[yi][xi], xi, yi);
    printf("Dest value: %i ; on coords x=%i y=%i\n", arr[yf][xf], xf, yf);

    if (arr[yf][xf] == 0) return true; // move to blank space

    printf("Checkpoint\n");

    printf("Current color: %i\n Initial Tile color: %i\n Dest color: %i\n", current_color, arr[yi][xi], arr[yf][xf]);

    if (arr[yf][xf] == current_color) {
        if (yi < 5) {
            if (movement[1] == -1) {
                if (movement[0] == -1) direction = 0;
                else direction = 1;
            }
            else if (movement[1] == 0) {
                if (movement[0] == -1) direction = 2;
                else direction = 3;
            }
            else {
                if (movement[0] == 0) direction = 4;
                else direction = 5;
            }
        }
        
        else if (yi == 5) {
            if (movement[1] == -1) {
                if (movement[0] == -1) direction = 0;
                else direction = 1;
            }
            else if (movement[1] == 0) {
                if (movement[0] == -1) direction = 2;
                else direction = 3;
            }
            else {
                if (movement[0] == -1) direction = 4;
                else direction = 5;
            }
        }

        else if (yi > 5) {
            if (movement[1] == -1) {
                if (movement[0] == 0) direction = 0;
                else direction = 1;
            }
            else if (movement[1] == 0) {
                if (movement[0] == -1) direction = 2;
                else direction = 3;
            }
            else {
                if (movement[0] == -1) direction = 4;
                else direction = 5;
            }
        }
        printf("Direction: %i\n", direction);
        return check_jump(arr, current_color, direction, xi, yi);
    }
}
/*
int move_piece(int *board[11][11], int piece_x, int piece_y, int new_x, int new_y){
    if (check_block(board,piece_x,piece_y) == true) return 1;
    //if(valid_move(board,piece_x,piece_y,new_x,new_y) == false) return 2;

    *board[new_x,new_y] = *board[piece_x,piece_y];
    *board[piece_x,piece_y] = 0;
    
    return 0;
}*/

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

        int test_board[11][11]={{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                       {-1,1,0,0,0,2,-1,-1,-1,-1,-1},
                       {-1,1,0,0,0,0,2,-1,-1,-1,-1},
                       {-1,1,0,0,2,0,0,2,-1,-1,-1},
                       {-1,1,0,0,2,0,0,0,2,-1,-1},
                       {-1,0,1,1,1,0,0,0,2,0,-1},
                       {-1,0,0,1,0,0,0,0,2,-1,-1},
                       {-1,0,1,0,0,0,0,2,-1,-1,-1},
                       {-1,0,0,0,0,0,2,-1,-1,-1,-1},
                       {-1,0,0,0,0,2,-1,-1,-1,-1,-1},
                       {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};
    
    print_board(test_board);
    bool check = check_move(test_board, 2, 7, 3, 6);
    printf("Check1: %d\n", check);
    bool check2 = check_move(test_board, 8, 5, 7, 4);
    printf("Check2: %d\n", check2);
    bool check3 = check_move(test_board, 1, 8, 2, 8);
    printf("Check3: %d\n",check3);

    //bool check = check_jump(test_board, 1, 5, 1, 4);
    //printf("Check1: %d\n", check);
    return 0;
}

