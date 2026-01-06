#include <iostream>

using namespace std;

void display(char image[][11], int width, int height) 
{

    for (int r=0; r < height; ++r) {

        for (int c=0; c < width; ++c) {
        
           cout << image[r][c];            
        
        }        
        
        cout << endl;

    }

}



void flipHorizontal(char image[][11], int width, int height) 
{
    int temp =0;
    for(int k = 0; k<height-1; ++k)
    {

        for(int i=0; i<=width/2; ++i)
        {
            temp = image[k][width-i-1];
            image[k][width-i-1] = image[k][i];
            image[k][i] = temp;
        }
    }


}


void flipVertical(char image[][11], int width, int height) 
{
int temp =0;
    for(int k = 0; k<width-1; ++k)
    {

        for(int i=0; i<=height/2; ++i)
        {
            temp = image[width-i-1][k];
            image[width-i-1][k] = image[i][k];
            image[i][k] = temp;
        }
    }
    
}



int main() {

    string horizontalImageAsStrings[] = 
        {
	          "+---------+",
	          "|         |",
	          "|         |",
	          "|      *  |",
	          "|       * |",
	          "|******* *|",
	          "|       * |",
	          "|      *  |",
	          "|         |",
	          "|         |",
	          "+---------+"
	    };


    string verticalImageAsStrings[] = 
        {
	          "+---------+",
	          "|    *    |",
	          "|   * *   |",
	          "|  * * *  |",
	          "|    *    |",
	          "|    *    |",
	          "|    *    |",
	          "|    *    |",
	          "|    *    |",
	          "|    *    |",
	          "+---------+"
	    };

    
    const int WIDTH  = 11;
    const int HEIGHT = 11;

    char horizontalImage[HEIGHT][WIDTH];
    char verticalImage[HEIGHT][WIDTH];

    
    // Converst the string-based image to the character-based image.
    //
    for (int r=0; r < HEIGHT; ++r) {

        for (int c=0; c < WIDTH; ++c) {

            horizontalImage[r][c] = horizontalImageAsStrings[r][c];

            verticalImage[r][c] = verticalImageAsStrings[r][c];

        }

    }


    display(horizontalImage, WIDTH, HEIGHT);

    flipHorizontal(horizontalImage, WIDTH, HEIGHT);

    display(horizontalImage, WIDTH, HEIGHT);

    cout << endl << endl << endl;

    display(verticalImage, WIDTH, HEIGHT);

    flipVertical(verticalImage, WIDTH, HEIGHT);

    display(verticalImage, WIDTH, HEIGHT);


    return 0;

}
