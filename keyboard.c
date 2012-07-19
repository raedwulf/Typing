/*
 *  keyboard.c
 *  Typing
 *
 *  Created by Michael Dickens on 8/7/09.
 *
 */

#include "keyboard.h"

int legalBox[] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
};

int legalBox2[] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 
	3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 
};

int legalBox3[] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 
	4, 4, 3, 3, 3, 3, 3, 3, 4, 4, 
};

int legalBox4[] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 
	3, 3, 4, 4, 3, 3, 4, 4, 3, 3, 
};

int legalBox5[] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
};

int bigLegalBox[] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
};

int bigLegalBox1[] = {
	1, 2, 3, 4, 5, 6, 7, 8, 9,10,11, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
};

int bigLegalBox2[] = {
	1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
};

int bigLegalBoxAtle[] = {
	1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
};

int bigLegalBoxConsonants[] = {
	1,12, 3, 4, 5, 6, 7, 8, 9,10,11, 2, 2, 2, 
	1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 
	1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 
	1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
};

int kinesisLegalBox[] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
};

int kinesisLegalBox2[] = {
	1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
};

int initKeyboard(Keyboard *k)
{
	int i;
	
	copy(k, &nilKeyboard);
	setLayout(k, keysToInclude);
			
	for (i = 0; i < FINGER_COUNT; ++i) k->fingerUsage[i] = 0;
	
	shuffleLayout(k);
	
	/* If keepZXCV is enabled, move ZXCV back to their positions. */
	if (keepZXCV && ksize == 30) {
		for (i = 0; i < ksize; ++i) {
			if (k->layout[i] == 'z') {
				k->layout[i] = k->layout[20];
				k->layout[20] = 'z';
			} else if (k->layout[i] == 'x') {
				k->layout[i] = k->layout[21];
				k->layout[21] = 'x';
			} else if (k->layout[i] == 'c') {
				k->layout[i] = k->layout[22];
				k->layout[22] = 'c';
			} else if (k->layout[i] == 'v') {
				k->layout[i] = k->layout[23];
				k->layout[23] = 'v';
			}
		}
	}
	
	/* If keepNumbers is enabled, move all numbers back to their positions. */
	if (keepNumbers && ksize > 30) {
		char c;
		for (c = '0'; c <= '9'; ++c) {
			i = loc(k, c);
			int n = (c - '0' + 9) % 10 + numStart;
			swap(k, i, n);
		}
	}
	
	if (keepTab) {
		int loc = locWithShifted(k, '\t');
		if (loc >= 0) {
			int tabLoc = ksize == 72 ? 12 : 14;
			swap(k, loc, tabLoc);
		}
	}
	
	if (keepConsonantsRight && (fullKeyboard == FK_STANDARD) || (fullKeyboard == FK_BS4822)) {
		const char *consonants = "bcdfghjklmnpqrstvwxyz";
		/* TODO: Swap both shifted and unshifted */
		int halfIndices[] = {
			11, 12, 
			20, 21, 22, 23, 24, 25, 26, 27, 
			34, 35, 36, 37, 38, 39, 
			48, 49, 50, 51, 52, 
		};
				
		for (i = 0; i < sizeof(halfIndices)/sizeof(int); ++i)
			swap(k, loc(k, consonants[i]), halfIndices[i]);
	}
	
	k->fitness = 0;
	k->distance = 0;
	k->inRoll = 0;
	k->outRoll = 0;
	k->sameHand = 0;
	k->sameFinger = 0;
	k->rowChange = 0;
	k->homeJump = 0;
	k->toCenter = 0;
	k->toOutside = 0;
	
	return 0;
}

int setLayout(Keyboard *k, char *layout)
{
	int i;
	char *savedLayout = layout;
	for (i = 0; i < ksize; ++i) {
		if (printable[i] && *layout == '\0') {
			fprintf(stderr, "Error: in setLayout(), layout %s does not have enough characters (%d expected, %ld found).\n", 
					savedLayout, trueksize, strlen(savedLayout));
			return -1;
		}
		if (printable[i]) k->layout[i] = *(layout++);
		else k->layout[i] = '*';
	}
	
	savedLayout = layout;
	for (i = 0; i < ksize; ++i) {
		if (printable[i] && *layout == '\0') {
			fprintf(stderr, "Error: in setLayout(), layout %s does not have enough characters (%d expected, %ld found).\n", 
					savedLayout, trueksize, strlen(savedLayout));
			return -1;
		}
		if (printable[i]) k->shiftedLayout[i] = *(layout++);
		else k->shiftedLayout[i] = '*';
	}
	
	k->layout[i] = '\0';
	k->shiftedLayout[i] = '\0';
	
	return 0;
}

