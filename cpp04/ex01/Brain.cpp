/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:49:34 by ybouryal          #+#    #+#             */
/*   Updated: 2026/01/06 18:01:53 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() { std::cout << "Brain default constructor called" << std::endl; }

Brain::Brain(const Brain &other) {
  for (int i = 0; i < MAX_IDEAS; i++) {
    this->ideas[i] = other.ideas[i];
  }
  std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
  if (this != &other) {
    for (int i = 0; i < MAX_IDEAS; i++) {
      this->ideas[i] = other.ideas[i];
    }
  }
  std::cout << "Brain copy assignement operator called" << std::endl;
  return *this;
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }
