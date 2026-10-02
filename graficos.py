import matplotlib.pyplot as plt


# ============================================================
# TAMANHOS DOS VETORES
# ============================================================

tamanhos = [
    0, 1000, 2000, 3000, 4000, 5000,
    6000, 7000, 8000, 9000, 10000,
    11000, 12000, 13000, 14000, 15000,
    16000, 17000, 18000, 19000, 20000
]


# ============================================================
# 1. INSERTION SORT
# ============================================================

insertion_melhor = [
    0, 9618, 12437, 23389, 27569, 40455,
    38692, 67592, 90362, 107843, 161042,
    87657, 110973, 147561, 136815, 93163,
    99559, 105757, 140832, 206664, 173648
]

insertion_pior = [
    0, 3201968, 12405943, 54593582, 107038120,
    98645273, 122175762, 160754071, 209917870,
    250690966, 322545346, 401715378, 475522599,
    559590983, 612003524, 733668079, 844394613,
    918867526, 1063196974, 1163309985, 1320389872
]

plt.figure(figsize=(10, 6))

plt.plot(
    tamanhos,
    insertion_melhor,
    marker='o',
    label='Melhor caso'
)

plt.plot(
    tamanhos,
    insertion_pior,
    marker='o',
    label='Pior caso'
)

plt.title('Insertion Sort - Melhor e Pior Caso')
plt.xlabel('Tamanho do vetor')
plt.ylabel('Tempo (ns)')
plt.legend()
plt.grid(True)

plt.tight_layout()

plt.savefig('grafico_insertion_sort.png', dpi=300)

plt.show()


# ============================================================
# 2. SELECTION SORT
# ============================================================

selection_melhor = [
    0, 2250253, 13689314, 19841982, 48148289,
    75287894, 88845650, 99438943, 126021132,
    160390893, 227159559, 261208420, 290115839,
    337039414, 406922780, 459389830, 548507218,
    590926183, 678120637, 746740768, 832607279
]

selection_pior = [
    0, 2288707, 8185018, 23460834, 32203357,
    51121077, 72758042, 103086763, 129424332,
    179484572, 202052436, 281984049, 301431747,
    357202820, 409699679, 461945169, 564194289,
    597059834, 681374158, 792499489, 838676222
]

plt.figure(figsize=(10, 6))

plt.plot(
    tamanhos,
    selection_melhor,
    marker='o',
    label='Melhor caso'
)

plt.plot(
    tamanhos,
    selection_pior,
    marker='o',
    label='Pior caso'
)

plt.title('Selection Sort - Melhor e Pior Caso')
plt.xlabel('Tamanho do vetor')
plt.ylabel('Tempo (ns)')
plt.legend()
plt.grid(True)

plt.tight_layout()

plt.savefig('grafico_selection_sort.png', dpi=300)

plt.show()


# ============================================================
# 3. BUBBLE SORT
# ============================================================

bubble_melhor = [
    0, 2196, 4466, 7007, 8434, 11115,
    13022, 16320, 18630, 20297, 22738,
    240363, 32436, 23497, 31815, 33923,
    36433, 74128, 40918, 43308, 48372
]

bubble_pior = [
    0, 2325526, 7533559, 17515766, 52904717,
    62265304, 100422799, 94642572, 126475957,
    155528131, 203379894, 232965688, 290363736,
    325295824, 390029971, 445559568, 503478461,
    563469520, 611593194, 725154451, 778634136
]

plt.figure(figsize=(10, 6))

plt.plot(
    tamanhos,
    bubble_melhor,
    marker='o',
    label='Melhor caso'
)

plt.plot(
    tamanhos,
    bubble_pior,
    marker='o',
    label='Pior caso'
)

plt.title('Bubble Sort - Melhor e Pior Caso')
plt.xlabel('Tamanho do vetor')
plt.ylabel('Tempo (ns)')
plt.legend()
plt.grid(True)

plt.tight_layout()

plt.savefig('grafico_bubble_sort.png', dpi=300)

plt.show()


# ============================================================
# 4. QUICK SORT
# ============================================================

