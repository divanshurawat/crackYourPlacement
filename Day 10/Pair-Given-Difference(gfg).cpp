sort(arr.begin(), arr.end());
        int i = 0, j = 1;
        while (i < n && j < n) 
        {
            if (i != j && arr[j] - arr[i] == x) 
            {
                return 1;
            } 
            else if (arr[j] - arr[i] < x) 
            {
                j++;
            } 
            else 
            {
                i++;
            }
        }
        return -1;