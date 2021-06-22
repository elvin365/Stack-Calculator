#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<float.h>
#include<math.h>
#include<cmath>
int proverka_probel(char);
int kydaprobel(char);
int znaklilinet(char*);
int functrigo(char*);
int znakilinet(char*);
double factorial(double f)
{
	if (f == 0)
	return 1;
	return(f * factorial(f - 1));
}
int TypeOfChar(char a)
{
	if (isdigit(a))
		return 1;
	if (isalpha(a))
		return 2;
	return 0;
}
char* MakeSpaces(char* a)
{
	char* result = (char*)malloc(sizeof(char) * 255);
	memset(result, 0, 255);

	result[0] = a[0];

	for (int i = 1; i < strlen(a); i++)
	{
		int t1 = TypeOfChar(a[i - 1]);
		int t2 = TypeOfChar(a[i]);
		if ((t1 != t2 || (t1 == 0 && t2 == 0)) && a[i - 1] != '.' && a[i] != '.')
		{
			strcat(result, " ");
			int len = strlen(result);
			result[len] = a[i];
			result[len + 1] = 0;
		}
		else
		{
			int len = strlen(result);
			result[len] = a[i];
			result[len + 1] = 0;
		}
	}
	return result;
}


struct Node
{
	char Data[100] = { 0 };
	struct Node* next;
};

struct Node* push(struct Node* head, char*  c)
{
	struct Node* New = (struct Node*)malloc(sizeof(Node));
	strcpy(New->Data, c);
	New->next = head;
	return New;

}





struct Node* Show(Node* head)
{
	//head = head->next;
	printf("%f", atof(head->Data));
	return head;


}



struct Node* Delete(struct Node* head, struct Node* removable)
{
	if ((head->Data) == NULL)
		return 0;
	if (head == removable)
	{
		head = head->next;
		free(removable);
	}
	else
	{
		Node *prev = head;
		while (prev->next != removable)
		{
			prev = prev->next;
		}

		prev->next = removable->next;
		free(removable);
	}
	return head;
}




