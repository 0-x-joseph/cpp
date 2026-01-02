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

#ifndef __ANIMAL__
#define __ANIMAL__

#include <string>

class Animal {
protected:
  std::string type;

public:
  Animal();
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);
  virtual ~Animal();

  virtual void makeSound() const;
  std::string getType() const;
};

#endif /* __ANIMAL__ */
