//selection sort
#include<stdio.h>
#include<conio.h>
void selectionsort(int a[20],int n);
int main()
{
	int n,a[20],i;
	printf("enter size of array\n");
	scanf("%d",&n);
	printf("enter list pof array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d \t",&a[i]);
	}
	selectionsort(a,n);
	printf("sorted list\n");
	for(i=0;i<n;i++)
	{
		printf("%d \t",a[i]);
    }
    return 0;
}
void selectionsort(int a[20],int n)
{
	int i,j,k,temp;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[k])
			{
				k=j;
			}
			if(i!=k)
			{
				temp=a[i];
				a[i]=a[k];
				a[k]=temp;
			}
		}
	}
}
