//N-QUEENS CODE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int min(int a,int b){
    return (a>b) ? b:a;
}
bool isSafe(bool **board,int row,int col,int n){
    //check for the columns
    for(int i=0;i<row;i++){
        if(board[i][col]==true){
            return false;
        }
    }
    // check for the left diagonal
    
    for(int i=row -1 , j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]==true){
            return false;
        }
    }
    
    //check for the right diagonal
    
    for(int i=row -1,j=col+1;i>=0 && j<n;i--,j++){
        if(board[i][j]==true){
            return false;
        }
    }
    
    return true;
}

// funtion for printing the board
void display(bool **board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==true){
                printf("Q ");
            }
            else{
                printf("X ");
            }
            
        }
        printf("\n");
    }
}

//functiuon to make the NQUEENS

int NQUEENS(bool **board,int n,int row){
    if(row==n){
        display(board, n);
        printf("\n");
        return 1;
    }
    int count =0;
    for(int col=0;col<n;col++){
        if(isSafe(board, row, col, n)){
            board[row][col]=true;
            count+=NQUEENS(board,n,row+1);
            board[row][col]=false;
        }
    }
    return count;
}

int main(void){
    int n;
    printf("ENTER THE NUMBER OF ROWS");
    scanf("%d",&n);
    bool **board=(bool **)malloc(sizeof(bool *)*n);
    for(int i=0;i<n;i++){
        board[i]=(bool *)malloc(sizeof(bool)*n);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=false;
        }
    }
    int c=NQUEENS(board, n, 0);
    printf("THE TOTAL NUMBER OF BOARDS IS %d",c);
    
    
    
}
