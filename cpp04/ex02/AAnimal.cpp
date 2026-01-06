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

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : type("Animal") {
  std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
  *this = other;
  std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
  if (this != &other) {
    this->type = other.type;
  }
  std::cout << "Animal assignment operator called" << std::endl;
  return *this;
}

AAnimal::~AAnimal() { std::cout << "Animal destructor called" << std::endl; }

std::string AAnimal::getType() const { return this->type; }
