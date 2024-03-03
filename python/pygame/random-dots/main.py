import pygame
import numpy as np

# pygame setup
pygame.init()
screen = pygame.display.set_mode((1920, 1080))
clock = pygame.time.Clock()
running = True

def gen_rand_dots_opt(shape: tuple, light, dark) -> np.ndarray:
    """
    utilizing all bits for random number
    """
    height, width = shape
    rand_int32_cnt = height * width
    rand_int32_cnt = (rand_int32_cnt + 31) // 32
    # note here introduces a memory allocation, which is not desired
    seeds = np.random.randint(0, 1 << 32, rand_int32_cnt, dtype=np.uint32)
    seeds = seeds.view(dtype=np.uint8)
    pic = np.unpackbits(seeds)
    pic.resize((height, width))
    diff = light - dark
    pic *= diff
    pic += dark
    return pic

buf = np.ndarray((screen.get_width(), screen.get_height(), 3), dtype=np.uint8)

while running:
    # poll for events
    # pygame.QUIT event means the user clicked X to close your window
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    arr = gen_rand_dots_opt(screen.get_size(), 255, 0)
    # make it to grey scale

    screen.fill((0, 0, 0))
    buf[:, :, 0] = arr
    buf[:, :, 1] = arr
    buf[:, :, 2] = arr
    pygame.surfarray.blit_array(screen, buf)

    # RENDER YOUR GAME HERE

    # flip() the display to put your work on screen
    pygame.display.flip()

    # print true fps
    print(clock.get_fps())

    clock.tick(120)  # limits FPS to 60

pygame.quit()