/* 
 * Copies a layout from fp onto k.
 * 
 * Return Codes
 * -1: Error.
 * -2: No new layout was found in the file.
 * 0: Success.
 */
int layoutFromFile(FILE *fp, Keyboard *k)
{
	int i;
	int prevC = 0, c = 0;
	
	copy(k, &nilKeyboard);
	
	int readUntilN = FALSE, noNewKeyboard = TRUE, escaped = FALSE;
	for (i = 0; (c = getc(fp)) != EOF && i < 2 * ksize; ++i, prevC = c) {
		if (readUntilN) {
			i = -1;
			if (c == '\n') readUntilN = FALSE;
		} else if (c == '/' && prevC == '/') { // "//" comments out the rest of the line.
			noNewKeyboard = TRUE;
			copy(k, &nilKeyboard);
			readUntilN = TRUE;
			i = -1;
		} else if (!escaped && c == '\\') {
			escaped = TRUE;
			--i;
		} else if (c == '\n') { 
			if (i > 0) {
				fprintf(stderr, "Error: In layoutFromFile(), keyboard layout is not %d characters.\n", trueksize);
				copy(k, &nilKeyboard);
				return -1;
			} else i = -1;
		} else if (strchr(keysToInclude, c) == NULL) {
			fprintf(stderr, "Error: In layoutFromFile(), character '%c' (#%d) may not be used in a keyboard.\n", c, c);
			fprintf(stderr, "i = %d\n", i);
			copy(k, &nilKeyboard);
			return -1;
		} else {
			while (i < 2 * ksize && !printable[i % ksize])
				++i;
			
			if (escaped) {
				escaped = FALSE;
				char saved = c;
				c = convertEscapeChar(c);
				if (c == 0) {
					fprintf(stderr, "Error: Unknown escape character \\%c.\n", saved);
					return -1;
				} else if (strchr(keysToInclude, c) == NULL) {
					fprintf(stderr, "Error: In layoutFromFile(), escape character '%c' (#%d) may not be used in a keyboard.\n", c, c);
					fprintf(stderr, "i = %d\n", i);
					copy(k, &nilKeyboard);
					return -1;
				}
			}
						
			if (i < ksize) k->layout[i] = (char) c;
			else if (i < 2 * ksize) k->shiftedLayout[i - ksize] = (char) c;

			while (i+1 < 2 * ksize && !printable[(i+1) % ksize])
				++i;
			noNewKeyboard = FALSE;
		}
	}
	
	k->layout[ksize] = '\0';
	k->shiftedLayout[ksize] = '\0';
	while (c != EOF && c != '\n') c = fgetc(fp);
		
	if (noNewKeyboard)
		return -2;
	calcFitness(k);
	
	return 0;
}

int copy(Keyboard *k, Keyboard *original)
{
	int i;
	for (i = 0; i < ksize; ++i) {
		k->layout[i] = original->layout[i];
		k->shiftedLayout[i] = original->shiftedLayout[i];
	}
	k->fitness = original->fitness;
	k->inRoll = original->inRoll;
	k->outRoll = original->outRoll;
	k->sameHand = original->sameHand;
	k->sameFinger = original->sameFinger;
	k->rowChange = original->rowChange;
	k->homeJump = original->homeJump;
	k->toCenter = original->toCenter;
	k->toOutside = original->toOutside;
	
	return 0;
}

/* 
 * WARNING: Can perform illegal swaps.
 * 
 * Return Codes
 * 0: Success.
 * -1: loc1 or loc2 is out of bounds.
 * -2: loc1 or loc2 is over an unprintable position.
 */
