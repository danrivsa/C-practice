/***********LIBRERIA LISTAS*************/

#pragma region STRUCTURE

struct lista
{

	int valor;
	lista *prox;

};

#pragma endregion

#pragma region EJERCICOS EN UNA LISTA

/************EJERCICIOS BASADOS EN LISTAS SIMPLEMENTE ENLAZADAS****************/

#pragma region FUNCIONES BASICAS

/*IMPRIMIR LISTA*/
void printList(lista *cab)
{
	
	lista *runner = cab;
	while (runner)
	{

		printf("[%i]->", runner->valor);
		runner = runner->prox;

	}

	printf("NULL\n\n");

}

/*ELIMINAR UN NUMERO*/
void deleteElement(lista **cab, int number)
{

	lista *auxD = NULL, *runner = *cab, *prev = NULL;

	while (runner && runner->prox && (runner->valor != number))
	{

		prev = runner;
		runner = runner->prox;

	}

	//CASES
	if (!prev) //Number to delete is in head of the list
	{

		auxD = *cab;
		*cab = (*cab)->prox;
		delete auxD;

	}
	else if (!runner) //it wasn't found
	{

		system("cls");
		printf("El valor no fue encontrado\n\n");

	}
	else //found the number somewhere in the middle 
	{

		auxD = runner;
		prev->prox = runner->prox;
		delete auxD;

	}
}

/*EXISTENCIA DE UN NUMERO*/
bool exists(lista *cab, int num)
{
	lista *aux = cab;

	while (aux && aux->valor != num)
	{

		aux = aux->prox;

	}

	if (aux)
	{

		return 1;

	}
	else
	{

		return 0;

	}
}

/*NUMERO DE REPETICIONES*/
int repetitionOfElement(lista *cab, int number)
{

	lista *aux = cab;
	int repAmount = 0;

	if (exists(cab, number))
	{

		while (aux)
		{

			if (aux->valor == number)
			{

				repAmount++;

			}

		}

		return repAmount;

	}
	else
	{
		{

			return 0;

		}
	}

}

/*CAMBIO DE NUMEROS*/
void swap(int *A, int *B)
{

	int C = *A;
	*A = *B;
	*B = C;
	

}

/*CANTIDAD DE DIGITOS DE UN NUMERO*/
int digitsSizeOfNumer(int n)
{

	int cont = 0;
	while (n > 0)
	{

		n /= 10;
		cont++;

	}

	return cont;

}

#pragma endregion

#pragma region TAREAS LAB

#pragma region METODOS DE ORDENAMIENTO

/*ORDENAR POR INTERCAMBIO*/
void ordenarIntercambio(lista **cab)
{

	lista *t = *cab, *q;

	while (t && t->prox)
	{

		q = t->prox;

		while (q)
		{

			if (t->valor > q->valor)
			{

				swap(&t->valor, &q->valor);

			}

			q = q->prox;

		}

		t = t->prox;
	}

}

#pragma endregion

#pragma region SUMA DE DIGITOS Y NUMERO VOLTEADO

/*NUMERO VOLTEADO*/
int getReverseNum(int n)
{

	int revertedN = 0, digit = 0;

	while (n > 0)
	{

		digit = n % 10;
		n /= 10;
		revertedN = (revertedN * 10) + digit;

	}

	return revertedN;

}

/*SUMA DE DIGITOS DE UN NUMERO*/
int SumOfDigits(int n)
{

	int sum = 0, digit = 0;

	while (n > 0)
	{

		digit = n % 10;
		n /= 10;
		sum += digit;

	}

	return sum;

}

/*CAMBIA LOS NUMEROS DE LA LISTA POR LA SUMA DE SUS DIGITOS E IMPRIME EL NUMERO VOLTEADO*/
void modifyList(lista **cab)
{

	lista *t = *cab;


	while (t)
	{

		int digitsTotalSum = SumOfDigits(t->valor);
		printf("Numero de la casilla [%i] fue volteado: [%i]\n", t->valor, getReverseNum(t->valor));
		t->valor = digitsTotalSum;

		t = t->prox;

	}

	printList(*cab);

}

