#include <stdio.h>
#include <string.h>

int main()
{

    // Declare the file pointer
    FILE *filePointer;
    int n, i;
    // Get the data to be written in file
    printf("Enter the length of the string to be in file\n");
    scanf("%d", &n);
    printf("Enter the string\n");
    char dataToBeWritten[n];
    char dataToBeRead[n];
    scanf("%s", dataToBeWritten);

    // Open the existing file GfgTest.c using fopen()
    // in write mode using "w" attribute
    filePointer = fopen("BMSCE.txt", "w");

    // Check if this filePointer is null
    // which maybe if the file does not exist
    if (filePointer == NULL)
    {
        printf("GfgTest.c file failed to open.");
    }
    else
    {

        printf("The file is now opened.\n");

        // Write the dataToBeWritten into the file
        if (strlen(dataToBeWritten) > 0)
        {

            // writing in the file using fputs()
            fputs(dataToBeWritten, filePointer);
            fputs("\n", filePointer);
        }

        // Closing the file using fclose()
        fclose(filePointer);

        printf("Data successfully written in file BMSCE\n");
        printf("The file is now closed.");
    }
    // Open the existing file GfgTest.c using fopen()
    // in write mode using "w" attribute
    filePointer = fopen("BMSCE.txt", "r");

    // Check if this filePointer is null
    // which maybe if the file does not exist
    if (filePointer == NULL)
    {
        printf("GfgTest.c file failed to open.");
    }
    else
    {
        printf("\nReading data from the file BMSCE.\n");
        while( fgets ( dataToBeRead, 50, filePointer ) != NULL )
        {
          
            // Print the dataToBeRead 
            printf( "%s" , dataToBeRead ) ;
         }
        fclose(filePointer);

        printf("Data successfully read from file BMSCE\n");
        printf("The file is now closed.");
    }
        return 0;
}