#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

int		set_direction(char input, double* turn_dir, double* walk_dir);
void	normalize_angle(double *angle);
void	print_message(char input);

int main(void) 
{
	char	input;
	double	px = 25;
	double	py = 25;
	double	nx;
	double	ny;
	double	turn_dir;
	double	walk_dir;
	double	turn_speed = 5 * (PI / 180);
	double	walk_speed = 1;
	double	angle = PI * 2;

	printf("px : %f py : %f\n", px, py);
    while (1) 
	{
        if (scanf("%c", &input) == EOF)
            exit(1);
        if (set_direction(input, &turn_dir, &walk_dir))
		{
			printf("w a s d q e를 입력해주세요\n");
			continue;
		}
        double rotation = turn_dir * turn_speed;
        angle += rotation;
		normalize_angle(&angle);
		double move_step = walk_dir * walk_speed;
		if (input == 'w' || input == 's')
		{
			nx = px + move_step * cos(angle);
			ny = py + move_step * sin(angle);
		}
		else if (input == 'a' || input == 'd')
		{
			nx = px + move_step * sin(angle);
			ny = py + move_step * cos(angle);
		}
		else
		{
			nx = px;
			ny = py;
		}
        px = nx;
		py = ny;
		printf("nx : %f ny : %f angle : %f\n", px, py, angle * (180 / PI));
		print_message(input);
        fflush(stdin);
		walk_dir = 0;
		turn_dir = 0;
    }
	return 0;
}

int	set_direction(char input, double* turn_dir, double* walk_dir) {
	if (input == 'w') //up
		*walk_dir = -1;
	else if (input == 's') //down
		*walk_dir = 1;
	else if (input == 'q') //turn left
		*turn_dir = -1;
	else if (input == 'e') //turn right
		*turn_dir = 1;
	else if (input == 'a') //left
		*walk_dir = -1;
	else if (input == 'd') //right
		*walk_dir = 1;
	else
		return (1);
	return (0);
		
}

void	normalize_angle(double *angle)
{
	if (*angle >= 0)
		while (*angle >= 2 * PI)
			*angle -= 2 * PI;
	else
		while (*angle <= 0)
			*angle += 2 * PI;
}

void	print_message(char input)
{
	if (input == 'w') //up
		printf("캐릭터가 위로 움직였습니다\n");
	else if (input == 's') //down
		printf("캐릭터가 아래로 움직였습니다\n");
	else if (input == 'q') //turn left
		printf("캐릭터가 왼쪽으로 고개를 돌렸습니다\n");
	else if (input == 'e') //turn right
		printf("캐릭터가 오른쪽으로 고개를 돌렸습니다\n");
	else if (input == 'a') //left
		printf("캐릭터가 왼쪽으로 움직였습니다\n");
	else if (input == 'd') //right
		printf("캐릭터가 오른쪽으로 움직였습니다\n");
	else
		printf("???\n");
}
