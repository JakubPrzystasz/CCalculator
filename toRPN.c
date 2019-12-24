#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <string.h>

/* Convert infix to postfix */
char** toRPN(char** array, size_t* sizeOfArray) {
	
	//Output Queue
	char** output = 0;
	size_t sizeOfOutput = 0;

	//Stack for operators
	char** stack = 0;
	size_t sizeOfStack = 0;
	
	expType token = 0;
	expType stackToken = 0;

	for (size_t index = 0;index < *sizeOfArray;index++) {

		token = getExpType(array[index]);

		//If token is a number
		if (token == number) {
			output = appendToArray(output, array[index], &sizeOfOutput);
			continue;
		}

		//Je�li symbol jest funkcj� w�� go na stos.
		if (token == function) {
			stack = appendToArray(stack, array[index], &sizeOfStack);
			continue;
		}
		
		//Je�li symbol jest znakiem oddzielaj�cym argumenty funkcji (przecinek):
		if (token == comma) {
			/*Dop�ki najwy�szy element stosu nie jest lewym nawiasem,
			zdejmij element ze stosu i dodaj go do kolejki wyj�cie.
			Je�li lewy nawias nie zosta� napotkany oznacza to, �e znaki
			oddzielaj�ce zosta�y postawione w z�ym miejscu lub 
			nawiasy s� �le umieszczone.*/
			
			for (int i = sizeOfStack - 1;i >= 0;i--) {
				if (stack != NULL && stack[i] != NULL && getExpType(stack[i]) != leftBracket) {
					output = appendToArray(output, stack[i], &sizeOfOutput);
					stack = popArray(stack, &sizeOfStack, false);
				}
			}
			continue;
		}
		
		//Je�eli symbol jest lewym nawiasem to w�� go na stos.
		if (token == leftBracket) {
			stack = appendToArray(stack, array[index], &sizeOfStack);
			continue;
		}

		/*
		Je�eli symbol jest prawym nawiasem to zdejmuj operatory ze stosu
		i dok�adaj je do kolejki wyj�cie, dop�ki symbol na g�rze stosu nie jest
		lewym nawiasem, kiedy dojdziesz do tego miejsca zdejmij lewy nawias ze 
		stosu bez dok�adania go do kolejki wyj�cie. 
		*/
		if (token == rightBracket) {
			for (int i = sizeOfStack - 1;i >= 0;i--) {
				if (stack != NULL && stack[i] != NULL) {
					//usun nawias ze stosu 
					if (getExpType(stack[i]) == leftBracket) {
						stack = popArray(stack, &sizeOfStack, true);
						continue;
					} else {
						output = appendToArray(output, stack[i], &sizeOfOutput);
						stack = popArray(stack, &sizeOfStack, false);
					}
				} else {
					break;
				}
			}
			/*
			Teraz, je�li najwy�szy 	element na stosie jest funkcj�,
			tak�e do�� go do kolejki wyj�cie. Je�li stos zostanie opr�niony 
			i nie napotkasz lewego nawiasu, oznacza to, �e nawiasy zosta�y �le umieszczone.
			*/
			for (int i = sizeOfStack - 1;i >= 0;i--) {
				if (stack != NULL && stack[i] != NULL) {;
					if (getExpType(stack[i]) == leftBracket) {
						stack = popArray(stack, &sizeOfStack, true);
						continue;
					}
					if (getExpType(stack[i]) == function) {
						output = appendToArray(output, stack[i], &sizeOfOutput);
						stack = popArray(stack, &sizeOfStack, false);
					}
				}
			}
			continue;
		}

		/*
		Je�li symbol jest operatorem, o1, wtedy:
			1) dop�ki na g�rze stosu znajduje si� operator, o2 taki, �e:
				o1 jest lewostronnie ��czny i jego kolejno�� wykonywania jest
				mniejsza lub r�wna kolejno�ci wyk. o2,
				lub
				o1 jest prawostronnie ��czny i jego kolejno�� wykonywania jest
				mniejsza od o2, zdejmij o2 ze stosu i do�� go do kolejki wyj�ciowej
				i wykonaj jeszcze raz 1)
			2) w�� o1 na stos operator�w.
		*/
		if (token != number && token != function && token != undefined) {
			//stos pusty 
			if (sizeOfStack == 0) {
				stack = appendToArray(stack, array[index], &sizeOfStack);
				continue;
			}
			
			stackToken = getExpType(stack[sizeOfStack - 1]);
			
			//priorytet o1, jest wieszy od priorytetu o2
			if (getOperatorPriority(token) > getOperatorPriority(stackToken)) {
				stack = appendToArray(stack, array[index], &sizeOfStack);
				continue;
			}


			//wiekszy lub rowny priorytet na stosie
			for (int i = sizeOfStack - 1;i >= 0;i--) {
				//usun nawias jesli jest na stosie
				stackToken = getExpType(stack[i]);
				if (getExpType == leftBracket) {
					stack = popArray(stack, &sizeOfStack, true);
					continue;
				}


				//lewostronnie ��czny
				if (getOperatorTie(token) == 0) {
					if (getOperatorPriority(token) <= getOperatorPriority(stackToken)) {
						output = appendToArray(output, stack[i], &sizeOfOutput);
						stack = popArray(stack, &sizeOfStack, false);
					}
				}

				//prawostronnie ��czny
				if (getOperatorTie(token) == 1) {
					if (getOperatorPriority(token) < getOperatorPriority(stackToken)) {
						output = appendToArray(output, stack[i], &sizeOfOutput);
						stack = popArray(stack, &sizeOfStack, false);
					}
				}

			}

			stack = appendToArray(stack, array[index], &sizeOfStack);
		}

		//end of loop 
	}

	/*
	Je�li nie ma wi�cej symboli do przeczytania, zdejmuj wszystkie symbole
	ze stosu (je�li jakie� s�) i dodawaj je do kolejki wyj�cia. 
	(Powinny to by� wy��cznie operatory, je�li natrafisz na jaki� nawias
	oznacza to, �e nawiasy zosta�y �le umieszczone.)
	*/

	for (int i = sizeOfStack - 1;i >= 0;i--){
		output = appendToArray(output, stack[i], &sizeOfOutput);
		free(stack[i]);
	}

	*sizeOfArray = sizeOfOutput;

	return output;
}