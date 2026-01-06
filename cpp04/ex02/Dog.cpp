/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:51:12 by ybouryal          #+#    #+#             */
/*   Updated: 2026/01/06 18:20:53 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog() {
  this->type = "Dog";
  this->brain = new Brain();
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other) {
  this->brain = new Brain(*other.brain);
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
  if (this != &other) {
    this->type = other.type;

    Brain *new_brain = new Brain(*other.brain);

    delete this->brain;

    this->brain = new_brain;
  }

  std::cout << "Dog assignment operator called" << std::endl;
  return *this;
}

Dog::~Dog() {
  delete this->brain;
  std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const { std::cout << "Bark Bark Bark..." << std::endl; }
