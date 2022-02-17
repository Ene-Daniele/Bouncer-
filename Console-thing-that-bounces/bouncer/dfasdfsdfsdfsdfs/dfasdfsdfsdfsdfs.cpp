#include <iostream>
#include <string>

int main() {

	const int size = 20; //Matrix size
	std::string matrix[size][size];
	std::string bouncer = "";
	std::cout << "Input bouncer: ";
	std::cin >> bouncer; //User chooses the shape of the bouncer

	//Physics
	int grv = 1;
	int vsp = 0;
	int x = 10;
	int y = 0;

	//Initialize the matrix
	for (int i = 0; i < size; i++) { //Initialize the matrix
		for (int j = 0; j < size; j++) {
			matrix[i][j] = "     ";
		}
	}

	int frames = 0; //Needed to control the update speed
	while (true) {
		frames++;

		if (frames > 2) {
			frames = 0;

			matrix[y][x] = "     "; //Reset the last position of the bouncer
			vsp += grv; // Gravitational acceleration
			if (y + vsp < 20) {
				y += vsp;
			} else { //If y + vsp is bigger than 19, then bring y to 19 one by one
				while (y < 19) {
					y++;
				}
				vsp *= -1; //Bounce the bouncer once it reaches 19
			}
			matrix[y][x] = bouncer; //Update the bouncers position in the matrix
		}

		system("CLS"); //Clear the terminal
		for (int i = 0; i < size; i++) { //Update the terminal
			for (int j = 0; j < size; j++) {
				std::cout << matrix[i][j];
			}
			std::cout << "\n";
		}
	}
}
