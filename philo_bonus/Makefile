# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 16:36:01 by omoreno-          #+#    #+#              #
#    Updated: 2023/01/31 14:28:05 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo_bonus

SRC_R := philo_bonus.c\
ft_take_args_bonus.c\
ft_atoi_bonus.c\
ft_strlen_bonus.c\
ft_time_diff_bonus.c\
ft_print_event_bonus.c\
ft_get_timestamp_bonus.c\
ft_update_dead_bonus.c\
ft_philo_behavior_bonus.c\
sem_bonus.c

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