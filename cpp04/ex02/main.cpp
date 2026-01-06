/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:25:37 by ybouryal          #+#    #+#             */
/*   Updated: 2026/01/06 18:22:48 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  const AAnimal *j = new Dog();
  const AAnimal *i = new Cat();
  const int size = 50;
  const AAnimal *animals[size];

  for (int k = 0; k < size; k++) {
    if (k < size / 2)
      animals[k] = new Dog();
    else
      animals[k] = new Cat();
  }
  delete j;
  delete i;

  for (int k = 0; k < size; k++) {
    animals[k]->makeSound();
  }

  for (int k = 0; k < size; k++) {
    delete animals[k];
  }
  return 0;
}
