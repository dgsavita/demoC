#include <stdio.h>
// for basic 8 bit ANSI codes go from [30m-[37m for foreground and [40m-[47m for background
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"

#define ANSI_COLOR_BOLD_GREEN "\x1b[1;32m" // uses BOLD

#define ANSI_COLOR_256_TEXT(color) "\x1b[38;5;" #color "m"
#define ANSI_COLOR_256_BG(color) "\x1b[48;5;" #color "m" // function to define extended color set(0 to 256),not supported on all terminals

#define ANSI_COLOR_256_TEXT_DEC(color, decoration) "\x1b[38;5;" #color "m" decoration // same but with decoration(underline,bold,reversed)
#define ANSI_COLOR_256_BG_DEC(color, decoration) "\x1b[48;5;" #color "m" decoration

#define ANSI_BOLD "\x1b[1m"
#define ANSI_UNDERLINE "\x1b[4m"
#define ANSI_REVERSED "\x1b[7m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define TABS "\t\t\t"

int main()
{
    // Assuming you have a file named "ascii_art.txt" with the ASCII art content
    FILE *file = fopen("cat.txt", "r");
    int lineCount = 0;
    if (file != NULL)
    {
        // Read ASCII art from the file
        char buffer[256]; // Adjust the buffer size based on your ASCII art size
      
        while (fgets(buffer, sizeof(buffer), file) != NULL)
        {
            switch (lineCount % 4)
            {
            case 0:
                printf(TABS ANSI_COLOR_RED ANSI_COLOR_256_BG_DEC(232, "\x1b[1m") "%s" ANSI_COLOR_RESET, buffer);
                break;
            case 1:
                printf(TABS ANSI_COLOR_256_TEXT_DEC(208, "\x1b[1m") ANSI_COLOR_256_BG(235) "%s" ANSI_COLOR_RESET, buffer); // Orange text, dark gray background
                break;
            case 2:
                printf(TABS ANSI_COLOR_YELLOW ANSI_COLOR_256_BG(236) "%s" ANSI_COLOR_RESET, buffer);
                break;
            case 3:
                printf(TABS ANSI_COLOR_256_TEXT_DEC(215, "\x1b[1m") ANSI_COLOR_256_BG(234) "%s" ANSI_COLOR_RESET, buffer); // Orange light text, dark gray background
                break;
            }
            fflush(stdout);  // Ensure the output is flushed
            lineCount++;
        }

        fclose(file);
    }
    else
    {
        // Handle file opening error
        fprintf(stderr, "Error opening file\n");
    }

    return 0;
}

/**
 * code for just bright colors (16 bit extended color set)
 *  switch (lineCount % 3) {
                case 0:
                    printf(ANSI_COLOR_16_TEXT(9, "\x1b[1m") ANSI_COLOR_16_BG(7, "\x1b[4m") "%s" ANSI_COLOR_RESET, buffer);  // Bright blue text, white background, bold
                    break;
                case 1:
                    printf(ANSI_COLOR_16_TEXT(2, "\x1b[4m") ANSI_COLOR_16_BG(0, "\x1b[1m") "%s" ANSI_COLOR_RESET, buffer);  // Green text, black background, underline
                    break;
                case 2:
                    printf(ANSI_COLOR_16_TEXT(3, "\x1b[1;4m") ANSI_COLOR_16_BG(15, "\x1b[1m") "%s" ANSI_COLOR_RESET, buffer); // Cyan text, bright white background, bold and underline
                    break;
            }
 *
*/