/*
 *  charsets.h
 *  Typing
 *
 *  Created by Michael Dickens on 8/7/09.
 *
 */
 
#include "values.h"

#define streq(str1, str2) (strcmp(str1, str2) == 0)
#define streqn(str1, str2, n) (strncmp(str1, str2, n) == 0)

#define ASCII_SHIFT 14
 
#define MAX_TRI_LEN 5000
#define MAX_DI_LEN 5000
#define MAX_MON_LEN 200

#define ERROR_RATE_PERCENT 2

int64_t totalMon;
int64_t totalDi;
int monLen, diLen, triLen;

/* Constant definitions */

#define LEFT 0
#define RIGHT 1

#define PINKY 0
#define RING 1
#define MIDDLE 2
#define INDEX 3
#define THUMB 4

/* Reduces monValues and diValues so as to prevent integer overflow. */
#define DIVISOR 100

/* These are guaranteed to hold a standard QWERTY layout. */
#define DEFAULT_KEYBOARD_26 "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"
#define DEFAULT_KEYBOARD_30 "qwertyuiopasdfghjkl;zxcvbnm,./QWERTYUIOPASDFGHJKL:ZXCVBNM<>?"
#define DEFAULT_KEYBOARD_STANDARD "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?"
#define DEFAULT_KEYBOARD_KINESIS "1234567890-\tqwertyuiop=asdfghjkl;'zxcvbnm,./`\\[]\n !@#$%^&*()_\tQWERTYUIOP+ASDFGHJKL:\"ZXCVBNM<>?~|{}\n "
#define DEFAULT_KEYBOARD_BS4822 "`1234567890-=qwertyuiop[]asdfghjkl;'#\\zxcvbnm,./~!\"#$%^&*()_+QWERTYUIOP{}ASDFGHJKL:@~|ZXCVBNM<>?"

char keysToInclude[200];

typedef struct {
	char layout[KSIZE_MAX + 1]; /* The one extra character is set to '\0' so 
								(layout) can be treated as a string. */
	char shiftedLayout[KSIZE_MAX + 1];
	int64_t fingerUsage[FINGER_COUNT];
	int64_t shortcut;
	int64_t fitness;
	int64_t distance;
	int64_t fingerWork;
	int64_t inRoll;
	int64_t outRoll;
	int64_t sameHand;
	int64_t sameFinger;
	int64_t rowChange;
	int64_t homeJump;
	int64_t ringJump;
	int64_t toCenter;
	int64_t toOutside;
} Keyboard;



Keyboard nilKeyboard;

/* These are declared here because C's file hierarchy is stupid.
 */
Keyboard atleMutate(Keyboard k);
Keyboard simpleMutate(Keyboard k);
Keyboard mutate(Keyboard k);

void copyArray(int out[], int in[], int length);
int strNumsToArr(int arr[], char *str, int length);
int initData();
void initKeyboardData();
void initTypingData();
int compileTypingData(char *outfileName, char *filenames[], int multipliers[], int length, int unit, int max);
int sortTypingData(char **keys, int *values, int left, int right);
char convertEscapeChar(char c);

/* Sort by values from highest to lowest.
 */
int sortDigraphs(char keys[][2], int64_t values[], int left, int right);
int sortMonographs(char keys[], int64_t values[], int left, int right);

int setValue(char *str);
int getValue(char *name);

#define isBracket(c) (getMatchingBracket(c) != 0)
char getMatchingBracket(char c);

int alwaysKeepShiftPairP(char c);


int qwerty[30];

int randomizer;

/* For each key, indicates which hand (LEFT or RIGHT) is responsible for typing that key.
 */
int hand[KSIZE_MAX];

/* For each key, indicates which finger (PINKY, RING, MIDDLE or INDEX) is responsible for 
 * typing that key.
 */
int finger[KSIZE_MAX];

/* Where 0 is pinky, -1 is left of pinky, ..., 3 is index, 4 is right of index.
 * Anything greater than 4 is thumb.
 */
int column[KSIZE_MAX];

/* For each key, indicates which row that key lies on. The top row is 0, the row below it 
 * is 1, the row below that is 2, etc.
 */
int row[KSIZE_MAX];

/* Indicates which row is the home row.
 */
int homeRow;

/* Indicates the index of the first number in the layout, assuming keepNumbers == TRUE.
 */
int numStart;

/* For each key, indicates whether that key requires a reach to the center.
 */
int isCenter[KSIZE_MAX];

/* For each key, indicates whether that key requires a reach to the outside.
 */
int isOutside[KSIZE_MAX];

/* For each key, indicates whether that key requires a reach to the center OR a reach to 
 * the outside. This one is produced automatically from isCenter[] and isOutside[].
 */
int isCenterOrOutside[KSIZE_MAX];

/* For each key, indicates whether that key should be printed. Any place-holder key that 
 * does not actually exist on the keyboard should not be printed.
 */
int printable[KSIZE_MAX];

/* Lookup tables for calcRowChange(). Each row and column represents a finger.
 */
int rowChangeTableUp[5][5];
int rowChangeTableDown[5][5];


int costs[900];

char triKeys[MAX_TRI_LEN][3];
int64_t triValues[MAX_TRI_LEN];

char diKeys[MAX_DI_LEN][2];
int64_t diValues[MAX_DI_LEN];

char monKeys[MAX_MON_LEN];
int64_t monValues[MAX_MON_LEN];

/* Used in cjalgorithm.c. */
int indices[2 * KSIZE_MAX];
