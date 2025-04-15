/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:24:04 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/15 14:57:43 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
# include "Data.hpp"
# include <iostream>

//Serialization is the process of converting an object or data into a format that can be stored 
//or transferred and then reconstructed (deserialized) back into the original form.
class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const &other);
		Serializer &operator=(Serializer const &other);
		~Serializer(void);

	public:
		//uintptr_t is an unsigned integer type guaranteed to be large enough to hold a pointer. It comes from <cstdint>.
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif

