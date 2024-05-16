#include <stdbool.h>

bool queens(int board[], int n, int q){
    if(q==n){
        // izpis
        return true;
    }
    for (int i = 0; i<n; i++) {
        bool a = true;
        if(a){
            board[q]=i;
            bool smoc = queens(board, n, q+1);
            if(smoc)
                return true;
        }
    
    }
    return false;
}


int main(){
    return 0;
}
