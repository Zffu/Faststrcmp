# Fast strcmp
A small library containing faster and better alternatives for `strcmp`.

## Benchmarks.

Here are the following benchmark results for small strings (strings of length 100):
| Method Used | Time / op | Estimated strings / second | 
| strcmp | 9.587ns | 104.3M/s |
| faststrcmp (classic) | 1.483ns | 674.4M/s |
