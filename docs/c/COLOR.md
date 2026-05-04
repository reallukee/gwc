# COLOR

Torna a [API C](./index.md)

> C API v0.4.0 - rev1

| Sorgente        | Ref                                 |
| :-------------- | :---------------------------------- |
| Intestazione    | [COLOR.h](../../gwc.native/COLOR.h) |
| Implementazione | [COLOR.c](../../gwc.native/COLOR.c) |



# Sommario

* [Macro](#macro)
* [Strutture](#strutture)
* [Funzioni](#funzioni)



# Macro

* `GWC_COLOR_H`



# Strutture

## `gCOLOR`

Rappresenta un colore.

```c
typedef struct gCOLOR gCOLOR;
```

<br />



# Funzioni

## `color_new`

### Sommario

Alloca una struttura di tipo [`gCOLOR`](#gcolor).

```c
GWC_C_API gCOLOR* color_new(int alpha, int red, int green, int blue);
```

### Parametri

* `int` `alpha`: Componente alpha.
* `int` `alpha`: Componente rossa.
* `int` `alpha`: Componente verde.
* `int` `alpha`: Componente blue.

### Restituisce

`NULL` o [`gCOLOR`](#gcolor).

<br />



## `color_delete`

### Sommario

Dealloca una struttura di tipo [`gCOLOR`](#gcolor).

```c
GWC_C_API void color_delete(gCOLOR* color);
```

### Parametri

* [`gCOLOR`](#gcolor) `color`: Puntatore a [`gCOLOR`](#gcolor).

### Restituisce

`void`.

<br />



## `color_getAlpha`

### Sommario

Ottiene la componente alpha.

```c
GWC_C_API int color_getAlpha(const gCOLOR* color);
```

### Parametri

* [`gCOLOR`](#gcolor) `color`: Puntatore a [`gCOLOR`](#gcolor).

### Restituisce

`int`.

<br />



## `color_setAlpha`

### Sommario

Imposta la componente alpha.

```c
GWC_C_API void color_setAlpha(gCOLOR* color, int value);
```

### Parametri

* [`gCOLOR`](#gcolor) `color`: Puntatore a [`gCOLOR`](#gcolor).
* `int` `value`: Componente alpha.

### Restituisce

`void`.

<br />



## `color_getRed`

### Sommario

Ottiene la componente rossa.

```c
GWC_C_API int color_getRed(const gCOLOR* color);
```

### Parametri

* [`gCOLOR`](#gcolor) `color`: Puntatore a [`gCOLOR`](#gcolor).

### Restituisce

`int`.

<br />



## `color_setRed`

### Sommario

Imposta la componente rossa.

```c
GWC_C_API void color_setRed(gCOLOR* color, int value);
```

### Parametri

* [`gCOLOR`](#gcolor) `color`: Puntatore a [`gCOLOR`](#gcolor).
* `int` `value`: Componente rossa.

### Restituisce

`void`.

<br />



## `color_getGreen`

### Sommario

Ottiene la componente verde.

```c
GWC_C_API int color_getGreen(const gCOLOR* color);
```

### Parametri

* [`gCOLOR`](#gcolor) `color`: Puntatore a [`gCOLOR`](#gcolor).

### Restituisce

`int`.

<br />



## `color_setGreen`

### Sommario

Imposta la componente verde.

```c
GWC_C_API void color_setGreen(gCOLOR* color, int value);
```

### Parametri

* [`gCOLOR`](#gcolor) `color`: Puntatore a [`gCOLOR`](#gcolor).
* `int` `value`: Componente verde.

### Restituisce

`void`.

<br />



## `color_getBlue`

### Sommario

Ottiene la componente blu.

```c
GWC_C_API int color_getBlue(const gCOLOR* color);
```

### Parametri

* [`gCOLOR`](#gcolor) `color`: Puntatore a [`gCOLOR`](#gcolor).

### Restituisce

`int`.

<br />



## `color_setBlue`

### Sommario

Imposta la componente blu.

```c
GWC_C_API void color_setBlue(gCOLOR* color, int value);
```

### Parametri

* [`gCOLOR`](#gcolor) `color`: Puntatore a [`gCOLOR`](#gcolor).
* `int` `value`: Componente blu.

### Restituisce

`void`.

<br />



## `color_equal`

### Sommario

Verifica se due puntatori a [`gCOLOR`](#gcolor) sono uguali.

Viene controllato sia l'indirizzo che i valori.

```c
GWC_C_API bool color_equal(const gCOLOR* color, const gCOLOR* other);
```

### Parametri

* [`gCOLOR`](#gcolor) `color`: Puntatore a [`gCOLOR`](#gcolor).
* [`gCOLOR`](#gcolor) `other`: Puntatore a [`gCOLOR`](#gcolor).

### Restituisce

`bool`.

<br />



## `color_notequal`

### Sommario

Verifica se due puntatori a [`gCOLOR`](#gcolor) non sono uguali.

Viene controllato sia l'indirizzo che i valori.

```c
GWC_C_API bool color_notequal(const gCOLOR* color, const gCOLOR* other);
```

### Parametri

* [`gCOLOR`](#gcolor) `color`: Puntatore a [`gCOLOR`](#gcolor).
* [`gCOLOR`](#gcolor) `other`: Puntatore a [`gCOLOR`](#gcolor).

### Restituisce

`bool`.

<br />



[Torna su](#)
