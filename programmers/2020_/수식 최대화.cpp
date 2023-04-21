#include <string>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

int priority[3];

int get_priority(char oprator)
{
    switch(oprator)
    {
        case '+':
            return priority[0];
        case '-':
            return priority[1];
        case '*':
            return priority[2];
    }
}


long long solution(string expression) {
    long long answer = 0;
    vector<char> oprator;
    vector<long long> oprand;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                if(i==j || i==k || j==k) continue;
                priority[0] = i;
                priority[1] = j;
                priority[2] = k;
                long long num=0;
                oprand.clear();
                oprator.clear();
                for(int l=0;l<expression.length();l++)
                {
                    if(expression[l]>='0' && expression[l]<='9')
                    {
                        num*=10;
                        num+=expression[l]-'0';
                    }
                    else{
                        oprand.push_back(num);
                        num=0;
                        if(!oprator.empty() && get_priority(expression[l]) >= get_priority(oprator.back()))
                        {
                            while(!oprator.empty() && get_priority(oprator.back()) <= get_priority(expression[l]))
                            {
                                char cur_oprator;
                                long long oprand1,oprand2;
                                cur_oprator = oprator.back();
                                oprator.pop_back();
                                oprand2 = oprand.back();
                                oprand.pop_back();
                                oprand1 = oprand.back();
                                oprand.pop_back();
                                long long result;
                                switch(cur_oprator)
                                {
                                    case '+':
                                        result = oprand1 + oprand2;
                                        break;
                                    case '-':
                                        result = oprand1 - oprand2;
                                        break;
                                    case '*':
                                        result = oprand1 * oprand2;
                                        break;
                                }
                                oprand.push_back(result);
                                //printf("%d\n",result);
                            }
                        }
                        oprator.push_back(expression[l]);
                    }
                    /*
                    for(int p = 0;p<oprand.size();p++)
                    {
                        printf("%lld ",oprand[p]);
                    }
                    printf("\n");
                    for(int q = 0;q<oprator.size();q++)
                    {
                        printf("%c ",oprator[q]);
                    }
                    printf("\n");
                    */
                }
                oprand.push_back(num);
                while(!oprator.empty())
                {
                    char cur_oprator;
                    long long oprand1,oprand2;
                    cur_oprator = oprator.back();
                    oprator.pop_back();
                    oprand2 = oprand.back();
                    oprand.pop_back();
                    oprand1 = oprand.back();
                    oprand.pop_back();
                    long long result;
                    switch(cur_oprator)
                    {
                        case '+':
                            result = oprand1 + oprand2;
                            break;
                        case '-':
                            result = oprand1 - oprand2;
                            break;
                        case '*':
                            result = oprand1 * oprand2;
                            break;
                    }
                    oprand.push_back(result);
                    //printf("%lld\n",result);
                }
                //printf("%lld\n",oprand.back());
                long long absolute;
                oprand.back()<0?absolute = -oprand.back():absolute = oprand.back();
                if(answer < absolute) answer = absolute;
            }
        }
    }
    return answer;
}
/*
유명한 계산기 문제의 응용문제
중위연산을 후위연산으로 변환하는 알고리즘을 응용하면 된다.
연산순위가 낮은 연산이 나왔을 때,
해당 연산보다 연산순위가 높거나 같은 연산을 스택에서 모조리  pop 해서 계산하면 된다. 
*/ 
