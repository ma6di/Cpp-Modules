/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyList.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:28:09 by mhuszar           #+#    #+#             */
/*   Updated: 2025/04/30 13:58:27 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIST_HPP
# define MYLIST_HPP

#include <iostream>


template <class Container>
struct Node
{
    Container cont;
    struct Node *next;
    struct Node *prev;
    int idx;
};

template <class Container>
class MyList
{
    public:
        
        MyList(void);
        MyList(int argc, char **argv);
        ~MyList(void);

        Container&  operator[](int index);
        void        init_list_head(int argc, char **argv, bool print);
        void        setup_next_depth();
        void        eliminate_empty_nodes();
        int         size();
        void        display_list();
        void        print_content(int index);

        
    private:

        MyList(const MyList& other);
        MyList& operator=(const MyList& other);

        void    attach_new_node(int cont_size);
        int     get_smallest_cont_size();
        void    delete_internal_list();

        int             old_size;
        int             internal_list_size;
        Node<Container> *internal_list_head;
};

#include "MyList.tpp"

#endif