int main()
{
	printf("%d", kydaprobel('6'));

	//делаю из инфиксной в обратную польскую она же постфиксная 
	int i = 0;
	int j = 0;
	puts("Enter the quary");
	char stringin[100] = { 0 };
	char stringout[100] = { 0 };
	scanf("%s", stringin);
	int flag = 0; // тут я храню инфу о том, есть ли минус перед функцией или нет , если минус есть то 1 иначе 0 в нем будет лежаь
	i = 0;
	j = 0;
	int u = 0;

	int tamestfunc = 0;

	char stringin2[100] = { 0 }; // сюда введет пользователь свою расшифровку функции

	char stringin3[100] = { 0 }; // сюда соберется получившееся выражение

	int chislootbykvifunc = 0;

	while (stringin[i] != '\0')
	{
		if (stringin[i] == 'S' || stringin[i] == 'F' || stringin[i] == 'G')
			tamestfunc++;
		i++;
	}
	i = 0;
	if (tamestfunc > 0)
	{
		while (stringin[i] != '\0')
		{

			if (stringin[i] == 'S' || stringin[i] == 'F' || stringin[i] == 'G')
			{
				if (stringin[i - 1] == '-')
				{
					flag = 1; // знак - есть
				}
				while (stringin[i] != ')')
				{
					i++;
				}
				i++;
				puts("Enter the function");


				scanf("%s", stringin2);
				if (flag == 1)
				{
					int e = 1;
					for (int l = strlen(stringin2) - 1; l >= e - 1; l--)
						stringin2[l + 1] = stringin2[l];
					stringin2[e - 1] = '(';
					stringin2[strlen(stringin2)] = ')';
				}
				flag = 0;

				//stringin2[strlen(stringin2)] = ')';
				strcat(stringin3, stringin2);
				stringin2[strlen(stringin2) + 2] = '\0';
				j = strlen(stringin3);

			}

			if (stringin[i] != 'S' || stringin[i] != 'F' || stringin[i] != 'G')
				stringin3[j] = stringin[i];
			j++;
			i++;

			memset(stringin2, 0, sizeof(stringin2));
		}

	}
	j = 0;
	if (tamestfunc == 0)
		memcpy(stringin3, stringin, 100);
	// теперь stringin3 оригинал обработка фукций закончена
	char stringin4[200] = { 0 };
	i = 0;
	flag = 0;
	while (stringin3[i] != '\0')
	{

		if (stringin3[i] == 'a' && stringin3[i + 1] != 'r')
		{

			puts("Enter the a:");
			char stroka[15] = { 0 };
			scanf("%s", stroka);
			if (stroka[0] == '-')
			{
				int e = 1;
				for (int l = strlen(stroka) - 1; l >= e - 1; l--)
					stroka[l + 1] = stroka[l];
				stroka[e - 1] = '(';
				stroka[strlen(stroka)] = ')';
			}
			strcat(stringin4, stroka);
			memset(stroka, 0, sizeof(stroka));
			j = strlen(stringin4);

			i++;
		}
		if (stringin3[i] == 'b')
		{
			puts("Enter the b:");
			char stroka[15] = { 0 };
			scanf("%s", stroka);
			if (stroka[0] == '-')
			{
				int e = 1;
				for (int l = strlen(stroka) - 1; l >= e - 1; l--)
					stroka[l + 1] = stroka[l];
				stroka[e - 1] = '(';
				stroka[strlen(stroka)] = ')';
			}
			strcat(stringin4, stroka);
			memset(stroka, 0, sizeof(stroka));
			j = strlen(stringin4);

			i++;
		}
		if (stringin3[i] == 'c' && stringin3[i + 1] != 'o')
		{
			puts("Enter the c:");
			char stroka[15] = { 0 };
			scanf("%s", stroka);
			if (stroka[0] == '-')
			{
				int e = 1;
				for (int l = strlen(stroka) - 1; l >= e - 1; l--)
					stroka[l + 1] = stroka[l];
				stroka[e - 1] = '(';
				stroka[strlen(stroka)] = ')';
			}
			strcat(stringin4, stroka);
			memset(stroka, 0, sizeof(stroka));
			j = strlen(stringin4);

			i++;
		}
		if (stringin3[i] == 'd')
		{
			puts("Enter the d:");
			char stroka[15] = { 0 };
			scanf("%s", stroka);
			if (stroka[0] == '-')
			{
				int e = 1;
				for (int l = strlen(stroka) - 1; l >= e - 1; l--)
					stroka[l + 1] = stroka[l];
				stroka[e - 1] = '(';
				stroka[strlen(stroka)] = ')';
			}
			strcat(stringin4, stroka);
			memset(stroka, 0, sizeof(stroka));
			j = strlen(stringin4);

			i++;
		}
		if (stringin3[i] == 'e')
		{
			puts("Enter the e:");
			char stroka[15] = { 0 };
			scanf("%s", stroka);
			if (stroka[0] == '-')
			{
				int e = 1;
				for (int l = strlen(stroka) - 1; l >= e - 1; l--)
					stroka[l + 1] = stroka[l];
				stroka[e - 1] = '(';
				stroka[strlen(stroka)] = ')';
			}
			strcat(stringin4, stroka);
			memset(stroka, 0, sizeof(stroka));
			j = strlen(stringin4);

			i++;
		}
		if (stringin3[i] == 'x')
		{
			puts("Enter the x:");
			char stroka[15] = { 0 };
			scanf("%s", stroka);
			if (stroka[0] == '-')
			{
				int e = 1;
				for (int l = strlen(stroka) - 1; l >= e - 1; l--)
					stroka[l + 1] = stroka[l];
				stroka[e - 1] = '(';
				stroka[strlen(stroka)] = ')';
			}
			strcat(stringin4, stroka);
			memset(stroka, 0, sizeof(stroka));
			j = strlen(stringin4);

			i++;
		}
		if (stringin3[i] == 'y')
		{
			puts("Enter the y:");
			char stroka[15] = { 0 };
			scanf("%s", stroka);
			if (stroka[0] == '-')
			{
				int e = 1;
				for (int l = strlen(stroka) - 1; l >= e - 1; l--)
					stroka[l + 1] = stroka[l];
				stroka[e - 1] = '(';
				stroka[strlen(stroka)] = ')';
			}
			strcat(stringin4, stroka);
			memset(stroka, 0, sizeof(stroka));
			j = strlen(stringin4);

			i++;
		}
		if (stringin3[i] == 'z')
		{
			puts("Enter the z:");
			char stroka[15] = { 0 };
			scanf("%s", stroka);
			if (stroka[0] == '-')
			{
				int e = 1;
				for (int l = strlen(stroka) - 1; l >= e - 1; l--)
					stroka[l + 1] = stroka[l];
				stroka[e - 1] = '(';
				stroka[strlen(stroka)] = ')';
			}
			strcat(stringin4, stroka);
			memset(stroka, 0, sizeof(stroka));
			j = strlen(stringin4);

			i++;
		}

		//		if ( (stringin3[i] == 'a' && stringin3[i+1] == 'r') && stringin3[i] != 'b' && (stringin3[i] == 'c' && stringin3[i+1] == 'o') && stringin3[i] != 'd' && stringin3[i] != 'e' && stringin3[i] != 'x' && stringin3[i] != 'y' && stringin3[i] != 'z')
		if (stringin3[i] == 'a' && stringin3[i + 1] == 'r' && stringin3[i + 2] == 'c' && stringin3[i + 3] != 't')
		{
			for (int qwe = 0; qwe < 6; qwe++)
			{
				stringin4[j] = stringin3[i];
				i++;
				j++;
			}
		}


		if (stringin3[i] == 'a' && stringin3[i + 1] == 'r' && stringin3[i + 2] == 'c' && stringin3[i + 3] == 't')
		{
			for (int qwe = 0; qwe < 5; qwe++)
			{
				stringin4[j] = stringin3[i];
				i++;
				j++;
			}
		}
		if (stringin3[i] != 'b'   && stringin3[i] != 'd' && stringin3[i] != 'e' && stringin3[i] != 'x' && stringin3[i] != 'y' && stringin3[i] != 'z')
		{
			stringin4[j] = stringin3[i];
			i++;
			j++;
		}
		if (stringin3[i] == 'c' && stringin3[i + 1] == 'o')
		{
			for (int qwe = 0; qwe < 3; qwe++)
			{
				stringin4[j] = stringin3[i];
				i++;
				j++;
			}
		}
		if (stringin3[i] == 'c' && stringin3[i + 1] == 't')
		{
			for (int qwe = 0; qwe < 3; qwe++)
			{
				stringin4[j] = stringin3[i];
				i++;
				j++;
			}
		}


	}
	i = 0;
	j = 0;
	getchar();

	while (stringin4[i] != '\0')
	{
		if ((stringin4[i] == '(') && (stringin4[i + 1] == '-'))
		{
			int e = i + 1 + 1;
			for (int l = strlen(stringin4) - 1; l >= e - 1; l--)
				stringin4[l + 1] = stringin4[l];
			stringin4[e - 1] = '0';
		}
		i++;
	}

	i = 1;
	j = 1;
	if (stringin4[0] == '-')
	{
		int e = 1;
		for (int l = strlen(stringin4) - 2; l >= e - 1; l--)
			stringin4[l + 1] = stringin4[l];
		stringin4[e - 1] = '0';
	}
	char *stringin6 = MakeSpaces(stringin4);




	i = 0;
	j = 0;
	//-------------------------------------------------------------------------- обработка функций и переменных закончена
	struct Node* z = NULL;

	char* forstr; // тут будет лежать адрес с начала (отдельная строка) , 

	forstr = strtok(stringin6, " ");//строку на несколько подстрок
	while (forstr)
	{
		if ( atof(forstr) || forstr[0]=='0') // если очередной токен число , то иф  выполнится 
		{
			strcat(stringout, forstr);
			strcat(stringout, " ");
		}
		else
		{



			{
				if (!strcmp(forstr, "("))
				{
					z = push(z, forstr);
				}
				else
				{
					if (!strcmp(forstr, ")"))
					{
						while ((strcmp(z->Data, "(")) != 0) // (!strcmp(z->Data,"("))
						{
							strcat(stringout, z->Data);
							strcat(stringout, " ");
							z = Delete(z, z);
						}
						z = Delete(z, z);
					}
					else
					{
						if (znakilinet(forstr))
						{
							if (z != NULL)
							{
								int t1 = znakilinet(z->Data); // проверка вершины стека
								int t2 = znakilinet(forstr); //прибывший	
								if (t1 >= t2)
								{
									while ((t1 >= t2))
									{
										strcat(stringout, z->Data);
										strcat(stringout, " ");
										z = Delete(z, z);
										if (z == NULL)
											break;
										t1 = znakilinet(z->Data);//опять проверяем вершину стека
									}

								}
							}
							z = push(z, forstr);
						}
					}
				}
			}

		}
		i++;
		forstr = strtok(NULL, " ");
	}
	while (z != NULL)
	{
		strcat(stringout, z->Data);
		strcat(stringout, " ");
		z = Delete(z, z);
	}

	//вычисление на стеке 
	i = 0;
	float result = 0;
	struct Node* d = z;
	char buffer[100] = { 0 };
	forstr = strtok(stringout, " ");
	while (forstr)
	{
		if (atof(forstr) || forstr[0]=='0') // если очередной токен число , то иф  выполнится 
		{
			z = push(z, forstr);
		}
		if (znakilinet(forstr))
		{
			int t1 = znakilinet(forstr);
			if (t1 == 1 || t1 == 2)
			{
				d = z;
				d = d->next;
				if (forstr[0] == '-')
				{
					float oper1 = atof(z->Data);
					float oper2 = atof(d->Data);
					result = oper2 - oper1;
					z = Delete(z, d);
					z = Delete(z, z);

					sprintf(buffer, "%f", result);
					z = push(z, buffer);
					memset(buffer, 0, 100);
				}
				if (forstr[0] == '+')
				{
					float oper1 = atof(z->Data);
					float oper2 = atof(d->Data);
					result = oper2 + oper1;

					z = Delete(z, d);
					z = Delete(z, z);
					sprintf(buffer, "%f", result);
					z = push(z, buffer);
					memset(buffer, 0, 100);
				}
				if (forstr[0] == '*')
				{
					float oper1 = atof(z->Data);
					float oper2 = atof(d->Data);
					result = oper2 * oper1;
					z = Delete(z, d);
					z = Delete(z, z);

					sprintf(buffer, "%f", result);
					z = push(z, buffer);
					memset(buffer, 0, 100);
				}
				if (forstr[0] == '/')
				{
					float oper1 = atof(z->Data);
					float oper2 = atof(d->Data);
					result = oper2 / oper1;
					z = Delete(z, d);
					z = Delete(z, z);

					sprintf(buffer, "%f", result);
					z = push(z, buffer);
					memset(buffer, 0, 100);
				}
			}
			 t1 = znakilinet(forstr);
			if (t1 == 3) 
			{
				d = z;
				d = d->next;
				if (forstr[0] == '^')
				{
					double oper1 = atof(z->Data);
					double oper2 = atof(d->Data);
					result = pow(oper2, oper1);
					z = Delete(z, d);
					z = Delete(z, z);

					sprintf(buffer, "%f", result);
					z = push(z, buffer);
					memset(buffer, 0, 100);

				}
			}
			if (t1 == 4)
			{
				
				
				if (forstr[0] == '!')
				{
					double oper1 = atof(z->Data);
					if (oper1 == round(oper1)) {
						oper1 = factorial(oper1);
					}
					else {
						oper1++;
						oper1 = tgamma(oper1);
					}
					//double oper2 = atof(d->Data);
					//result = (oper2, oper1);
					z = Delete(z, z);

					sprintf(buffer, "%f", oper1);
					z = push(z, buffer);
					memset(buffer, 0, 100);

				}
				if (forstr[0] == 's')
				{
					double oper1 = atof(z->Data);
					//float oper2 = atof(d->Data);
					result = sin((oper1/180)*3.1415926535897932);
					//z = Delete(z, d);
					z = Delete(z, z);

					sprintf(buffer, "%f", result);
					z = push(z, buffer);
					memset(buffer, 0, 100);

				}
				if (forstr[0] == 'c' && forstr[1] == 'o' && forstr[2] == 's')
				{
					double oper1 = atof(z->Data);
					//float oper2 = atof(d->Data);
					result = cos((oper1 / 180)*3.1415926535897932);
					//z = Delete(z, d);
					z = Delete(z, z);

					sprintf(buffer, "%f", result);
					z = push(z, buffer);
					memset(buffer, 0, 100);

				}
				if (forstr[0] == 't' && forstr[1] == 'g')
				{
					double oper1 = atof(z->Data);
					//float oper2 = atof(d->Data);
					result = tan((oper1 / 180)*3.1415926535897932);
					//z = Delete(z, d);
					z = Delete(z, z);

					sprintf(buffer, "%f", result);
					z = push(z, buffer);
					memset(buffer, 0, 100);

				}
				if (forstr[0] == 'c' && forstr[1] == 'o' && forstr[2] == 't')
				{
					double oper1 = atof(z->Data);
					//float oper2 = atof(d->Data);
					result = 1/tan(((oper1 / 180)*3.1415926535897932));
					//z = Delete(z, d);
					z = Delete(z, z);

					sprintf(buffer, "%f", result);
					z = push(z, buffer);
					memset(buffer, 0, 100);

				}
				if (!strcmp(forstr,"arcsin"))
				{
					double oper1 = atof(z->Data);
					//float oper2 = atof(d->Data);
					result = asin(oper1);
					//z = Delete(z, d);
					z = Delete(z, z);

					sprintf(buffer, "%f", result);
					z = push(z, buffer);
					memset(buffer, 0, 100);
				}
				if (!strcmp(forstr, "arccos"))
				{
					double oper1 = atof(z->Data);
					//float oper2 = atof(d->Data);
					result = acos(oper1);
					//z = Delete(z, d);
					z = Delete(z, z);

					sprintf(buffer, "%f", result);
					z = push(z, buffer);
					memset(buffer, 0, 100);
				}
				if (!strcmp(forstr, "arctg"))
				{
					double oper1 = atof(z->Data);
					//float oper2 = atof(d->Data);
					result = atan(oper1);
					//z = Delete(z, d);
					z = Delete(z, z);

					sprintf(buffer, "%f", result);
					z = push(z, buffer);
					memset(buffer, 0, 100);
				}
				if (!strcmp(forstr, "arcctg"))
				{
					double oper1 = atof(z->Data);
					//float oper2 = atof(d->Data);
					result = 3.1415926535897932/2-atan(oper1);
					//z = Delete(z, d);
					z = Delete(z, z);

					sprintf(buffer, "%f", result);
					z = push(z, buffer);
					memset(buffer, 0, 100);
				}
			}

				
			

		}
		forstr = strtok(NULL, " ");
	}
	Show(z);



	_getch();
	return 0;
}

