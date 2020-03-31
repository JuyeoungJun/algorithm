/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// scanf(&quot;%d&quot;, &a);                      // int 변수 1개 입력받는 예제
// scanf(&quot;%f %f&quot;, &b, &c);               // float 변수 2개 입력받는 예제 
// scanf(&quot;%lf %lf %lf&quot;, &d, &e, &f);     // double 변수 3개 입력받는 예제
// scanf(&quot;%c&quot;, &g);                      // char 변수 1개 입력받는 예제
// scanf(&quot;%s&quot;, &var);                    // 문자열 1개 입력받는 예제
// scanf(&quot;%lld&quot;, &AB);                   // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = &apos;b&apos;;
// char var[256] = &quot;ABCDEFG&quot;;
// long long AB = 12345678901234567L;
// printf(&quot;%d&quot;, a);                      // int 변수 1개 출력하는 예제
// printf(&quot;%f %f&quot;, b, c);                // float 변수 2개 출력하는 예제
// printf(&quot;%lf %lf %lf&quot;, d, e, f);       // double 변수 3개 출력하는 예제
// printf(&quot;%c&quot;, g);                      // char 변수 1개 출력하는 예제
// printf(&quot;%s&quot;, var);                    // 문자열 1개 출력하는 예제
// printf(&quot;%lld&quot;, AB);                   // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
int main(void)
{
	int test_case;
	int T;
    int check[10] = {0}, value, temp, res=0,i,j;
    char ch;
    scanf("%d",&T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
        scanf("%d", &value);
        //printf("val:%d\n",value);
        for(j = 0; j<10 ;j++){
            check[j] = 0;
        }
        res = 0;
        for(i = 0; ; i++){
            //printf("val1:%d\n",value%10);
            if(check[value % 10] == 0){
                res += 1;
            }
            check[value % 10] = 1;
            value = value / 10;
            if(value == 0){
                break;
            }
        }
        printf("#%d %d\n",test_case,res);


	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}