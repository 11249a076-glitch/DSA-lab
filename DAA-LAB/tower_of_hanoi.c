#include <stdio.h> 
 void towerOfHanoi(int diskNumber, char source, char destination, char auxiliary) 
 {  
     if (diskNumber == 1) { 
         printf("Move disk 1 from %c to %c\n", source, destination); 
         return; 
     }   
     towerOfHanoi(diskNumber - 1, source, auxiliary, destination);  
     printf("Move disk %d from %c to %c\n", diskNumber, source, destination); 
     towerOfHanoi(diskNumber - 1, auxiliary, destination, source); 
 } 
  
 int main() { 
     int n; 
     printf("Enter number of disks: "); 
     if (scanf("%d", &n) != 1 || n <= 0) { 
         printf("Please enter a valid positive integer.\n"); 
         return 1; 
     } 
     printf("\nRequired moves:\n"); 
     towerOfHanoi(n, 'S', 'D', 'A'); 
     return 0; 
}