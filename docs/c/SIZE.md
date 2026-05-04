# SIZE

Torna a [API C](./index.md)

> C API v0.4.0 - rev1

| Sorgente        | Ref                               |
| :-------------- | :-------------------------------- |
| Intestazione    | [SIZE.h](../../gwc.native/SIZE.h) |
| Implementazione | [SIZE.c](../../gwc.native/SIZE.c) |



# Sommario

* [Macro](#macro)
* [Strutture](#strutture)
* [Funzioni](#funzioni)



# Macro

* `GWC_SIZE_H`



# Strutture

## `gSIZE`

Rappresenta una dimensione.

```c
typedef struct gSIZE gSIZE;
```

<br />



# Funzioni

## `size_new`

### Sommario

Alloca una struttura di tipo [`gSIZE`](#gsize).

```c
GWC_C_API gSIZE* size_new(int width, int height);
```

### Parametri

* `int` `width`: Lunghezza.
* `int` `height`: Altezza.

### Restituisce

`NULL` o [`gSIZE`](#gsize).

<br />



## `size_delete`

### Sommario

Dealloca una struttura di tipo [`gSIZE`](#gsize).

```c
GWC_C_API void size_delete(gSIZE* size);
```

### Parametri

* [`gSIZE`](#gsize) `size`: Puntatore a [`gSIZE`](#gsize).

### Restituisce

`void`.

<br />



## `size_getWidth`

### Sommario

Ottiene la lunghezza.

```c
GWC_C_API int size_getWidth(const gSIZE* size);
```

### Parametri

* [`gSIZE`](#gsize) `size`: Puntatore a [`gSIZE`](#gsize).

### Restituisce

`int`.

<br />



## `size_setWidth`

### Sommario

Imposta la lunghezza.

```c
GWC_C_API void size_setWidth(gSIZE* size, int value);
```

### Parametri

* [`gSIZE`](#gsize) `size`: Puntatore a [`gSIZE`](#gsize).
* `int` `value`: Lunghezza.

### Restituisce

`void`.

<br />



## `size_getHeight`

### Sommario

Ottiene l'altezza.

```c
GWC_C_API int size_getHeight(const gSIZE* size);
```

### Parametri

* [`gSIZE`](#gsize) `size`: Puntatore a [`gSIZE`](#gsize).

### Restituisce

`int`.

<br />



## `size_setHeight`

### Sommario

Imposta l'altezza.

```c
GWC_C_API void size_setHeight(gSIZE* size, int value);
```

### Parametri

* [`gSIZE`](#gsize) `size`: Puntatore a [`gSIZE`](#gsize).
* `int` `value`: Altezza.

### Restituisce

`void`.

<br />



## `size_equal`

### Sommario

Verifica se due puntatori a [`gSIZE`](#gsize) sono uguali.

Viene controllato sia l'indirizzo che i valori.

```c
GWC_C_API bool size_equal(const gSIZE* size, const gSIZE* other);
```

### Parametri

* [`gSIZE`](#gsize) `size`: Puntatore a [`gSIZE`](#gsize).
* [`gSIZE`](#gsize) `other`: Puntatore a [`gSIZE`](#gsize).

### Restituisce

`bool`.

<br />



## `size_notequal`

### Sommario

Verifica se due puntatori a [`gSIZE`](#gsize) non sono uguali.

Viene controllato sia l'indirizzo che i valori.

```c
GWC_C_API bool size_notequal(const gSIZE* size, const gSIZE* other);
```

### Parametri

* [`gSIZE`](#gsize) `size`: Puntatore a [`gSIZE`](#gsize).
* [`gSIZE`](#gsize) `other`: Puntatore a [`gSIZE`](#gsize).

### Restituisce

`bool`.

<br />



[Torna su](#)
