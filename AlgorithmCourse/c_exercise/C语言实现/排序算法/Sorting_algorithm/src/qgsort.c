#include "../inc/qgsort.h"



//插入
void insertSort(int *a, int n){
    int i, j, key;
    for(i = 1; i < n; ++i){
        key = a[i];
        for(j = i-1; j >=0; --j){
            if(a[j] > key)
                a[j+1] = a[j];
            else
                break;
        }
        a[j+1] = key;
    }
}


//归并
void MergeArray(int *a, int begin, int mid, int end, int *temp){//实现“治”
	int i = begin;
	int j = mid + 1;
	int k = begin;//临时下标

	while (i <= mid&&j <= end){
		if (a[i] < a[j]){
			temp[k++] = a[i++];
		}
		else
			temp[k++] = a[j++];		
	}

	while (i <= mid)
		temp[k++] = a[i++];	
	while (j <= end)
		temp[k++] = a[j++];	

	//把temp中的内容拷给a数组中
	//进行归并的时候，处理的区间是a[begin,end],对应的会把
	//这部分区间的数组填到temp[begin,end]区间上
	memcpy(a + begin, temp + begin, sizeof(int)*(end - begin+1));
}
void MergeSort(int *a,int begin,int end,int *temp){//实现“分”
	int mid = 0;
	if (begin < end){
		mid = begin + (end - begin) / 2;
		MergeSort(a, begin, mid, temp);
		MergeSort(a, mid + 1, end, temp);
		MergeArray(a, begin, mid, end, temp);       
	}	
}
void merge(int *arr,int n){
	int *temp = (int *)malloc(sizeof(int)*n);

	MergeSort(arr,0,n-1,temp);
	free(temp);
	temp = NULL;
}


//快速排序（递归版）
void QuickSort_Recursion(int *a, int begin, int end)
{
	int i,j,pivot;

    if (begin < end)
    {
        i = begin, j = end, pivot = a[begin];
        while (i < j)
        {
            while (i < j && a[j] >= pivot)
            {
                j--;
            }
            a[i] = a[j];
            while (i < j && a[i] <= pivot)
            {
                i++;
            }
            a[j] = a[i];
        }
        a[i] = pivot;
        QuickSort_Recursion(a, begin, i - 1);
        QuickSort_Recursion(a, i + 1, end);
    }
}
void quicksort_re(int *arr,int n)
{
	QuickSort_Recursion(arr,0,n-1);
}


//快速排序（非递归版）

void QuickSort(int *a,int size)
{
	//1.申请一块内存当栈
    //2.进行一次快速排序，找到基准
    //3.把左边 右边的数对进行入栈
    //4.取出数据进行一趟快速排序
    //5.top>0
	int top,low,high,par;
    int *stack = (int *)malloc(sizeof(int) * size);//定义栈的大小
    assert(stack != NULL);
    top = 0;
    low = 0;
    high = size - 1;
    par = Partition(a, low, high);
    if (par>low + 1)//左边有两个数据以上数时  入栈
    {
        stack[top++] = low;
        stack[top++] = par - 1;
    }
    if (par<high - 1)//右边左边有两个数据以上数时  入栈
    {
        stack[top++] = par + 1;
        stack[top++] = high;
    }
    while (top>0)//出栈  栈不空，需要取两个数据出来排序
    {
        high = stack[--top];
        low = stack[--top];
        par = Partition(a, low, high);
        if (par>low + 1)
        {
            stack[top++] = low;
            stack[top++] = par - 1;
        }
        if (par<high - 1)
        {
            stack[top++] = par + 1;
            stack[top++] = high;
        }
    }
    free(stack);
    stack = NULL;
}
int Partition(int *a, int begin, int end)
{
	int tmp = a[begin];
    while (begin<end)
    {
        while (begin < end && a[end] >= tmp)
        {
            end--;
        }
        if (begin >= end)
        {
            break;
        }
        else
        {
            a[begin] = a[end];
        }
        while (begin<end && a[begin] <= tmp)
        {
            begin++;
        }
        if (begin >= end)
        {
            break;
        }
        else
        {
            a[end] = a[begin];
        }
    }
    a[begin] = tmp;
    return begin;//par基准
}



//计数排序
void CountSort(int *a, int size , int max)
{
	//通过max和min计算出临时数组所需要开辟的空间大小
	int min = a[0];
	int range,i,j;
	int *b;

	for (i = 0; i < size; i++){
		if (a[i] < min)
			min = a[i];
	}

	//使用calloc将数组都初始化为0
	range = max - min + 1;
	b = (int *)calloc(range, sizeof(int));

	//使用临时数组记录原始数组中每个数的个数
	for (i = 0; i < size; i++){
		//注意：这里在存储上要在原始数组数值上减去min才不会出现越界问题
		b[a[i] - min] += 1;
	}

	j = 0;

	//根据统计结果，重新对元素进行回收
	for (i = 0; i < range; i++){
		while (b[i]--){
			//注意：要将i的值加上min才能还原到原始数据
			a[j++] = i + min;
		}
	}

	//释放临时数组
	free(b);
	b = NULL;
}
void count(int *a,int n)
{
	int max = 0;
    int i;

	for(i = 0; i < n; i++){
		if (a[i] > max)
		max = a[i];
	}

	CountSort(a,n,max);
}