int proverka_probel(char symbol)
{
	if (symbol >= 48 && symbol <= 57)
	{
		return 1;
	}
	else return 2;



}
int kydaprobel(char symbol)
{
	if (symbol != 32 && (symbol == '-' || symbol == '+' || symbol == '*' || symbol == '/' || symbol == '!' || symbol == '^' || symbol == ')' || symbol == '('))
		return 1;
	else return 0;
}
int znaklilnet(char* c) // является ли очередной токен арифметическим действием 
{
	if (strcmp(c, "-") == 0)
	{
		return 0;
	}

}

int znakilinet(char* znak)
{
	if (!strcmp(znak, "-"))
	{
		return 1;
	}
	if (!strcmp(znak, "+"))
	{
		return 1;
	}
	if (!strcmp(znak, "*"))
	{
		return 2;
	}
	if (!strcmp(znak, "/"))
	{
		return 2;
	}
	if (!strcmp(znak, "!"))
	{
		return 4;
	}
	if (!strcmp(znak, "^"))
	{
		return 3;
	}
	if (!strcmp(znak, "sin"))
	{
		return 4;
	}
	if (!strcmp(znak, "cos"))
	{
		return 4;
	}
	if (!strcmp(znak, "tg"))
	{
		return 4;
	}
	if (!strcmp(znak, "cot"))
	{
		return 4;
	}
	if (!strcmp(znak, "arcsin"))
	{
		return 4;
	}
	if (!strcmp(znak, "arccos"))
	{
		return 4;
	}
	if (!strcmp(znak, "arctg"))
	{
		return 4;
	}
	if (!strcmp(znak, "arcctg"))
	{
		return 4;
	}

}