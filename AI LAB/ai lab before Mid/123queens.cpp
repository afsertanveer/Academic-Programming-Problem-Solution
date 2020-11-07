#include<bits/stdc++.h>
#define N 8

using namespace std;
int arr[10]={3,1,3,6,5,4,6,7};
struct Node{
    vector<int> Q;
    int conflict;

    Node(){
        Q.resize(N);
    }

    void init(){
      for(int i=0; i<N; i++) Q[i] = rand()%N;
      //  for(int i=0; i<N; i++) Q[i] = arr[i];


    }

    void conflict_check()
    {
        conflict = 0;
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                /*if((Q[i]==Q[j])|| (Q[i]-Q[j]==i-j) || (Q[i]-Q[j]==j-i) )
                {
                    conflict++;
                }*/
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
        mtemp2.conflict_check();
        int c=mtemp2.conflict;
        printf("\n\n\n\nPrimary Conflict : %d\n\n\n\n",c);
        mtemp3.Q =Q;
        mtemp3.conflict=mtemp.conflict;
       int i=0,j=0,k=0;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                mtemp2.Q[i]=j;
                mtemp2.conflict_check();

                printf("\n\n\n%d no Conflict: %d \n\nPrimary Conflict: %d\n\n",i,mtemp2.conflict,c);

                if(c>mtemp2.conflict)
                {
                    c=mtemp2.conflict;
                    mtemp3.Q=mtemp2.Q;
                }


            }
            mtemp2.Q=mtemp3.Q;
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

    for(int i=0; i<N; i++) A[Queen.Q[i]][i] = true;

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
    while(1){
        Node temp = Queen.successor();

        temp.conflict_check();
        printf("\n\nTemp: %d\n\n",temp.conflict);
        if(temp.conflict==0){
            cout << "Hurray! Solution Found !!!!" << endl;

            print(temp);
            break;
        }

        Queen.init();
    }

    return 0;
}
