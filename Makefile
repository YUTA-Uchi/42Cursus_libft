SOURCE			:=	ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
 					ft_isprint.c \
					ft_itoa.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putchar_fd.c \
 					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
					ft_split.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_striteri.c \
					ft_strjoin.c \
 					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
 					ft_strtrim.c \
					ft_substr.c \
					ft_tolower.c \
					ft_toupper.c
OBJ_DIR			:=	./obj
OBJECT			:=	$(SOURCE:%.c=$(OBJ_DIR)/%.o)
BONUS			:=	ft_lstnew_bonus.c \
					ft_lstadd_front_bonus.c \
					ft_lstsize_bonus.c \
					ft_lstlast_bonus.c \
					ft_lstadd_back_bonus.c \
 					ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstmap_bonus.c
BONUS_OBJECT	:=	$(BONUS:%.c=$(OBJ_DIR)/%.o)
PRINTF_SRCS		:=	ft_printf.c \
					ft_printf_utils.c \
					ft_printf_output.c
PRINTF_OBJECT	:=	$(PRINTF_SRCS:%.c=$(OBJ_DIR)/%.o)
HEADER			:=	libft.h
NAME			:=	libft.a
CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror
CPPFLAGS		:=	-I.

ifdef WITH_BONUS
	SOURCE		+=	$(BONUS)
	OBJECT		+=	$(BONUS_OBJECT)
endif

ifdef WITH_PRINTF
	SOURCE		+=	$(PRINTF_SRCS)
	OBJECT		+=	$(PRINTF_OBJECT)
endif

.PHONY: clean fclean re all bonus

$(NAME): $(OBJECT)
	ar rcs $(NAME) $(OBJECT)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all: $(NAME)

bonus:
	$(MAKE) WITH_BONUS=1

printf:
	$(MAKE) WITH_PRINTF=1

complete:
	$(MAKE) WITH_BONUS=1 WITH_PRINTF=1

clean:
	$(RM) -r $(OBJECT) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

