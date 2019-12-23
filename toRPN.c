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

		//Jeœli symbol jest liczb¹ dodaj go do kolejki wyjœcie.
		if (isNumber(expressionArray[index])) {
			output = appendToArray(output, expressionArray[index], &outputSize);
			continue;
		}

		//Jeœli symbol jest funkcj¹ w³ó¿ go na stos.
		if (getFunction(expressionArray[index]) >= 0) {
			stack = appendToArray(stack, expressionArray[index], &outputSize);
			continue;
		}
		
		//Jeœli symbol jest znakiem oddzielaj¹cym argumenty funkcji (przecinek):
		if (getOperator(expressionArray[index]) == 8) {
			/*Dopóki najwy¿szy element stosu nie jest lewym nawiasem,
			zdejmij element ze stosu i dodaj go do kolejki wyjœcie.
			Jeœli lewy nawias nie zosta³ napotkany oznacza to, ¿e znaki
			oddzielaj¹ce zosta³y postawione w z³ym miejscu lub 
			nawiasy s¹ Ÿle umieszczone.*/
			
			for (int i = stackSize - 1;i >= 0;i--) {
				if (stack != NULL && stack[i] != NULL && getOperator(stack[i]) != 6) {
					output = appendToArray(output, stack[i], &outputSize);
					stack = popArray(stack, &stackSize, false);
				}
			}
			continue;
		}
		
		//Je¿eli symbol jest lewym nawiasem to w³ó¿ go na stos.
		if (getOperator(expressionArray[index]) == 6) {
			stack = appendToArray(stack, expressionArray[index], &stackSize);
			continue;
		}

		/*
		Je¿eli symbol jest prawym nawiasem to zdejmuj operatory ze stosu
		i dok³adaj je do kolejki wyjœcie, dopóki symbol na górze stosu nie jest
		lewym nawiasem, kiedy dojdziesz do tego miejsca zdejmij lewy nawias ze 
		stosu bez dok³adania go do kolejki wyjœcie. 
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
			Teraz, jeœli najwy¿szy 	element na stosie jest funkcj¹,
			tak¿e do³ó¿ go do kolejki wyjœcie. Jeœli stos zostanie opró¿niony 
			i nie napotkasz lewego nawiasu, oznacza to, ¿e nawiasy zosta³y Ÿle umieszczone.
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
		Jeœli symbol jest operatorem, o1, wtedy:
			1) dopóki na górze stosu znajduje siê operator, o2 taki, ¿e:
				o1 jest lewostronnie ³¹czny i jego kolejnoœæ wykonywania jest
				mniejsza lub równa kolejnoœci wyk. o2,
				lub
				o1 jest prawostronnie ³¹czny i jego kolejnoœæ wykonywania jest
				mniejsza od o2, zdejmij o2 ze stosu i do³ó¿ go do kolejki wyjœciowej
				i wykonaj jeszcze raz 1)
			2) w³ó¿ o1 na stos operatorów.
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


				//lewostronnie ³¹czny
				if (getOperatorTie(o1) == 0) {
					if (getOperatorPriority(o1) <= getOperatorPriority(o2)) {
						output = appendToArray(output, stack[i], &outputSize);
						stack = popArray(stack, &stackSize, false);
					}
				}

				//prawostronnie ³¹czny
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
	Jeœli nie ma wiêcej symboli do przeczytania, zdejmuj wszystkie symbole
	ze stosu (jeœli jakieœ s¹) i dodawaj je do kolejki wyjœcia. 
	(Powinny to byæ wy³¹cznie operatory, jeœli natrafisz na jakiœ nawias
	oznacza to, ¿e nawiasy zosta³y Ÿle umieszczone.)
	*/

	for (int i = stackSize - 1;i >= 0;i--){
		output = appendToArray(output, stack[i], &outputSize);
		free(stack[i]);
	}


	free(stack);

	*length = outputSize;

	return output;
}