#include <stdio.h>

void merge(int [], int [], int []);

int main()
{
    int a[5] = { 1,3,5,7,9 };
    int b[6] = { 2,4,6,8,10,12};
    int sorted[11];
    int i;

    merge (a, b, sorted);

    printf("\n\nMerge sorted array:\n\n");

    for (i = 0; i < 11; i++) 
    {
        printf("%d\n", sorted[i]);
    }

return 0;
}

void merge(int a[5], int b[6], int sorted[]) 
{
  int i, j, k;

  j = k = 0;

  for (i = 0; i < 11;) 
  {
    if (j < 5 && k < 6) 
    {
      if (a[j] < b[k]) 
      {
        sorted[i] = a[j];
        j++;
      }
      else {
        sorted[i] = b[k];
        k++;
      }
      i++;
    }
    else if (j == 5) {
      for (; i < 11;) {
        sorted[i] = b[k];
        k++;
        i++;
      }
    }
    else {
      for (; i < 11;) {
        sorted[i] = a[j];
        j++;
        i++;
      }
    }
  }
}


