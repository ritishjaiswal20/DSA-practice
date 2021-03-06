class Solution
{
    public:
    bool static mycomp(Item a,Item b)
    {
        double r1=(double)a.value /(double) a.weight;
        double r2=(double)b.value /(double) b.weight;
        return r1>r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double res=0.0;
        sort(arr,arr+n,mycomp);
        for(int i=0;i<n;i++)
        {
            if(arr[i].weight<= W)
            {
                res+=arr[i].value;
                W-=arr[i].weight;
            }
            else
            {
                res+=arr[i].value * ((double)W/arr[i].weight);
                break;
            }
        }
        return res;
    }
        
};
