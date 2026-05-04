# Rectangle

Torna a [API C++](./index.md)

> C++ API v0.4.0 - rev1

| Sorgente        | Ref                                             |
| :-------------- | :---------------------------------------------- |
| Intestazione    | [Rectangle.hpp](../../gwc.native/Rectangle.hpp) |
| Implementazione | [Rectangle.cpp](../../gwc.native/Rectangle.cpp) |



# Sommario

* [Namespace](#namespace)
* [Macro](#macro)
* [Classi](#classi)
* [Metodi](#metodi)
* [Operatori](#operatori)



# Namespace

* `gwc`



# Macro

* `GWC_RECTANGLE_HPP`



# Classi

## `gRectangle`

Rappresenta un rettangolo.

```cpp
class GWC_CPP_API gRectangle sealed
```

<br />



# Metodi

## (*Costruttore*) `gRectangle::gRectangle`

### Sommario

Alloca una classe di tipo [`gRectangle`](#grectangle).

```cpp
gRectangle(int x, int y, int width, int height);
```

### Parametri

* `int` `x`: Coordinata X.
* `int` `y`: Coordinata Y.
* `int` `width`: Lunghezza.
* `int` `height`: Altezza.

### Restituisce

[`gRectangle`](#grectangle).

<br />



## (*Distruttore*) `gRectangle::~gRectangle`

### Sommario

Dealloca una classe di tipo [`gRectangle`](#grectangle).

```cpp
~gRectangle();
```

### Parametri

* `void`.

### Restituisce

`void`.

<br />



## `gRectangle::getX`

### Sommario

Ottiene la coordinata X.

```cpp
int getX() const;
```

### Parametri

* `void`.

### Restituisce

`int`.

<br />



## `gRectangle::setX`

### Sommario

Imposta la coordinata X.

```cpp
void setX(int value);
```

### Parametri

* `int` `value`: Coordinata X.

### Restituisce

`void`.

<br />



## `gRectangle::getY`

### Sommario

Ottiene la coordinata Y.

```cpp
int getY() const;
```

### Parametri

* `void`.

### Restituisce

`int`.

<br />



## `gRectangle::setY`

### Sommario

Imposta la coordinata Y.

```cpp
void setY(int value);
```

### Parametri

* `int` `value`: Coordinata Y.

### Restituisce

`void`.

<br />



## `gRectangle::getWidth`

### Sommario

Ottiene la lunghezza.

```cpp
int getWidth() const;
```

### Parametri

* `void`.

### Restituisce

`int`.

<br />



## `gRectangle::setWidth`

### Sommario

Imposta la lunghezza.

```cpp
void setWidth(int value);
```

### Parametri

* `int` `value`: Lunghezza.

### Restituisce

`void`.

<br />



## `gRectangle::getHeight`

### Sommario

Ottiene l'altezza.

```cpp
int getHeight() const;
```

### Parametri

* `void`.

### Restituisce

`int`.

<br />



## `gRectangle::setHeight`

### Sommario

Imposta l'altezza.

```cpp
void setHeight(int value);
```

### Parametri

* `int` `value`: Altezza.

### Restituisce

`void`.

<br />



# Operatori

## `gRectangle::operator==`

### Sommario

Verifica se due istanze di [`gRectangle`](#grectangle) sono uguali.

```cpp
bool operator==(const gRectangle& other) const;
```

### Parametri

* [`gRectangle`](#grectangle) `other`: Istanza di [`gRectangle`](#grectangle).

### Restituisce

`bool`.

<br />



## `gRectangle::operator!=`

### Sommario

Verifica se due istanze di [`gRectangle`](#grectangle) non sono uguali.

```cpp
bool operator!=(const gRectangle& other) const;
```

### Parametri

* [`gRectangle`](#grectangle) `other`: Istanza di [`gRectangle`](#grectangle).

### Restituisce

`bool`.

<br />



[Torna su](#)