#pragma endregion

#pragma region TIPOS DE INSERCIONES

/*insercion por cabeza*/
void insertNodeByHead(lista **cab, int numero)
{

	lista *aux = new lista;
	aux->valor = numero;
	aux->prox = *cab;
	*cab = aux;

}

/*POR FINAL DE LISTA*/
void finalInsertion(lista **cab, int x)
{

	if (!(*cab))
		insertNodeByHead(cab, x);
	else
	{

		lista *runner = *cab;
		while (runner->prox)
			runner = runner->prox;
		lista *aux = new lista;
		aux->valor = x;
		aux->prox = runner->prox;
		runner->prox = aux;

	}

}

/*Despues de un valor y version 1*/
void middleInsertion(lista **cab, int numberY, int numberX)
{

	lista *t = *cab, *prev = NULL;

	while (t && t->valor != numberY)
	{

		prev = t;
		t = t->prox;

	}

	if (!prev)
	{

		//cabeza
		lista *aux = new lista;
		aux->valor = numberX;
		aux->prox = (*cab)->prox;
		(*cab)->prox = aux;


	}
	else
	{

		//caso comun
		lista *aux = new lista;
		aux->valor = numberX;
		aux->prox = t->prox;
		t->prox = aux;

	}

}

/*DESPUES DE UN VALOR Y VERSION 2*/
void middleInsertion2(lista **cab, int y, int x)
{

	if (!(*cab))
		insertNodeByHead(cab, x);
	else
	{

		lista *t = *cab;

		while (t && t->prox && t->valor != y)
			t = t->prox;

		lista *aux = new lista;//crea casilla
		aux->valor = x;

		aux->prox = t->prox;//enlaza (OJO incluso enlaza null de uno con el null de otro )
		t->prox = aux;

		/*si esta en la ultima casilla el aux->prox  = t->prox me enlaza el nulo de aux con el de t porque ambos valen nulo hasta que
		toma en cuenta esa linea*/

	}

}

/*INSERTAR ORDENADAMENTE (ORDENA LA LISTA SI ESTO NO SE ENCUENTRA ORDENADA)*/
void organizeInsertion(lista **cab, int x)
{

	insertNodeByHead(cab, x);
	ordenarIntercambio(cab);

}

#pragma endregion

#pragma region ELIMINACIONES

#pragma region FUNCIONES SECUNDARIAS PARA ELIMINACIONES

/*NUMERO DE VECES QUE SE REPITE UN NUMERO EN LA LISTA*/
int amountOfInstances(lista *cab, int x)
{
	int cont = 0;

	if (!cab)
		return 0;
	else
	{

		lista *t = cab;
		while (t)
		{

			if (t->valor == x)
				cont++;
			t = t->prox;

		}
		return cont;
	}

}

/*Ver si un numero es multiplo de un n dado*/
bool isM(int x,int n)
{

	if ((x % n) == 0) return true;
	else return false;


}

#pragma endregion

/*ELIMINAR LA PRIMERA VEZ QUE CONSIGA EL NUMERO*/
void deleteFirstInstance(lista **cab, int x)
{

	if (!(*cab))
		return;
	else
	{

		lista *t = *cab, *auxD, *prev = NULL;

		while (t && t->prox && t->valor != x)
		{

			prev = t;
			t = t->prox;

		}

		//casos

		if (!prev) //cabeza 
		{

			auxD = *cab;
			*cab = (*cab)->prox;
			delete auxD;

		}
		else
		{

			auxD = t;
			prev->prox = auxD->prox;
			delete auxD;

		}
	}

}

