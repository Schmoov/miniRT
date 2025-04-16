bool model_init(t_model *mod)
{
	ft_memset(mod, 0, sizeof(mod));
	mod->img = malloc(W*H*sizeof(t_rgb));

	return mod->img;
}

void	model_destroy(t_model *mod)
{
	free(mod->img);
}

void model_add_pl(float p[3], float n[3], t_rgb col)
{

}

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
