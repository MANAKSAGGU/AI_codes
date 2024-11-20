#include<iostream>
using namespace std;
#include<vector>
vector<int>board(9,2);
int turn = 1;
void display() {
    for (int i = 0; i < 9; i++) 
    {
        if (i == 3 || i == 6) {
            cout << endl;
        }
        if (board[i] == 3) {
            cout << "X ";
        } else if (board[i] == 5) {
            cout << "O ";
        } else {
            cout << "- ";
        }
    }
    cout << endl; 
}
int make2(vector<int>&board){
    if(board[4] == 2){
        return 4;
    }
    else{
        for(int i=0;i<9;i++){
            if(board[i] == 2){
                return i;
            }
        }
    }
    return -1;
}
void go(int n){
    if(turn%2==0){
        board[n] = 5;
    }
    else{
        board[n] = 3;
    }
    turn = turn + 1;
}

int posswinX(vector<int>&board){
    for(int i=0;i<=6;i=i+3){  
    if(board[i]*board[i+1]*board[i+2] == 18){
        if(board[i] == 2){
            return i;
        }
        if(board[i+1]==2){
            return i+1;
        }
        if(board[i+2]==2){
            return i+2;
        }
    }
     for(int i=0;i<3;i++){ 
    if(board[i]*board[i+3]*board[i+6] == 18){
        if(board[i] == 2){
            return i;
        }
        if(board[i+3]==2){
            return i+3;
        }
        if(board[i+6]==2){
            return i+6;
        }
    }
    }
    }
    if(board[0]*board[4]*board[8] == 18){ 
        if(board[0] == 2){
            return 0;
        }
        if(board[4]==2){
            return 4;
        }
        if(board[8]==2){
            return 8;
        }
    }
    if(board[2]*board[4]*board[6] == 18){ 
        if(board[2] == 2){
            return 2;
        }
        if(board[4]==2){
            return 4;
        }
        if(board[6]==2){
            return 6;
        }
    }
    
    return -1; 
}

int posswinO(vector<int>&board){
    for(int i=0;i<=6;i=i+3){  
    if(board[i]*board[i+1]*board[i+2] == 50){
        if(board[i] == 2){
            return i;
        }
        if(board[i+1]==2){
            return i+1;
        }
        if(board[i+2]==2){
            return i+2;
        }
    }
    }
   
    for(int i=0;i<3;i++){ 
    if(board[i]*board[i+3]*board[i+6] == 50){
        if(board[i] == 2){
            return i;
        }
        if(board[i+3]==2){
            return i+3;
        }
        if(board[i+6]==2){
            return i+6;
        }
    }
    }
    
    if(board[0]*board[4]*board[8] == 50){ 
        if(board[0] == 2){
            return 0;
        }
        if(board[4]==2){
            return 4;
        }
        if(board[8]==2){
            return 8;
        }
    }
    
    if(board[2]*board[4]*board[6] == 50){
        if(board[2] == 2){
            return 2;
        }
        if(board[4]==2){
            return 4;
        }
        if(board[6]==2){
            return 6;
        }
    }
    return -1; 
}
void checkwinX(vector<int>&board){
    for(int i=0;i<=6;i=i+3){  
    if(board[i]*board[i+1]*board[i+2] == 27){
        cout << endl;
        cout << "player 1 wins" << endl;
        exit(1);
    }
     for(int i=0;i<3;i++){ 
    if(board[i]*board[i+3]*board[i+6] == 27){
        cout << endl;
        cout << "player 1 wins" << endl;
        exit(1);
    }
    }
    }
    if(board[0]*board[4]*board[8] == 27){ 
        cout << endl;
        cout << "player 1 wins" << endl;
        exit(1);
    }
    if(board[2]*board[4]*board[6] == 27){ 
       cout << endl;
       cout << "player 1 wins" << endl;
       exit(1);
    }
    
}
void checkwinO(vector<int>&board){
    for(int i=0;i<=6;i=i+3){  
    if(board[i]*board[i+1]*board[i+2] == 125){
        cout << endl;
        cout << "player 2 wins" << endl;
        exit(1);
    }
     for(int i=0;i<3;i++){ 
    if(board[i]*board[i+3]*board[i+6] == 125){
        cout << endl;
        cout << "player 2 wins" << endl;
        exit(1);
    }
    }
    }
    if(board[0]*board[4]*board[8] == 125){ 
        cout << endl;
        cout << "player 2 wins" << endl;
        exit(1);
    }
    if(board[2]*board[4]*board[6] == 125){
         
       cout << endl;
       cout << "player 2 wins" << endl;
       exit(1);
    }
    
    
}
void usermove();
void computermove(){

            if(turn == 1){
                go(0);
                display();
                usermove();
            }
            else if(turn == 2){
                if(board[4] == 2){
                    go(4);
                }
                else{
                    go(0);
                }
                display();
                usermove();
            }
            else if(turn == 3){
                if(board[8] == 2){
                    go(8);
                }
                else{
                    go(2);
                }
                display();
                usermove();
            }
            else if(turn == 4){
                if(posswinX(board)!=-1){
                    go(posswinX(board));
                }
                else{
                    go(make2(board));
                }
                display();
                usermove();
            }
            else if(turn == 5){
                if(posswinX(board)!=-1){
                    go(posswinX(board));
                }
                else if(posswinO(board)!=-1){
                    go(posswinO(board));
                }
                else if(board[6]==2){
                    go(6);
                }
                else{
                    go(2);
                }
                display();
                checkwinX(board);
                usermove();
            }
            else if(turn == 6){
                if(posswinO(board)!=-1){
                    go(posswinO(board));
                }
                else if(posswinX(board)!=-1){
                    go(posswinX(board));
                }
                else{
                    go(make2(board));
                }
                display();
                checkwinO(board);
                usermove();
            }
            else if(turn == 7){
                if(posswinX(board)!=-1){
                    go(posswinX(board));
                }
                else if(posswinO(board)!=-1){
                    go(posswinO(board));
                }
                else{
                    go(make2(board));
                }
                display();
                checkwinX(board);
                usermove();
            }
            else if(turn == 8){
                if(posswinO(board)!=-1){
                    go(posswinO(board));
                }
                else if(posswinX(board)!=-1){
                    go(posswinX(board));
                }
                else{
                    go(make2(board));
                }
                display();
                checkwinO(board);
                usermove();
            }
            else if(turn == 9){
                if(posswinX(board)!=-1){
                    go(posswinX(board));
                }
                else if(posswinO(board)!=-1){
                    go(posswinO(board));
                }
                else{
                    go(make2(board));
                }
                display();
                checkwinX(board);
            }
            cout << endl;
            cout << "game draws" << endl;
            exit(1);
        }

void usermove(){
    bool valid;
    int n;
    cout << endl;
    cout << "enter the block number for your move : " << endl;
    cin >> n;
    do{
        if(turn <= 9 && board[n-1] == 2){
            
            valid = true;
            go(n-1);
            display();
            checkwinX(board);
            checkwinO(board);
            cout << endl;
            cout << endl;
            cout << "computer's move" << endl;
            computermove();
            }
            else if(board[n-1] != 2){
                valid = true;
                cout << "invalid move : " << endl;
                cout << "enter the block number for your move : " << endl;
                cin >> n;
            }
            else if(turn > 9){
                valid = false;
                cout << "game draws" << endl;
            }
            
    }while(valid);
}

int main(){
    cout << "you want to play first or second" << endl;
    int myturn;
    cin >> myturn;
    if(myturn == 1){
        usermove();
    }
    else if(myturn == 2){
        computermove();
    }
    return 0;
}