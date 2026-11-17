#include <unistd.h>
#include <libft.h>
#include <stdio.h>


int	words_counter(int ac, char **av)
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
void	words_copy(int ac, char **av,char **tokens)
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
	while(tokens[index]!=NULL)
	{
		n = 0;
		while(tokens[index][n])
		{
			if(!ft_isdigit(tokens[index][n]))
				return printf("error");
			n++;
		}
		printf("%s\n",tokens[index++]);
	}
}
