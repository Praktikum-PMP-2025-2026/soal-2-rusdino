/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 5
 *   Hari dan Tanggal    : Rabu, 13 Mei 2026
 *   Nama (NIM)          : Rusydi Noor Abdurrahman (13224030)
 *   Nama File           : soal1.c
 *   Deskripsi           : Deskripsi Soal
Sebuah peta energi direpresentasikan sebagai grid biner, di mana sel bernilai 1 menunjukkan wilayah aktif dan 0 menunjukkan wilayah kosong. Wilayah aktif yang saling terhubung secara vertikal atau horizontal dianggap sebagai satu pulau energi. Tim analisis medan ingin mengetahui berapa banyak pulau yang ada serta seberapa besar pulau terbesar yang muncul pada peta tersebut.
Hitung jumlah pulau dan ukuran pulau terbesar pada grid biner.
Kondisi/Aturan
1.
Grid berukuran R x C
2.
Setiap sel berisi 0 atau 1
3.
Dua sel 1 dianggap terhubung jika berdampingan atas, bawah, kiri, atau kanan
4.
Jumlah pulau = banyak komponen terhubung dari sel 1
5.
Ukuran pulau = banyak sel 1 di komponen itu
6.
Jika tidak ada pulau, ukuran terbesar = 0
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <assert.h>
/*
 #define MAX_COL        6
 #define MAX_ROW        5
 #define MAX_SIZE   (MAX_COL * MAX_ROW) 

 int a[5][6] = {
    1, 1, 0, 0, 0, 0,
    1, 1, 0, 1, 0, 0,
    1, 0, 0, 0, 0, 1,
    0, 0, 1, 1, 0, 1,
    0, 0, 1, 0, 1, 1,
};

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

struct point {
    int x;
    int y;
};

struct node {
    struct point pos;
    struct node *next;
};

struct node* cluster_set[MAX_SIZE];
int cluster_set_index = 0;

int is_inside(int height, int width, int i, int j)
{
    if (0 <= j && j < width && i >= 0 && i < height)
        return 1;
    return 0;
}

int cluster_check(int (*matrix)[MAX_COL], int height, int width, int row, int col, int (*flag_matrix)[MAX_COL], struct node* head)
{
    int i, tmp_x, tmp_y;
    flag_matrix[row][col] = 1;

    for (i = 0; i < 4; i++)
    {
        tmp_x = row + dir_x[i];
        tmp_y = col + dir_y[i];
        if (is_inside(height, width, tmp_x, tmp_y) && matrix[tmp_x][tmp_y] && !flag_matrix[tmp_x][tmp_y]) {
            flag_matrix[tmp_x][tmp_y] = 1;
            struct node *new_node = (struct node*)malloc(sizeof(struct node));
            assert(new_node != NULL);
            new_node -> pos.x = tmp_x; 
            new_node -> pos.y = tmp_y; 
            new_node -> next = NULL;
            head -> next = new_node;
            cluster_check(matrix, height, width, tmp_x, tmp_y, flag_matrix, new_node);
        }
    }
}

int cluster_count(int (*matrix)[MAX_COL], int height, int width)
{
    int count = 0, i, j;
    int flag_matrix[MAX_ROW][MAX_COL] = {0};

    for (i = 0; i < height; i++)
        for (j = 0; j < width; j++)
        {
            if (matrix[i][j] && !flag_matrix[i][j]) {
                count++;
                struct node *new_node = (struct node*)malloc(sizeof(struct node));
                assert(new_node != NULL);
                new_node -> pos.x = i; 
                new_node -> pos.y = j; 
                new_node -> next = NULL;
                cluster_set[cluster_set_index++] = new_node;
                cluster_check(matrix, height, width, i, j, flag_matrix, new_node);
            }
        }
    return count;
}

void print_cluster(int (*map)[MAX_COL], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%2d ", map[i][j]);
        printf("\n");
    }
    printf("\n");
}

*/

