#include <stdio.h>
#include<conio.h>

int main()
{
  int array[20], search, c, n;

  printf("\nEnter number of elements in array(<20)===>>>");
  scanf("%d", &n);

  printf("\nEnter %d Elements: ", n);

  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  printf("\nEnter a number to search===>>>");
  scanf("%d", &search);

  for (c = 0; c < n; c++)
  {
    if (array[c] == search)   
    {
      printf("%d is present at location %d.\n", search, c+1);
      break;
    }
  }
  if (c == n)
    printf("%d isn't present in the array.\n", search);

  return 0;
}
