/**
* IMPLEMENTACAO DA TABELA HASH
* AUTOR: ALEX MATOS IUASSE
* */

#include <stdio.h>
#include <stdlib.h>
#define siz 30

struct hash
{
  int key;
  char word;
};
typedef struct hash type_hash;

int function_hash (int key)
{
  int position;
  position = (key*13) % siz;
  return position;
}

int verify_position (int position, type_hash *table_hash)
{
  if (table_hash [position] . key == -666)
  {
    return position;
  }
  else
  {
    if(position == siz-1)
      position = 0;
    else
    {
      position = position + 3;
      verify_position (position, table_hash);
    }
  }
}

void insert_hash (type_hash *table_hash, type_hash hash, int key)
{
  int pos;
  pos = function_hash (key);
  pos = verify_position (pos, table_hash);
  table_hash [pos] = hash;
}

type_hash remove_hash ( type_hash *table_hash, int key)
{
  int pos;
  type_hash remove_hash;
  pos = function_hash (key);
  do
  {
    if (table_hash[pos].key == -666)
    {
      printf ("KEY INVALIDA\n");
      return remove_hash;
    }
    else
    {
      if (table_hash[pos].key == key)
      {
	remove_hash = table_hash[pos];
	table_hash[pos].key = -666;
	pos = -1;
	return remove_hash;
      }
      else
      {
	if (pos == siz -1)
	  pos = 0;
	else
	  pos = pos + 3;
      }
    }
  }while (pos != -1);
}

void start (type_hash *table_hash)
{
  int aux = 0;
  while (aux != siz)
  {
    table_hash [aux] . key = -666;
    aux ++;
  }
}

void print (type_hash  *table_hash, int key)
{
  int pos = function_hash(key);
  
  do
  {
    if (table_hash[pos].key == -666)
    {
      printf("\nKEY INVALIDA\n");
      exit(1);
    }
    else
    {
      if (table_hash [pos] . key == key)
      {
	printf ("TEM QUE SER ESSE :\t%c\n", table_hash[pos].word);
	printf("KEY : \t%i\n",table_hash[pos].key);
	printf ("POS : \t%i\n",pos);
	pos = -1;
      }
      else
      {
	if (pos == siz-1)
	  pos = 0;
	else
	  pos = pos + 3;
      }
    }
  }while(pos != -1);
}

int main (int argc, char **argv)
{
  type_hash table_hash [siz];
  type_hash hash;
  
  start (table_hash);
  hash.word = 'a';
  hash.key = 123456;
  insert_hash (table_hash, hash, 123456);
  hash.word = 'l';
  hash.key = 234567;
  insert_hash (table_hash, hash, 123456);
  print(table_hash,123456);
  print(table_hash,234567);
  remove_hash(table_hash,123456);
  print(table_hash,123456);
  
  return 0;
}
