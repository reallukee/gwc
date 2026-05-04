# Point

Torna a [API C++](./index.md)

> C++ API v0.4.0 - rev1

| Sorgente        | Ref                                     |
| :-------------- | :-------------------------------------- |
| Intestazione    | [Point.hpp](../../gwc.native/Point.hpp) |
| Implementazione | [Point.cpp](../../gwc.native/Point.cpp) |



# Sommario

* [Namespace](#namespace)
* [Macro](#macro)
* [Classi](#classi)
* [Metodi](#metodi)
* [Operatori](#operatori)



# Namespace

* `gwc`



# Macro

* `GWC_POINT_HPP`



# Classi

## `gPoint`

Rappresenta un punto.

```cpp
class GWC_CPP_API gPoint sealed
```

<br />



# Metodi

## (*Costruttore*) `gPoint::gPoint`

### Sommario

Alloca una classe di tipo [`gPoint`](#gpoint).

```cpp
gPoint(int x, int y);
```

### Parametri

* `int` `x`: Coordinata X.
* `int` `y`: Coordinata Y.

### Restituisce

[`gPoint`](#gpoint).

<br />



## (*Distruttore*) `gPoint::~gPoint`

### Sommario

Dealloca una classe di tipo [`gPoint`](#gpoint).

```cpp
~gPoint();
```

### Parametri

* `void`.

### Restituisce

`void`.

<br />



## `gPoint::getX`

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



## `gPoint::setX`

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



## `gPoint::getY`

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



## `gPoint::setY`

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



# Operatori

## `gPoint::operator==`

### Sommario

Verifica se due istanze di [`gPoint`](#gpoint) sono uguali.

```cpp
bool operator==(const gPoint& other) const;
```

### Parametri

* [`gPoint`](#gpoint) `other`: Istanza di [`gPoint`](#gpoint).

### Restituisce

`bool`.

<br />



## `gPoint::operator!=`

### Sommario

Verifica se due istanze di [`gPoint`](#gpoint) non sono uguali.

```cpp
bool operator!=(const gPoint& other) const;
```

### Parametri

* [`gPoint`](#gpoint) `other`: Istanza di [`gPoint`](#gpoint).

### Restituisce

`bool`.

<br />



[Torna su](#)
