#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <string.h>

/* CONVERT INFIX EXPRESSION TO POSTFIX EXPRESSION */
char** toRPN(char** expressionArray, int* length) {
	//output queue
	char** output = 0;

	//stack
	char** stack = 0;

	int outputSize = 0, stackSize = 0, o1 = -1, o2 = -1;

	for (int index = 0;index < *length;index++) {

		//Je�li symbol jest liczb� dodaj go do kolejki wyj�cie.
		if (isNumber(expressionArray[index])) {
			output = appendToArray(output, expressionArray[index], &outputSize);
			continue;
		}

		//Je�li symbol jest funkcj� w�� go na stos.
		if (getFunction(expressionArray[index]) >= 0) {
			stack = appendToArray(stack, expressionArray[index], &outputSize);
			continue;
		}
		
		//Je�li symbol jest znakiem oddzielaj�cym argumenty funkcji (przecinek):
		if (getOperator(expressionArray[index]) == 8) {
			/*Dop�ki najwy�szy element stosu nie jest lewym nawiasem,
			zdejmij element ze stosu i dodaj go do kolejki wyj�cie.
			Je�li lewy nawias nie zosta� napotkany oznacza to, �e znaki
			oddzielaj�ce zosta�y postawione w z�ym miejscu lub 
			nawiasy s� �le umieszczone.*/
			
			for (int i = stackSize - 1;i >= 0;i--) {
				if (stack != NULL && stack[i] != NULL && getOperator(stack[i]) != 6) {
					output = appendToArray(output, stack[i], &outputSize);
					stack = popArray(stack, &stackSize, false);
				}
			}
			continue;
		}
		
		//Je�eli symbol jest lewym nawiasem to w�� go na stos.
		if (getOperator(expressionArray[index]) == 6) {
			stack = appendToArray(stack, expressionArray[index], &stackSize);
			continue;
		}

		/*
		Je�eli symbol jest prawym nawiasem to zdejmuj operatory ze stosu
		i dok�adaj je do kolejki wyj�cie, dop�ki symbol na g�rze stosu nie jest
		lewym nawiasem, kiedy dojdziesz do tego miejsca zdejmij lewy nawias ze 
		stosu bez dok�adania go do kolejki wyj�cie. 
		*/
		if (getOperator(expressionArray[index]) == 7) {
			for (int i = stackSize - 1;i >= 0;i--) {
				if (stack != NULL && stack[i] != NULL) {
					//usun nawias ze stosu 
					if (getOperator(stack[i]) == 6) {
						stack = popArray(stack, &stackSize, true);
						continue;
					} else {
						output = appendToArray(output, stack[i], &outputSize);
						stack = popArray(stack, &stackSize, false);
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
			for (int i = stackSize - 1;i >= 0;i--) {
				if (stack != NULL && stack[i] != NULL) {;
					if (getOperator(stack[i]) == 6) {
						stack = popArray(stack, &stackSize, true);
						continue;
					}
					if (getFunction(stack[i]) >= 0) {
						output = appendToArray(output, stack[i], &outputSize);
						stack = popArray(stack, &stackSize, false);
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
		if (getOperator(expressionArray[index]) >= 0 && 5 >= getOperator(expressionArray[index])) {
			//stos pusty 
			if (stackSize == 0) {
				stack = appendToArray(stack, expressionArray[index], &stackSize);
				continue;
			}
			
			o1 = getOperator(expressionArray[index]);
			o2 = getOperator(stack[stackSize - 1]);
			
			//priorytet o1, jest wieszy od priorytetu o2
			if (getOperatorPriority(o1) > getOperatorPriority(o2)) {
				stack = appendToArray(stack, expressionArray[index], &stackSize);
				continue;
			}


			//wiekszy lub rowny priorytet na stosie
			for (int i = stackSize - 1;i >= 0;i--) {
				//usun nawias jesli jest na stosie
				o2 = getOperator(stack[i]);
				if (o2 == 6) {
					stack = popArray(stack, &stackSize, true);
					continue;
				}


				//lewostronnie ��czny
				if (getOperatorTie(o1) == 0) {
					if (getOperatorPriority(o1) <= getOperatorPriority(o2)) {
						output = appendToArray(output, stack[i], &outputSize);
						stack = popArray(stack, &stackSize, false);
					}
				}

				//prawostronnie ��czny
				if (getOperatorTie(o1) == 1) {
					if (getOperatorPriority(o1) < getOperatorPriority(o2)) {
						output = appendToArray(output, stack[i], &outputSize);
						stack = popArray(stack, &stackSize, false);
					}
				}

			}

			stack = appendToArray(stack, expressionArray[index], &stackSize);
		}

		//end of loop 
	}

	/*
	Je�li nie ma wi�cej symboli do przeczytania, zdejmuj wszystkie symbole
	ze stosu (je�li jakie� s�) i dodawaj je do kolejki wyj�cia. 
	(Powinny to by� wy��cznie operatory, je�li natrafisz na jaki� nawias
	oznacza to, �e nawiasy zosta�y �le umieszczone.)
	*/

	for (int i = stackSize - 1;i >= 0;i--){
		output = appendToArray(output, stack[i], &outputSize);
		free(stack[i]);
	}


	free(stack);

	*length = outputSize;

	return output;
}