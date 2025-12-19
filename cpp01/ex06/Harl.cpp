/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 08:53:07 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/27 08:57:56 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

unsigned Harl::simple_hash(const std::string &s) {
  unsigned h = 0;
  for (unsigned i = 0; i < s.size(); ++i)
    h = h * 31 + s[i];
  return h;
}

Harl::Harl(void) {}

void Harl::complain(std::string level) {
  switch (this->simple_hash(level)) {
  case 0x225cae:
    this->info();
    /* fall through */
  case 0x3de9e33:
    this->debug();
    /* fall through */
  case 0x6dd13b7c:
    this->warning();
    /* fall through */
  case 0x3f2d9e8:
    this->error();
    break;
  default:
    this->unknown();
    return;
  }
  std::cout << std::endl;
}

void Harl::debug(void) {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout
      << "I love having extra bacon for my"
      << " 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
      << std::endl;
}

void Harl::info(void) {
  std::cout << "[ INFO ]" << std::endl;
  std::cout << "I cannot believe adding extra bacon costs more money."
            << std::endl
            << "You didn’t put enough bacon in my burger! If you did, I "
               "wouldn’t be asking for more!"
            << std::endl;
}

void Harl::warning(void) {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout << "I think I deserve to have some extra bacon for free."
            << std::endl
            << "I’ve been coming for years, whereas you started working here "
               "just last month."
            << std::endl;
}

void Harl::error(void) {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

void Harl::unknown(void) {
  std::cout << "[ Probably complaining about insignificant problems ]"
            << std::endl;
}

Harl::~Harl(void) {}