quick_melhor = [
    82, 114333, 616427, 2192450, 2279118,
    1691762, 2040757, 2627382, 3305903,
    3878976, 4698241, 5087706, 6751290,
    10011230, 13724455, 16248450, 19765688,
    17936999, 13977264, 18510609, 27051854
]

quick_pior = [
    42, 2143589, 8480600, 19028439, 31405854,
    43076826, 55774855, 78447192, 101515212,
    128221979, 163180381, 199372198, 224774637,
    258478941, 312141166, 345188156, 409647188,
    473395963, 495414833, 575040585, 618745129
]

plt.figure(figsize=(10, 6))

plt.plot(
    tamanhos,
    quick_melhor,
    marker='o',
    label='Melhor caso'
)

plt.plot(
    tamanhos,
    quick_pior,
    marker='o',
    label='Pior caso'
)

plt.title('Quick Sort - Melhor e Pior Caso')
plt.xlabel('Tamanho do vetor')
plt.ylabel('Tempo (ns)')
plt.legend()
plt.grid(True)

plt.tight_layout()

plt.savefig('grafico_quick_sort.png', dpi=300)

plt.show()


# ============================================================
# 5. MERGE SORT
# ============================================================

merge_melhor = [
    74, 757054, 984576, 1100672, 1489893,
    1965603, 2279958, 2457761, 2838056,
    3197759, 3491276, 5541218, 6559094,
    15070171, 7885878, 9019122, 10064694,
    12614321, 11663594, 12082110, 7900251
]

merge_pior = [
    52, 319695, 698248, 1151229, 1712854,
    2576645, 2974952, 2462037, 3130558,
    3475804, 3823604, 3907784, 4940888,
    7899818, 12616124, 14435569, 8773321,
    9906902, 10989503, 7399453, 7617837
]

plt.figure(figsize=(10, 6))

plt.plot(
    tamanhos,
    merge_melhor,
    marker='o',
    label='Melhor caso'
)

plt.plot(
    tamanhos,
    merge_pior,
    marker='o',
    label='Pior caso'
)

plt.title('Merge Sort - Melhor e Pior Caso')
plt.xlabel('Tamanho do vetor')
plt.ylabel('Tempo (ns)')
plt.legend()
plt.grid(True)

plt.tight_layout()

plt.savefig('grafico_merge_sort.png', dpi=300)

plt.show()

# ============================================================
# 6. COMPARAÇÃO DOS MELHORES CASOS
# ============================================================

plt.figure(figsize=(10, 6))

plt.plot(
    tamanhos,
    insertion_melhor,
    marker='o',
    label='Insertion Sort'
)

plt.plot(
    tamanhos,
    selection_melhor,
    marker='o',
    label='Selection Sort'
)

plt.plot(
    tamanhos,
    bubble_melhor,
    marker='o',
    label='Bubble Sort'
)

plt.plot(
    tamanhos,
    quick_melhor,
    marker='o',
    label='Quick Sort'
)

plt.plot(
    tamanhos,
    merge_melhor,
    marker='o',
    label='Merge Sort'
)

plt.title('Comparação dos Melhores Casos')
plt.xlabel('Tamanho do vetor')
plt.ylabel('Tempo (ns)')
plt.legend()
plt.grid(True)

plt.tight_layout()

plt.savefig('comparacao_melhores_casos.png', dpi=300)

plt.show()


# ============================================================
# 7. COMPARAÇÃO DOS PIORES CASOS
# ============================================================

plt.figure(figsize=(10, 6))

plt.plot(
    tamanhos,
    insertion_pior,
    marker='o',
    label='Insertion Sort'
)

plt.plot(
    tamanhos,
    selection_pior,
    marker='o',
    label='Selection Sort'
)

plt.plot(
    tamanhos,
    bubble_pior,
    marker='o',
    label='Bubble Sort'
)

plt.plot(
    tamanhos,
    quick_pior,
    marker='o',
    label='Quick Sort'
)

plt.plot(
    tamanhos,
    merge_pior,
    marker='o',
    label='Merge Sort'
)

plt.title('Comparação dos Piores Casos')
plt.xlabel('Tamanho do vetor')
plt.ylabel('Tempo (ns)')
plt.legend()
plt.grid(True)

plt.tight_layout()

plt.savefig('comparacao_piores_casos.png', dpi=300)

plt.show()