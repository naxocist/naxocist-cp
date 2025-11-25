#import<iostream>
int n,a=1,b=2,m=1e8+7;main(){for(std::cin>>n;n--;b%=m)b+=a=(2*b-a+m)%m;std::cout<<a;}
