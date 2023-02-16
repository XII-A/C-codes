#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

struct info{
    int index;
    double area;
};
typedef struct info info;

void sort_by_area(triangle* tr, int n) {
	int i;
    double S = 0;
    double inf = 353000.0;
    info *arr = (info *)malloc(n*sizeof(info));
    triangle *sort_tr = (triangle *)malloc(n*sizeof(triangle));
    for (i = 0; i < n;i++) {
        int a = tr[i].a;
        int b = tr[i].b;
        int c = tr[i].c;
        double p = (a+b+c)/2.0;
        S = sqrt(p*(p-a)*(p-b)*(p-c));
        arr[i].area = S;
        arr[i].index = i;   
    }
    double min = inf;
    int j = 0;
    int record = 0;
    while (1)
    {
        for ( i = 0; i < n; i++)
        {
            if (arr[i].area < min)
            {
                min = arr[i].area;
                record = i;
                
            }
        }
        sort_tr[j] = tr[record];
        arr[record].area = 353000;
        min = inf;
        j++;
        if (j == n)
        {
            for ( i = 0; i < n; i++)
            {
                tr[i] = sort_tr[i];
            }
            
            break;
        }
        

    }
    
    
    
    
    
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
    printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}