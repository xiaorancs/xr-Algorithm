#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int MAXN = 50 * 4096 + 5;
int cpu[MAXN],a[55];

int main()
{

	int n,b;
	while(cin>>n){
        memset(cpu,0,sizeof(cpu));
        int sum = 0;
        for(int i=0;i<n;i++){
			cin>>b;
			a[i] = b / 1024;
            sum += a[i];
        }
        int sum1 = sum / 2;
//		cout<<sum1<<" "<<sum<<endl;
        cpu[0] = 1;
        for(int i=0;i<n;i++){
            for(int j=sum1;j>=a[i];j--){
             	cpu[j] = cpu[j] | cpu[j - a[i]];   
            }
        }
        while(cpu[sum1] == 0) sum1--;
//        cout<<sum1<<endl;
        
        cout<<(sum - sum1) * 1024<<endl;
        
    }
	return 0;
}
