/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 10:43:06 by hthomas           #+#    #+#             */
/*   Updated: 2024/04/03 08:07:53 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <fcntl.h>
#include <unistd.h>


unsigned char	*file_header_bmp(int filesize)
{
	unsigned char	*bmpfileheader;

	bmpfileheader = (unsigned char*) malloc(14 * sizeof(unsigned char));
	ft_memcpy(bmpfileheader, (char[]){'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0}, 14);
	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);
	return (bmpfileheader);
}

unsigned char	*info_header_bmp(void)
{
	unsigned char	*bmpinfoheader;

	bmpinfoheader = (unsigned char*) malloc(40 * sizeof(unsigned char));
	ft_memcpy(bmpinfoheader, (char[]){40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 32,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0}, 40);
	bmpinfoheader[4] = (unsigned char)(WIDTH);
	bmpinfoheader[5] = (unsigned char)(WIDTH >> 8);
	bmpinfoheader[6] = (unsigned char)(WIDTH >> 16);
	bmpinfoheader[7] = (unsigned char)(WIDTH >> 24);
	bmpinfoheader[8] = (unsigned char)(HEIGHT);
	bmpinfoheader[9] = (unsigned char)(HEIGHT >> 8);
	bmpinfoheader[10] = (unsigned char)(HEIGHT >> 16);
	bmpinfoheader[11] = (unsigned char)(HEIGHT >> 24);
	return (bmpinfoheader);
}

void	write_data(int f, const unsigned char *data)
{
	int 			line;

	line = HEIGHT;
	while(--line + 1)
		write(f, data + WIDTH * line * 4, WIDTH * 4);
}

void	save_bmp(const char *filename, const unsigned char *data)
{
	int				filesize;
	int				f;
	unsigned char	*bmpfileheader;
	unsigned char	*bmpinfoheader;

	filesize = 14 + 40 + 3 * WIDTH * HEIGHT;
	f = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0755);
	bmpfileheader = file_header_bmp(filesize);
	write(f, bmpfileheader, 14);
	free(bmpfileheader);
	bmpinfoheader = info_header_bmp();
	write(f, bmpinfoheader, 40);
	free(bmpinfoheader);
	write_data(f, data);
	close(f);
}