//基数计数排序
void RadixCountSort(int *a,int size){
	int i,pos;
	int *radix[10];    //分别为0~9的序列空间
	for ( i= 0; i < 10; i++){
		radix[i] = (int *)malloc(sizeof(int) * (size + 1));
		radix[i][0] = 0;    //index为0处记录这组数据的个数
	}	

	for (pos = 1; pos <= 7; pos++){    //从个位开始到十万位	
		int i,j,k,num,index;
		for ( i= 0; i < size; i++){    //分配过程		
			num = GetPos(a[i], pos);
			index = ++radix[num][0];
			radix[num][index] = a[i];
		}        

		for (i = 0, j =0; i < 10; i++){    //收集		
			for (k = 1; k <= radix[i][0]; k++)
				a[j++] = radix[i][k];
			radix[i][0] = 0;    //复位
		}
	}
}
int GetPos(int k,int pos){   // 找到k的从低到高的第pos位的数据
	int i;
	int temp = 1;
	for ( i= 0; i < pos - 1; i++)
		temp *= 10;   
	return (k / temp) % 10;
}
//颜色排序
void swap(int* nums, int i, int j) {
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}
void ColorSort(int *a,int size)
{
	int i = 0, j = 0, k = size - 1;
    int t = 0;
    for(i = 0; i <= k; i++) {
        if(a[i] == 0) {
            swap(a, i, j);
            j++;
        }
        else if(a[i] == 2) {
            swap(a, i, k);
            k--;
            i--;
        }
    }
}

//在一个无序序列中找到第K大/小的数
void quickSearch_find(int array[], int low, int high, int k){
    int index = 0;
    while (high >= low) {
        index = Partition(array, low, high);
        if (index == k - 1) {
            //printf("find: %d\n", array[index]);
            break ;
        }
        if (index > k - 1) {
            high = index - 1;
        }
        if (index < k - 1) {
            low = index + 1;
        }
    }
}
void find(int *a,int n)
{
	int k;

	k= rand() % N;
	
	quickSearch_find(a,0,n-1,k);
}

//输出
void show(int *a,int n){
	int i;

	printf("\n");
	for(i=0;i<N;i++)
		printf("【%d】",a[i]);
	printf("\n");
}

//判断是否排序成功
int isSorted(int arr[],int n)
{	
    int flag = 1;
	int i;
    for(i=0;i < n-1;++i)
	{
        if(arr[i+1] < arr[i])
		{
            flag = 0;
            break;
        }
    }
    return flag;
}
//功能表
void menu()
{
	
	printf("                 *请选择以下功能*\n\n");
	printf("     |——————输入  &&   功能———————|\n");
	printf("     |-————————————————————|\n");
	printf("     |-------------a    TO   插入排序----------|\n");
	printf("     |-------------b    TO   归并排序----------|\n");
	printf("     |-------------c    TO   快速排序(递归)----|\n");
	printf("     |-------------d    TO   快速排序(非递归)--|\n");
	printf("     |-------------e    TO   计数排序----------|\n");
	printf("     |-------------f    TO   基数计数排序------|\n");
	printf("     |-------------g    TO   颜色排序----------|\n");
	printf("     |-------------h    TO   无序寻点----------|\n");
	printf("     |-------------i    TO   退出--------------|\n");
	printf("     |-————————————————————|\n");
	printf("     |-————————————————————|\n");
}
//简化交互
void reactive()
{
	printf("\n");
	system("PAUSE");
	system("cls");
	menu();
	printf("\n输入你选择的操作(以输入的第一个字符为准): ");
}
//输出
void print(void (*p)(int *a,int len))
{
	int i,j;
	int k=1;
	int max;
	int *a,*b,*c,*d;

	clock_t start,end;

	//给数组a,b,c分配空间
	a = (int *)malloc(sizeof(int)*N);
	b = (int *)malloc(sizeof(int)*M);
	c = (int *)malloc(sizeof(int)*Q);

	//给数组a,b,c随机播种
	if(p == ColorSort) max = 3;
	else max = MAX;
    srand((unsigned)time(NULL));
    for(i =0; i < N; ++i )    
		a[i] =  rand()% max;
	for(i =0; i < M; ++i )    
		b[i] =  rand()% max;
	for(i =0; i < Q; ++i )    
		c[i] =  rand()% max;

	printf("\n<--已生成随机数组a[%d],b[%d],c[%d],d[100]*100k-->\n    正在分别排序中……\n\n",N,M,Q);

	
    start=clock();
    p(a,N);
    end=clock();
	printf("\n1. a[%d] ",N);
	if(p != find)
		printf(" 排序——%s",isSorted(a,N) == 1 ? "成功":"失败");
	printf("\n   耗时: %lf ms\n\n",(double)(end-start)/CLOCKS_PER_SEC*1000);
	
	start=clock();
    p(b,M);
    end=clock();
	printf("\n2. b[%d] ",M);
	if(p != find)
		printf(" 排序——%s",isSorted(b,M) == 1 ? "成功":"失败");
	printf("\n   耗时: %lf ms\n\n",(double)(end-start)/CLOCKS_PER_SEC*1000);
	
	start=clock();
    p(c,Q);
    end=clock();
	printf("\n3. c[%d] ",Q);
	if(p != find)
		printf(" 排序——%s",isSorted(c,Q) == 1 ? "成功":"失败");
	printf("\n   耗时: %lf ms\n\n",(double)(end-start)/CLOCKS_PER_SEC*1000); 
    
	start=clock();
	for(i = 0; i < 100000; i++){
		d = (int *)malloc(sizeof(int)*100);
		for(j =0; j < 100; ++j )    
			d[j] =  rand()% max;		
		p(d,100);
		if(isSorted(d,100) == 0) 
			k = 0;
		free(d);
	}
	end=clock();
	printf("\n4. d[100]*100k");
	if(p != find)
		printf(" 排序——%s",k == 1 ? "成功":"失败");
	printf("\n   耗时: %lf ms\n\n",(double)(end-start)/CLOCKS_PER_SEC*1000);	
    
	free(a);
	free(b);
	free(c);
	a = b = c = NULL;

}

			