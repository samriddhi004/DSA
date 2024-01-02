int * arr = new int[n];
      for(int i=0; i<n; i++){
        arr[i] = i+1;
      }
      // Binary
      int low = 0;
      int high = n-1;
      int ind = high / 2;
      while(high > low){
        if (isBadVersion(arr[ind])){
          high = ind;
        }else{
          low = ind;
        }
      }
      return ind;