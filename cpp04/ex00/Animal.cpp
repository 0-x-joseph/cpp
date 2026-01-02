/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:42:14 by ybouryal          #+#    #+#             */
/*   Updated: 2026/01/02 20:48:16 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
  *this = other;
  std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
  if (this != &other) {
    this->type = other.type;
  }
  std::cout << "Animal assignment operator called" << std::endl;
  return *this;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

void Animal::makeSound() const {
  std::cout << "Default Animal sound" << std::endl;
}

std::string Animal::getType() const { return this->type; }