/*BORRARLO LA ULTIMA VEZ QUE LO ENCUENTRE ()*/
void deleteLastInstance(lista **cab, int x)
{

	lista *t = *cab, *prev = NULL, *auxD;
	int rep = amountOfInstances(*cab, x), seen = 0;

	if (rep < 2) return;

	else
	{

		while (t && t->prox && seen < rep)
		{

			if (t->valor == x)
				seen++;
			//parche
			if (seen == rep)break; //si se para en la ultima instancia, salte del ciclo, es decir no lo muevas
			prev = t;
			t = t->prox;

		}

		auxD = t;
		prev->prox = auxD->prox;
		delete auxD;

	}

}

/*BORRARLO TODAS LAS VECES QUE LO ENCUENTRE*/
void deleteEveryInstance(lista **cab, int x)
{

	lista *t = *cab, *prev = NULL, *auxD;

	while (t)
	{

		if (t->valor == x)
		{

			//casos
			if (!prev)//cabeza
			{

				auxD = t;
				*cab = (*cab)->prox;
				t = *cab;
				delete auxD;

			}
			else
			{

				auxD = t;
				prev->prox = t->prox;
				t = t->prox;
				delete auxD;


			}

		}
		else
		{

			prev = t;
			t = t->prox;

		}

	}

}

/*BORRARLO TODAS LAS VECES QUE LO ENCUENTRE MENOS SU ULTIMA OCURRENCIA*/
void deleteUntilLastInstance(lista **cab, int x)
{

	if (!(*cab)) return;

	int Rep = amountOfInstances(*cab, x), cont = 0;
	lista *t = *cab, *aux, *prev = NULL;

	if (Rep < 2) return;

	while (t->prox)
	{

		if (t->valor == x)
		{

			cont++;
			if (cont == Rep) break; //esta en la ultima instancia
									//casos

			if (!prev)
			{

				aux = *cab;
				*cab = (*cab)->prox;
				t = *cab;
				delete aux;

			}
			else
			{

				aux = t;
				prev->prox = t->prox;
				t = t->prox;
				delete aux;

			}

		}
		else
		{

			prev = t;
			t = t->prox;

		}


	}


}

/*ELIMINAR LISTA*/
void cleanList(lista **cab)
{

	if (!(*cab)) return;

	while (*cab)
	{

		lista *aux = *cab;
		*cab = (*cab)->prox;
		delete aux;

	}

}

/*ELIMINAR ELEMENTOS REPETIDOS DEJANDO SU PRIMERA INSTANCIA*/
void deleteRepeatedElementsLeavingFirstInstance(lista **cab)
{

	lista *T = *cab, *k, *auxD;
	while (T && T->prox)
	{

		k = T;
		while (k->prox)
		{

			if (k->prox->valor == T->valor)
			{

				auxD = k->prox;
				k->prox = k->prox->prox;
				delete auxD;

			}
			else
			{

				k = k->prox;

			}

		}

		T = T->prox;
	}


}

/*ELIMINAR ELEMENTOS REPETIDOS DEJANDO SU ULTIMA INSTANCIA*/
void DRELlastInstance(lista **cab)
{

	if (!(*cab)) return;

	lista *t = *cab;
	while (t)
	{

		deleteUntilLastInstance(cab, t->valor);
		t = t->prox;

	}

}

/*ELIMINAR LAS CASILLAS EN POSICION MULTIPLO DE N*/
void deleteNmultiplier(lista **cab,int n)
{

	if (!(*cab))return;

	lista *t = *cab, *prev = NULL;
	int pos = 0;
	while(t)
	{
	
		if(isM(pos,n))
		{
			pos++; //actualiza posicion
			//elimina
			if(!prev)
			{
			
				lista *aux = t;
				*cab = (*cab)->prox;
				t = *cab;
				delete aux;
			
			}else
			{
				lista *aux = t;
				prev->prox = t->prox;
				t = t->prox;
				delete aux;
			
			}
		
		}else
		{
			prev = t;
			t = t->prox;
			pos++;//actualiza posicion
		
		}
	
	}

}

#pragma endregion 

#pragma region MANEJO PAR,IMPAR,PRIMO

