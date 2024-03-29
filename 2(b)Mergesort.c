#include<stdio.h>
void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge(int a[],int low,int mid,int high)
{
    int i,j,k,c[20],x;
    i=low;j=mid+1;k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]>a[j])
            c[k++]=a[i++];
        else
            c[k++]=a[j++];
    }
    if(i>mid)
    {
        for(x=j;x<=high;x++)
            c[k++]=a[x];
    }
    else
    {
        for(x=i;x<=mid;x++)
        {
            c[k++]=a[x];
        }
    }
    for(i=low;i<=high;i++)
        a[i]=c[i];
}
main()
{
    int a[20],i,n;
    printf("Enter size\n");
    scanf("%d",&n);
    printf("Enter array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