int swap(Keyboard *k, int loc1, int loc2)
{
	if (loc1 < 0 || loc2 < 0 || loc1 >= 2 * ksize || loc2 >= 2 * ksize) return -1;
	if (printable[loc1 % ksize] ^ printable[loc2 % ksize]) return -2;
	
	if (keepShiftPairs || 
			(alwaysKeepShiftPairP(k->layout[loc1 % ksize]) || 
			 alwaysKeepShiftPairP(k->layout[loc2 % ksize]))) {
		return swapPair(k, loc1, loc2);
	}
	
	char *layout1;
	char *layout2;
	
	if (loc1 < ksize) layout1 = k->layout;
	else {
		layout1 = k->shiftedLayout;
		loc1 -= ksize;
	}
	
	if (loc2 < ksize) layout2 = k->layout;
	else {
		layout2 = k->shiftedLayout;
		loc2 -= ksize;
	}
	
	char temp = layout1[loc1];
	layout1[loc1] = layout2[loc2];
	layout2[loc2] = temp;
			
	return 0;
}

/* 
 * Simultaneously swaps two keys' shifted and unshifted values.
 */
int swapPair(Keyboard *k, int loc1, int loc2)
{
	if (loc1 < 0 || loc2 < 0 || loc1 >= ksize || loc2 >= ksize) return -1;
	if (printable[loc1] ^ printable[loc2]) return -2;
	
	char temp = k->layout[loc1];
	k->layout[loc1] = k->layout[loc2];
	k->layout[loc2] = temp;
	
	temp = k->shiftedLayout[loc1];
	k->shiftedLayout[loc1] = k->shiftedLayout[loc2];
	k->shiftedLayout[loc2] = temp;
	
	return 0;
}

int numberOfSameKeys(Keyboard *k, Keyboard *m)
{
	int i;
	int result;
	for (i = 0, result = 0; i < ksize; i++) if (k->layout[i] == m->layout[i]) ++result;
	return result;
}

int isEqual(Keyboard *k, Keyboard *m)
{
	int i;
	for (i = 0; i < ksize; ++i) if (k->layout[i] != m->layout[i]) return FALSE;
	if (k->fitness != m->fitness) return FALSE;
	if (k->inRoll != m->inRoll) return FALSE;
	if (k->outRoll != m->outRoll) return FALSE;
	if (k->sameHand != m->sameHand) return FALSE;
	if (k->sameFinger != m->sameFinger) return FALSE;
	if (k->rowChange != m->rowChange) return FALSE;
	if (k->homeJump != m->homeJump) return FALSE;
	if (k->toCenter != m->toCenter) return FALSE;
	if (k->toOutside != m->toOutside) return FALSE;
	
	return TRUE;
}

int qwertyPositions(Keyboard *k)
{
	NOT_WORK_WITH_full_keyboard("qwertyPositions()");
	
	int count = 0;
	
	int i;
	for (i = 0; i < ksize; ++i)
		if (k->layout[i] == qwerty[i])
			count++;
	
	return count;
}

int printLayoutOnly(Keyboard *k)
{
	printLayoutRaw(k->shiftedLayout);
	printLayoutRaw(k->layout);
	return 0;
}

int printLayoutRaw(char layout[])
{
	int i;
	
	char str[10];
	
	for (i = 0; i < ksize; ++i) {
		charToPrintable(str, layout[i], TRUE);
		
		if (fullKeyboard == FK_KINESIS) {
			if (printable[i]) {
				if (i % 12 == 11) printf("%s\n", str);
				else if (i % 12 == 5) printf("%s  ", str);
				else printf("%s ", str);
			} else {
				if (i % 12 == 11) printf(" \n");
				else if (i % 12 == 5) printf("    ");
				else printf("   ");
			}
		} else if (fullKeyboard == FK_STANDARD || fullKeyboard == FK_BS4822) {
			if (printable[i] == FALSE) {
				if (i % 14 == 13) printf("   \n");
				else printf("   ");
			} else if (i % 14 == 13) printf("%s\n", str);
			else if (i % 14 == 5) printf("%s  ", str);
			else printf("%s ", str);
		} else {
			if (printable[i] == FALSE) {
				if (i % 10 == 9) printf("  \n");
				else printf("   ");
			} else if (i % 10 == 9) printf("%s\n", str);
			else if (i % 10 == 4) printf("%s  ", str);
			else printf("%s ", str);
		}
	}
	printf("\n");
	return 0;
}

