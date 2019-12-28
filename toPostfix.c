#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <string.h>

/* Convert infix to postfix */
char** toPostfix(char** array, size_t* sizeOfArray) {
	
	//Output Queue
	char** output = 0;
	size_t sizeOfOutput = 0;

	//Stack for operators
	char** stack = 0;
	size_t sizeOfStack = 0;
	
	objectType typeOfValue = 0;
	objectType typeOfStackValue = 0;

	for (size_t index = 0;index < *sizeOfArray;index++) {

		typeOfValue = getObjectType(array[index]);

		//If value is a number
		if (typeOfValue == number) {
			output = appendToArray(output, array[index], &sizeOfOutput, tString);
			continue;
		}

		//Je¿eli symbol jest lewym nawiasem to w³ó¿ go na stos.
		if (typeOfValue == leftBracket) {
			stack = appendToArray(stack, array[index], &sizeOfStack, tString);
			continue;
		}

		//Jeœli symbol jest funkcj¹ w³ó¿ go na stos.
		if (isFunction(typeOfValue)) {
			stack = appendToArray(stack, array[index], &sizeOfStack, tString);
			continue;
		}
		
		//Jeœli symbol jest znakiem oddzielaj¹cym argumenty funkcji (przecinek):
		if (typeOfValue == comma) {
			/*Dopóki najwy¿szy element stosu nie jest lewym nawiasem,
			zdejmij element ze stosu i dodaj go do kolejki wyjœcie.
			Jeœli lewy nawias nie zosta³ napotkany oznacza to, ¿e znaki
			oddzielaj¹ce zosta³y postawione w z³ym miejscu lub 
			nawiasy s¹ Ÿle umieszczone.*/

			/*for (int i = sizeOfStack - 1;i >= 0;i--) {
				if (stack != NULL && stack[i] != NULL && getObjectType(stack[i]) != leftBracket) {
					output = appendToArray(output, stack[i], &sizeOfOutput, tString);
					stack = popArray(stack, &sizeOfStack, false, tString);
				}
			}*/
			continue;
		}

		/*
		Je¿eli symbol jest prawym nawiasem to zdejmuj operatory ze stosu
		i dok³adaj je do kolejki wyjœcie, dopóki symbol na górze stosu nie jest
		lewym nawiasem, kiedy dojdziesz do tego miejsca zdejmij lewy nawias ze 
		stosu bez dok³adania go do kolejki wyjœcie. 
		*/
		if (typeOfValue == rightBracket) {
			for (int i = sizeOfStack - 1;i >= 0;i--) {
				if (stack != NULL && stack[i] != NULL) {
					//usun nawias ze stosu 
					if (getObjectType(stack[i]) == leftBracket) {
						stack = popArray(stack, &sizeOfStack, true,tString);
						continue;
					} else {
						output = appendToArray(output, stack[i], &sizeOfOutput,tString);
						stack = popArray(stack, &sizeOfStack, false,tString);
					}
				} else {
					break;
				}
			}
			continue;
			/*
			Teraz, jeœli najwy¿szy 	element na stosie jest funkcj¹,
			tak¿e do³ó¿ go do kolejki wyjœcie. Jeœli stos zostanie opró¿niony 
			i nie napotkasz lewego nawiasu, oznacza to, ¿e nawiasy zosta³y Ÿle umieszczone.
			*/
			for (int i = sizeOfStack - 1;i >= 0;i--) {
				if (stack != NULL && stack[i] != NULL) {;
					if (getObjectType(stack[i]) == leftBracket) {
						stack = popArray(stack, &sizeOfStack, true, tString);
						continue;
					}
					if (isFunction(getObjectType(stack[i]))) {
						output = appendToArray(output, stack[i], &sizeOfOutput, tString);
						stack = popArray(stack, &sizeOfStack, false, tString);
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
		if (typeOfValue != number && !isFunction(typeOfValue) && typeOfValue != undefined) {
			//stos pusty 
			if (sizeOfStack == 0) {
				stack = appendToArray(stack, array[index], &sizeOfStack, tString);
				continue;
			}
			
			typeOfStackValue = getObjectType(stack[sizeOfStack - 1]);
			
			//priorytet o1, jest wieszy od priorytetu o2
			if (getOperatorPriority(typeOfValue) > getOperatorPriority(typeOfStackValue)) {
				stack = appendToArray(stack, array[index], &sizeOfStack, tString);
				continue;
			}


			//wiekszy lub rowny priorytet na stosie
			for (int i = sizeOfStack - 1;i >= 0;i--) {
				//usun nawias jesli jest na stosie
				typeOfStackValue = getObjectType(stack[i]);
				if (getObjectType == leftBracket) {
					stack = popArray(stack, &sizeOfStack, true, tString);
					continue;
				}


				//lewostronnie ³¹czny
				if (getOperatorTie(typeOfValue) == 0) {
					if (getOperatorPriority(typeOfValue) <= getOperatorPriority(typeOfStackValue)) {
						output = appendToArray(output, stack[i], &sizeOfOutput, tString);
						stack = popArray(stack, &sizeOfStack, false, tString);
					}
				}

				//prawostronnie ³¹czny
				if (getOperatorTie(typeOfValue) == 1) {
					if (getOperatorPriority(typeOfValue) < getOperatorPriority(typeOfStackValue)) {
						output = appendToArray(output, stack[i], &sizeOfOutput, tString);
						stack = popArray(stack, &sizeOfStack, false, tString);
					}
				}

			}
			stack = appendToArray(stack, array[index], &sizeOfStack, tString);
			continue;
		}
		//end of loop 
	}

	/*
	Jeœli nie ma wiêcej symboli do przeczytania, zdejmuj wszystkie symbole
	ze stosu (jeœli jakieœ s¹) i dodawaj je do kolejki wyjœcia. 
	(Powinny to byæ wy³¹cznie operatory, jeœli natrafisz na jakiœ nawias
	oznacza to, ¿e nawiasy zosta³y Ÿle umieszczone.)
	*/

	for (int i = sizeOfStack - 1;i >= 0;i--){
		output = appendToArray(output, stack[i], &sizeOfOutput, tString);
		free(stack[i]);
	}

	*sizeOfArray = sizeOfOutput;

	return output;
}