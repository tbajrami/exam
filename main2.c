#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main (int ac, char **av)
{
	char k;
	int width;
	int height;
	char c;
	char d;
	FILE * fp;
	int ret;

	if (ac != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	fp = fopen (av[1], "r");
	if ((fscanf(fp, "%d %d %c", &width, &height, &c) == 3)
		&& ((ret = fread(&k, 1, 1, fp)) || !ret)
		&& ((k == '\n') || !ret)
		&& (width >= 0 && width <= 300 && height >= 0 && height <= 300))
	{
		char tab[height][width];
		char r;
		char c2;
		float w;
		float h;
		float x;
		float y;
        float ry;
		int i;
		int j;

		i = 0;
		j = 0;
		while (i < height)
		{
			while (j < width)
			{
				tab[i][j] = c;
				j++;
			}
			j = 0;
			i++;
		}
		while ((fscanf(fp, "%c %f %f %f %c", &r, &x, &y, &ry, &c2) == 5)
		&& ((ret = fread(&k, 1, 1, fp)) || !ret)
		&& ((k == '\n') || !ret))
		{
			i = 0;
			j = 0;
			dprintf(1, "%f %f %f", x, y, ry);
			while (i < width)
			{
				while (j < height)
				{
					float dist = sqrt((i - y) * (i - y) + (j - x) * (j - x));

                    if ((dist <= ry)
					{
						if (ry - dist < 1) && r = 'c')
                        	tab[j][i] = c2;
						else if (r == 'C')
							tab[j][i] = c2;
					}
                    j++;
				}
				j = 0;
				i++;
			}
		}
		i = 0;
		j = 0;
		while (i < height)
		{
			while (j < width)
			{
				dprintf(1, "%c", tab[i][j]);
				j++;
			}
			dprintf(1, "\n");
			j = 0;
			i++;
		}
	}
	fclose(fp);
	return(0);
}
