/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:48:33 by ybouryal          #+#    #+#             */
/*   Updated: 2026/01/02 20:50:23 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG__
#define __DOG__

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
private:
  Brain *brain;

public:
  Dog();
  Dog(const Dog &other);
  Dog &operator=(const Dog &other);
  ~Dog();

  void makeSound() const;
};

#endif /* __DOG__ */