#pragma region FUNCIONES SECUNDARIAS PARA MANEJO PAR,IMPAR,PRIMO

/*NUMERO PRIMO?*/
bool Primo(int n)
{

	for (int i = 2; i < n; i++)
	{

		if ((n  % i) == 0)
		{

			return false;

		}

	}

	return true;
}

/*NUMERO IMPAR?*/
bool impar(int n)
{

	if ((n % 2) == 0)
	{

		return false;

	}
	else
	{

		return true;

	}

}

#pragma endregion

/*INTERCALAR PAR IMPAR*/
void inercalarParImpar(lista **cab)
{

	if (!(*cab)) return;

	else
	{

		lista *t = *cab, *q;
		bool buscaPar;
		int cont = 0;

		while (t && t->prox)
		{

			q = t->prox;

			if (!impar(cont)) buscaPar = true;
			else buscaPar = false;

			while (q)
			{

				if (buscaPar)
				{

					if (!impar(t->valor)) break;

					if (!impar(q->valor)) swap(&t->valor, &q->valor);;

				}
				else
				{
					if (impar(t->valor)) break;

					if (impar(q->valor)) swap(&t->valor, &q->valor);


				}

				q = q->prox;

			}

			t = t->prox;
			cont++;

		}


	}

}

/*IMPARES AL COMIENZO*/
void imparesAlComienzo(lista **cab)
{

	lista *t = *cab, *q;

	while (t && t->prox)
	{
		q = t;

		while (q)
		{

			if (impar(q->valor))
			{

				swap(&t->valor, &q->valor);

			}

			q = q->prox;
		}

		t = t->prox;

	}

}

/*ELIMINAR PAR Y PRIMOS*/
void EliminarParyPrimos(lista **cab)
{

	lista *t = *cab, *auxD, *prev = NULL;
	while (t)
	{

		if (Primo(t->valor) || !impar(t->valor))
		{

			if (!prev)
			{

				//Esta en la primera casilla
				auxD = t;
				*cab = (*cab)->prox;
				t = *cab;
				delete auxD;

			}
			else
			{
				//caso normal
				auxD = t;
				prev->prox = auxD->prox;
				t = t->prox;
				delete auxD;

			}


		}
		else
		{

			prev = t;
			t = t->prox;

		}


	}

}

/*ELIMINAR IMPARES DE MAS DE DOS DIGITOS*/
void eliminarImparesPlusDigitSize(lista **cab)
{
	lista *t = *cab, *auxD, *prev = NULL;

	while (t)
	{

		if (impar(t->valor) && digitsSizeOfNumer(t->valor) >= 2)
		{

			if (!prev)
			{
				//primera casilla
				auxD = *cab;
				*cab = (*cab)->prox;
				t = *cab;
				delete auxD;

			}
			else
			{
				//caso comun
				auxD = t;
				prev->prox = auxD->prox;
				t = t->prox;
				delete auxD;

			}

		}
		else
		{

			prev = t;
			t = t->prox;

		}

	}


}

/*DEJAR IMPARES AL COMIENZO Y PRIMOS AL FINAL*/
void impPrincipioPrimosFinal(lista **cab)
{

	lista *t = *cab, *q;
	while (t && t->prox)
	{
		q = t->prox;
		while (q)
		{

			if (Primo(q->valor))
			{

				q = q->prox;

			}
			else if (impar(q->valor))
			{

				swap(&t->valor, &q->valor);
				q = q->prox;

			}
			else
			{

				q = q->prox;

			}

		}

		t = t->prox;

	}

}

/*DEJAR IMPARES PARES Y PRIMOS*/
void impparprim(lista *cab)
{

	if (!cab)return;

	impPrincipioPrimosFinal(&cab); //deja los impares al principio y los primos al final

	lista *t = cab, *k;

	while (t && t->prox)
	{

		k = t->prox;
		while(k)
		{
		
			if (impar(t->valor) && !Primo(t->valor)) break;

			if ((!impar(k->valor) && !Primo(k->valor)) || k->valor == 2) swap(&t->valor, &k->valor);
			
			k = k->prox;
		
		
		}
		t = t->prox;

	}
	

}

