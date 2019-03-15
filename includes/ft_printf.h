/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:01:05 by bsprigga          #+#    #+#             */
/*   Updated: 2019/02/07 14:09:04 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "colors.h"
# include <stdarg.h>
# include <wchar.h>

# define TRUE 1
# define FALSE 0
# define INT_SPECS "bdiouxX"
# define FLOAT_SPECS "aefg"
# define STR_CHR_SPECS "sc"
# define FLAGS "-+ #0"
# define ERR_BAD_SPEC -1
# define ERR_NO_SPEC -2

enum	e_size		{L_NONE, L_LB, L_HH, L_H, L_Z, L_LL, L_J, L_T, L_L};

typedef struct		s_format
{
	char			*curr_flags;
	int				width_value;
	int				prec_value;
	int				null_c_len;
	int				type_p;
	int				big_f;
	enum e_size		size;
	char			type;
	char			*str;
}					t_format;

extern va_list		g_ap;
extern t_format		*g_f;
extern int			g_count;

int					ft_printf(const char *format, ...);
void				parse_print_format(char *format, int i);
int					parse_precision(const char *format_i);
int					parse_width(const char *format_i);
int					parse_size(const char *format_i);
int					parse_type(const char *format_i, int *spec_end);
int					parse_deprecated(const char *format_i, int *spec_end);
char				*make_size_string(char *str);
t_format			*g_f_new(void);
void				make_str();
void				make_str_di(void);
void				make_str_boux(void);
void				make_str_aefg(void);
void				make_str_s(void);
void				make_str_c(void);
void				make_str_p(void);
char				*ft_itoa_base_unsigned(unsigned long long n, int base);
void				clear_all_exit(int option);
char				*convert_af(long double tmp, int base);
int					count_decimal_len(char *str);
void				wchar_to_char(char *buffer, int *offset, wchar_t c);
int					wchar_strlen(wchar_t *str);
int					wchar_strlen_symbols(wchar_t *str);
void				upper_lower_aefg(char **str);
void				apply_plus_space_aefg(char **str);
void				apply_zero_aefg(char **str);
char				*write_nan_inf(double tmp);
void				upper_lower_xp(char **str);
char				apply_prefix_boux(char **str, unsigned long long tmp);
void				apply_zero_boux(char **str);
void				fix_prefix_2_16_boux(char **str, char num_sys,
					int len_ini_tmp_str);
void				fix_prefix_16_p(char **str, int len_ini_tmp_str);
void				adjust_width_c_null(char **str);
void				adjust_width_s(char **str);
void				apply_zero_s(char **str);
void				apply_zero_di(char **str);
char				*make_string_from_char(char c);
int					wint_size(wint_t c);
int					check_exclusion_symbol(wint_t c);
int					check_exclusion_symbols(wchar_t *str);
char				*check_colors(char *format, int *i);

void				write_ordinary_symbols(char *format, int i);
char				*parse_colors(char *format, int ord);
int					apply_text_edit(char *format, int j, int ord);

#endif
