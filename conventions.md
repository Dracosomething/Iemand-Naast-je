# Naming
## PascalCase
- Class names
- public methods
- public fields
- file names

## camelCase
- private/protected methods
- private/protected field. Deze hebben ook een '\_' prefix.
- folder names

## snake\_case
- variabelen
- functies
- macros zijn in BIG\_SNAKE\_CASE
- structs en unions.
- Enum definities en members zijn BIG\_SNAKE\_CASE
- Argumenten, deze doe je ook in een logische volgorde.

## Prefixes
Prefixes zijn altijd het eerste woord in een naam.
Deze moeten altijd in kleine letters zijn.

### Volgorde
global, static, constant, pointer/function pointer.
Dus bijvoorbeeld `gscpName`.

- pointers hebben een 'p' prefix.
- static hebben een 's' prefix.
- globals hebben een 'g' prefix.
- constants hebben een 'c' prefix.
- function pointers hebben een 'f' prefix, en geen 'p' prefix.

## Suffix
- Types hebben altijd een '\_t' suffix.

# Namespaces en Using
- Gebruik using nooit als je een namespace gebruikt van een external library.
- Gebruik using altijd voor namespaces die in ons project zijn gedefinieerd.

# Booleans
- Gebruik de keywords en nooit nummers.
- Gebruik 'bool' en niet '\_Bool'.
- Naam van een boolean is geformuleerd als vraag.

# Pointers
- Sterretje direct na het datatype. Voorbeeld 'int* x' en niet 'int \*x'.
- void* voor generic variables.
- Gebruik indexing en niet rekenen. Voorbeeld: `int* x; x[5];` en niet `x+5;`.

# Pre-Processor
- includes boven in het bestand.
- includes binnen het ifndef define blokje.
voorbeeld:
```c++
#ifndef X
#define X
#include ...
#endif
```

# Casting
- Gebruik de standaard manier. Voorbeeld: `int x; char y = (char)x;`.
- Gebruik dynamic\_cast als manier om het data type van een variable te checken.

# Inline
- Gebruik dit als je een functie hebt met 1-2 lijnen code.

# Goto en Jmp
- Mogen worden gebruikt worden, maar alleen als dit de enige optie is.

# Keywords
- Plaats een spatie tussen keywords en '()'. Voorbeeld: 'while ()' of 'if ()'.
- Voor een infinite loop gebruik je een lege for loop, dit is dus `for (;;)`.

# Error handling
- Gebruik exceptions, try en catch

# Denesting
- Denest wanneer je 2 of meer levels van nesting hebt relatief van het huidige body.
- Denest wanneer je returnt in je huidige nesting level.
- Mutlidimensionale arrays moeten een indentatie hebben voor elke dimensie.
- Switch case bodies mogen maar maximaal 2 lijnen lang zijn exclusief break.
- Als je een variable maar 1 keer bijna direct gebruikt dan doe je dit in een niewe body.
Voorbeeld: ```c++
func() {
    ...
    { // nieuw stuk van de stack
	int x=1;
	x++;
    }
    ...
}
```

# if statements
- Variable in een if statement initializeren mag.

# Binaire operators
- Gebruik deze alleen wanneer het niet anders kan.

# Bytes
- Gebruik voor een byte opslaan het char datatype.
- Initializeer een byte met de hexadecimal syntax, geld ook voor binary. Voorbeeld `char x = 0xff;`.

# integers
- Gebruik de int types van stdint.h. Voorbeeld `uint32\_t x;` en niet `int x;`.

# enums
- Prefix enum members met de naam van de enum.

# Strings
- Gebruik `char\*` en niet `string`.

# Constants
- Global constants moet je als macro definieren. Voorbeeld: ```c++
// good
#define NAME 2

// bad
const int NAME = 2;
```

# Structs en Unions
- Gebruik hiervoor typedef.
- Geen nested struct en union definities. Voorbeeld: ```c++
// bad
struct x {
    struct {

    } y;
}
```
- Gebruik structs wanneer je een class hebt die geen methods heeft.
- Gebruik unions wanneer je een aantal exacte data typen wil meegeven aan een functie/method.

# Magic values
- Leg met een comment uit wat dit is.
- Gebruik ze gewoon zo min mogelijk.

# Files
- Elke class eigen file.
- Structs en unions in een eigen file, hier moeten de bijbehoorende functies.
- Macros in specifieke files.
