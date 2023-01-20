# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 16:36:01 by omoreno-          #+#    #+#              #
#    Updated: 2023/01/20 16:46:46 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
NAMEB := ${addsuffix _bonus, $(NAME)}

SRC_R := philo.c\
forks.c\
ft_init_philo.c\
ft_philo_behavior.c\
ft_start_threads.c\
ft_take_args.c\
ft_atoi.c\
ft_strlen.c

SRCB_R := 

SRC_PATH := philo/
SRCB_PATH := philo_bonus/
SRC := ${addprefix $(SRC_PATH), $(SRC_R)}
SRCB := ${addprefix $(SRCB_PATH), $(SRCB_R)}

OBJ := $(SRC:.c=.o)
OBJB := $(SRCB:.c=.o)
DEPS := $(SRC:.c=.d)
DEPSB := $(SRCB:.c=.d)
CC	:= 	gcc
CFLAGS := -Wall -Werror -Wextra
CFD := -MMD
RM	:= 	rm -f
HEADER := ${addprefix $(SRC_PATH), philo.h}
HEADERB := ${addprefix $(SRCB_PATH), philo_bonus.h}

philo/%.o : src/%.c ${HEADER}
	${CC} ${CFLAGS} ${CFD} -I ${HEADER} -c $< -o $@

philo_bonus/%.o : src_bonus/%.c ${HEADERB}
	${CC} ${CFLAGS} ${CFD} -I ${HEADERB} -c $< -o $@

all : $(NAME)
bonus : $(NAMEB)

-include $(DEPS)
$(NAME) : ${OBJ} 
	${CC} ${CFLAGS} -I ${HEADER} ${OBJ} -o $@

-include $(DEPSB)
$(NAMEB): ${LIBFT_A} ${MLX_A} ${OBJC} ${OBJB}
	${CC} ${CFLAGS} -I ${HEADERB} ${OBJB} -o $@

clean :
	$(RM) $(OBJ)
	$(RM) $(OBJB)
	$(RM) $(DEPS)
	$(RM) $(DEPSB)
	$(RM) *.o
	$(RM) *.d

fclean : clean
	$(RM) $(NAME)
	$(RM) $(NAMEB)

re: fclean all

.PHONY : clean fclean re all bonus