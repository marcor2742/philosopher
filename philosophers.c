/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:21:56 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/17 18:17:40 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *do_philosophy(void *arg)
{
	t_lock *lock = (t_lock *)arg;
	pthread_mutex_lock(&lock->lock);
	lock->ledger += 1;
	pthread_mutex_unlock(&lock->lock);
	return (NULL);
}

int main(int argc, char **argv)
{
	t_lock lock;
	pthread_t	thread[100]; // array of threads forks
	lock.ledger = 0;
	int i;
	
	pthread_mutex_init(&lock.lock, NULL);
	i = 0;

	while (i < 100)
	{
		pthread_create(thread + i, NULL, do_philosophy, (void *)&lock); 
		
		i++;
	}
	i = 0;
	while (i < 100)
	{
		pthread_join(thread[i], NULL); // wait for thread to finish
		
		i++;
	}
	printf ("ledger: %d\n", lock.ledger);
	pthread_mutex_destroy(&lock.lock);
	return (0);
}