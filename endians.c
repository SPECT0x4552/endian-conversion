#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#pragma warning (disable:4996)

// Function to swap a value from big Endian to little Endian and vice-versa
int swapEndian(int value) {

    int leftmost_byte; // Holds the leftmost 8 bits of the ouput;
 
    int left_middle_byte; // Holds the left middle 8 bits of the output.

    int right_middle_byte;

    int rightmost_byte;

    int result;


    // Get the rightmost 8 bits of the number by anding it 0x000000FF
    // Since the last 8 bits are all ones, the result will be the rightmost 8 bits of the number. 

    // This will be converted into the leftmost 8 bits for the output (swapping)

    leftmost_byte = (value & 0x000000FF) >> 0;

    // Get the right middle and left middle 8 bits which will become the left_middle bits in the output

    left_middle_byte = (value & 0x0000FF00) >> 8;

    right_middle_byte = (value & 0x00FF0000) >> 16;

    // Get the leftmost 8 bits which will be the rightmost 8 bits of the output

    rightmost_byte = (value & 0xFF000000) >> 24;

    // Left shift the 8 bits by 24 bits so that it is shifted to the leftmost end

    leftmost_byte <<= 24;


    // Left shift by 16 so that is in the left_middle position
    // In other words, it starts at the 9th bit from the left and ends at the 16 bith from the left

    left_middle_byte <<= 16;
    right_middle_byte <<= 8;


    // The rightmost bit stays as it is
    // as it is in the correct position

    rightmost_byte <<= 0;


    result = (leftmost_byte | left_middle_byte | right_middle_byte | rightmost_byte);

    return result;

    return 0;
}

unsigned char rawData[] = {
    0xA7, 0x03, 0x2D, 0x63
};

uint32_t hex2int(char *hex) {
    uint32_t val = 0;

    while(*hex) {

        // Get the current character and then increment
        uint8_t byte = *hex++;

        // Transform the hex character to the 4bit equivalent number using ASCII
        if(byte >= '0' && byte <= '9') {
            byte = byte - '0';
        } else if (byte >= 'a' && byte <= 'f') {
            byte = byte - 'a' + 10;
        } else if (byte >= 'A' && byte <= 'F') {
            byte = byte - 'A' + 10;
        }

        // Shift 4 bits to make space for the new digit, and add the 4 bits to the new digit
        val = (val << 4) | (byte & 0xF);
    }

    return val;
}

int main(void) {

   char str[sizeof(rawData)];
   sprintf(str, "%0.2X%0.2X%0.2X%0.2X", rawData[0], rawData[1], rawData[2], rawData[3]);
    printf("%s\n", str);

   int number = hex2int(str);
   int result = swapEndian(number);

    printf("%i\n", number);
    printf("0x%X\n", result);

   

    return 0;
}
