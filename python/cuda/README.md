# Python/CUDA
This folder contains examples of using the pycuda library in python to execute code on the GPU using
CUDA.

## Setup
* Create a python venv using ```python -m venv .venv```
* Activate the venv using ```source .venv/bin/activate```
* Install the dependencies using ```pip install -r requirements.txt```
  * Pip will try to install pycuda, which probably requires that CUDA is installed locally on your
    PC.

## Running examples
* Use ```make <example>``` to run the given example.

## Cleanup
* Once done, the venv can be deactivated using ```deactivate```
* To clean auxiliary files that examples may generate use ```make clean```
