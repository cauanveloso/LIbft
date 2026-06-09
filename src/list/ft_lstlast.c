#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lab;

	lab = lst;
	while (lab && (lab)->next)
	{
		lab = (lab)->next;
	}
	return (lab);
}
