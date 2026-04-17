/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:50:39 by rchiam            #+#    #+#             */
/*   Updated: 2026/04/17 22:58:23 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* heapzombie = newZombie("Foo");
	heapzombie->announce();
	delete heapzombie;
	randomChump("Bar");
	return (0);
}