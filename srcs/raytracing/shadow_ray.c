/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:16:55 by hnogared          #+#    #+#             */
/*   Updated: 2024/01/09 00:09:47 by hnogared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Function to check if the given shadow ray touches the light with the '@param
 * light_id' inside the '@param objects_array' unobstructed by other objects.
 * The ray won't be obstructed by other lights present in the scene.
 * The pointed parameter ray's color will be updated if the light is reached.
 *
 * @param t_ray *shadow_ray				-> pointer to the ray to cast and modify
 * @param t_object *objects_array		-> pointer to the scene objects to check
 * @param unsigned short objects_count	-> amount of scene objects to check
 * @param int light_id					-> tested light id in the objects pointer
 * @return[redundant] t_rgb_color		-> the new calculated shadow ray color
 *
 * @parent_func shadow_ray	-> function to get the lighting of a point in space
 */
static t_rgb_color	advance_shadow_ray(t_ray *shadow_ray,
	const t_object *objects_array, unsigned short objects_count, int light_id)
{
	int			i;
	float		strength;
	t_object	light;

	i = -1;
	while (++i < (int) objects_count)
	{
		if (objects_array[i].type == LIGHT_OBJ && i != light_id)
			continue ;
		do_touch(shadow_ray, objects_array[i], i);
	}
	if (shadow_ray->go != light_id)
		return (shadow_ray->light_color);
	light = objects_array[shadow_ray->go];
	strength = light.special_data.light.brightness * 20 / shadow_ray->sol;
	shadow_ray->light_color = rgb_color_lighten(shadow_ray->light_color,
			light.special_data.light.color, strength);
	return (shadow_ray->light_color);
}

/*
 * Function to get the lighting color of a point at the parameter coords
 * according to the lights present in the parameter objects array.
 *
 * @param t_coords start_coords			-> coords of the point in space to check
 * @param t_object *objects_array		-> pointer to the scene objects to check
 * @param unsigned short objects_count	-> amount of scene objects to check
 * @param t_ambient_light ambient_l		-> the scene ambient lighting
 * @return t_rgb_color					-> the resulting lighting color
 *
 * @child_func advance_shadow_ray	-> function to check if a ray touches a light
 */
t_rgb_color	shadow_ray(t_coords start_coords, const t_object *objects_array,
	unsigned short objects_count, t_ambient_light ambient_l)
{
	int		i;
	t_ray	shadow_ray;

	shadow_ray = new_ray((t_basis){{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
			start_coords);
	shadow_ray.light_color = (t_rgb_color){0, 0, 0};
	i = -1;
	while (++i < objects_count)
	{
		if (objects_array[i].type != LIGHT_OBJ)
			continue ;
		shadow_ray.vector = normalise(subs_vec_coords(objects_array[i].coords,
					start_coords));
		shadow_ray.sol = -1;
		shadow_ray.go = -1;
		shadow_ray.res = 0;
		shadow_ray.light_color = advance_shadow_ray(&shadow_ray, objects_array,
				objects_count, i);
	}
	return (rgb_color_lighten(shadow_ray.light_color, ambient_l.color,
			ambient_l.ratio * 0.7f));
}
