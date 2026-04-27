/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:52:00 by rchiam            #+#    #+#             */
/*   Updated: 2026/04/27 22:24:29 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string type);
        ~Weapon();
        const std::string &getType();
        void setType(std::string type);
};
#endif
