/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:52:39 by rchiam            #+#    #+#             */
/*   Updated: 2026/04/20 15:43:48 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"
class HumanB
{
    private:
        std::string type;
        Weapon *weapon;
    public:
    HumanB(std::string name, Weapon *weapon);
    ~HumanB();
    void attack();
};
#endif