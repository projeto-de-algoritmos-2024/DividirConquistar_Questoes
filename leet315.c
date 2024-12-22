int *cnt;
int *idx;
void merge(int *v, int l, int m, int r) {
    int size = (r-l+1);
    int *aux = malloc(size*sizeof(int));
    int *new_idx = malloc(size*sizeof(int));

    int i = l;
    int j = m+1;
    int k = 0;

    int inv_cnt = 0;
    while (i <= m && j <= r) {
        if (v[i] <= v[j]) {
            cnt[idx[i]] += inv_cnt;
            new_idx[k] = idx[i];
            aux[k++] = v[i++];
        } else {
            inv_cnt++;
            new_idx[k] = idx[j];
            aux[k++] = v[j++];
        }
    }

    while (i<=m) { 
        cnt[idx[i]] += inv_cnt;
        new_idx[k] = idx[i];
        aux[k++] = v[i++];
    }
    while (j<=r)  {
        new_idx[k] = idx[j];
        aux[k++] = v[j++];
    }

    memcpy(&v[l], aux, size*sizeof(int));
    memcpy(&idx[l], new_idx, size*sizeof(int));
    free(aux);
    free(new_idx);
}

void count(int *v, int l, int r) {
    if (l >= r) return;
    
    int m = (l+r)/2;

    count(v, l, m);
    count(v, m+1, r);
    merge(v, l, m, r);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    cnt = calloc(numsSize, sizeof(int));
    idx = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    for (int i=0; i<numsSize; i++)
        idx[i] = i;

    count(nums, 0, numsSize-1);
    return cnt;
}
