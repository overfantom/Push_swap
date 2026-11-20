#include <unistd.h>
#include <libft.h>
#include <stdio.h>


static int	words_counter(int ac, char **av)
{
	int i = 1;
	int n = 0;
	int count = 0;
	char **buffer = NULL;
	while(i<ac)
	{
		buffer = ft_split(av[i],' ');
		while(buffer[n]!=NULL)
			n++;
		count += n;
		n = 0;
		i++;
		free(buffer);
	}
	return count;
}
static void	words_copy(int ac, char **av,char **tokens)
{
	int	i = 1;
	int	n = 0;
	char 	**buffer = NULL;
	int	index = 0;
	while(i<ac)
	{
		buffer = ft_split(av[i],' ');
		while(buffer[n]!=NULL)
		{
			tokens[index] = buffer[n];
			index++;
			n++;
		}
		n = 0;
		i++;
		free(buffer);
	}
	tokens[index]=NULL;
}
int	main(int ac, char **av)
{
	int word_count = 0;
	char **buffer = NULL;
	int i = 1;
	int n = 0;
	word_count=words_counter(ac,av);
	i = 1;
	n = 0;
	char **tokens = malloc(sizeof(char *) * (word_count+1));
	int index = 0;
	words_copy(ac,av,tokens);
	int *tmp = NULL;
	while(tokens[index][n])
	{
		if(!ft_isdigit(tokens[index][n]))
			return printf("error");
		n++;
	}
	tmp = malloc(sizeof(int));
	*tmp = ft_atoi(tokens[index]);
	t_list *head = ft_lstnew(tmp);
	index++;
	t_list *store = head;
	while(tokens[index]!=NULL)
	{
		n = 0;
		while(tokens[index][n])
		{
			if(!ft_isdigit(tokens[index][n]))
				return printf("error");
			n++;
		}
		tmp = malloc(sizeof(int));
		*tmp = ft_atoi(tokens[index]);
		while(head != NULL)
		{
			if(*(int*)(head->content) == *tmp)
				return printf("error");
			head = head->next;
		}
		head = store;
		ft_lstadd_back(&head,ft_lstnew(tmp));
		index++;

	}
	printf("correct");
}
