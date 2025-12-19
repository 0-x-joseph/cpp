/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:09:23 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/24 22:09:55 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE__
#define __ZOMBIE__

#include <string>

class Zombie {

public:
  void setName(std::string &n);

  void announce(void);

  ~Zombie(void);

private:
  std::string name;
};

#endif /* __ZOMBIE__ */
