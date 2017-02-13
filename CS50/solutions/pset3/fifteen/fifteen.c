/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int getTileX(int tile);
int getTileY(int tile);
bool isValidMove(int tileX, int tileY, int emptyTileX, int emptyTileY);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int n = d * d - 1;

    for (int y = 0; y < d; y++)
    {
        for (int x = 0; x < d; x++)
        {
            if (y == d - 1 && x == d - 1)
            {
                board[y][x] = 0;
            }
            else if (n == 1 && d % 2 == 0)
            {
                board[y][x] = 2;
            }
            else if (n == 2 && d % 2 == 0)
            {
                board[y][x] = 1;
            }
            else
            {
                board[y][x] = n;
            }
            
            n--;
        }
    } 
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int y = 0; y < d; y++)
    {
        for (int x = 0; x < d; x++)
        {
            if (board[y][x] == 0)
            {
                printf("  _");
            }
            else
            {
                printf("%*d", 3, board[y][x]);
            }
        }
        
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int tileX = getTileX(tile);
    int tileY = getTileY(tile);
    int emptyTileX = getTileX(0);
    int emptyTileY = getTileY(0);

    if (isValidMove(tileX, tileY, emptyTileX, emptyTileY))
    {
        board[tileY][tileX] = 0;
        board[emptyTileY][emptyTileX] = tile;
        
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int n = 1;

    for (int y = 0; y < d; y++)
    {
        for (int x = 0; x < d; x++)
        {
            if (!(y == d - 1 && x == d - 1) && (board[y][x] != n))
            {
                return false;
            }
            
            n++;
        }
    }

    return true;
}

int getTileX(int tile)
{
    for (int y = 0; y < d; y++)
    {
        for (int x = 0; x < d; x++)
        {
            if (board[y][x] == tile)
            {
                return x;
            }
        }
    }
    
    return -1;
}

int getTileY(int tile)
{
    for (int y = 0; y < d; y++)
    {
        for (int x = 0; x < d; x++)
        {
            if (board[y][x] == tile)
            {
                return y;
            }
        }
    }
    
    return -1;
}

bool isValidMove(int tileX, int tileY, int emptyTileX, int emptyTileY)
{
    return abs(tileX - emptyTileX) + abs(tileY - emptyTileY) == 1;
}