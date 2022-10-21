#! /bin/bash
rm *.so # strange crashing on macOS if remove the line
mkdir build; cd build && cmake .. && make && cp *.so ../ && cd ..
python3 setup.py build && python3 -m pip install -e .