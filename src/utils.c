/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:03:12 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/18 15:41:17 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

char	*c_strdup(char *str)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\n';
    copy[i + 1] = '\0';
	return (copy);
}

char	*c_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc(s1_len + s2_len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcpy(new_str + (s1_len), s2, s2_len + 1);
	free(s1);
	return (new_str);
}

void *safe_malloc(size_t size)
{
    void *ptr;

    ptr = malloc(size);
    if (!ptr)
    {
        ft_putendl_fd("Error: malloc failed", 2);
        exit(1);
    }
    return (ptr);
}

void *safe_calloc(size_t size, size_t count)
{
    void *ptr;

    ptr = ft_calloc(size, count);
    if (!ptr)
    {
        ft_putendl_fd("Error: malloc failed", 2);
        exit(1);
    }
    return (ptr);
}

void *safe_empty(size_t size, size_t count)
{
    void *ptr;
	size_t x;
	unsigned char *p;

	x = count * size;
    ptr = malloc(x + 1);
	if (!ptr)
		return (0);
	p = ptr;
	while (x--)
		*p++ = ' ';
    if (!ptr)
    {
        ft_putendl_fd("Error: malloc failed", 2);
        exit(1);
    }
	*p = '\0';
    return (ptr);
}

void	print_error(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit (1);
}
