/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:50:54 by rchiam            #+#    #+#             */
/*   Updated: 2026/04/17 22:56:55 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <string>
class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif