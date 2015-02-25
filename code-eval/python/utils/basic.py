def splitby(list, size):
    """
    Split list in n chunks.
    """
    return [list[i:i+size] for i in range(0, len(list), size)]
