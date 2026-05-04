# RECTANGLE

Torna a [API C](./index.md)

> C API v0.4.0 - rev1

| Sorgente        | Ref                                         |
| :-------------- | :------------------------------------------ |
| Intestazione    | [RECTANGLE.h](../../gwc.native/RECTANGLE.h) |
| Implementazione | [RECTANGLE.c](../../gwc.native/RECTANGLE.c) |



# Sommario

* [Macro](#macro)
* [Strutture](#strutture)
* [Funzioni](#funzioni)



# Macro

* `GWC_RECTANGLE_H`



# Strutture

## `gRECTANGLE`

Rappresenta un rettangolo.

```c
typedef struct gRECTANGLE gRECTANGLE;
```

<br />



# Funzioni

## `rectangle_new`

### Sommario

Alloca una struttura di tipo [`gRECTANGLE`](#grectangle).

```c
GWC_C_API gRECTANGLE* rectangle_new(int x, int y, int width, int height);
```

### Parametri

* `int` `x`: Coordinata X.
* `int` `y`: Coordinata Y.
* `int` `width`: Lunghezza.
* `int` `height`: Altezza.

### Restituisce

`NULL` o [`gRECTANGLE`](#grectangle).

<br />



## `rectangle_delete`

### Sommario

Dealloca una struttura di tipo [`gRECTANGLE`](#grectangle).

```c
GWC_C_API void rectangle_delete(gRECTANGLE* rectangle);
```

### Parametri

* [`gRECTANGLE`](#grectangle) `rectangle`: Puntatore a [`gRECTANGLE`](#grectangle).

### Restituisce

`void`.

<br />



## `rectangle_getX`

### Sommario

Ottiene la coordinata X.

```c
GWC_C_API int rectangle_getX(const gRECTANGLE* rectangle);
```

### Parametri

* [`gRECTANGLE`](#grectangle) `rectangle`: Puntatore a [`gRECTANGLE`](#grectangle).

### Restituisce

`int`.

<br />



## `rectangle_setX`

### Sommario

Imposta la coordinata X.

```c
GWC_C_API void rectangle_setX(gRECTANGLE* rectangle, int value);
```

### Parametri

* [`gRECTANGLE`](#grectangle) `rectangle`: Puntatore a [`gRECTANGLE`](#grectangle).
* `int` `value`: Coordinata X.

### Restituisce

`void`.

<br />



## `rectangle_getY`

### Sommario

Ottiene la coordinata Y.

```c
GWC_C_API int rectangle_getY(const gRECTANGLE* rectangle);
```

### Parametri

* [`gRECTANGLE`](#grectangle) `rectangle`: Puntatore a [`gRECTANGLE`](#grectangle).

### Restituisce

`int`.

<br />



## `rectangle_setY`

### Sommario

Imposta la coordinata Y.

```c
GWC_C_API void rectangle_setY(gRECTANGLE* rectangle, int value);
```

### Parametri

* [`gRECTANGLE`](#grectangle) `rectangle`: Puntatore a [`gRECTANGLE`](#grectangle).
* `int` `value`: Coordinata Y.

### Restituisce

`void`.

<br />



## `rectangle_getWidth`

### Sommario

Ottiene la lunghezza.

```c
GWC_C_API int rectangle_getWidth(const gRECTANGLE* rectangle);
```

### Parametri

* [`gRECTANGLE`](#grectangle) `rectangle`: Puntatore a [`gRECTANGLE`](#grectangle).

### Restituisce

`int`.

<br />



## `rectangle_setWidth`

### Sommario

Imposta la lunghezza.

```c
GWC_C_API void rectangle_setWidth(gRECTANGLE* rectangle, int value);
```

### Parametri

* [`gRECTANGLE`](#grectangle) `rectangle`: Puntatore a [`gRECTANGLE`](#grectangle).
* `int` `value`: Lunghezza.

### Restituisce

`void`.

<br />



## `rectangle_getHeight`

### Sommario

Ottiene l'altezza.

```c
GWC_C_API int rectangle_getHeight(const gRECTANGLE* rectangle);
```

### Parametri

* [`gRECTANGLE`](#grectangle) `rectangle`: Puntatore a [`gRECTANGLE`](#grectangle).

### Restituisce

`int`.

<br />



## `rectangle_setHeight`

### Sommario

Imposta l'altezza.

```c
GWC_C_API void rectangle_setHeight(gRECTANGLE* rectangle, int value);
```

### Parametri

* [`gRECTANGLE`](#grectangle) `rectangle`: Puntatore a [`gRECTANGLE`](#grectangle).
* `int` `value`: Altezza.

### Restituisce

`void`.

<br />



## `rectangle_equal`

### Sommario

Verifica se due puntatori a [`gRECTANGLE`](#grectangle) sono uguali.

Viene controllato sia l'indirizzo che i valori.

```c
GWC_C_API bool rectangle_equal(const gRECTANGLE* rectangle, const gRECTANGLE* other);
```

### Parametri

* [`gRECTANGLE`](#grectangle) `rectangle`: Puntatore a [`gRECTANGLE`](#grectangle).
* [`gRECTANGLE`](#grectangle) `other`: Puntatore a [`gRECTANGLE`](#grectangle).

### Restituisce

`bool`.

<br />



## `rectangle_notequal`

### Sommario

Verifica se due puntatori a [`gRECTANGLE`](#grectangle) non sono uguali.

Viene controllato sia l'indirizzo che i valori.

```c
GWC_C_API bool rectangle_notequal(const gRECTANGLE* rectangle, const gRECTANGLE* other);
```

### Parametri

* [`gRECTANGLE`](#grectangle) `rectangle`: Puntatore a [`gRECTANGLE`](#grectangle).
* [`gRECTANGLE`](#grectangle) `other`: Puntatore a [`gRECTANGLE`](#grectangle).

### Restituisce

`bool`.

<br />



[Torna su](#)
