Scenario 1: A software application for an online store needs to sort a list 
of product prices in ascending order to help customers easily find cheaper 
options. The list is stored dynamically, and the program should work efficiently 
even for large datasets.


#include<stdio.h>

void swap(float *a,float *b){
    float temp=*a;
    *a=*b;
    *b=temp;
}

int partition(float arr[],int low,int high){
    float pivot=arr[high];
    int i=(low-1);

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return(i+1);
}

void quickSort(float arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}


void printArray(float arr[],int size){
    for(int i=0;i<size;i++){
        printf("%.2f ",arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the number of product prices: ");
    scanf("%d",&n);
    float prices[n];
    
    printf("Enter the product prices:\n");
    for(int i=0;i<n;i++){
        scanf("%f",&prices[i]);
    }

    quickSort(prices,0,n-1);

    printf("Sorted product prices in ascending order:\n");
    printArray(prices,n);

    return 0;
}


Sample output:

Enter the number of product prices: 5
Enter the product prices:
450.50
120.00
999.99
300.75
200.25

Sorted product prices in ascending order:
120.00 200.25 300.75 450.50 999.99


Scenario 2: A team of researchers needs to sort the ages of participants 
in a clinical trial from youngest to oldest. The list of ages is stored 
using pointers in dynamically allocated memory to allow flexibility in 
the size of the dataset.



#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *arr,int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the number of participants: ");
    scanf("%d",&n);
    int *ages=(int *)malloc(n * sizeof(int));
    if (ages == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter the ages of participants:\n");
    for (int i=0;i<n;i++){
        scanf("%d",&ages[i]);
    }

    bubbleSort(ages,n);

    printf("Sorted ages from youngest to oldest:\n");
    for (int i=0;i<n;i++){
        printf("%d ",ages[i]);
    }
    printf("\n");

    free(ages);

    return 0;
}



Sample Output:

Enter the number of participants: 5
Enter the ages of participants:
29 45 19 33 21
Sorted ages from youngest to oldest:
19 21 29 33 45



Scenario 3: A library management system needs to sort the titles of books alphabetically 
in an efficient manner. The program should dynamically allocate memory for storing the 
book titles and use a suitable sorting algorithm to handle a large number of books.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int compareTitles(const void *a,const void *b){
    return strcmp(*(const char **)a,*(const char **)b);
}

int main(){
    int numBooks;
    printf("Enter the number of books: ");
    scanf("%d",&numBooks);


    char **bookTitles=(char **)malloc(numBooks * sizeof(char *));
    if (bookTitles == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }


    char buffer[100];
    getchar();// To consume the newline character left by scanf
    for (int i=0;i<numBooks;i++){
        printf("Enter title of book %d: ",i+1);
        fgets(buffer,sizeof(buffer),stdin);
        buffer[strcspn(buffer,"\n")]='\0';// Remove newline character


        bookTitles[i]=(char *)malloc((strlen(buffer)+1) * sizeof(char));
        if (bookTitles[i] == NULL){
            printf("Memory allocation failed for book title.\n");
            return 1;
        }
        strcpy(bookTitles[i],buffer);
    }


    qsort(bookTitles,numBooks,sizeof(char *),compareTitles);
    printf("\nSorted Book Titles:\n");
    for (int i=0;i<numBooks;i++){
        printf("%s\n",bookTitles[i]);
        free(bookTitles[i]);// Free each book title
    }


    free(bookTitles);

    return 0;
}



Sample Output:

Enter the number of books: 3
Enter title of book 1: The Great Gatsby
Enter title of book 2: War and Peace
Enter title of book 3: Moby Dick

Sorted Book Titles:
Moby Dick
The Great Gatsby
War and Peace



