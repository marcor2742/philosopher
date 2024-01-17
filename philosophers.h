/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:21:31 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/17 18:13:20 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
#include <stdio.h>

typedef struct	s_lock
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	int ledger;
}				t_lock;

#endif