int printKeyboard(Keyboard *k)
{
	printLayoutOnly(k);

	printf("Fitness: %lld\n", k->fitness);
	if (keepQWERTY) printf("QWERTY positions: %d\n", qwertyPositions(k));
	printf("Distance: %lld\n", k->distance);
	printf("Finger work: %lld\n", k->fingerWork);
	printf("Inward rolls: %lld\n", k->inRoll);
	printf("Outward rolls: %lld\n", k->outRoll);
	printf("Same hand: %lld\n", k->sameHand);
	printf("Same finger: %lld\n", k->sameFinger);
	printf("Row change: %lld\n", k->rowChange);
	printf("Home jump: %lld\n", k->homeJump);
	printf("Ring jump: %lld\n", k->ringJump);
	printf("To center: %lld\n", k->toCenter);
	if (ksize != 30) printf("To outside: %lld\n", k->toOutside);
	printf("\n");
	
	return 0;
}

int printPercentages(Keyboard *k)
{
	int i;
	
	int64_t total = 0;
	for (i = 0; i < FINGER_COUNT; ++i) total += k->fingerUsage[i];

	// Hand
	printf("\nHands: ");
	printf("%lld%% ", 100 * (k->fingerUsage[0] + k->fingerUsage[1] + 
			k->fingerUsage[2] + k->fingerUsage[3] + k->fingerUsage[4]) / total);
	printf("%lld%%\n", 100 * (k->fingerUsage[5] + 
			k->fingerUsage[6] + k->fingerUsage[7] + k->fingerUsage[8]
			 + k->fingerUsage[9]) / total);

	if (total == 0) printf("warning: total = 0\n");
	// Finger
	printf("Fingers: ");
	for (i = 0; i < FINGER_COUNT; ++i) {
		double usage = lround(100.0 * k->fingerUsage[i] / total);
		if (usage < 1) printf("%.2f%% ", usage);
		else if (usage < 10) printf("%.1f%% ", usage);
		else printf("%.0f%% ", usage);
	}
	printf("\n\n");
	
	// Print the keyboard layout.
	printLayoutOnly(k);
		
	// Print all the fitness criteria.
	printf("Fitness:       %lld\n",   k->fitness);
	if (keepQWERTY) printf("QWERTY positions: %d\n", qwertyPositions(k));
	printf("Distance:      %lld\n",   (        (    k->distance  )           ));
	printf("Finger work:   %lld\n",   (        (    k->fingerWork)           ));
	printf("Inward rolls:  %.2f%%\n", ((double)(100*k->inRoll    ) / totalDi ));
	printf("Outward rolls: %.2f%%\n", ((double)(100*k->outRoll   ) / totalDi ));
	printf("Same hand:     %.2f%%\n", ((double)(100*k->sameHand  ) / totalDi ));
	printf("Same finger:   %.2f%%\n", ((double)(100*k->sameFinger) / totalDi ));
	printf("Row change:    %.2f%%\n", ((double)(100*k->rowChange ) / totalDi ));
	printf("Home jump:     %.2f%%\n", ((double)(100*k->homeJump  ) / totalDi ));
	printf("Ring jump:     %.2f%%\n", ((double)(100*k->ringJump  ) / totalDi ));
	printf("To center:     %.2f%%\n", ((double)(100*k->toCenter  ) / totalDi ));
	if (ksize != 30) printf("To outside:    %.2f%%\n", ((double)(100*k->toOutside) / totalDi ));
	printf("\n");

	return 0;
}

int simplePrintKeyboard(Keyboard *k)
{
	printLayoutOnly(k);
		
	printf("\n");
	printf("Fitness: %lld\n", (int64_t) (k->fitness / pow(10, SIMPLE_SHIFT)));
	printf("Distance: %lld\n", (int64_t) (k->distance / pow(10, SIMPLE_SHIFT)));
	printf("Inward rolls: %lld\n", (int64_t) (k->inRoll / pow(10, SIMPLE_SHIFT)));
	printf("Outward rolls: %lld\n", (int64_t) (k->outRoll / pow(10, SIMPLE_SHIFT)));
	printf("Same hand: %lld\n", (int64_t) (k->sameHand / pow(10, SIMPLE_SHIFT)));
	printf("Same finger: %lld\n", (int64_t) (k->sameFinger / pow(10, SIMPLE_SHIFT)));
	printf("Row change: %lld\n", (int64_t) (k->rowChange / pow(10, SIMPLE_SHIFT)));
	printf("Home jump: %lld\n", (int64_t) (k->homeJump / pow(10, SIMPLE_SHIFT)));
	printf("To center: %lld\n", (int64_t) (k->toCenter / pow(10, SIMPLE_SHIFT)));
	if (ksize != 30) printf("To outside: %lld\n", (int64_t) (k->toOutside / pow(10, SIMPLE_SHIFT)));
	printf("\n");
	
	return 0;
}

