#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int	size;
	t_list	*lab;

	size = 0;
	lab = lst;
	while (lab)
	{
		size++;
		lab = (lab)->next;
	}
	return (size);
}
