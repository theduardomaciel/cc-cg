
def bresenham(x0, y0, x1, y1):
    """
    Algoritmo de Bresenham para calcular os pontos entre (x0, y0) e (x1, y1).
    Retorna uma lista de tuplas (x, y) representando os pontos calculados.
    """
    points = []
    
    dx = abs(x1 - x0)
    dy = abs(y1 - y0)

    x, y = x0, y0

    sx = 1 if x0 < x1 else -1
    sy = 1 if y0 < y1 else -1

    if dx > dy:
        err = dx / 2.0
        while x != x1:
            points.append((x, y))
            err -= dy
            if err < 0:
                y += sy
                err += dx
            x += sx
    else:
        err = dy / 2.0
        while y != y1:
            points.append((x, y))
            err -= dx
            if err < 0:
                x += sx
                err += dy
            y += sy
    points.append((x, y))
    return points

if __name__ == "__main__":
    x0, y0 = 1, 1  # Ponto A
    x1, y1 = 8, 5 # Ponto B
    
    result = bresenham(x0, y0, x1, y1)

    print("Pontos calculados pelo algoritmo de Bresenham:")

    for point in result:
        print(point)
