/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_champ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:12:12 by mdamesto          #+#    #+#             */
/*   Updated: 2017/03/18 18:12:13 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

uint8_t			*convert_strhex_to_hex(char *str, int size_champ)
{
	uint8_t	*ret;
	int		i;
	char	tmp[3];

	ret = (uint8_t*)ft_strnew(size_champ);
	i = 0;
	tmp[2] = '\0';
	while (*str && i <= size_champ)
	{
		ft_strncpy(tmp, str, 2);
		ret[i++] = ft_atoi_hex(tmp);
		str += 2;
	}
	return (ret);
}

static uint8_t	*get_full_insts(t_env *env)
{
	char	*insts;
	t_inst	*tmp_inst;
	char	*to_free;

	insts = ft_strnew(1);
	tmp_inst = env->inst;
	if (!tmp_inst)
		ft_error(E_CHMP_NULL);
	while (tmp_inst)
	{
		to_free = insts;
		insts = ft_strjoin(insts, tmp_inst->content);
		tmp_inst = tmp_inst->next;
		if (to_free)
			free(to_free);
	}
	return (convert_strhex_to_hex(insts, env->c_adress));
}

uint32_t		convert_be(uint32_t data)
{
	uint32_t	ret;

	ret = (uint32_t)((data << 24) | ((data >> 8) << 16) \
	| ((data >> 16) << 8) | (data >> 24));
	return (ret);
}

#define ABS(x) (((x) < 0) ? -(x) : (x))

void			create_champion(t_env *env)
{
	int			fd_cor;
	uint8_t		h[sizeof(t_header) + env->c_adress];
	uint8_t		*prog;
	size_t		siz;
	uint32_t	champ_siz;

	ft_memset(&h[0], 0x42, sizeof(t_header));
	ft_memcpy(&h[0], "\x00\xEA\x83\xF3", 4);
	siz = ft_strlen(env->header->prog_name);
	ft_memcpy(&h[4], env->header->prog_name, siz);
	ft_memset(&h[siz + 4], '\0', PROG_NAME_LENGTH - siz + 4);
	champ_siz = convert_be(env->c_adress);
	ft_memcpy(&h[PROG_NAME_LENGTH + 8], &champ_siz, 4);
	siz = ft_strlen(env->header->comment);
	ft_memcpy(&h[PROG_NAME_LENGTH + 12], env->header->comment, siz);
	ft_memset(&h[PROG_NAME_LENGTH + 12 + siz], '\0', COMMENT_LENGTH - siz + 4);
	prog = get_full_insts(env);
	ft_memcpy(&h[PROG_NAME_LENGTH + COMMENT_LENGTH + 16], prog, env->c_adress);
	fd_cor = open(ft_strjoin(env->filename, ".cor")\
	, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	write(fd_cor, &h[0], sizeof(t_header) + env->c_adress);
	ft_putstr("Writing output program to ");
	ft_putstr(ft_strjoin(env->filename, ".cor"));
	ft_putstr("\n");
}
