/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:02:04 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/02 21:08:26 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

/*
 * Animations
 */
# define FRAMES_PER_STEP	24

/*
 * Colors
 */
# define MAGENTA	0x00FF00FF
# define ORANGE		0x00FF8800
# define RED		0x00FF0000
# define BLACK		0x00000000
# define SILVER		0x00C0C0C0
# define CYPRUS		0x00404040

/*
 * Minimap constants
 */
# define MINIMAP_SIZE		160
# define CELL_SIZE			8
# define OFFSET_X			20
# define OFFSET_Y			20
# define BORDER_THICKNESS	2

/*
 * Minimap colors
 */
# define BORDER_COLOR	BLACK
# define FOV_COLOR		ORANGE
# define PLAYER_COLOR	RED
# define PLAYER_SIZE	3

/* Door colors (closed / open) */
# define DOOR_COLOR			ORANGE
# define OPEN_DOOR_COLOR	SILVER

/*
 * Minimap raycasting
 */
# define RAY_STEP	0.05

/*
 *Exit constants
 */
# define SUCCESS	0
# define ERROR		1
/*
 * Window dimensions (fullscreen mode for macOS)
 * Common resolutions: 1920x1080, 1920x1200, 2560x1440
 */
# define WDW_HEIGHT	950
# define WDW_WIDTH	1710

/*
 * Key constants (macOS keycodes)
 */
# define ESC		53

/*
 * W A S D (ZQSD sur AZERTY, WASD sur QWERTY)
 */
# define UP			13
# define LEFT		0
# define DOWN		1
# define RIGHT		2
# define KEY_E		14
# define KEY_P		35

/*
 * Arrows
 */
# define ARR_UP		126
# define ARR_LEFT	123
# define ARR_DOWN	125
# define ARR_RIGHT	124

#endif /* CONSTANTS_H */
