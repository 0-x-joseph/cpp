/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:02:21 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/27 11:07:10 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->fp = 0;
}

Fixed::Fixed(int raw) {
	std::cout << "Copy constructor called" << std::endl;
	this->fp = raw;
};

Fixed& Fixed::operator=( const Fixed& c )
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this == &c)
		return (*this);
	this->fp = c.fp;
	return (*this);
}

int Fixed::getRawBits( void )
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fp);
}

int Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fp = raw;
	return (raw);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}
