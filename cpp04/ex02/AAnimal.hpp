/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:23:06 by ybouryal          #+#    #+#             */
/*   Updated: 2026/01/02 20:44:36 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL__
#define __AANIMAL__

#include <string>

class AAnimal {
protected:
  std::string type;

public:
  AAnimal();
  AAnimal(const AAnimal &other);
  AAnimal &operator=(const AAnimal &other);
  virtual ~AAnimal();

  virtual void makeSound() const = 0;
  std::string getType() const;
};

#endif /* __AANIMAL__ */
