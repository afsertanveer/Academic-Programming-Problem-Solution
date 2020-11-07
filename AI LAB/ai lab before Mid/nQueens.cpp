#include<bits/stdc++.h>
#define N 8

using namespace std;

struct Node{
    vector<int> Q;
    int conflict;

    Node(){
        Q.resize(N);
    }

    void init(){
        for(int i=0; i<N; i++) Q[i] = rand()%N;
    }

    void conflict_check()
    {
        conflict = 0;
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if((Q[i]==Q[j])|| (Q[i]+j== Q[j]+i) || (Q[i]-j==Q[j]-i) )
                {
                    conflict++;
                }
            }


        }

        /// --------------- Work 1 ---------------------------------------------------------------------------------->>>>
        ///*** Calculate the conflict and store in the variable conflict for the board Q[] ***///

    }


    Node successor(){
        Node mtemp;
        mtemp.Q = Q;

        mtemp.conflict_check();

        Node mtemp2;
        mtemp2.Q=Q;
        for(int i=0;i<N;i++)
        {
            printf("\n%d\t",mtemp2.Q[i]);
        }
        mtemp2.conflict=mtemp.conflict;
        Node mtemp3;
        int c=mtemp2.conflict;
        mtemp3.Q =Q;
        mtemp3.conflict=mtemp.conflict;
       int i=0,j=0,k=0;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                mtemp2.Q[i]=j;
                printf("\n");
                for(int i=0;i<N;i++)
                {
                    printf("loop ervitore: %d\t",mtemp2.Q[i]);
                }
                return mtemp2;

                mtemp2.conflict_check();
                printf("\n\n\nConflict for %d %d = %d",i,j,mtemp2.conflict);
                if(c>mtemp2.conflict)
                {
                    printf("\n %d %d asdasdasda\n",i,j);
                    c=mtemp2.conflict;
                    mtemp3.Q=mtemp2.Q;
                    mtemp2.Q=mtemp3.Q;
                    mtemp3.conflict=mtemp2.conflict;
                }
                printf("\n\n\n\n");
            }
            if(c==0)break;
        }



        /// --------------- Work 2 ---------------------------------------------------------------------------------->>>>
        ///*** Find the next best successor and store in the variable mtemp. ***///


            mtemp.Q = mtemp3.Q;

            printf("%d",mtemp.conflict);
            printf("\n\nmtemp3: %d",mtemp.conflict);




        return mtemp;
    }

};

void print(Node Queen){

    bool A[N][N] = {0};

    for(int i=0; i<N; i++) A[i][Queen.Q[i]] = true;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(A[i][j]==1) cout << "Q";
            else cout << ".";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));

    Node Queen;
    Queen.init();
    print(Queen);
    int k=0;
    printf("\n\n\n\n");
    while(true){
        Node temp = Queen.successor();

        temp.conflict_check();
        printf("\n\nTemp: %d\n\n",temp.conflict);
        if(temp.conflict==0){
            cout << "Hurray! Solution Found !!!!" << endl;

            print(temp);
            break;
        }

        Queen = temp;
        k++;
        if(k==15)break;
    }

    return 0;
}
