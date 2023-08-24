#include "monty.h"
/**
 * _calloc - cfunction that concatenate two strings specially
 * @nmemb: number of elements
 * @size: type of data
 * Return: nothing
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *j = NULL;
	unsigned int k;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	j = malloc(nmemb * size);
	if (j == NULL)
	{
		return (NULL);
	}
	for (k = 0; k < (nmemb * size); k++)
	{
		*((char *)(j) + k) = 0;
	}
	return (j);
}
/**
 * _realloc -function that changes the size and copy the content
 * @ptr: malloc ptr to reallocate
 * @old_size: old number of bytes
 * @new_size: new number of Bytes
 * Return: nothing
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *j = NULL;
	unsigned int k;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		j = malloc(new_size);
		if (!j)
			return (NULL);
		return (j);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		j = malloc(new_size);
		if (!j)
			return (NULL);
		for (k = 0; k < old_size; j++)
			p[k] = *((char *)ptr + k);
		free(ptr);
	}
	else
	{
		j = malloc(new_size);
		if (!j)
			return (NULL);
		for (k = 0; k < new_size; k++)
			p[k] = *((char *)ptr + k);
		free(ptr);
	}
	return (j);
}
