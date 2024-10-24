/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_macro.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:18:25 by motoko            #+#    #+#             */
/*   Updated: 2024/01/08 14:54:01 by hnogared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MACRO_H
# define MINIRT_MACRO_H

/*
 * If set at 1 at compilation, enables the bonus features of the program,
 * else defaults to only the mandatory ones.
 *
 * Use 'make bonus' or 'BONUS=<value>' with make to set it to 1.
 */
# ifndef RT_BONUS
#  define RT_BONUS	0
# endif

/*
 * Program main window width override.
 * If equal to 0, the main window takes the width of the computer screen.
 *
 * Use 'WIN_WIDTH=<value>' with make to set it.
 */
# ifndef WIN_WIDTH
#  define WIN_WIDTH		0
# endif

/*
 * Program main window height override.
 * If equal to 0, the main window takes the height of the computer screen.
 *
 * Use 'WIN_HEIGHT=<value>' with make to set it.
 */
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT	0
# endif

/*
 * The display pixel ratio represents the width and height, in screen pixels,
 * of one calculated pixel.
 * If equal or less than 0, the program taks a pixel ratio of 1.
 *
 * Use 'PIXEL_RATIO=<value>' with make to set it.
 */
# ifndef DEFAULT_PIXEL_RATIO
#  define DEFAULT_PIXEL_RATIO	3
# endif

# define RT_MAX_BOUNCES	1

# define RT_BUFFER_SIZE 1000

/* Different scene object types (see t_object structure at miniRT_struct.h) */
# define BLANK_OBJ		0
# define CAMERA_OBJ		1
# define LIGHT_OBJ		2
# define SPHERE_OBJ		3
# define PLANE_OBJ		4
# define CYLINDER_OBJ	5

# define RT_LIGHT_DIAMETER	10.0f

#endif
