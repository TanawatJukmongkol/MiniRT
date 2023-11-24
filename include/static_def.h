/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:55:55 by tjukmong          #+#    #+#             */
/*   Updated: 2023/11/24 23:29:15 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

// Mask
# define STATIC_DESTROY          17

// Keycodes

# define X_EVENT_KEY_PRESS        2
# define X_EVENT_KEY_RELEASE    3
# define X_EVENT_KEY_EXIT        17
# ifdef __linux__
#  define KEY_CTRL            65507
#  define KEY_ENTER            65293
#  define KEY_SPACE            32
#  define KEY_ESC            65307
#  define KEY_LEFT            65361
#  define KEY_RIGHT            65363
#  define KEY_UP            65362
#  define KEY_DOWN            65364
#  define KEY_A                97
#  define KEY_S                115
#  define KEY_D                100
#  define KEY_W                119
#  define KEY_R                114
#  include <X11/keysym.h>
#  include <X11/X.h>
# else
#  define KEY_CTRL            256
#  define KEY_ENTER            36
#  define KEY_SPACE            49
#  define KEY_ESC            53
#  define KEY_LEFT            123
#  define KEY_RIGHT            124
#  define KEY_UP            126
#  define KEY_DOWN            125
#  define KEY_A                0
#  define KEY_S                1
#  define KEY_D                2
#  define KEY_W                13
#  define KEY_R                15
# endif

#endif
