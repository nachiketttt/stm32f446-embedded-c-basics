# STM32F446RE Embedded C GPIO Examples

Basic GPIO examples for STM32F446RE using direct 
register manipulation without HAL.

## Projects

| Project | Description |
|---------|-------------|
| 001_led_toggle | LED toggle using GPIO output register |
| 002_keypad_input | 4x4 keypad scanning using GPIO input |
| 003_led_bitfield | LED control using C bitfield structs |
| 004_port_reset | Reading and resetting Port A and B values |

## Note
These are basic and foundational GPIO exercises demonstrating 
direct register access and manipulation before moving to bare-metal driver abstraction.
Full peripheral drivers available in 
[stm32f446-baremetal-peripheral-drivers](https://github.com/nachiketttt/stm32f446-baremetal-peripheral-drivers)
