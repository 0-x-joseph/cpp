/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:00:28 by ybouryal          #+#    #+#             */
/*   Updated: 2026/01/06 18:21:07 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() {
  this->type = "Cat";
  this->brain = new Brain();
  std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other) {
  this->brain = new Brain(*other.brain);
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
  if (this != &other) {
    this->type = other.type;

    Brain *new_brain = new Brain(*other.brain);

    delete this->brain;

    this->brain = new_brain;
  }

  std::cout << "Cat assignment operator called" << std::endl;
  return *this;
}

Cat::~Cat() {
  delete this->brain;
  std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const { std::cout << "Meow Meow Meow..." << std::endl; }
