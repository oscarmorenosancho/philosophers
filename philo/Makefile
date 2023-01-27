# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 16:36:01 by omoreno-          #+#    #+#              #
#    Updated: 2023/01/27 16:27:42 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

SRC_R := philo.c\
forks.c\
threads.c\
ft_init_philo.c\
ft_philo_behavior.c\
ft_take_args.c\
ft_atoi.c\
ft_strlen.c\
ft_time_diff.c\
ft_print_event.c\
ft_update_dead.c\
ft_get_timestamp.c

SRC_PATH := 
SRC := ${addprefix $(SRC_PATH), $(SRC_R)}

OBJ := $(SRC:.c=.o)
DEPS := $(SRC:.c=.d)
CC	:= 	gcc
CFLAGS := -Wall -Werror -Wextra
CFD := -MMD
RM	:= 	rm -f
HEADER := ${addprefix $(SRC_PATH), philo.h}

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} ${CFD} -I ${HEADER} -c $< -o $@

all : $(NAME)

-include $(DEPS)
$(NAME) : ${OBJ} 
	${CC} ${CFLAGS} -I ${HEADER} ${OBJ} -o $@

clean :
	$(RM) $(OBJ)
	$(RM) $(DEPS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY : clean fclean re all bonus