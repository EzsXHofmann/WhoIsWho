#include <stdlib.h>
#include <stdio.h>

int calcul(int ii[], int type, int w, int h, int width, int x, int y, int ori)
{
    int s1, s2;

    if (type == 1)
    {
        if (x == 0 && y == 0)
        {
            s1 = ii[ori + w + h*width];
            s2 = ii[ori + w/2 + h*width];
        }
        else
        {
            if (x != 0 && y != 0)
            {
                s1 = ii[ori + w/2 + h*width] + ii[ori - 1 - width]
                   - ii[ori + w/2 - width] - ii[ori - 1 + h*width];
                s2 = ii[ori + w + h*width] + ii[ori + w/2 - width]
                   - ii[ori + w - width] - ii[ori + w/2 + h*width];
             }
             else
             {
                 if (x == 0)
                 {
                     s1 = ii[ori + w/2 + h*width] - ii[ori + w/2 - width];
                     s2 = ii[ori + w + h*width] + ii[ori + w/2 - width]
                        - ii[ori + w - width] - ii[ori + w/2 + h*width];
                 }
                 else
                 {
                     s1 = ii[ori + w/2 + h*width]
                        - ii[ori + w/2 - width] - ii[ori - 1 + h*width];
                     s2 = ii[ori + w + h*width] - ii[ori + w/2 + h*width];
             
                 }
             }
        }

        return s1 - s2;
    }

    if (type == 2)
    {
        if (x == 0 && y == 0)
        {
            return (ii[ori + w + h*width] - 2*ii[ori + ((w + 1)/3) + h*width]
                    + 2*ii[ori + h*width]);
        }
        else
        {
            if (x != 0 && y != 0)
            {
                return (ii[ori + w + h*width]
                        - 2*ii[ori + ((w + 1)/3) + h*width]
                        + 2*ii[ori + h*width] - ii[ori + w - width]
                        + 2*ii[ori + ((w + 1)/3) - width] - 2*ii[ori - width]
                        - ii[ori - 1 + width] + ii[ori - 1 - width]);
            }
            else
            {
                if (x == 0)
                {
                    return (ii[ori + w + h*width]
                            - 2*ii[ori + ((w + 1)/3) + h*width]
                            + 2*ii[ori + h*width] - ii[ori + w - width]
                            + 2*ii[ori + ((w + 1)/3) - width]
                            - 2*ii[ori - width]);
                }
                else
                {
                    return (ii[ori + w + h*width]
                            - 2*ii[ori + ((w + 1)/3) + h*width]
                            + 2*ii[ori + h*width] - ii[ori - 1 + width]); 
                }
            }
        }
    }

    if (type == 3)
    {
        if (x == 0 && y == 0)
        {
            return (2*ii[ori + w] - ii[ori + w + h*width]);
        }
        else
        {
            if (x != 0 && y != 0)
            {
                return (2*ii[ori + w] - ii[ori + w + h*width]
                        - ii[ori + w - width]
                        + ii[ori - 1 + h*width] - 2*ii[ori - 1]
                        + ii[ori - 1 - width]);
            }
            else
            {
                if (x == 0)
                {
                    return (2*ii[ori + w] - ii[ori + w + h*width]
                            - ii[ori + w - width]);
                }
                else
                {
                    return (2*ii[ori + w] - ii[ori + w + h*width]
                            + ii[ori - 1 + h*width] - 2*ii[ori - 1]); 
                }
            }
        }
    }

    if (type == 4)
    {
        if (x == 0 && y == 0)
        {
            return ();
        }
        else
        {
            if (x != 0 && y != 0)
            {
                return ();
            }
            else
            {
                if (x == 0)
                {
                    return ();
                }
                else
                {
                    return (); 
                }
            }
        }
    }

    if (type == 5)
    {
        if (x == 0 && y == 0)
        {
            return ();
        }
        else
        {
            if (x != 0 && y != 0)
            {
                return ();
            }
            else
            {
                if (x == 0)
                {
                    return ();
                }
                else
                {
                    return (); 
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