#pragma endregion

#pragma region VOLTEAR LISTA
/*VOLTEAR LISTA*/

void revertList(lista **cab)
{

	if (!(*cab)) return;

	lista *newNode = NULL;

	while (*cab)
	{
		//copia cabeza en nueva lista
		insertNodeByHead(&newNode, (*cab)->valor);

		//borra cabeza
		lista * aux = *cab;
		*cab = (*cab)->prox;
		delete aux;

	}

	*cab = newNode;

}

#pragma endregion

#pragma region EJERCICIOS CON MANEJO DE DIGITOS

#pragma region FUNCIONES SECUNDARIAS

/*CANTIDAD DE ELEMENTOS DE UNA LISTA*/
int cantElements(lista *cab)
{
	if (!cab) return 0;
	lista*t = cab;
	int cont = 0;

	while (t)
	{

		cont++;
		t = t->prox;

	}

	return cont;

}

#pragma endregion

/*ORDENAR POR CANTIDAD DE DIGITOS*/
void ordenarPorDigitsSize(lista **cab)
{

	lista *t = *cab, *q;
	while (t && t->prox)
	{

		q = t->prox;
		while (q)
		{

			if (digitsSizeOfNumer(t->valor) > digitsSizeOfNumer(q->valor))
			{

				swap(&t->valor, &q->valor);

			}

			q = q->prox;

		}

		t = t->prox;

	}

}

/*DEJAR LAS CASILLAS CUYOS NUMEROS TIENEN DIGITOS QUE AL SUMARLOS DAN UN NUMERO IMPAR AL FINAL DE LA LISTA (EN LA MISMA SECUENCIA)*/
void impDigitSum(lista **cab)
{

	if (!(*cab)) return;

	int cant = cantElements(*cab), cont = 0;
	lista *t = *cab, *prev = NULL;

	while (t)
	{

		if (cont == cant)break;

		if(impar(SumOfDigits(t->valor)))
		{
		
			cont++;
			//INSERTA
			finalInsertion(cab, t->valor);
			//ELIMINA
			if(!prev)
			{
			
				lista *aux = t;
				*cab = (*cab)->prox;
				t = *cab;
				delete aux;
			
			}else
			{
			
				lista *aux = t;
				prev->prox = t->prox;
				t = t->prox;
				delete aux;
			
			}

		
		}else
		{
		
			prev = t;
			t = t->prox;

		}

	}

}

#pragma endregion

#pragma region SEPARAR NUMERO EN DIGITOS Y METERLOS EN UNA LISTA

void separate(lista **cab)
{

	if (!(*cab)) return;
	lista *t = NULL;
	int x, digit;
	while(*cab)
	{
	
		x = (*cab)->valor, digit = 0;
		while (x > 0)
		{

			digit = x % 10;
			x /= 10;
			insertNodeByHead(&t, digit);

		}
		lista *auxD = *cab;
		*cab = (*cab)->prox;
		delete auxD;
	
	}

	*cab = t;

}

#pragma endregion

#pragma region MOVER LAS N ULTIMAS CASILLAS AL COMIENZO, MANTENIENDO SU ORDEN

/*DEJAR LAS N ULTIMAS CASILLAS AL PRINCIPIO DMANTENIENDO SU ORDEN*/
void lastToStart(lista **cab, int n)
{

	if (!(*cab)) return;

	lista *t = *cab, *prev = NULL;
	int cont = 0;

	while(cont != n)
	{
		t = *cab;

		while(t->prox)
		{
		
			prev = t;
			t = t->prox;

		}

		insertNodeByHead(cab, t->valor);
		cont++;
		lista *aux = t;
		prev->prox = t->prox;
		t = t->prox;
		delete aux;
	
	}


}

#pragma endregion

