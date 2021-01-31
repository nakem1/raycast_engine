/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 04:45:03 by lmurray           #+#    #+#             */
/*   Updated: 2021/01/13 04:51:21 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void		init_cub3d_etc(t_cub3d *cub)
{
//	cub->frame0 = NULL;
//	cub->frame1 = NULL;
	cub->fd = -1;
}

void		player_init(t_cub3d *cub)
{
	cub->player.x_pos = 0;
	cub->player.y_pos = 0;
	cub->player.x_dir = -1;
	cub->player.y_dir = 0;
	cub->player.step_speed = 0;
	cub->player.turn_speed = 0;
}

void		init_event(t_event *event)
{
	event->a = 0;
	event->d = 0;
	event->escape = 0;
	event->left_turn = 0;
	event->right_turn = 0;
	event->s = 0;
	event->w = 0;
}

void		init_sprite(t_cub3d *cub)
{
	cub->sprite.zbuf = NULL;
	cub->sprite.len_sprite = 0;
	cub->sprite.sprite_x = 0;
}

void		init_cub3d(t_cub3d *cub)
{
	init_cub3d_etc(cub);
	init_tex(&(cub->texture));
	init_camera_field(&(cub->field), &(cub->camera));
	init_window_ray(&(cub->window), &(cub->ray));
	init_event(&(cub->event));
	init_sprite(&(cub->sprite));
	player_init(cub);
	if (!(cub->window.mlx_ptr = mlx_init()))
		stop_cub(cub, MLX_INIT_FAIL);
}
