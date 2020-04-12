
#include<iostream.h>
#include<stdio.h>

void main()
{

int k=0;
 for(int x=0;x<50;x++)
 {

    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp,arr[250],a;
    float avg_wt=0,avg_tat=0;

    n=5;


    FILE *fp1 = fopen("data.txt", "r");


    for(i=0;i<250;i++)
    {
        fscanf(fp1,"%d", &a);
        arr[i]=a;
    }

      fclose(fp1);


    for(i=0;i<250;i++){


    }

    for(i=0;i<n;i++)
    {

        bt[i]=arr[k++];
        p[i]=i+1;           //contains process number
    }

    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wt[0]=0;            //waiting time for first process will be zero

    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    avg_wt=(float)total/n;      //average waiting time
    total=0;

    FILE *fptr;
    fptr =fopen("outp_file.txt","a");

     fprintf(fptr,"\n \n");
    fprintf(fptr," %s ","Output ");
     fprintf(fptr,"%d\n",x+1);

     fprintf(fptr,"\n %s","Process");
     fprintf(fptr,"\t %s"," Burst Time ");
     fprintf(fptr,"\t %s","Waiting Time ");
     fprintf(fptr,"\t %s \n","Turnaround Time ");

    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        fprintf(fptr,"\n %d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }

    avg_tat=(float)total/n;     //average turnaround time
    fprintf(fptr,"\n \n");
    fprintf(fptr,"%s" ,"Average waiting time:-");     //average turnaround time
    fprintf(fptr,"%f\n",avg_wt);
    fprintf(fptr,"%s" ,"Average turn around time:-");
    fprintf(fptr,"%f\n",avg_tat);
    fclose(fptr);
    total=0;
 }
}

