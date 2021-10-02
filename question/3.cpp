/*
几种二分方法整理
元素可以重复
*/

//lower_bound(num, num+size, x)-num:大于等于x的第一个数的下标
//upper_bound(num, num+size, x)-num:大于x的第一个数的下标

//1.求等于x的最小的index，不存在返回-1
int binary (int *num, int start, int end, int x) {
	int l = start, r = end, ans=-1;
	while(l <= r) {
		int mid = (l+r) >> 1;
		if(num[mid] == x) {
			ans = mid;
			r = mid - 1;
		}
		else if(num[mid] > x)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return ans;
}

//2.求等于x的最大的index，不存在返回-1
int binary (int *num, int start, int end, int x) {
	int l = start, r = end, ans=-1;
	while(l <= r) {
		int mid = (l+r) >> 1;
		if(num[mid] == x) {
			ans = mid;
			l = mid + 1;
		}
		else if(num[mid] > x)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return ans;
}

//3.求小于x的最大的index
int binary (int *num, int start, int end, int x) {
	int l = start, r = end;
	while(l <= r) {
		int mid = (l+r) >> 1;
		if(num[mid] >= x)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return r;
}

//4.求大于x的最小的index
int binary (int *num, int start, int end, int x) {
	int l = start, r = end;
	while(l <= r) {
		int mid = (l+r) >> 1;
		if(num[mid] <= x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}

//5.求大于等于x的最小的index
int binary (int *num, int start, int end, int x) {
	int l = start, r = end;
	while(l <= r) {
		int mid = (l+r) >> 1;
		if(num[mid] >= x)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}

//6.求小于等于x的最大的index
int binary (int *num, int start, int end, int x) {
	int l = start, r = end;
	while(l <= r) {
		int mid = (l+r) >> 1;
		if(num[mid] <= x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return r;
}