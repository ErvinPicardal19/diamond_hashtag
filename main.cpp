#include <iostream>
#include <limits>

void draw(int n);

int main(int argc, const char* argv[])
{
   char input;
   while(1)
   {
      std::cout << "Enter number: ";
      std::cin >> input;
      
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      if(input == 113)
      {
         break;
      }
      else
      {
         if(input >= 48 && input <= 57)
         {
            draw(int(input - 48));
         }
         else
         {
            std::cout << "Invalid input" << std::endl;
         }
      }

   }
   return 0;
}

bool isOdd(int n)
{
   return (n%2)==0 ? false : true;
}

void draw(int n)
{
   int image_size = n+(n-1);
   char image[image_size/2][image_size];
   int max_square_range = isOdd(n) ? ((image_size/2)+(n/2))+1 : ((image_size/2)+(n/2));
   for(int y=0; y<=(image_size/2); y++)
   {
      for(int x=0; x<image_size; x++)
      {
         if(
            (x >= ((image_size/2)-y)) &&
            (x <= ((image_size/2)+y))
            )
         {
            if(x >= (n/2) && x < max_square_range && y>=(n/2))
            {
               image[y][x] = '#';
            }
            else
            {
               image[y][x] = '*';
            }
         }
         else
         {
            image[y][x] = ' ';
         }
      }
   }

   for(int y=0; y<=(image_size/2); y++)
   {
      for(int x=0; x<image_size; x++)
      {
         std::cout << image[y][x];
      }
      std::cout << std::endl;
   }
   for(int y=(image_size/2)-1; y>=0; y--)
   {
      for(int x=0; x<image_size; x++)
      {
         std::cout << image[y][x];
      }
      std::cout << std::endl;
   }
}