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

    int main()
    {


        int testCases;
        cin>>testCases;


        for(int countT = 1; countT <= testCases; countT++)
        {
            int N;
            cin>>N;
            int result = 0;
            int intArr[N];
            for(int i = 0; i < N; i++)
            {
                cin>>intArr[i];
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
            cout<<"Case #"<<countT<<": "<<result<<endl;
        }
        return 0;
    }