#pragma endregion

#pragma endregion

#pragma region EJERCICIOS CON DOS LISTAS
/******************EJERCICIOS BASADOS EN DOS LISTSA SIMPLEMENTE ENLAZADAS*********************/

#pragma region FUNCIONES BASICAS
/*IMPRIMIR DOS LISTAS*/
void printTwoLists(lista *cab1, lista *cab2)
{

	lista *t = cab1, *k = cab2;

	//impimir lista A
	printf("Lista A:\n");

	while (t) 
	{
		printf("[%i]->", t->valor);
		t = t->prox;

	}
	printf("[NULL]\n\n");

	//imprimir lista b
	printf("Lista B:\n");

	while (k)
	{
		printf("[%i]->", k->valor);
		k = k->prox;

	}
	printf("[NULL]\n\n");
}

#pragma endregion

#pragma region EJERCICIOS

#pragma region INTERCALAR ELEMENTOS DE A Y ELEMENTOS DE B

/*INTERCALAR UN ELEMENTO DE A Y LUEGO UNO DE B HASTA QUE A QUEDE VACIA*/
void oneAoneB(lista **cab1, lista **cab2)
{

	if (!(*cab1) || !(*cab2)) return;
	lista  *k = *cab2;

	while (*cab1 && k)
	{

		//creo una casilla con el valor de a
		lista *aux = new lista;
		aux->valor = (*cab1)->valor;

		//meto aux en b
		aux->prox = k->prox;
		k->prox = aux;
		k = aux->prox;

		//borro cab 1
		lista *auxD = *cab1;
		*cab1 = (*cab1)->prox;
		delete auxD;
	}

	//si se acaba la segunda lista pero todavia hay elementos en la primera
	while(*cab1)
	{

		finalInsertion(cab2, (*cab1)->valor); //inserta por final de lista en la segunda
		
		//borra cab1
		lista *auxD = *cab1;
		*cab1 = (*cab1)->prox;
		delete auxD;
	
	}

}

/*INTERCALAR EN UNA LISTA C UN ELEMENTO DE A Y UNO DE BE, 1 DE A Y 2 DE B Y ASI SUCESIVAMENTE*/
void mixAandBinC(lista **a, lista **b, lista **c)
{

	if (!(*a) || !(*b)) return;
	int cont = 0,inserted = 0; //cuantos elementos de b vas a insertar en c? inserted te dice cuantos elementos de b se han insertado en c

	while (*a)
	{
		finalInsertion(c, (*a)->valor); //inserta por cola en c
		//elimina cabeza de a
		lista *aux = *a;
		*a = (*a)->prox;
		delete aux;

		cont++; //incrementa por uno la cantidad de elementos de b que se van a insertar en c
		inserted = 0; //refresca la cantidad de elementos de b insertados en c

		while (*b && inserted <cont)
		{

			finalInsertion(c, (*b)->valor);
			inserted++;

			//borra cabeza de b
			lista *aux = *b;
			*b = (*b)->prox;
			delete aux;

		}


	}

	//si se acaba a y todavia hay elementos en b
	while (*b)
	{

		finalInsertion(c, (*b)->valor);//insertalos por final de la lista c

		lista *aux = *b;
		*b = (*b)->prox;
		delete aux;

	}

	//si se acaba b y todavia hay elementos en a
	while (*a)
	{

		finalInsertion(c, (*a)->valor);//insertalos por final de la lista c

		lista *aux = *a;
		*a = (*a)->prox;
		delete aux;

	}

}

#pragma endregion

#pragma region CONTAR ELEMENTOS COMUNES
/*CANTIDAD DE ELEMENTOS COMUNES SIN REPETIDOS*/
int CommonElements(lista *a, lista *b)
{

	if (!a || !b) return 0;

	lista *t = a, *k ;
	int cant = 0, prevE = -1;

	while(t)
	{
	
		k = b;

		while (k)
		{

			if (t->valor == k->valor && k->valor != prevE) 
			{
				prevE = t->valor;
				cant++;
			}

			k = k->prox;

		}

		t = t->prox;
	}

}

