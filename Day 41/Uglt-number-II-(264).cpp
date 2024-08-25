class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1);
        //t[i] ith ugly number

        int i2,i3,i5;
        i2=i3=i5=1;
        //1st ugly number is 1
        arr[1]=1;
        for(int i=2;i<=n;i++){
            int x=arr[i2]*2;//i2 ugly number
            int y= arr[i3]*3;//i3 ugly number
            int z=arr[i5]*5;//i5 ugly number

            //push minimum of these 3 on ith postion in the array as ith ugly nmber
            int minUgly=min({x,y,z});
            arr[i]= minUgly;

            //jiska minmum hua uska pointer ko badao
            if(minUgly==x) i2++;
            if(minUgly==y) i3++;
            if(minUgly==z) i5++;
        }
        return arr[n];
    }
};