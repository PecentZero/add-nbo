#include <stdio.h> //for print
#include <stdint.h> //for uint32_t
#include <netinet/in.h> //for ntohl htonl

int main(int argc, char** argv)
{


  FILE *f1 = NULL;
  FILE *f2 = NULL;
  uint32_t input1;
  uint32_t input2;
  
  if(argc != 3) 
  {
	  printf("Plz match type like  input ./add <xx.bin> <xxxx.bin>");  
 	  return -1;
  }
  f1 = fopen(argv[1],"rb");
  f2 = fopen(argv[2],"rb");
  
 if(f1 == NULL || f2 == NULL)
 {
	 printf("Plz input exist file");
	return -1;
   }	

  fread(&input1,sizeof(uint32_t),1,f1);
  fread(&input2,sizeof(uint32_t),1,f2);

  input1 = ntohl(input1);
  input2 = ntohl(input2);


  fclose(f1);
  fclose(f2);
  
  
 printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",input1,input1,input2,input2,input1+input2,input1+input2);
 return 0;

}



