/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 08:58:44 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/27 08:58:49 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
  Harl harl;
  if (ac != 2)
    harl.complain(av[0]);
  else
    harl.complain(av[1]);
  return (0);
}
