#include "../includes/fractol.h"

t_complex add_complex(t_complex c1, t_complex c2)
{
    t_complex c3;

    c3.re = c1.re + c2.re;
    c3.im = c1.im + c2.im;
    return (c3);
}

t_complex mult_complex(t_complex c1, t_complex c2)
{
    t_complex c3;

    c3.re = c1.re * c2.re - c1.im * c2.im;
    c3.im = c1.re * c2.im + c1.im * c2.re;
    return (c3);
}

double module_complex(t_complex c)
{
    return (c.re * c.re  + c.im * c.im);
}

t_complex suite_complexe(t_complex z, t_complex c)
{
    t_complex result;

    result = mult_complex(z, z);
    result = add_complex(result, c);

    return (result);
}

t_complex suite_complexebu(t_complex z, t_complex c)
{
    t_complex result;
    t_complex z_abs;
    
    // Burning Ship utilise abs() sur re et im
    z_abs.re = fabs(z.re);
    z_abs.im = fabs(z.im);
    
    result = mult_complex(z_abs, z_abs);
    result = add_complex(result, c);
    
    return (result);
}

t_complex pixel_to_complex(int x, int y, t_data *data)
{
    t_complex c;
    
    c.re = data->min_re + (double)x / data->w * (data->max_re - data->min_re);
    c.im = data->max_im + (double)y / data->h * (data->min_im - data->max_im);
    
    return (c);
}




