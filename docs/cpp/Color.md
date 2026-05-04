# Color

Torna a [API C++](./index.md)

> C++ API v0.4.0 - rev1

| Sorgente        | Ref                                     |
| :-------------- | :-------------------------------------- |
| Intestazione    | [Color.hpp](../../gwc.native/Color.hpp) |
| Implementazione | [Color.cpp](../../gwc.native/Color.cpp) |



# Sommario

* [Namespace](#namespace)
* [Macro](#macro)
* [Classi](#classi)
* [Metodi](#metodi)
* [Operatori](#operatori)



# Namespace

* `gwc`



# Macro

* `GWC_COLOR_HPP`



# Classi

## `gColor`

Rappresenta un colore.

```cpp
class GWC_CPP_API gColor sealed
```

<br />



# Metodi

## (*Costruttore*) `gColor::gColor`

### Sommario

Alloca una classe di tipo [`gColor`](#gcolor).

```cpp
gColor(int alpha, int red, int green, int blue);
```

### Parametri

* `int` `alpha`: Componente alpha.
* `int` `alpha`: Componente rossa.
* `int` `alpha`: Componente verde.
* `int` `alpha`: Componente blue.

### Restituisce

[`gColor`](#gcolor).

<br />



## (*Distruttore*) `gColor::~gColor`

### Sommario

Dealloca una classe di tipo [`gColor`](#gcolor).

```cpp
~gColor();
```

### Parametri

* `void`.

### Restituisce

`void`.

<br />



## `gColor::getAlpha`

### Sommario

Ottiene la componente alpha.

```cpp
int getAlpha() const;
```

### Parametri

* `void`.

### Restituisce

`int`.

<br />



## `gColor::setAlpha`

### Sommario

Imposta la componente alpha.

```cpp
void setAlpha(int value);
```

### Parametri

* `int` `value`: Componente alpha.

### Restituisce

`void`.

<br />



## `gColor::getRed`

### Sommario

Ottiene la componente rossa.

```cpp
int getRed() const;
```

### Parametri

* `void`.

### Restituisce

`int`.

<br />



## `gColor::setRed`

### Sommario

Imposta la componente rossa.

```cpp
void setRed(int value);
```

### Parametri

* `int` `value`: Componente rossa.

### Restituisce

`void`.

<br />



## `gColor::getGreen`

### Sommario

Ottiene la componente verde.

```cpp
int getGreen() const;
```

### Parametri

* `void`.

### Restituisce

`int`.

<br />



## `gColor::setGreen`

### Sommario

Imposta la componente verde.

```cpp
void setGreen(int value);
```

### Parametri

* `int` `value`: Componente verde.

### Restituisce

`void`.

<br />



## `gColor::getBlue`

### Sommario

Ottiene la componente blu.

```cpp
int getBlue() const;
```

### Parametri

* `void`.

### Restituisce

`int`.

<br />



## `gColor::setBlue`

### Sommario

Imposta la componente blu.

```cpp
void setBlue(int value);
```

### Parametri

* `int` `value`: Componente blu.

### Restituisce

`void`.

<br />



# Operatori

## `gColor::operator==`

### Sommario

Verifica se due istanze di [`gColor`](#gcolor) sono uguali.

```cpp
bool operator==(const gColor& other) const;
```

### Parametri

* [`gColor`](#gcolor) `other`: Istanza di [`gColor`](#gcolor).

### Restituisce

`bool`.

<br />



## `gColor::operator!=`

### Sommario

Verifica se due istanze di [`gColor`](#gcolor) non sono uguali.

```cpp
bool operator!=(const gColor& other) const;
```

### Parametri

* [`gColor`](#gcolor) `other`: Istanza di [`gColor`](#gcolor).

### Restituisce

`bool`.

<br />



[Torna su](#)
