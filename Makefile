NAME := libftprintf.a
INCLUDES := includes
SRCS := ft_printf.c \
		ft_memalloc.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memdel.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strchr_wo_zero.c \
		ft_strclr.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strncpy.c \
		ft_strnew.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_strstr.c \
		ft_strstr_to_find_zero.c \
		ft_strnstr.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strsplit.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_str_append_char.c \
		ft_str_append_str.c \
		ft_isin.c \
		ft_isinf.c \
		ft_isnan.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_itoa_long.c \
		ft_itoa_base.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_natural_pow.c \
		ft_sqrt.c \
		ft_sqrt_rational.c \
		ft_range.c \
		get_next_line.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstreverse.c \
		parse_format_part_1.c \
		parse_format_part_2.c \
		parse_format_part_3.c \
		parse_format_part_4.c \
		make_formatted_strings.c \
		make_di_string_part_1.c \
		make_di_string_part_2.c \
		make_boux_string_part_1.c \
		make_boux_string_part_2.c \
		make_boux_string_part_3.c \
		make_aefg_string_part_1.c \
		make_aefg_string_part_2.c \
		make_s_string_part_1.c \
		make_s_string_part_2.c \
		make_c_string_part_1.c \
		make_c_string_part_2.c \
		make_p_string_part_1.c \
		make_p_string_part_2.c \
		support_part_1.c \
		support_part_2.c \
		support_part_3.c \

OBJ := $(patsubst %c, %o, $(SRCS))
FLAGS := -Wall -Werror -Wextra
VPATH := . srcs
.PHONY := all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) 
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

# for every .o file in $(OBJ) use respective rule
%.o: %.c
	gcc -g -c $(FLAGS) $< -o $@ $(addprefix -I, $(INCLUDES))

test: all
	gcc -g srcs/main.c -lftprintf -L./ $(addprefix -I, $(INCLUDES)) -o a.out
# test: all
# 	gcc -g ./srcs/main.c -lftprintf -L./ $(addprefix -I, $(INCLUDES))

test2: all
	gcc -g tests.c -lftprintf -L./ $(addprefix -I, $(INCLUDES))

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all