/* Assumes buffer is at least 3 characters. 
 * 
 * Converts ' ' to "SP" if changeSpace is true.
 */
int charToPrintable(char *buffer, char c, int changeSpace)
{
	if (c == '\n') sprintf(buffer, "\\n");
	else if (c == '\t') sprintf(buffer, "\\t");
	else if (c == ASCII_SHIFT) sprintf(buffer, "\\s");
	else if (c == '\b') sprintf(buffer, "\\b");
	else if (changeSpace && c == ' ') sprintf(buffer, "SP");
	else sprintf(buffer, "%2c", c);

	return 0;
}

int isSwappable(char c)
{
	return !(keepNumbers && c >= '0' && c <= '9');
}

int isLegalSwap(Keyboard *k, int i, int j)
{
	if (i < 0 || j < 0 || i >= 2 * ksize || j >= 2 * ksize)
		return FALSE;
	
	if (!printable[i % ksize] || !printable[j % ksize])
		return FALSE;
	
	if ((i >= ksize && (keepShiftPairs || alwaysKeepShiftPairP(k->shiftedLayout[i % ksize]))) || 
			(j >= ksize && (keepShiftPairs || alwaysKeepShiftPairP(k->shiftedLayout[j % ksize])))) {
		return FALSE;
	}
	
	if (keepNumbers == 1 && (isdigit(charAt(k, i)) || isdigit(charAt(k, j)))) {
		return FALSE;
	} else if (keepNumbers == 2 && (isdigit(charAt(k, i)) ^ isdigit(charAt(k, j)))) {
		return FALSE;
	}
	
	if (keepTab && (charAt(k, i) == '\t' || charAt(k, j) == '\t'))
		return FALSE;
		
	i %= ksize;
	j %= ksize;
	
	if (fullKeyboard == FK_NO) {
		return legalBox[i] == legalBox[j];
	} else if (fullKeyboard == FK_STANDARD || fullKeyboard == FK_BS4822) {
		if (keepConsonantsRight) return bigLegalBoxConsonants[i] == bigLegalBoxConsonants[j];
		else return bigLegalBox[i] == bigLegalBox[j];
	} else if (fullKeyboard == FK_KINESIS) {
		return kinesisLegalBox[i] == kinesisLegalBox[j];
	}

	return TRUE;
}

void shuffleIndices()
{
	int temp, k, n = 2 * trueksize;

	while (n > 1) {
		k = rand() % n;
		n--;

		temp = indices[n];
		indices[n] = indices[k];
		indices[k] = temp;
	}
}

void shuffleLayout(Keyboard *k)
{
	/* Shuffle the layout where shifted and unshifted characters are bound 
	 * together.
	 */
	int x, n = 2 * ksize;
	int i, legalSwapExists;
	while (n > 1) 
	{
		--n;
		while (!printable[n]) --n;
				
		legalSwapExists = FALSE;
		for (i = 0; i < n; ++i)
			if (isLegalSwap(k, i, n)) {
				legalSwapExists = TRUE;
				break;
			}
		
		if (legalSwapExists) {
			do {
				x = rand() % (n + 1);
			} while (!isLegalSwap(k, x, n));
		}
		
		swap(k, x, n);
	}
}

int loc(Keyboard *k, char c)
{
	int i;
	for (i = 0; i < ksize; ++i) {
		if (k->layout[i] == c || k->shiftedLayout[i] == c)
			return i;
	}
	
	return -1;
}

/* Guaranteed to check unshifted first, so if a character is the same on both 
 * shifted and unshifted layouts, it will return unshifted first.
 */
int locWithShifted(Keyboard *k, char c)
{
	int i;
	for (i = 0; i < ksize; ++i) {
		if (k->layout[i] == c) {
			return i;
		} else if (k->shiftedLayout[i] == c) {
			 return i + ksize;
		}
	}
	
	return -1;	
}

