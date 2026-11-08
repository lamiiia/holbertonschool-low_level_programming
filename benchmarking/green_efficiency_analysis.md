# Green Efficiency Analysis

## Measurement Methodology

All programs were compiled with gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long and executed on the same machine and environment. Time was measured inside each program with clock(), converted to seconds by dividing by CLOCKS_PER_SEC, which measures CPU time used by the process rather than wall-clock time.

The baseline loop (100000000 iterations) was run three times and every output was recorded verbatim. The two algorithms in comparison_algorithms.c were run five times, and I computed the average of each. In instrumentation_lab.c, I started a total timer before the first phase and stopped it after the last one. Each phase (build, process, reduce) has its own start and end taken immediately around the function call. The printf calls come after all measurements so that output time does not pollute the results.

## Observed Performance Differences

The baseline loop took 0.197473, 0.197300 and 0.197309 seconds across three runs. The average is 0.197361 seconds, and the gap between the fastest and slowest run is 0.000173 seconds. The same deterministic work therefore produced close but not identical times.

In the algorithm comparison, the naive implementation averaged 0.667325 seconds while the single-pass implementation averaged 0.000031 seconds. The naive version is ~21389 times slower. Both solve the same kind of counting problem, but the naive version uses nested loops that perform about n squared divided by 2 operations, while the single pass performs n operations.

In the instrumented program, TOTAL was 0.000329 seconds, with BUILD_DATA at 0.000121, PROCESS at 0.000141 and REDUCE at 0.000065 seconds. TOTAL is greater than or equal to each phase, as expected, because it covers all of them.

## Relation Between Runtime and Energy Consumption

I did not measure power in watts, so I cannot state any energy value. Runtime is used only as a proxy: a program that runs longer keeps the CPU active longer, which generally means more energy is consumed. Based on my measurements, the naive algorithm kept the CPU busy for 0.667325 seconds compared with 0.000031 seconds for the single pass, so on this proxy it is the far less efficient choice. At scale, for example when the same code runs many times on servers, such a difference would add up, but that scaling is an argument and not something I measured.

## Limitations of the Experiment

The measurements have several limits. First, clock() has limited resolution, so very short times such as the phases of the instrumented program, which are only a fraction of a millisecond, are noisy and can be rounded. Second, the baseline spread of 0.000173 seconds shows run-to-run variability caused by other processes, CPU frequency changes and caching. Third, only a few runs were made, so the averages are not statistically strong. Fourth, runtime is not energy: a faster program may use different hardware resources, and I used no energy measuring tool. Finally, all results come from one machine and one compiler configuration and may differ elsewhere.

## Practical Engineering Takeaway

Algorithmic choice mattered far more than small details: replacing a quadratic approach with a linear one produced a difference of ~21389 times in my measurements. Before optimizing, measure each phase separately, as the instrumented program does, so effort goes to the phase that really costs time. Repeat measurements under the same conditions, report averages and variability, and state the limits of the method. Efficient code reduces CPU time, and reduced CPU time is a reasonable first step toward more sustainable software, even though real energy profiling needs specialized tools.
