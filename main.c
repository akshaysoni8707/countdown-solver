#include<stdio.h>
void forloops(int low,int end,int loops,int inc,int a[1][4],int ans[3],int n,int answer,int* count,int* count1)
{
    int i, l = low, e = end,x,y;
    while(loops>0)
    {

        if(inc == 1)
        {
            for(i = low ; i < end; i++)
            {
                if(loops == (n-1))
                {
                    if(i==0)
                    {
                        ans[n-(loops+1)]=a[0][0]+a[0][1];

                    }
                    if(i==1)
                    {
                        ans[n-(loops+1)]=a[0][0]-a[0][1];

                    }
                    if(i==2)
                    {
                        ans[n-(loops+1)]=a[0][0]*a[0][1];
                    }
                    if(i==3)
                    {
                        ans[n-(loops+1)]=a[0][0]/a[0][1];

                    }
                    if(*count==1)
                    {
                        y=i-1;
                        if(y==0)
                        {
                            printf("\n%d+%d=",a[0][0],a[0][1]);
                            printf("%d",a[0][0]+a[0][1]);
                            break;
                        }
                        if(y==1)
                        {
                            printf("\n%d-%d=",a[0][0],a[0][1]);
                            printf("%d",a[0][0]-a[0][1]);
                            break;
                        }
                        if(y==2)
                        {
                            printf("\n%d*%d=",a[0][0],a[0][1]);
                            printf("%d",a[0][0]*a[0][1]);
                            break;
                        }
                        if(y==3)
                        {
                            printf("\n%d/%d=",a[0][0],a[0][1]);
                            printf("%d",a[0][0]/a[0][1]);
                            break;
                        }
                    }

                }
                else if(loops!=(n-1))
                {

                    if(i==0)
                    {
                        ans[n-(loops+1)]=ans[n-(loops+2)]+a[0][n-loops];

                    }
                    if(i==1)
                    {
                        ans[n-(loops+1)]=ans[n-(loops+2)]-a[0][n-loops];
                    }
                    if(i==2)
                    {
                        ans[n-(loops+1)]=ans[n-(loops+2)]*a[0][n-loops];

                    }
                    if(i==3)
                    {
                        ans[n-(loops+1)]=ans[n-(loops+2)]/a[0][n-loops];

                    }
                    if(*count==1&&loops!=1)
                    {
                        x=i-1;
                        if(x==0)
                        {
                            printf("\n%d+%d=",ans[n-(loops+2)],a[0][n-loops]);
                            printf("%d",ans[n-(loops+2)]+a[0][n-loops]);
                            break;
                        }
                        if(x==1)
                        {
                            printf("\n%d-%d=",ans[n-(loops+2)],a[0][n-loops]);
                            printf("%d",ans[n-(loops+2)]-a[0][n-loops]);
                            break;
                        }
                        if(x==2)
                        {
                            printf("\n%d*%d=",ans[n-(loops+2)],a[0][n-loops]);
                            printf("%d",ans[n-(loops+2)]*a[0][n-loops]);
                            break;
                        }
                        if(x==3)
                        {
                            printf("\n%d/%d=",ans[n-(loops+2)],a[0][n-loops]);
                            printf("%d",ans[n-(loops+2)]/a[0][n-loops]);
                            break;
                        }
                    }
                    if(loops==1&&ans[n-(loops+1)]==answer)
                    {
                        *count=1;
                        ///*count1=1;

                        if(i==0)
                        {
                            printf("\n%d+%d=",ans[n-(loops+2)],a[0][n-loops]);
                            printf("%d",ans[n-(loops+1)]);
                            break;
                        }
                        if(i==1)
                        {
                            printf("\n%d-%d=",ans[n-(loops+2)],a[0][n-loops]);
                            printf("%d",ans[n-(loops+1)]);
                            break;
                        }
                        if(i==2)
                        {
                            printf("\n%d*%d=",ans[n-(loops+2)],a[0][n-loops]);
                            printf("%d",ans[n-(loops+1)]);
                            break;
                        }
                        if(i==3)
                        {
                            printf("\n%d/%d=",ans[n-(loops+2)],a[0][n-loops]);
                            printf("%d",ans[n-(loops+1)]);
                            break;

                        }
                        i=end;
                    }
                }

                if(loops > 2)
                {
                    forloops(l,e,loops-1,inc,a,ans,n,answer,count,count1);
                }
                else if(loops > 1)
                {
                    {
                        forloops(l,e,loops-1,1,a,ans,n,answer,count,count1);
                    }
                    printf("\n");
                }
            }
            loops = 0;
        }

    }

}
int main()
{
    int a[1][50];
    int ans[50],n,b=0,loops,answer,count,count1;
    printf("enter how many numbers");
    scanf("%d",&n);
    for(b=0; b<n; ++b)
    {
        printf("enter no %d  :",b+1);
        scanf("%d",&a[0][b]);
    }
    printf("enter answer :");
    scanf("%d",&answer);
    loops=n-1;
    forloops(0,4,loops,1,a,&ans,n,answer,&count,&count1);

    return 0;
}
