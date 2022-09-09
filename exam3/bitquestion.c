#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// take the leftmost two bits from each byte in orig
// pack these bits to dest
// size is the number of bytes in orig
// 
// dest should have enough memory to store the result
// convert does not allocate memory in heap

void convert(const unsigned char * orig,
	     unsigned char * dest,
	     int size)
{
  int bitCount = 0;  // how many bits have been added
  int destCount = 0; // index for the destination array
  unsigned char bitMask = ???; // <--- ANSWER A
  unsigned char destByte = 0;  // destination byte
  int cnt;
  for (cnt = 0; cnt < size; cnt ++)
    {
      // get the leftmost two bits
      unsigned char oneBit = ???; // <--- ANSWER B 

      // shift right to the correct location
      unsigned char destBit = ??? // <--- ANSWER C

      // add the bit to the destination
      destByte = destByte | destBit;

      // increment bitCount
      bitCount += 2;

      // fill one byte 
      if (???) // <--- ANSWER D
	{
	  dest[destCount] = destByte;
	  destCount ++;
	  destByte = 0;
	}
    }
  // If size is not a multliple of 8, handle the last byte
  if ((size % 4) != 0)
    {
      dest[destCount] = destByte;
      // no need to update destCount since it is the last
    }
}

int main(int argc, char * argv[])
{
  // argv[1]: input file
  // argv[2]: output file
  if (argc < 3)
    {
      return EXIT_FAILURE;
    }
  FILE * fpin = fopen(argv[1], "r");
  if (fpin == NULL)
    {
      return EXIT_FAILURE;
    }
  FILE * fpout = fopen(argv[2], "w");
  if (fpout == NULL)
    {
      fclose (fpin);
      return EXIT_FAILURE;
    }

  // find the length of the input file
  fseek(fpin, 0, SEEK_END);
  long length = ftell(fpin);
  // allocate memory for the input
  unsigned char * orig = malloc(sizeof(unsigned char) * length);
  // return the beginning of the file
  fseek(fpin, 0, SEEK_SET);
  
  // read the input from the file
  int rtv = fread(orig, sizeof(unsigned char), length, fpin);
  if (rtv != length)
    {
      printf("fread fail, rtv = %d, length = %ld\n",
	     rtv, length);
    }

  // calculate the output's length
  long outlength = length / 4;
  if ((length % 4) != 0)
    {
      outlength ++;
    }

  // allocate memory for the output
  unsigned char * dest = malloc(sizeof(unsigned char) * outlength);

  convert(orig, dest, length);

  // write the result to the output file
  rtv = fwrite(dest, sizeof(unsigned char), outlength, fpout);
  
  if (rtv != outlength)
    {
      printf("fwrite fail, rtv = %d, outlength = %ld\n",
	     rtv, outlength);
    }
  
  // close the files
  fclose (fpin)
  fclose (fpout);
  return EXIT_SUCCESS;
}
