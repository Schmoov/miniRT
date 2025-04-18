#include "../inc/model.h"

bool model_init(t_model *mod)
{
	ft_memset(mod, 0, sizeof(t_model));
	return true;
}

void	model_destroy(t_model *mod)
{
}

void model_set_cam(t_model *mod, t_camera *cam)
{
	mod->cam.pos[0] = cam->pos.x;
	mod->cam.pos[1] = cam->pos.y;
	mod->cam.pos[2] = cam->pos.z;
	mod->cam.dir[0] = cam->orientation.x;
	mod->cam.dir[1] = cam->orientation.y;
	mod->cam.dir[2] = cam->orientation.z;
	mod->cam.fov = cam->fov;
}

void model_set_ambient(t_model *mod, t_ambient_lighting *amb)
{
	mod->amb.lum = amb->ratio;
	mod->amb.col = (amb->color.r << 8) | (amb->color.g << 4) | amb->color.b;
}

void model_add_light(t_model *mod, t_light *l)
{
	int i;

	i = mod->lit_nb;
	mod->lit[i].pos[0] = l->pos.x;
	mod->lit[i].pos[1] = l->pos.y;
	mod->lit[i].pos[2] = l->pos.z;
	mod->lit[i].lum = l->brightness;
	mod->lit[i].lum = l->brightness;
	mod->lit[i].col = (l->color.r << 8) | (l->color.g << 4) | l->color.b;
	mod->lit_nb++;
}

void model_add_plane(t_model *mod, t_plane *p)
{
	t_pla	*obj;

	mod->obj[mod->obj_nb].type = PLA;
	obj = &(mod->obj[mod->obj_nb].pla);
	obj->pos[0] = p->pos.x;
	obj->pos[1] = p->pos.y;
	obj->pos[2] = p->pos.z;
	obj->nor[0] = p->axis.x;
	obj->nor[1] = p->axis.y;
	obj->nor[2] = p->axis.z;
	obj->col = (p->color.r << 8) | (p->color.g << 4) | p->color.b;
	mod->obj_nb++;
}

void model_add_sphere(t_model *mod, t_sphere *s)
{
	t_sph	*obj;

	mod->obj[mod->obj_nb].type = SPH;
	obj = &(mod->obj[mod->obj_nb].sph);
	obj->pos[0] = s->pos.x;
	obj->pos[1] = s->pos.y;
	obj->pos[2] = s->pos.z;
	obj->rad = s->diameter / 2;
	obj->col = (s->color.r << 8) | (s->color.g << 4) | s->color.b;
}

void model_add_cylinder(t_model *mod, t_cylinder *c)
{
	t_cyl	*obj;

	mod->obj[mod->obj_nb].type = CYL;
	obj = &(mod->obj[mod->obj_nb].cyl);
	obj->pos[0] = c->pos.x;
	obj->pos[1] = c->pos.y;
	obj->pos[2] = c->pos.z;
	obj->ax[0] = c->axis.x;
	obj->ax[1] = c->axis.y;
	obj->ax[2] = c->axis.z;
	obj->rad = c->diameter / 2;
	obj->hgt = c->height / 2;
	obj->col = (c->color.r << 8) | (c->color.g << 4) | c->color.b;
	mod->obj_nb++;
}

/*
t_rgb *model_compute(t_mod *mod)
{
	//for pixel in img {
	//	Point p = inter(ray, mod);
	//	res[pixel] = compute_light(p);
	//}
	return img;
}

// inter(ray, mod) {
// float best = -1;
// Point res;
// 		for (obj in mod->obj)
// 			if (inter_obj(obj, ray) < best)
// 				best = inter
//
// 		return best;
// }
*/
