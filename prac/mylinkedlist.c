#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(void	*content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *ne)
{
	// p lst, (t_list **) $1 = 0x00007ffeefbff500
	ne->next = *lst; 
	*lst = ne;
	// p ne, (t_list *) $2 = 0x0000000100604090
	// p ne->next (s_list *) $3 = 0x0000000100604080
	// p *lst (t_list *) $4 = 0x0000000100604090
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*curr;

	curr = *lst;
	while (curr)
	{
		tmp = curr->next;
		ft_lstdelone(curr, del);
		curr = tmp;
	}
	*lst = NULL;
}

void	leakcheck()
{
	system("leaks a.out");
}

void	freeWord(void	*content)
{
	free(content);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*tmp;
	void	*new_content;

	ptr = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		tmp = ft_lstnew(new_content);
		if (!tmp)
		{
			del(new_content);
			ft_lstclear(&ptr, del);
			return (NULL);
		}
		ft_lstadd_back(&ptr, tmp);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (ptr);
}

void	*Mylower(void	*content)
{
	int	idx = 0;
	int	len = strlen((char*)content);
	char	*upper = (char*) malloc(len + 1);
	while (idx < len)
	{
		upper[idx] = tolower(((char *)content)[idx]);
		idx++;
	}
	upper[idx] = '\0';
	return upper; 
}

void	MyUpper(void	*content)
{
	int	idx = 0;
	int	len = strlen((char*)content);
	char	*upper = (char*) malloc(len + 1);
	while (idx < len)
	{
		upper[idx] = toupper(((char *)content)[idx]);
		idx++;
	}
	idx = 0;
	while (idx < len)
	{
		((char *)content)[idx] = upper[idx];
		idx++;
	}
	upper[idx] = '\0';
}

int main()
{
	char	*tom = (char*)malloc(sizeof(char) * 4);
	tom[0] = 'T'; tom[1] = 'o'; tom[2] = 'm'; tom[3] = '\0';
	char	*kim = (char*)malloc(sizeof(char) * 4);
	kim[0] = 'K'; kim[1] = 'i'; kim[2] = 'm'; kim[3] = '\0';
	char	*jay = (char*)malloc(sizeof(char) * 4);
	jay[0] = 'J'; jay[1] = 'a'; jay[2] = 'y'; jay[3] = '\0';


	t_list*		a = ft_lstnew(tom);
	t_list*		b = ft_lstnew(kim);
	t_list*		c = ft_lstnew(jay);

	ft_lstadd_front(&a, b);
	ft_lstadd_back(&b, c);
	ft_lstiter(b, MyUpper);

	printf("b->content : %s\n", b->content);
	printf("b->next->content : %s\n", b->next->content);
	printf("b->next->next->content : %s\n", b->next->next->content);

	t_list*		new_name = ft_lstmap(b, Mylower, freeWord);

	printf("new_name->content : %s\n", new_name->content);
	printf("new_name->next->content : %s\n", new_name->next->content);
	printf("new_name->next->next->content : %s\n", new_name->next->next->content);
	
	ft_lstclear(&b, freeWord);
	ft_lstclear(&new_name, freeWord);
	// atexit(leakcheck);
	return 0;
}