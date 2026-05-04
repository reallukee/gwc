# Size

Torna a [API C++](./index.md)

> C++ API v0.4.0 - rev1

| Sorgente        | Ref                                   |
| :-------------- | :------------------------------------ |
| Intestazione    | [Size.hpp](../../gwc.native/Size.hpp) |
| Implementazione | [Size.cpp](../../gwc.native/Size.cpp) |



# Sommario

* [Namespace](#namespace)
* [Macro](#macro)
* [Classi](#classi)
* [Metodi](#metodi)
* [Operatori](#operatori)



# Namespace

* `gwc`



# Macro

* `GWC_SIZE_HPP`



# Classi

## `gSize`

Rappresenta una dimensione.

```cpp
class GWC_CPP_API gSize sealed
```

<br />



# Metodi

## (*Costruttore*) `gSize::gSize`

### Sommario

Alloca una classe di tipo [`gSize`](#gsize).

```cpp
gSize(int width, int height);
```

### Parametri

* `int` `width`: Lunghezza.
* `int` `height`: Altezza.

### Restituisce

[`gSize`](#gsize).

<br />



## (*Distruttore*) `gSize::~gSize`

### Sommario

Dealloca una classe di tipo [`gSize`](#gsize).

```cpp
~gSize();
```

### Parametri

* `void`.

### Restituisce

`void`.

<br />



## `gSize::getWidth`

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



## `gSize::setWidth`

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



## `gSize::getHeight`

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



## `gSize::setHeight`

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

## `gSize::operator==`

### Sommario

Verifica se due istanze di [`gSize`](#gsize) sono uguali.

```cpp
bool operator==(const gSize& other) const;
```

### Parametri

* [`gSize`](#gsize) `other`: Istanza di [`gSize`](#gsize).

### Restituisce

`bool`.

<br />



## `gSize::operator!=`

### Sommario

Verifica se due istanze di [`gSize`](#gsize) non sono uguali.

```cpp
bool operator!=(const gSize& other) const;
```

### Parametri

* [`gSize`](#gsize) `other`: Istanza di [`gSize`](#gsize).

### Restituisce

`bool`.

<br />



[Torna su](#)
