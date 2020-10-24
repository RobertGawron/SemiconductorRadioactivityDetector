cd ../Test/UnitTest && \
\
\
cd test_gm_circular_buffer && \
make clean && \
make -j12 && \
ls -l && \
./test_gm_circular_buffer --output=./test_gm_circular_buffer.xml &&
\
\
cd .. && \
\
\
cd test_gm_histogram && \
make clean && \
make -j12 && \
ls -l && \
./test_gm_histogram --output=./test_gm_histogram.xml
