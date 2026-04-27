/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:46:27 by rchiam            #+#    #+#             */
/*   Updated: 2026/04/27 22:23:02 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
    int N = 5;
    Zombie* horde = zombieHorde(N, "HordeZombieTest");
    if (horde == 0)
    {
        std::cout << "Failed to create zombie horde." << std::endl;
        return (1);
    }
    int i = 0;
    while (i < N)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return (0);
}

