# Circular Input Queue in C

## ASSIGNMENT INFO 

Student: Isaac Ribeiro\
Professor: David Houtman\
Submission: 24/Jun/2022\
Course: CST8234 C Language\
Program: [Computer Engineering Technology: Computing Science](https://www.algonquincollege.com/coop/coop-entry/computer-engineering-technology-computing-science/)

## DESCRIPTION

A simple implementation of the circular queue data structure to perform a running average over values as they are entered by the user.

The assignment required a solution with the fewest lines of code without sacrificing readability. 

I used Visual Studio Code with WSL and GCC to complete this assignment.

## RELEASES

`v1.0.0` represents the initial version graded for the "Lab 2" assignment.\
`v1.1.0` represents the version graded for the "Lab 4" assignment, which is based on the "Lab 2" submission (v1.0.0).

## COMPATIBILITY

Compatible with Linux.

## INSTALL/BUILD 

Install the latest build [here](https://github.com/i-ribeiro/circular-input-queue/releases/latest).\
\
To build using GCC:\
`gcc -o bin/circular-input-queue src/main.c`

## USAGE

`circular-input-queue`

The application will prompt the user for the number of values to average over followed by a repeating prompt to enter a value for averaging. The buffer, the number of values entered, and the running average are displayed after each new entry. When finished, press CTRL+C to terminate the application.
