#include <stdlib.h>
#include <stdio.h>

int calcul(int ii[], int type, int w, int h, int width, int x, int y, int ori)
{

    if (type == 1)
    {
        if (x == 0 && y == 0)
        {
            return (2*ii[ori + w/2 + h*width] - ii[ori + w + h*width]);
        }
        else
        {
            if (x != 0 && y != 0)
            {
                return (2*ii[ori + w/2 + h*width] - ii[ori + w + h*width]
                        + ii[ori + w - width] - 2*[ori + w/2 - width]
                        - ii[ori - 1 + h*width] + ii[ori - 1 - width]);
            }
            else
            {
                if (x == 0)
                {
                    return (2*ii[ori + w/2 + h*width] - ii[ori + w + h*width]
                            + ii[ori + w - width] - 2*[ori + w/2 - width]);
                }
                else
                {
                    return (2*ii[ori + w/2 + h*width] - ii[ori + w + h*width]
                            - ii[ori - 1 + h*width]);
                }
            }
        }
    }

    if (type == 2)
    {
        if (x == 0 && y == 0)
        {
            return (ii[ori + w + h*width] - 2*ii[ori + (2*w)/3 + h*width]
                    + 2*ii[ori + w/3 h*width]);
        }
        else
        {
            if (x != 0 && y != 0)
            {
                return (ii[ori + w + h*width]
                        - 2*ii[ori + (2*w)/3 + h*width]
                        + 2*ii[ori + w/3 + h*width] - ii[ori + w - width]
                        + 2*ii[ori + (2*w)/3 - width] - 2*ii[ori + w/3 - width]
                        - ii[ori - 1 + h*width] + ii[ori - 1 - width]);
            }
            else
            {
                if (x == 0)
                {
                    return (ii[ori + w + h*width]
                            - 2*ii[ori + (2*w)/3 + h*width]
                            + 2*ii[ori + w/3 + h*width] - ii[ori + w - width]
                            + 2*ii[ori + (2*w)/3 - width]
                            - 2*ii[ori + w/3 - width]);
                }
                else
                {
                    return (ii[ori + w + h*width]
                            - 2*ii[ori + (2*w)/3 + h*width]
                            + 2*ii[ori + w/3 + h*width] - ii[ori - 1 + h*width]);
                }
            }
        }
    }

    if (type == 3)
    {
        if (x == 0 && y == 0)
        {
            return (2*ii[ori + w + (h/2)*width] - ii[ori + w + h*width]);
        }
        else
        {
            if (x != 0 && y != 0)
            {
                return (2*ii[ori + w + (h/2)*width] - ii[ori + w + h*width]
                        - ii[ori + w - width] + ii[ori - 1 + h*width]
                        - 2*ii[ori - 1 + (h/2)*width] + ii[ori - 1 - width]);
            }
            else
            {
                if (x == 0)
                {
                    return (2*ii[ori + w + (h/2)*width] - ii[ori + w + h*width]
                            - ii[ori + w - width]);
                }
                else
                {
                    return (2*ii[ori + w + (h/2)*width] - ii[ori + w + h*width]
                            + ii[ori - 1 + h*width]
                            - 2*ii[ori - 1 + (h/2)*width]); 
                }
            }
        }
    }

    if (type == 4)
    {
        if (x == 0 && y == 0)
        {
            return (ii[ori + w + h*width] - 2*[ori + w + ((2*h)/3)*width]
                    + 2*ii[ori + w + (h/3)*width]);
        }
        else
        {
            if (x != 0 && y != 0)
            {
                return (ii[ori + w + h*width] - 2*[ori + w + ((2*h)/3)*width]
                        + 2*ii[ori + w + (h/3)*width] - ii[ori - 1 + h*width]
                        + 2*ii[ori - 1 + ((2*h)/3)*width]
                        - 2*ii[ori - 1 + (h/3)*width]
                        - ii[ori + w - width] + ii[ori - 1 - width]);
            }
            else
            {
                if (x == 0)
                {
                    return (ii[ori + w + h*width]
                            - 2*[ori + w + ((2*h)/3)*width]
                            + 2*ii[ori + w + (h/3)*width] 
                            - ii[ori + w - width]);
                }
                else
                {
                    return (ii[ori + w + h*width]
                            - 2*[ori + w + ((2*h)/3)*width]
                            + 2*ii[ori + w] - ii[ori - 1 + h*width]
                            + 2*ii[ori - 1 + ((2*h)/3)*width]
                            - 2*ii[ori - 1 + (h/3)*width]); 
                }
            }
        }
    }

    if (type == 5)
    {
        if (x == 0 && y == 0)
        {
            return (ii[ori + w + h*width] - 2*ii[ori + w/2 + h*width]
                    - 2*ii[ori + w + (h/2)*width]
                    + 4*ii[ori + w/2 + (h/2)*width]);
        }
        else
        {
            if (x != 0 && y != 0)
            {
                return (ii[ori + w + h*width] - 2*ii[ori + w/2 + h*width]
                        - 2*ii[ori + w + (h/2)*width]
                        + 4*ii[ori + w/2 + (h/2)*width]
                        + ii[ori - 1 + h*width] - 2*ii[ori - 1 + (h/2)*width]
                        + ii[ori + w - width] - 2*ii[ori + w/2 - width]
                        + ii[ori - 1 - width]);
            }
            else
            {
                if (x == 0)
                {
                    return (ii[ori + w + h*width] - 2*ii[ori + w/2 + h*width]
                            - 2*ii[ori + w + (h/2)*width]
                            + 4*ii[ori + w/2 + (h/2)*width]
                            + ii[ori + w - width] - 2*ii[ori + w/2 - width]);
                }
                else
                {
                    return (ii[ori + w + h*width] - 2*ii[ori + w/2 + h*width]
                            - 2*ii[ori + w + (h/2)*width]
                            + 4*ii[ori + w/2 + (h/2)*width]
                            + ii[ori - 1 + h*width]
                            - 2*ii[ori - 1 + (h/2)*width]);
                }
            }
        }
    }

    return 0;
}

int main()
{
    return 0;
}
