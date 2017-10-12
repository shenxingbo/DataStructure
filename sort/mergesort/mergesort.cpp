//这种归并排序写的实在是精妙 
void merge_sort(int A[],int x,int y, int T[]) {
	/**
	* x 为起点  m为中点    y为终点 
	*/
	if (y - x > 1) {
		int m = x + (y - x) / 2;
		int p  = x, q = m, i = x;
		merge_sort(A, x, m, T);
		merge_sort(A, m, y, T);
		while(p < m || q < y) {
			if (q >= y || (p < m && A[p] <= A[q]))
				T[i++] = A[p++];
			else 
				T[i++] = A[q++]; 
		} 
		
		for (i = x; i < y; i++) 
			A[i] = T[i];
	}
}

