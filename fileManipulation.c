/*
Program totals all the characters, words, and lines in a file or files.
Demonstrates knowledge of file manipulation.
*/

#include<stdio.h>
#include<string.h>

int main(int argc,char* argv[]) {
  //initialize variables to be used
  int w=0, c=0, l=0;
  char currentChar, prevChar;
  int sum = 0;
  
  //check to see if there are enough arguments
  if(argc < 2) {
    fprintf(stderr, "NOT ENOUGH ARGUMENTS GIVEN");
    return 1;
  }
  
  //use a for loop to cycle count the given stat for each file
  int i;
  for (i = 2; i < argc; i++) {
    //open the file and chekc to make sure it exists
    FILE* file = fopen(argv[i], "r");
    if(file == NULL) {
      fprintf(stderr, "THE FILE DID NOT EXIST OR WAS NOT OPENED CORRECTLY");
      return 1;
    }

    /*
    Use a while loop to cycle through each character until the end of the
    file is
    reached.
    Increment the number of characters except for when there is a new line
    character.
    If there is a new line then increment the number of lines.
    If there is a space or new line make sure the previous character is not
    a space. If it is not then increment the word counter.
    */
    currentChar = fgetc(file);
    while(currentChar != EOF)
    {
      c++;
      if (currentChar == '\n') {
        l++;
      }
      prevChar = currentChar;
      currentChar = fgetc(file);
      if ((currentChar == ' ' && prevChar != ' ') || (currentChar == '\n' && prevChar != ' ')) {
        w++;
      }
    }

    //see which variable needs to be printed out, and it to the sum and set it to zero
    if(!strcmp(argv[1],"-w")) {
      printf("%d",w);
      sum += w;
      w = 0;
    } else if(!strcmp(argv[1],"-l")) {
      printf("%d",l);
      sum += l;
      l = 0;
    } else if(!strcmp(argv[1],"-c")) {
      printf("%d",c);
      sum += c;
      c = 0;
    }
    printf(" %s\n",argv[2]);
    
    //close the file
    fclose(file);
  }
          
  //print out the total of all the counted variable
  printf("%d Total\n", sum);
          
  //necessary return statement
  return 0;
}
