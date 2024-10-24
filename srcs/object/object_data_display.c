/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_data_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:28:41 by hnogared          #+#    #+#             */
/*   Updated: 2024/01/07 22:17:40 by hnogared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Function to display a t_object object structure's data in the terminal.
 * The object's data_print_func pointer is needed to display its special data.
 *
 * @param t_object object	-> the object structure to display
 */
void	print_object_data(t_object object)
{
	object.ft_print_data(object.special_data);
	printf("[Object data]\n");
	print_coords(object.coords, NULL);
	print_vector(object.orientation_vector, NULL);
	print_basis(object.local_basis, NULL);
	printf("\n");
}

/*
 * Function to display a t_coords coordinates structure in the terminal.
 *
 * @param t_coords coords	-> coordinates structure to display
 * @param const char *name	-> name of the coordinates displayed
 */
void	print_coords(t_coords coords, const char *name)
{
	char	*used_name;

	used_name = (char *)((uintptr_t) name + (uintptr_t) "Coords" * (!name));
	printf("%s : (%f,%f,%f)\n", used_name, coords.x, coords.y, coords.z);
}

/*
 * Function to display a t_vector vector structure in the terminal.
 *
 * @param t_vector vector	-> vector structure to display
 * @param const char *name	-> name of the vector displayed
 */
void	print_vector(t_vector vector, const char *name)
{
	char	*used_name;

	used_name = (char *)((uintptr_t) name + (uintptr_t) "Vector" * (!name));
	printf("%s : (%f,%f,%f)\n", used_name, vector.x, vector.y, vector.z);
}

/*
 * Function to display a t_rgb_color color structure in the terminal.
 *
 * @param t_rgb_color color	-> rgb color structure to display
 * @param const char *name	-> name of the color displayed
 */
void	print_rgb_color(t_rgb_color color, const char *name)
{
	char	*used_name;

	used_name = (char *)((uintptr_t) name + (uintptr_t) "Color" * (!name));
	printf("%s : (%d:%d:%d)\n", used_name, color.red, color.green, color.blue);
}

/*
 * Function to display a t_basis basis structure in the terminal.
 *
 * @param t_basis basis		-> basis structure to display
 * @param const char *name	-> name of the basis displayed
 */
void	print_basis(t_basis basis, const char *name)
{
	char	*used_name;

	used_name = (char *)((uintptr_t) name + (uintptr_t) "Basis" * (!name));
	printf("%s : ", used_name);
	print_vector(basis.x, "x");
	printf("        ");
	print_vector(basis.y, "y");
	printf("        ");
	print_vector(basis.z, "z");
}
