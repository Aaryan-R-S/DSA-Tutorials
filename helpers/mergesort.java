package helpers;

class Mergesort{
    static void merge(long arr[], int low, int mid, int high){
        int i=low;
        int j=mid+1;
        int k=low; 
        long arr_copy[] = new long[arr.length]; 
        while (i<=mid && j<=high)
        {
            if (arr[i]<=arr[j])
            {
                arr_copy[k] = arr[i];
                i++; k++;
            }
            else
            {
                arr_copy[k] = arr[j];
                j++; k++;
            }
        }
        while (i<=mid)
        {
            arr_copy[k] = arr[i];
            i++; k++; 
        }
        while (j<=high)
        {
            arr_copy[k] = arr[j];
            j++; k++;
        }
        for (int t = low; t <= high; t++)
        {
            arr[t] = arr_copy[t];
        }
    }

    static void mergesort(long arr[], int low, int high){
        if(low<high){
            int mid = low + (high-low)/2;
            mergesort(arr, low, mid);
            mergesort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }
    }

}