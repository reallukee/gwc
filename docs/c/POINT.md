# POINT

Torna a [API C](./index.md)

> C API v0.4.0 - rev1

| Sorgente        | Ref                                 |
| :-------------- | :---------------------------------- |
| Intestazione    | [POINT.h](../../gwc.native/POINT.h) |
| Implementazione | [POINT.c](../../gwc.native/POINT.c) |



# Sommario

* [Macro](#macro)
* [Strutture](#strutture)
* [Funzioni](#funzioni)



# Macro

* `GWC_POINT_H`



# Strutture

## `gPOINT`

Rappresenta un punto.

```c
typedef struct gPOINT gPOINT;
```

<br />



# Funzioni

## `point_new`

### Sommario

Alloca una struttura di tipo [`gPOINT`](#gpoint).

```c
GWC_C_API gPOINT* point_new(int x, int y);
```

### Parametri

* `int` `x`: Coordinata X.
* `int` `y`: Coordinata Y.

### Restituisce

`NULL` o [`gPOINT`](#gpoint).

<br />



## `point_delete`

### Sommario

Dealloca una struttura di tipo [`gPOINT`](#gpoint).

```c
GWC_C_API void point_delete(gPOINT* point);
```

### Parametri

* [`gPOINT`](#gpoint) `point`: Puntatore a [`gPOINT`](#gpoint).

### Restituisce

`void`.

<br />



## `point_getX`

### Sommario

Ottiene la coordinata X.

```c
GWC_C_API int point_getX(const gPOINT* point);
```

### Parametri

* [`gPOINT`](#gpoint) `point`: Puntatore a [`gPOINT`](#gpoint).

### Restituisce

`int`.

<br />



## `point_setX`

### Sommario

Imposta la coordinata X.

```c
GWC_C_API void point_setX(gPOINT* point, int value);
```

### Parametri

* [`gPOINT`](#gpoint) `point`: Puntatore a [`gPOINT`](#gpoint).
* `int` `value`: Coordinata X.

### Restituisce

`void`.

<br />



## `point_getY`

### Sommario

Ottiene la coordinata Y.

```c
GWC_C_API int point_getY(const gPOINT* point);
```

### Parametri

* [`gPOINT`](#gpoint) `point`: Puntatore a [`gPOINT`](#gpoint).

### Restituisce

`int`.

<br />



## `point_setY`

### Sommario

Imposta la coordinata Y.

```c
GWC_C_API void point_setY(gPOINT* point, int value);
```

### Parametri

* [`gPOINT`](#gpoint) `point`: Puntatore a [`gPOINT`](#gpoint).
* `int` `value`: Coordinata Y.

### Restituisce

`void`.

<br />



## `point_equal`

### Sommario

Verifica se due puntatori a [`gPOINT`](#gpoint) sono uguali.

Viene controllato sia l'indirizzo che i valori.

```c
GWC_C_API bool point_equal(const gPOINT* point, const gPOINT* other);
```

### Parametri

* [`gPOINT`](#gpoint) `point`: Puntatore a [`gPOINT`](#gpoint).
* [`gPOINT`](#gpoint) `other`: Puntatore a [`gPOINT`](#gpoint).

### Restituisce

`bool`.

<br />



## `point_notequal`

### Sommario

Verifica se due puntatori a [`gPOINT`](#gpoint) non sono uguali.

Viene controllato sia l'indirizzo che i valori.

```c
GWC_C_API bool point_notequal(const gPOINT* point, const gPOINT* other);
```

### Parametri

* [`gPOINT`](#gpoint) `point`: Puntatore a [`gPOINT`](#gpoint).
* [`gPOINT`](#gpoint) `other`: Puntatore a [`gPOINT`](#gpoint).

### Restituisce

`bool`.

<br />



[Torna su](#)
