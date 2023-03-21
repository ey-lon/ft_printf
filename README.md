# ft_printf
Recreation of the printf() function from libc.

| prototype |
| --------- |
| char  *get_next_line(int fd); |

- Supported conversions: `%` `c` `s` `p` `i` `d` `u` `x` `X`

## Bonus
- Supported flags: `#` `+` `(space)`
- Supported options: `-` `0` `.` `(width)`

## Usage
| command | info |
| ------- | ---- |
| `make` | to compile *libftprintf.a* (std. version) |
| `make bonus` | to compile *libftprintf.a* (bonus version) |
