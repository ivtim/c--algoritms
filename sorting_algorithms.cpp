void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void quick_sort(int* s_arr, int first, int last)
{
    int i = first, j = last, x = s_arr[(first + last) / 2];

    do {
        while (s_arr[i] < x) i++;
        while (s_arr[j] > x) j--;

        if (i <= j) {
            if (s_arr[i] > s_arr[j])
                swap(&s_arr[i], &s_arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        quick_sort(s_arr, i, last);
    if (first < j)
        quick_sort(s_arr, first, j);
}

void insertion_sort(int* ar, int size) {
    int i = 1;
    while (i < size)
    {
        int j = i;
        while (j > 0 && ar[j - 1] > ar[j])
        {
            swap(&ar[j], &ar[j - 1]);
            j--;
        }
        i++;
    }
}

void shell_sort(int* array, int size) {
    for (int s = size / 2; s > 0; s /= 2) {
        for (int i = 0; i < size; i++) {
            for (int j = i + s; j < size; j += s) {
                if (array[i] > array[j]) {
                    int temp = array[j];
                    array[j] = array[i];
                    array[i] = temp;
                }
            }
        }
    }
}

void bubble_sort(int* arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void comb_sort(int* data, int n)
{
    double factor = 1.2473309;
    int step = n - 1;

    while (step >= 1)
    {
        for (int i = 0; i + step < n; i++)
        {
            if (data[i] > data[i + step])
            {
                swap(&data[i], &data[i + step]);
            }
        }
        step /= factor;
    }
}

void heapify(int* arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int* arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void merge_sort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}