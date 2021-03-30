#include <string>
#include <iostream>
#include <vector>
#include <stdint.h>
#include <cstdint>
#include <math.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;

    vector<vector<int>> permutations;

    void getPermutations(vector<int> pattern, int a, int b)
    {
        if(a==b)
        {

            permutations.push_back(pattern);
        }
        else
        {
            for(int i = a; i <= b; i++)
            {
                int temp = pattern[i];
                pattern[i] = pattern[a];
                pattern[a] = temp;
                getPermutations(pattern, a+1, b);
                pattern[a] = pattern[i];
                pattern[i] = temp;
            }
        }
    }

    int main()
    {


        int testCases;
        cin>>testCases;


        for(int countT = 1; countT <= testCases; countT++)
        {
            int N, C;
            cin>>N>>C;
            vector<int> pattern;

            for(int i = 0; i < N; i++)
            {
                pattern.push_back(i+1);
            }


            getPermutations(pattern, 0, N-1);
            int wantedInd = -1;
            for(int p = 0; p < permutations.size(); p++)
            {
                int result = 0;
                int intArr[N];
                vector<int> tempV = permutations[p];
                for(int i = 0; i < N; i++)
                {
                    intArr[i] = tempV[i];
                }


                for(int i = 0; i < N; i++)
                {
                    int minInd = i;
                    int minVal = intArr[i];

                    for(int j = i; j < N; j++)
                    {
                        if(minVal > intArr[j])
                        {
                            minVal = intArr[j];
                            minInd = j;
                        }
                    }

                    int temp[minInd-i+1];
                    result+=(minInd-i+1);
                    for(int j = minInd; j >= i; j--)
                    {
                        temp[minInd-j] = intArr[j];
                    }
                    for(int j = i; j <= minInd; j++)
                    {
                        intArr[j] = temp[j-i];
                    }
                }
                result--;
                if(result==C)
                {
                    wantedInd = p;
                    break;
                }

            }
            string result = "";
            if(wantedInd==-1)
            {
                cout<<"Case #"<<countT<<": IMPOSSIBLE"<<endl;
            }
            else{
                vector<int> ansPattern = permutations[wantedInd];
                for(int c = 0; c < N; c++)
                {
                    if(c==0)
                    {
                        cout<<"Case #"<<countT<<": "<<ansPattern[c];
                    }
                    else{
                        cout<<" "<<ansPattern[c];
                    }
                }

                cout<<""<<endl;
            }

            permutations.clear();

        }
        return 0;
    }
