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
		while ((fscanf(fp, "%c %f %f %f %f %c", &r, &x, &y, &w, &h, &c2) == 6)
		&& ((ret = fread(&k, 1, 1, fp)) || !ret)
		&& ((k == '\n') || !ret))
		{
			i = 0;
			j = 0;
			dprintf(1, "%f %f %f %f", x, y, w, h);
			while (i < width)
			{
				while (j < height)
				{
					float cx = fabsf(i - (x - w / 2)); 
					float cy = fabsf(j - (y - h / 2));
					float csq = pow((cx - w / 2), 2) + pow((cy - h / 2), 2);

					if (cx > (w / 2 + 1))
						;
					else if (cy > (h / 2 + 1))
						;
					else if (cx <= w / 2)
						tab[j][i] = c2;
					else if (cy <= h / 2)
						tab[j][i] = c2;
					else if (csq < 1)
						tab[j][i] = c2;
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