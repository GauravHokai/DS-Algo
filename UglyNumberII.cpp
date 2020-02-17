class Solution {
public:
    int nthUglyNumber(int n) {
        int arr[n];
        arr[0] = 1;
        int x = 0,y=0,z=0;
        for(int i=1;i<n;i++)
        {
            arr[i] = min(arr[x]*2,min(arr[y]*3,arr[z]*5));
            if(arr[i]==arr[x]*2)
                x++;
            if(arr[i]==arr[y]*3)
                y++;
            if(arr[i]==arr[z]*5)
                z++;
        }
        return arr[n-1];
        
        
    }
};
