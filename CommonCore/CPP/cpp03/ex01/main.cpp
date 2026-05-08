/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 23:47:31 by rchiam            #+#    #+#             */
/*   Updated: 2026/05/08 23:22:16 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap a("Alpha");
	ClapTrap b("Beta");

	std::cout << "\n--- Basic actions ---" << std::endl;
	a.attack("Beta");
	b.takeDamage(3);
	b.beRepaired(2);

	std::cout << "\n--- No energy test ---" << std::endl;
	for (int i = 0; i < 11; i++)
		a.attack("Dummy");

	std::cout << "\n--- Death test ---" << std::endl;
	b.takeDamage(999);
	b.attack("Alpha");
	b.beRepaired(10);

	std::cout << "\n--- Copy test ---" << std::endl;
	ClapTrap c(a);
	ClapTrap d("Delta");
	d = b;

	std::cout << "\n--- End ---" << std::endl;
	return (0);
}
