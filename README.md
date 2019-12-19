# A Simple Genetic Algorithm

<p>This program is a simple implementation of a genetic algorithm found at <br> http://www.ai-junkie.com/ga/intro/gat1.html. When fed an integer number, the program will teach itself how to build a simple math formula that sums to that number. </p>

<p>The program simulates a population of 'critters' whose genome is represented by a 64-bit bitstring. Every 4 bits of the string is encoded into the digits 1-9 and the '+', '-', 'x' and '/' operators. At each generation, the critters whose genome are closest to the target are bred together, with a random mutation occurring at each crossover. The top critters of each generation 'survive' to the next. The program terminates when the sum of the fittest critter is equal to the target.

## Installation

```
git clone https://github.com/WillFarris/GeneticAlgorithm.git
cd GeneticAlgorithm
make
```

## Usage

```
./gene <target>
```

<p> Or, if no arguments are supplied, the program will prompt you for one.</p>
