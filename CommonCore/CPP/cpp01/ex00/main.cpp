/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:50:39 by rchiam            #+#    #+#             */
/*   Updated: 2026/04/25 18:28:36 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* heapzombie = newZombie("HeapZombie");
	heapzombie->announce();
	delete heapzombie;
	randomChump("StackZombie");
	return (0);
}