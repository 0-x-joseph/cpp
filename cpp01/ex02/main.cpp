/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:45:17 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/24 22:48:24 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <string>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << "string address    : " << &str << std::endl;
  std::cout << "string ptr address: " << stringPTR << std::endl;
  std::cout << "string ref address: " << &stringREF << std::endl;

  std::cout << std::endl;

  std::cout << "string content    : " << str << std::endl;
  std::cout << "string ptr content: " << *stringPTR << std::endl;
  std::cout << "string ref content: " << stringREF << std::endl;

  return (0);
}
