long long int merge(int *v, int l, int m, int r) {
    int size = (r-l+1);
    int *aux = malloc(size*sizeof(int));

    int i = l;
    int j = m+1;
    int k = 0;

    long long int inv_cnt = 0;
    while (i <= m && j <= r) {
        if (v[i] > v[j]) {
            inv_cnt += m-i+1;
            aux[k++] = v[j++];
        } else {
            aux[k++] = v[i++];
        }
    }

    while (i<=m) aux[k++] = v[i++];
    while (j<=r) aux[k++] = v[j++];

    memcpy(&v[l], aux, size*sizeof(int));
    free(aux);

    return inv_cnt;
}

long long int count(int *v, int l, int r) {
    if (l >= r) return 0;
    
    int m = (l+r)/2;

    long long int l_cnt = count(v, l, m);
    long long int r_cnt = count(v, m+1, r);
    
    long long int j_cnt = merge(v, l, m, r);

    return l_cnt+r_cnt+j_cnt;
}

long long int count_local(int *v, int n) {
    long long int cnt = 0;
    for (int i=0; i<n-1; i++) {
        if (v[i] > v[i+1]) cnt++;
    }
    return cnt;
}

bool isIdealPermutation(int* nums, int numsSize) {
    // local must come first due to merge-sort side effects
    long long int local = count_local(nums, numsSize);
    long long int global = count(nums, 0, numsSize-1);

    printf("g: %lld\nl: %lld", global, local);
    return global == local;
}
