#include<stdio.h>
void main(){
    int n, s, sub=0;
    printf("Enter the number of jobs: ");
    scanf("%d",&n);
    int jb[n], p[n], dl[n];
    for(int i=0; i<n; i++){
        printf("Profit of job%d : ",i);
        scanf("%d",&p[i]);
        printf("Dealline of job%d : ", i);
        scanf("%d", &dl[i]);
        jb[i] = i+1;
    }

    printf("\n\t\tINPUT\n\n");
    printf("JOBS\tPROFIT\tDEALLINE\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%d\n",jb[i], p[i], dl[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (p[i] > p[j]){
                s = p[i];
                p[i] = p[j];
                p[j] = s;

                s = jb[i];
                jb[i] = jb[j];
                jb[j] = s;

                s = dl[i];
                dl[i] = dl[j];
                dl[j] = s;
            }
            else if(p[i] == p[j] && i!=j){
                if(dl[i] < dl[j]){
                    p[j] = 0;
                }
                else if(dl[j] < dl[i]){
                    p[i] = 0;
                }
                else if(dl[i] == dl[j]){
                    p[j] = 0;
                }
            }
        }
    }

    printf("\n\t\tAfter sorting profit\n\n");
    printf("JOBS\tPROFIT\tDEALLINE\n");
    for (int i = 0; i < n; i++){
        printf("%d\t%d\t%d\n", jb[i], p[i], dl[i]);
    }

    printf("\n\t\tCummelative profits\n\n");
    printf("Jobs\tProfit\n");
    for(int i = 0; i <n; i++){
        if(p[i] == 0){
            continue;
        }
        if(dl[i]-sub>0){
            sub -= dl[i];
            printf("%d\t:%d\n",jb[i],p[i]);
            sub++;
        }
    }
}
