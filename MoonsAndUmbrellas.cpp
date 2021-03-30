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
            int CJ, JC;
            cin>>CJ>>JC;
            int result = 0;
            string pattern;
            cin>>pattern;

            for(int c = 0; c < pattern.length(); c++)
            {
                if(pattern[c]=='?')
                {
                    if(c==0)
                    {
                        if(pattern.length()>1)
                        {
                            if(pattern[c+1]!='?')
                            {
                                pattern[c]=pattern[c+1];
                            }
                            else{
                                char rChar = '-';
                                for(int c = 1; c < pattern.length(); c++)
                                {
                                    if(pattern[c]!='?')
                                    {
                                        rChar = pattern[c];
                                        break;
                                    }
                                }
                                if(rChar == '-')
                                {
                                    rChar = 'C';
                                }

                                pattern[c] = rChar;
                            }
                        }
                    }
                    else if(c==pattern.length()-1||pattern[c+1] == '?')
                    {
                        pattern[c]=pattern[c-1];
                    }
                    else{
                        if(pattern[c-1]==pattern[c+1])
                        {
                            pattern[c] = pattern[c-1];
                        }
                        else if(pattern[c-1]=='J' && pattern[c+1]=='C')
                        {
                            pattern[c] = 'C';
                        }
                        else if(pattern[c-1]=='C' && pattern[c+1]=='J')
                        {
                            pattern[c] = 'J';
                        }
                    }
                }
            }

            for(int i = 0; i < pattern.length()-1; i++)
            {
                if(pattern[i] == 'C' && pattern[i+1] == 'J')
                {
                    result+=CJ;
                }
                else if(pattern[i] == 'J' && pattern[i+1] == 'C')
                {
                    result+=JC;
                }
            }

            cout<<"Case #"<<countT<<": "<<result<<endl;
        }
        return 0;
    }
