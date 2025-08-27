/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 08:50:29 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/27 08:52:18 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL__
# define __HARL__

# include <string>

class Harl {
public:

	Harl(void);

	void complain( std::string level );

	~Harl(void);

private:

	void debug( void );

	void info( void );

	void warning( void );

	void error( void );

};

#endif /* __HARL__ */
