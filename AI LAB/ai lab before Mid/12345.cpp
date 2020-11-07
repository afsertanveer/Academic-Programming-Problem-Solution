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
        for(int i=0; i<N; i++) {
            Q[i] = rand()%N;
        }
    }

        /// --------------- Work 1 ---------------------------------------------------------------------------------->>>>
        ///*** Calculate the conflict and store in the variable conflict for the board Q[] ***///

void conflict_check()
    {
        conflict = 0;
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if((Q[i]==Q[j])|| Q[i]+j == Q[j]+i || Q[j]-i== Q[i]-j)
                {
                    conflict++;
                }
            }

        }
    }
        /// --------------- Work 2 ---------------------------------------------------------------------------------->>>>
        ///*** Find the next best successor and store in the variable mtemp. ***///

    Node successor()
    {
        Node mtemp, mtemp2, mtemp3;
        int c_conflict,i,j;
        mtemp.Q = Q;
        mtemp.conflict_check();
        mtemp2.Q = Q;
        mtemp2.conflict = mtemp.conflict;
        c_conflict = mtemp2.conflict;
        mtemp3.Q = Q;
        mtemp3.conflict = mtemp.conflict;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                mtemp2.Q[i] = j;

                mtemp2.conflict_check();
                if (c_conflict>mtemp2.conflict)
                {
                    c_conflict = mtemp2.conflict;
                    mtemp3.Q = mtemp2.Q;
                    mtemp3.conflict = mtemp2.conflict;
                }
                    if (c_conflict==0)
                    {

                            break;
                    }
            }

        mtemp2.Q = mtemp3.Q;
        mtemp2.conflict = mtemp3.conflict;
        }
        mtemp.Q = mtemp3.Q;
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
    while(true){

        Node temp = Queen.successor();
        temp.conflict_check();
        if(temp.conflict==0){
            cout << "Hurray! Solution Found !!!!" << endl;

            print(temp);
            break;
        }

        Queen=temp;
    }

    return 0;
}

