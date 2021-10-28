#include "../inc/qgsort.h"



//����
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


//�鲢
void MergeArray(int *a, int begin, int mid, int end, int *temp){//ʵ�֡��Ρ�
	int i = begin;
	int j = mid + 1;
	int k = begin;//��ʱ�±�

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

	//��temp�е����ݿ���a������
	//���й鲢��ʱ�򣬴����������a[begin,end],��Ӧ�Ļ��
	//�ⲿ������������temp[begin,end]������
	memcpy(a + begin, temp + begin, sizeof(int)*(end - begin+1));
}
void MergeSort(int *a,int begin,int end,int *temp){//ʵ�֡��֡�
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


//�������򣨵ݹ�棩
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


//�������򣨷ǵݹ�棩

void QuickSort(int *a,int size)
{
	//1.����һ���ڴ浱ջ
    //2.����һ�ο��������ҵ���׼
    //3.����� �ұߵ����Խ�����ջ
    //4.ȡ�����ݽ���һ�˿�������
    //5.top>0
	int top,low,high,par;
    int *stack = (int *)malloc(sizeof(int) * size);//����ջ�Ĵ�С
    assert(stack != NULL);
    top = 0;
    low = 0;
    high = size - 1;
    par = Partition(a, low, high);
    if (par>low + 1)//�������������������ʱ  ��ջ
    {
        stack[top++] = low;
        stack[top++] = par - 1;
    }
    if (par<high - 1)//�ұ��������������������ʱ  ��ջ
    {
        stack[top++] = par + 1;
        stack[top++] = high;
    }
    while (top>0)//��ջ  ջ���գ���Ҫȡ�������ݳ�������
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
    return begin;//par��׼
}



//��������
void CountSort(int *a, int size , int max)
{
	//ͨ��max��min�������ʱ��������Ҫ���ٵĿռ��С
	int min = a[0];
	int range,i,j;
	int *b;

	for (i = 0; i < size; i++){
		if (a[i] < min)
			min = a[i];
	}

	//ʹ��calloc�����鶼��ʼ��Ϊ0
	range = max - min + 1;
	b = (int *)calloc(range, sizeof(int));

	//ʹ����ʱ�����¼ԭʼ������ÿ�����ĸ���
	for (i = 0; i < size; i++){
		//ע�⣺�����ڴ洢��Ҫ��ԭʼ������ֵ�ϼ�ȥmin�Ų������Խ������
		b[a[i] - min] += 1;
	}

	j = 0;

	//����ͳ�ƽ�������¶�Ԫ�ؽ��л���
	for (i = 0; i < range; i++){
		while (b[i]--){
			//ע�⣺Ҫ��i��ֵ����min���ܻ�ԭ��ԭʼ����
			a[j++] = i + min;
		}
	}

	//�ͷ���ʱ����
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

//������������
void RadixCountSort(int *a,int size){
	int i,pos;
	int *radix[10];    //�ֱ�Ϊ0~9�����пռ�
	for ( i= 0; i < 10; i++){
		radix[i] = (int *)malloc(sizeof(int) * (size + 1));
		radix[i][0] = 0;    //indexΪ0����¼�������ݵĸ���
	}	

	for (pos = 1; pos <= 7; pos++){    //�Ӹ�λ��ʼ��ʮ��λ	
		int i,j,k,num,index;
		for ( i= 0; i < size; i++){    //�������		
			num = GetPos(a[i], pos);
			index = ++radix[num][0];
			radix[num][index] = a[i];
		}        

		for (i = 0, j =0; i < 10; i++){    //�ռ�		
			for (k = 1; k <= radix[i][0]; k++)
				a[j++] = radix[i][k];
			radix[i][0] = 0;    //��λ
		}
	}
}
int GetPos(int k,int pos){   // �ҵ�k�Ĵӵ͵��ߵĵ�posλ������
	int i;
	int temp = 1;
	for ( i= 0; i < pos - 1; i++)
		temp *= 10;   
	return (k / temp) % 10;
}
//��ɫ����
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

//��һ�������������ҵ���K��/С����
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

//���
void show(int *a,int n){
	int i;

	printf("\n");
	for(i=0;i<N;i++)
		printf("��%d��",a[i]);
	printf("\n");
}

//�ж��Ƿ�����ɹ�
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
//���ܱ�
void menu()
{
	
	printf("                 *��ѡ�����¹���*\n\n");
	printf("     |����������������  &&   ���ܡ�������������|\n");
	printf("     |-����������������������������������������|\n");
	printf("     |-------------a    TO   ��������----------|\n");
	printf("     |-------------b    TO   �鲢����----------|\n");
	printf("     |-------------c    TO   ��������(�ݹ�)----|\n");
	printf("     |-------------d    TO   ��������(�ǵݹ�)--|\n");
	printf("     |-------------e    TO   ��������----------|\n");
	printf("     |-------------f    TO   ������������------|\n");
	printf("     |-------------g    TO   ��ɫ����----------|\n");
	printf("     |-------------h    TO   ����Ѱ��----------|\n");
	printf("     |-------------i    TO   �˳�--------------|\n");
	printf("     |-����������������������������������������|\n");
	printf("     |-����������������������������������������|\n");
}
//�򻯽���
void reactive()
{
	printf("\n");
	system("PAUSE");
	system("cls");
	menu();
	printf("\n������ѡ��Ĳ���(������ĵ�һ���ַ�Ϊ׼): ");
}
//���
void print(void (*p)(int *a,int len))
{
	int i,j;
	int k=1;
	int max;
	int *a,*b,*c,*d;

	clock_t start,end;

	//������a,b,c����ռ�
	a = (int *)malloc(sizeof(int)*N);
	b = (int *)malloc(sizeof(int)*M);
	c = (int *)malloc(sizeof(int)*Q);

	//������a,b,c�������
	if(p == ColorSort) max = 3;
	else max = MAX;
    srand((unsigned)time(NULL));
    for(i =0; i < N; ++i )    
		a[i] =  rand()% max;
	for(i =0; i < M; ++i )    
		b[i] =  rand()% max;
	for(i =0; i < Q; ++i )    
		c[i] =  rand()% max;

	printf("\n<--�������������a[%d],b[%d],c[%d],d[100]*100k-->\n    ���ڷֱ������С���\n\n",N,M,Q);

	
    start=clock();
    p(a,N);
    end=clock();
	printf("\n1. a[%d] ",N);
	if(p != find)
		printf(" ���򡪡�%s",isSorted(a,N) == 1 ? "�ɹ�":"ʧ��");
	printf("\n   ��ʱ: %lf ms\n\n",(double)(end-start)/CLOCKS_PER_SEC*1000);
	
	start=clock();
    p(b,M);
    end=clock();
	printf("\n2. b[%d] ",M);
	if(p != find)
		printf(" ���򡪡�%s",isSorted(b,M) == 1 ? "�ɹ�":"ʧ��");
	printf("\n   ��ʱ: %lf ms\n\n",(double)(end-start)/CLOCKS_PER_SEC*1000);
	
	start=clock();
    p(c,Q);
    end=clock();
	printf("\n3. c[%d] ",Q);
	if(p != find)
		printf(" ���򡪡�%s",isSorted(c,Q) == 1 ? "�ɹ�":"ʧ��");
	printf("\n   ��ʱ: %lf ms\n\n",(double)(end-start)/CLOCKS_PER_SEC*1000); 
    
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
		printf(" ���򡪡�%s",k == 1 ? "�ɹ�":"ʧ��");
	printf("\n   ��ʱ: %lf ms\n\n",(double)(end-start)/CLOCKS_PER_SEC*1000);	
    
	free(a);
	free(b);
	free(c);
	a = b = c = NULL;

}

			