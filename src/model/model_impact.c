/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_impact.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:12:04 by parden            #+#    #+#             */
/*   Updated: 2025/05/22 18:09:26 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	impact_color(t_model *m, t_impact *imp)
{
	t_obj	*obj;

	obj = &(m->obj[imp->obj_idx]);
	if (obj->type == PLA)
		imp->col = obj->pla.col;
	if (obj->type == SPH)
		imp->col = obj->sph.col;
	if (obj->type == CYL)
		imp->col = obj->cyl.col;
	if (obj->type == CON)
		imp->col = obj->con.col;
	if (obj->type == DSK)
		imp->col = obj->dsk.col;
}

void	impact_normal(t_model *m, t_impact *imp)
{
	t_obj	*obj;

	obj = &(m->obj[imp->obj_idx]);
	if (obj->type == PLA)
		ft_memcpy(imp->normal, obj->pla.nor, sizeof(t_v3));
	if (obj->type == DSK)
		ft_memcpy(imp->normal, obj->dsk.nor, sizeof(t_v3));
	if (obj->type == SPH)
	{
		ft_memcpy(imp->normal, imp->pos, sizeof(t_v3));
		vec_sub(imp->normal, imp->normal, obj->sph.pos);
		vec_normalize(imp->normal);
	}
	if (obj->type == CYL)
	{
		t_v3	comp;
		ft_memcpy(imp->normal, imp->pos, sizeof(t_v3));
		vec_sub(imp->normal, imp->normal, obj->cyl.pos);
		ft_memcpy(comp, imp->normal, sizeof(t_v3));
		vec_scale(comp, obj->cyl.ax, vec_dot(imp->normal, obj->cyl.ax));
		vec_sub(imp->normal, imp->normal, comp);
		vec_normalize(imp->normal);
	}
	//caca
	if (obj->type == CON)
	{
		t_v3	comp;
		ft_memcpy(imp->normal, imp->pos, sizeof(t_v3));
		vec_sub(imp->normal, imp->normal, obj->con.pos);
		ft_memcpy(comp, imp->normal, sizeof(t_v3));
		vec_scale(comp, obj->con.ax, vec_dot(imp->normal, obj->con.ax));
		vec_sub(imp->normal, imp->normal, comp);
		vec_normalize(imp->normal);
	}

	if (vec_dot(imp->normal, imp->ray.dir) > 0)
		vec_opp(imp->normal);
}

void	model_impact_object(t_model *m, t_impact *imp, int i)
{
	float	old_scale;
	t_obj	*obj;

	old_scale = imp->scale;
	obj = &(m->obj[i]);
	if (obj->type == PLA)
		model_impact_plane(m, imp, &(obj->pla));
	if (obj->type == DSK)
		model_impact_disk(m, imp, &(obj->dsk));
	if (obj->type == SPH)
		model_impact_sphere(m, imp, &(obj->sph));
	if (obj->type == CYL)
		model_impact_cylinder(m, imp, &(obj->cyl));
	if (obj->type == CON)
		model_impact_cone(m, imp, &(obj->con));
	if (imp->scale < old_scale)
	{
		imp->obj_idx = i;
		imp->pos[0] = imp->scale * imp->ray.dir[0] + imp->ray.pos[0];
		imp->pos[1] = imp->scale * imp->ray.dir[1] + imp->ray.pos[1];
		imp->pos[2] = imp->scale * imp->ray.dir[2] + imp->ray.pos[2];
		impact_normal(m, imp);
		impact_color(m, imp);
	}
}

void	model_impact_plane(t_model *m, t_impact *imp, t_pla *pla)
{
	float	scale;
	t_v3	v_rp;

	if (fabsf(vec_dot(imp->ray.dir, pla->nor)) < EPS)
		return ;
	vec_sub(v_rp, pla->pos, imp->ray.pos);
	scale = vec_dot(v_rp, pla->nor)
		/ vec_dot(imp->ray.dir, pla->nor);
	if (scale > EPS && scale < imp->scale)
		imp->scale = scale;
}

void	model_impact_disk(t_model *m, t_impact *imp, t_dsk *dsk)
{
	float	scale;
	t_v3	v_rp;

	if (fabsf(vec_dot(imp->ray.dir, dsk->nor)) < EPS)
		return ;
	vec_sub(v_rp, dsk->pos, imp->ray.pos);
	scale = vec_dot(v_rp, dsk->nor)
		/ vec_dot(imp->ray.dir, dsk->nor);
	
	ft_memcpy(v_rp, imp->ray.pos, sizeof(t_v3));
	vec_move_along(v_rp, imp->ray.dir, scale);
	vec_sub(v_rp, v_rp, dsk->pos);
	if (scale > EPS && scale < imp->scale && vec_norm(v_rp) < dsk->rad)
		imp->scale = scale;
}

void	model_impact_sphere(t_model *m, t_impact *imp, t_sph *sph)
{
	t_v3	v_cr;
	float	dot2;
	float	delta;
	float	x1;
	float	x2;

	v_cr[0] = imp->ray.pos[0] - sph->pos[0];
	v_cr[1] = imp->ray.pos[1] - sph->pos[1];
	v_cr[2] = imp->ray.pos[2] - sph->pos[2];
	delta = 4 * (vec_dot(imp->ray.dir, v_cr) * vec_dot(imp->ray.dir, v_cr)
			- (vec_norm2(v_cr) - sph->rad * sph->rad));
	if (delta < EPS)
		return ;
	x1 = (-2 * vec_dot(imp->ray.dir, v_cr) + sqrt(delta))
		/ (2 * vec_norm2(imp->ray.dir));
	x2 = (-2 * vec_dot(imp->ray.dir, v_cr) - sqrt(delta))
		/ (2 * vec_norm2(imp->ray.dir));
	if (x2 > EPS && x2 < x1)
		x1 = x2;
	if (x1 > EPS && x1 < imp->scale)
		imp->scale = x1;
}

void	model_impact_cylinder(t_model *m, t_impact *imp, t_cyl *cyl)
{
	t_v3	v_rc;
	vec_sub(v_rc, imp->ray.pos, cyl->pos);
	t_v3	tmp1;
	vec_cross(tmp1, cyl->ax, v_rc);
	t_v3	tmp2;
	vec_cross(tmp2, cyl->ax, imp->ray.dir);
	float a = vec_norm2(tmp2);
	float b = 2 * vec_dot(tmp1, tmp2);
	float c = vec_norm2(tmp1) -cyl->rad * cyl->rad;
	float delta = b*b - 4*a*c;
	if (delta < EPS)
		return;
	float x1 = (-b + sqrt(delta)) / (2 * a);
	float x2 = (-b - sqrt(delta)) / (2 * a);

	t_v3 vx1;
	ft_memcpy(vx1, imp->ray.pos, sizeof(t_v3));
	vec_move_along(vx1, imp->ray.dir, x1);
	vec_sub(vx1, vx1, cyl->pos);
	float h1 = fabs(vec_dot(vx1, cyl->ax));
	t_v3 vx2;
	ft_memcpy(vx2, imp->ray.pos, sizeof(t_v3));
	vec_move_along(vx2, imp->ray.dir, x2);
	vec_sub(vx2, vx2, cyl->pos);
	float h2 = fabs(vec_dot(vx2, cyl->ax));

	if (x2 > EPS && x2 < x1 && h2 < cyl->hgt/2) {
		x1 = x2;
		h1 = h2;
	}
	if (x1 > EPS && x1 < imp->scale && h1 < cyl->hgt/2)
		imp->scale = x1;
}

void	model_impact_cone(t_model *m, t_impact *imp, t_con *con)
{
	t_v3	v_rc;
	vec_sub(v_rc, imp->ray.pos, con->pos);
	float a = pow(vec_dot(imp->ray.dir, con->ax), 2);
	a -= pow(cos(con->ang), 2);
	float b = 2 * (vec_dot(imp->ray.dir, con->ax) * vec_dot(v_rc, con->ax)
			- (vec_dot(imp->ray.dir, v_rc) * pow(cos(con->ang), 2)));
	float c = pow(vec_dot(v_rc, con->ax), 2)
			- vec_norm2(v_rc) * pow(cos(con->ang), 2);
	float delta = b*b - 4*a*c;
	if (delta < EPS)
		return;
	float x1 = (-b + sqrt(delta)) / (2 * a);
	float x2 = (-b - sqrt(delta)) / (2 * a);

	t_v3 vx1;
	ft_memcpy(vx1, imp->ray.pos, sizeof(t_v3));
	vec_move_along(vx1, imp->ray.dir, x1);
	vec_sub(vx1, vx1, con->pos);
	float h1 = fabs(vec_dot(vx1, con->ax));
	t_v3 vx2;
	ft_memcpy(vx2, imp->ray.pos, sizeof(t_v3));
	vec_move_along(vx2, imp->ray.dir, x2);
	vec_sub(vx2, vx2, con->pos);
	float h2 = fabs(vec_dot(vx2, con->ax));

	if (x2 > EPS && x2 < x1 && h2 < con->hgt) {
		x1 = x2;
		h1 = h2;
	}
	if (x1 > EPS && x1 < imp->scale && h1 < con->hgt)
		imp->scale = x1;
}