/*
int* cekR(char* x, int R, int C){
    int banyak = 0;
    int island = 0;
    int x[2] = {banyak, island};
    if(R == 0 || C == 0|| x == NULL){
        return banyak, island;
    }else{
        if(atoi(x[0]) == 1){
                if(atoi(x[1])==0){
                    banyak = 1 + cekR(&x[1], R, C-1)[0];
                }
            island = 1 + cekR(&x[1], R, C-1)[1];
        }else{
            island = 0;
        }
    }
    return x;
}

int* cek(char** x, int R, int C){
    int banyak = 0;
    int island = 0;
    int x[2] = {banyak, island};
    if(R == 0 || C == 0|| x == NULL){
        return banyak, island;
    }else{
        if(atoi(x[0][0]) == 1){
                if(atoi(x[0][1])==0 && atoi(x[1][0])==0){
                    banyak = 1 + cek(&x[1], R-1, C)[0]+ cek(&x[0][1], R, C-1)[0];
                }
            island = 1 + cek(&x[1], R-1, C)[1]+ cek(&x[0][1], R, C-1)[1];
        }else{
            island = 0;
        }
    }
    return x;
}
*/
// Source - https://stackoverflow.com/a/14466081
// Posted by gus, modified by community. See post 'Timeline' for change history
// Retrieved 2026-05-13, License - CC BY-SA 3.0

// direction vectors
const int dx[] = {+1, 0, -1, 0};
const int dy[] = {0, +1, 0, -1};

// matrix dimensi


void dfs(int x, int y, int current_label, int **m, int **label, int row_count, int col_count) {
  if (x < 0 || x == row_count) return; // out of bounds
  if (y < 0 || y == col_count) return; // out of bounds
  if (label[x][y] || !m[x][y]) return; // already labeled or not marked with 1 in m

  // mark the current cell
  label[x][y] = current_label;

  // recursively mark the neighbors
  for (int direction = 0; direction < 4; ++direction)
    dfs(x + dx[direction], y + dy[direction], current_label, m, label, row_count, col_count);
}

int find_components(int **m, int **label, int row_count, int col_count) {
  int component = 0;
  for (int i = 0; i < row_count; ++i) 
    for (int j = 0; j < col_count; ++j) 
      if (!label[i][j] && m[i][j]) dfs(i, j, ++component, m, label, row_count, col_count);
    return(component);
}

int main(){
    char buff[1024]; 
    fgets(buff, sizeof(buff), stdin);
    int R = atoi(strtok(buff, " "));
    int C = atoi(strtok(NULL, " "));
    //int* x = (int*)calloc(R, sizeof(int));
    char x[R][C+1];
    int visit[R][C];
    if(R!=0){
    for(int i =0; i < R; i++){
        char *temp = strtok(NULL, " ");
        if(temp != NULL){
            strcpy(x[i], temp);
        }
    }
    int **y;
    int** label;
    label = (int**)calloc(R, sizeof(int*));
    y = (int**)calloc(R, sizeof(int*));
    for(int i =0; i < R; i++){
        label[i] = (int*)calloc(C, sizeof(int));
        y[i]= (int*)calloc(C, sizeof(int));
        for(int j =0; j< C; j++){
        y[i][j] = x[i][j]-'0';
        }
    }
    int banyak, island;
    /*
    for (int i = 0; i < R-1; i++){
        for(int j = 0; j <C-1; j++){
            int tempisland;
            for (int k = i; k < R-1; k++){
                for(int l = j; l <C-1; l++){
                    if(x[i][j]=='1'){
                        if(x[k][l+1] == '1'){
                            if(x[k][l] == x[k][l+1]){
                                tempisland++;
                            }
                        }if(x[k+1][l] == '1'){
                            if(x[k][l] == x[k+1][l]){
                                tempisland++;
                            }
                        }if(tempisland > island){
                            island = tempisland;
                        }
                    }
                }}
                
                if(x[i][j+1]=='1' && visit[i][j+1] == 0){
                    island++;
                }if(x[i+1][j]=='1' && visit[i+1][j] == 0){
                    island++;
                }else if (x[i][j+1]== '0' &&x[i+1][j]=='0' && visit[i][j+1] == 0 && visit[i+1][j] == 0) {
                    banyak++;
                }
                visit[i][j] = 1;
                visit[i+1][j] = 1;
                visit[i][j+1] = 1;
                

            }
        }
            */
    int k = find_components(y, label, R, C);
    printf("\nISLANDS %d\n", k);
    printf("LARGEST %d\n", k);
    }
}

// Source - https://stackoverflow.com/a/27865006
// Posted by simon_xia
// Retrieved 2026-05-13, License - CC BY-SA 3.0

 
