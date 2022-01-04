bool isSubsetSum(int n, int arr[], int sum){
        
        bool t[n+1][sum+1];
       
       for(int j=0;j<sum+1;j++)
       t[0][j]=false;
       for(int i=0;i<n+1;i++)
       t[i][0]=true;
       
       
       
       
       for(int i=1;i<n+1;i++)
       for(int j=1;j<sum+1;j++)
       {
           if(arr[i-1]<=j)
           t[i][j]=(t[i-1][j-arr[i-1]] || t[i-1][j]);
           else
           t[i][j]=t[i-1][j];
       }
       return t[n][sum];
     
    }