#pragma endregion

#pragma region ELIMINACIONES

/*ELIMINAR ELEMENTOS COMUNES*/
void DCE(lista **a , lista **b)
{

	if (!(*a) || !(*b)) return;
	lista *t = *a, *k = *b;
	while(t)
	{
	
		while (k)
		{

			if(t->valor == k->valor)
			{
			
				deleteEveryInstance(a, t->valor);
				deleteEveryInstance(b, k->valor);

			}
			else
			{

				k = k->prox;

			}

		}

		t = t->prox;
	}

}	

#pragma endregion

#pragma region DEJAR EN A PARES (LOS DE B AL FINAL) Y EN B IMPARES (LOS DE A AL FINAL)

void PAIMPB(lista **a,lista **b)
{

	if (!(*a) || !(*b)) return;

	lista *t = *a, *k = *b,*pa =NULL,*pb =NULL;

	//dejo los impares de a al final de b
	while(t)
	{
	
		if(impar(t->valor))
		{
			finalInsertion(b, t->valor);

			//elimina la casilla
			if(!pa)
			{
			
				lista *auxD = *a;
				*a = (*a)->prox;
				t = *a;
				delete auxD;
			
			}else
			{
			
				lista *auxD = t;
				pa->prox = auxD->prox;
				t = t->prox;
				delete auxD;
			
			}
		
		}
		else { pa = t; t = t->prox; }
	
	}

	while (k)
	{

		if(!impar(k->valor))
		{
		
			finalInsertion(a, k->valor);
			//elimina casilla
			if (!pb)
			{

				lista *auxD = *b;
				*b = (*b)->prox;
				k = *b;
				delete auxD;

			}
			else
			{

				lista *auxD = k;
				pb->prox = auxD->prox;
				k = k->prox;
				delete auxD;

			}
		
		}

	}

}

#pragma endregion

#pragma region INTERCALAR ELEMENTOS DE A Y DE B (B DESDE EL FINAL) SIN VOLTEAR LISTA

void intercal2(lista **a, lista **b)
{

	if (!(*b)) return;
	lista *t = *a, *k = *b, *prevB = NULL;
	while (t)
	{

		k = *b;
		while (k->prox)
		{

			prevB = k;
			k = k->prox;

		}

		//concatenaciones:
		if(!prevB)
		{
		
			k->prox = t->prox;
			t->prox = k;
			*b = NULL;
		
		}
		prevB->prox = k->prox; //lo deja en NULL
		k->prox = t->prox;
		t->prox = k;
		t = t->prox->prox;

	}

}

void intercal3(lista **a, lista **b)
{

	if (!(*b))return;
	lista *t = *a, *k, *prevB = NULL;
	while(t && *b)
	{
		prevB = NULL;
		k = *b;
		while (k->prox)
		{
			prevB = k;
			k = k->prox;

		}

		lista *newAux = new lista;
		newAux->valor = k->valor;

		newAux->prox = t->prox;
		t->prox = newAux;
		t = t->prox->prox;

		if(!prevB)
		{
		
			lista *auxD = *b;
			*b = (*b)->prox;
			k = *b;
			delete auxD;
		
		}else
		{
		
			lista *auxD = k;
			prevB->prox = k->prox;
			//k = k->prox;
			delete auxD;
		
		}
	
	
	}

	while (*b)
	{

		k = *b;
		while (k->prox)
		{
			
			prevB = k;
			k = k->prox;
		}

		finalInsertion(a, k->valor);

		if (!prevB)
		{

			lista *auxD = *b;
			*b = (*b)->prox;
			k = *b;
			delete auxD;

		}
		else
		{

			lista *auxD = k;
			prevB->prox = k->prox;
			k = k->prox;
			delete auxD;

		}
	}

}

#pragma endregion

#pragma endregion


#pragma endregion
