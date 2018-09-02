### head

-    <a href="#e" target="_self">E:AC Challenge状压dp</a>

### <span id="e">[E:AC Challenge状压dp](#head)</span>

<font size="5" color="#FF0000"><b>你好</font><br>
 
 每个点的前置条件为各种包含pi的状态，所以容易想到状压dp<br>
 **对于动态规划，不要想着一个状态往其他状态转移，而应该想着某一个状态是由之前的所有状态不断地来规划该状态，从而得到最优值！！！**
```cpp
#include<bits/stdc++.h>
#define per(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
using namespace std;
typedef long long ll;
const ll inf =23333333333333333LL;
const double eps=1e-8;
int T;
int read(){
    char ch=getchar();
    int res=0,f=0;
    while(ch<'0' || ch>'9'){f=(ch=='-'?-1:1);ch=getchar();}
    while(ch>='0'&&ch<='9'){res=res*10+(ch-'0');ch=getchar();}
    return res*f;
}
// ------------------------head
const int siz=22;
int n,s[siz],p[siz][siz];
int a[siz],b[siz];
ll dp[1<<20];
int state[siz];
int bit[siz],bit_num[1<<22];
void init(){
    bit_num[0]=0;//得到每个状态的其中有多少个1
    per(i,1,1<<n){
        bit_num[i]=1+bit_num[i&(i-1)];
    }
    bit[0]=1;//位移i位的大小
    per(i,1,n){
        bit[i]=bit[i-1]<<1;
    }
}

int main()
{
    //freopen("Data_In.txt","r",stdin);
    scanf("%d",&n);
    init();
    memset(state,0,sizeof(state));
    per(i,0,n-1){
        scanf("%d%d%d",&a[i],&b[i],&s[i]);
        int tmp;
        per(j,0,s[i]-1){scanf("%d",&tmp);state[i]|=(bit[tmp-1]);}
    }
    per(i,0,bit[n]-1)dp[i]=-inf;
    dp[0]=0;
    ll ans=0;
    for(int i=0;i<(1<<n);i++){
        if(dp[i]==-inf)continue;
        if(dp[i]>ans)ans=dp[i];
        for(int j=0;j<n;j++){
            if(i&(1<<j))continue;//j已经有了
            if((i&state[j])!=state[j])continue;//i状态不能满足j的前置要求置要求
            dp[i|bit[j]]=max(dp[i|bit[j]],dp[i]+(ll)(bit_num[i]+1)*a[j]+b[j]);
        }
    }
    printf("%lld\n",ans);

    return 0;
}
```
