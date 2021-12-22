#include<stdio.h>
#include<conio.h>

#define ALL -1
#define MAXCITIES 10

enum BOOL{FALSE,TRUE};
long*visited;
long*min_circuit;
long*ham_circuit;
long min_circuit_length;
int n;
long matrix[MAXCITIES][MAXCITIES];
long INFI;

void reset_min_circuit(int s_v_id)
{
	    min_circuit[0]=s_v_id;
	      for(int i=1;i<n;i++)     min_circuit[i]=-1;
}

void set_visited(int v_id,BOOL flag)
{
	    if(v_id==ALL)
	    for(int i=0;i<n;i++)     visited[i]=flag;

	    else                 visited[v_id]=flag;
}

void SET_HAM_CKT(long pl)
{

	    ham_circuit[0]=pl;

	    for(int i=0;i<n;i++)
	    ham_circuit[i+1]=min_circuit[i];
	    ham_circuit[n+1]=min_circuit[0];
}

long get_valid_circuit(int s_v,int s_n_v)
{
	    int next_v,min,v_count=1;
	    long path_length=0;
	    min_circuit[0]=s_v;
	    min_circuit[1]=s_n_v;
	    set_visited(s_n_v,TRUE);
	    path_length+=matrix[s_v][s_n_v];

	    for(int V=s_n_v;v_count<n-1;v_count++)
	    {           min=INFI;

				    for(int i=0;i<n;i++)

						if (matrix[V][i]<INFI && !visited[i]
							    && matrix[V][i]<=min
						  )						   )
							    min=matrix[V][next_v=i];

			set_visited(next_v,TRUE);
			V=min_circuit[v_count+1]=next_v;
			path_length+=min;
	    }
	    path_length+=matrix[min_circuit[n-1]][s_v];
	    return(path_length);
}

void main()
{
	    clrscr();
	    printf("Make sure that infinity value < sum of all path distances\nSet Infinity at (signed long):");
	    scanf("%ld",&INFI);
	    int pathcount,i,j,source,dest;
	    long dist=0;
	    long new_circuit_length=INFI;
	    printf("Tedade Shahr ha ra vared Kon (MAX:%d):",MAXCITIES);
	    scanf("%d",&n);
	    printf("Tetade Masir ha ra vared kon :");
	    scanf("%d",&pathcount);
	    printf("Enter paths:< source_id destination_id distance >\n ids varying from 0 to %d\n",n-1);
	    for(i=0;i<n;i++)

			for(j=0;j<n;j++)
				   matrix[i][j]=INFI;

	    for(i=0;i<pathcount;i++)
	    {
			printf("[path %d]:",i);
			scanf("%d %d %ld",&source,&dest,&dist);

			if(source!=dest)

			     matrix[source][dest]=matrix[dest][source]=dist;
	    }

	    visited=new long[n];
	    min_circuit=new long[n];
	    ham_circuit=new long[n+2];
	    min_circuit_length=INFI;

	    for(int S_V_id=0;S_V_id<n;S_V_id++)
	    {
			for(i=0;i<n;i++)
			{
				    set_visited(ALL,FALSE);
				    set_visited(S_V_id,TRUE);
				    reset_min_circuit(S_V_id);
				    new_circuit_length=get_valid_circuit(S_V_id,i);

				    if(new_circuit_length<=min_circuit_length)
				    SET_HAM_CKT(min_circuit_length=new_circuit_length);

		       }
	    }

if(min_circuit_length<INFI)
{
	    printf("\n\nMinimum circuit length is: %ld\nCircuit is:\n",min_circuit_length);
	    for(i=1;i<n+2;i++)
	    printf("<%ld> ",ham_circuit[i]);
}

else     printf("\n\nNo hamiltonian circuit !");

getch();
delete []visited;
delete []min_circuit;
delete []ham_circuit;
} 