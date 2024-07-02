# CodeCraft-24 Project
The template/problem statement for the Dev Summer School(CodeCraft) mini-project

# Pattern-based File Processor

This is a C++ program that reads a file, processes its lines based on specified patterns and actions, and outputs the results. The program supports a variety of operations, including comparisons and logical operations on the parsed tokens.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Pattern Syntax](#pattern-syntax)
- [Action Syntax](#action-syntax)
- [Examples](#examples)
- [Building the Project](#building-the-project)

## Introduction

The Pattern-based File Processor reads lines from a file, applies user-defined patterns to each line, and performs specified actions if the patterns match. The patterns can include logical conditions and comparisons. Actions define how the matched lines are processed and output.

## Features

- **Pattern Matching**: Supports complex patterns using logical operators.
- **Comparison Operators**: Supports `<`, `>`, `<=`, `>=`, `==`, and `!=` for comparing fields.
- **Logical Operators**: Supports `AND` and `OR` logical operations between multiple patterns.
- **Field Access**: Supports accessing specific fields within a line using `$` notation.
- **Print Statements**: Allows printing specific fields or entire lines.

## Usage

```bash
./pattern_processor "<pattern { action }>" <filename>
```

### Arguments

- `<pattern { action }>`: A string that specifies the pattern and action to be applied.
- `<filename>`: The name of the file to process.

## Pattern Syntax

Patterns specify the conditions that each line must meet for the actions to be executed. Patterns can include logical and comparison operators.

- **Logical Operators**: 
  - `&`: Logical AND (default)
  - `|`: Logical OR
- **Comparison Operators**:
  - `>`: Greater than
  - `<`: Less than
  - `>=`: Greater than or equal to
  - `<=`: Less than or equal to
  - `==`: Equal to
  - `!=`: Not equal to
- **Special Patterns**:
  - `1`: Always true
  - `0`: Always false
  - `/regex/`: Checks if any token contains the substring `regex` (only supports /<substr>/ and /./)
  - `NR>x`: Line number is greater than `x`
  - `NR<x`: Line number is less than `x`
  - `NR=x`: Line number is equal to `x`
- **Field Access**: 
  - `$n`: Accesses the nth field (1-based index)

Note that the logical operations are very basic, and do not support complex chaining.

## Action Syntax

Actions define what to do with lines that match the patterns. Currently, only `print` statements are supported.

- **Print Statement**: 
  - `print $n`: Prints the nth field.
  - `print $0`: Prints the entire line.

## Examples

Test cases will be similar to the examples, and you will have to generate the correct output.

### Example 1: Print lines where the first field is greater than 5
```bash
./pattern_processor "$1>5 { print $0 }" example.txt
```

### Example 2: Print lines where the second field is "hello" or the line number is greater than 10
```bash
./pattern_processor "$2==hello||NR>10 { print $0 }" example.txt
```

### Example 3: Print second and third row, fifth and sixth column
```bash
./pattern_processor "NR<4 && NR >1 { print $5, $6 }" example.txt
```

### Example 4: Print third column of rows containing the word "hello"
```bash
./pattern_processor "/hello/ { print $3 }" example.txt
```

### Example 5: Print rows containing more than 5 columns
```bash
./pattern_processor "NF>5 { print $0 }" example.txt
```

## Pass criteria
To pass, your code must run **at least 50% of the test cases** correctly.  
Note that the patterns will only be upto 2 (a && b or a || b), and not more complex.  

We will be releasing a Google Form to collect your responses. We only expect the completed *template.cpp* file.  
Your details should be specified in the format mentioned in *sample.cpp*  

The deadline is: $$12^{th} July$$ $$11:59 PM$$  
## Building the Project

To build the project, use the following commands:

```bash
g++ -o pattern_processor main.cpp
```

This will compile the source code and produce an executable named `pattern_processor`.

## Solution Code

Credit for building the project goes to [Advik](https://github.com/advikkabra), [Tushar](https://github.com/tushar3q34) and [Nandha](https://github.com/nandhagk)  
The code is stored in [this](https://github.com/advikkabra/awk-clone) repository and will be made public after the submission deadline

---

